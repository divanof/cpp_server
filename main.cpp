#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "include/http_request.hpp"
#include "include/http_response.hpp"
#include "include/http_status_codes.hpp"

#include "include/config.hpp"


int main() {
    Config config = Config::load_from_file("server.conf");

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(config.get_port());
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        std::cerr << "bind failed" << std::endl;
        return 1;
    }

    listen(server_socket, config.get_nconnections());

    while (true) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);

        char request[1024];
        int bytes_received = recv(client_socket, request, sizeof(request), 0);
        std::cout << request << ' ' << bytes_received << std::endl;

        std::string request_string(request);
        http::Request request_obj = http::Request::create_request_from_string(request_string);
        std::vector<std::string> request_lines;
        boost::split(request_lines, request_string, boost::is_any_of("\r\n"));

        http::Response response = http::Response::create_response(http::HTTP_RESPONSE_STATUS_200_OK, "OK");
        response.add_body("server", "C++ Server");
        response.add_body("connection", "close");

        send(client_socket, response.to_string().c_str(), response.to_string().length(), 0);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}
