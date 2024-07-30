#ifndef LOGGER_H
#define LOGGER_H

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>

class Logger {
public:
    static void init();
    static void log(const std::string& message);
};

#endif // LOGGER_H
