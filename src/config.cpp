#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/config.hpp"


Config Config::load_from_file(const std::string filename) {
    Config config;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        char delim;
        if (iss >> key >> delim >> value) {
            if (key == "port") {
                config.port = std::stoi(value);
            } else if (key == "nconnections") {
                config.nconnections = std::stoi(value);
            }
        }
    }
    file.close();
    return config; 
}
unsigned int Config::get_port() { return port; }
unsigned char Config::get_nconnections() { return nconnections; }
