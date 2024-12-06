#include "dice.hpp"
#include <cstdlib>
#include <ctime>

Dice::Dice() : current_value(0) {}

int Dice::roll() {
    current_value = rand() % 6 + 1;
    return current_value;
}
