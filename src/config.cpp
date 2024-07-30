#include "config.h"
#include <fstream>
#include <iostream>
#include <boost/json.hpp>

Config& Config::getInstance() {
    static Config instance;
    return instance;
}

void Config::loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open config file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    boost::json::value json = boost::json::parse(buffer.str());
    parseConfig(json);
}

void Config::parseConfig(const boost::json::value& json) {
    if (json.kind() != boost::json::kind::object) {
        throw std::runtime_error("Invalid JSON format");
    }

    auto obj = json.as_object();
    httpPoolSize = obj["http_pool_size"].as_int64();
    httpBaseUrl = obj["http_base_url"].as_string().c_str();
    wsBaseUrl = obj["ws_base_url"].as_string().c_str();
    apiKey = obj["api_key"].as_string().c_str();
    apiSecret = obj["api_secret"].as_string().c_str();
}
