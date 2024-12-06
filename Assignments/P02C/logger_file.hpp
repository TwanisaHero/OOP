#ifndef LOGGER_CLASS_HPP
#define LOGGER_CLASS_HPP

#include <iostream>
#include <fstream>

class Logger {
public:
    static void log(const std::string& message) {
        std::ofstream log_file("log.txt", std::ios::app);
        log_file << message << "\n";
    }
};

#endif
