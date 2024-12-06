#ifndef INPUT_CLASS_HPP
#define INPUT_CLASS_HPP

#include <string>

class Input {
public:
    static std::string get_input() {
        char input[100];
        getstr(input);
        return std::string(input);
    }
};

#endif
