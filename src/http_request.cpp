#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "../include/http_request.hpp"


namespace http {
    Request Request::create_request_from_string(std::string request_str)
    {
        Request request;

        std::vector<std::string> request_lines;
        boost::split(request_lines, request_str, boost::is_any_of("\r\n"));
        request.method = request_lines[0].substr(0, request_lines[0].find(" "));
        request.path = request_lines[0].substr(request_lines[0].find(" ") + 1, request_lines[0].rfind(" ") - request_lines[0].find(" ") - 1);
        request.version = request_lines[0].substr(request_lines[0].rfind(" ") + 1);
        for (size_t i = 1; i < request_lines.size(); i++) {
            if (request_lines[i].empty()) {
                continue;
            }
            std::string header_line = request_lines[i];
            size_t colon_index = header_line.find(": ");
            std::string header_name = header_line.substr(0, colon_index);
            std::string header_value = header_line.substr(colon_index + 2);

            request.headers[header_name] = header_value;
        }
        return request;
    }
    // std::string http::Request::get_method() const { return method; }
    // std::string Request::get_path() const { return path; }
    // std::string Request::get_version() const { return version; }
    void Request::print_request()
    {
        std::cout << "Method: " << method << std::endl;
        std::cout << "Path: " << path << std::endl;
        std::cout << "Version: " << version << std::endl;
        for (const auto &header : headers) {
            std::cout << header.first << ": " << header.second << std::endl;
        }
    }
}
