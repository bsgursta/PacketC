#include "general.hpp"
#include <stdint.h>

//Check if pin is within the valid range
int checkPinValid(uint8_t pin_num) {
    if(pin_num > 15 || pin_num < 0) {
        return 0;
    }
    return 1;
}

/* Checks if the value is a binary number*/
bool checkBinary(uint8_t number) {
    if(number == 1 || number == 0) {
        return true;
    }
    return false;
}