#include "airplane.h"

double vehicle::get_max_speed_mph() const{
    return max_speed;
}

double vehicle::get_max_speed_kmph() const{
    return max_speed * 1.60934;
}

