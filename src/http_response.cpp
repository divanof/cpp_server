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

#include "../include/http_response.hpp"

std::string json_from_map(const std::map<std::string, std::string> &data) {
    std::stringstream ss;
    ss << "{";
    bool first = true;
    for (const auto &item : data) {
        if (!first) {
            ss << ", ";
        }
        ss << "\"" << item.first << "\": \"" << item.second << "\"";
        first = false;
    }
    ss << "}";
    return ss.str();
}


namespace http {
    Response::Response(unsigned short status_code, const std::string &reason_phrase) : status_code(status_code), reason_phrase(reason_phrase) {}
    void Response::add_header(const std::string &name, const std::string &value) { headers[name] = value; }
    void Response::add_body(const std::string &name, const std::string &value) { body[name] = value; }
    Response Response::create_response(unsigned int status_code, const std::string &reason_phrase) {
        Response response = Response(status_code, reason_phrase);
        response.add_header("Content-Type", "application/json");
        return response;
    }
    std::string Response::to_string() {
        std::stringstream ss;
        ss << "HTTP/1.1 " << status_code << " " << reason_phrase << "\r\n";
        for (const auto &header : headers) {
            ss << header.first << ": " << header.second << "\r\n";
        }
        std::string body_json = json_from_map(body);
        ss << "Content-Length: " << body_json.size() << "\r\n";
        ss << "\r\n";
        ss << body_json;
        return ss.str();
    }
}
