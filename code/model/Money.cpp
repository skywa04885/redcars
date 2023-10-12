#include "Money.hpp"

const int EURO_FACTOR = 100;

redcars::model::Money::Money(unsigned int euroCents, time_t valuedAt)
        : euroCents(euroCents), valuedAt(valuedAt) {

}

float redcars::model::Money::eurosAsFloat() const {
    return (float) euroCents / (float) EURO_FACTOR;
}
