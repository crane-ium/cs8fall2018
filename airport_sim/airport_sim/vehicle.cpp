#include "vehicle.h"
//This is an arbitrary class to be inherited by airplane

double vehicle::get_max_speed_mph(){
    return max_speed;
}

double vehicle::get_max_speed_kmph(){
    return max_speed * 1.60934;
}
