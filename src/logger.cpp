#include "logger.h"

void Logger::init() {
    boost::log::add_file_log("log/arbitrage.log");
    boost::log::add_console_log(std::cout);
    boost::log::add_common_attributes();
}

void Logger::log(const std::string& message) {
    BOOST_LOG_TRIVIAL(info) << message;
}
