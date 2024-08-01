#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


namespace http {
    class Request {
        private:
        std::string method;
        std::string path;
        std::string version;

        std::map<std::string, std::string> headers;
        std::map<std::string, std::string> data;
        public:
        Request() {}
        static Request create_request_from_string(std::string request_str);

        std::string get_method();
        std::string get_path();
        std::string get_version();
        void print_request();
    };
}
