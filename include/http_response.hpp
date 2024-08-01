#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


namespace http {
    class Response {
        private:
        unsigned short status_code;
        std::string reason_phrase;
        std::map<std::string, std::string> headers;
        std::map<std::string, std::string> body;
        public:
        Response(unsigned short status_code, const std::string &reason_phrase);
        void add_header(const std::string &name, const std::string &value);
        void add_body(const std::string &name, const std::string &value);
        static Response create_response(unsigned int status_code, const std::string &reason_phrase);
        std::string to_string();
    };
}
