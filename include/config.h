#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <boost/json.hpp>

class Config {
public:
    static Config& getInstance();
    void loadConfig(const std::string& filename);

    int httpPoolSize;
    std::string httpBaseUrl;
    std::string wsBaseUrl;
    std::string apiKey;
    std::string apiSecret;

private:
    Config() = default;
    void parseConfig(const boost::json::value& json);
};

#endif // CONFIG_H
