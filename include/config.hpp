#include <string>


class Config {
    private:
    unsigned int port;
    unsigned char nconnections;
    std::string config_path;
    public:
    Config() {}
    static Config load_from_file(const std::string filename);
    unsigned int get_port();
    unsigned char get_nconnections();
};