#ifndef DICE_HPP
#define DICE_HPP

class Dice {
public:
    Dice();
    int roll();  // Roll the dice and return the value

private:
    int current_value;
};

#endif
