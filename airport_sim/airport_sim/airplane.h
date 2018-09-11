#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "vehicle.h"
class vehicle
{
public:
    //CTOR
    vehicle(): wheels(4), doors(2), windows(8), max_speed(100){}
    //CONSTANT MEMBER FUNCTIONS
    double get_max_speed_mph() const; //returns max_speed
    double get_max_speed_kmph() const; //returns max speed converted to km/h

protected:
    int wheels, doors, windows;
private:
    double max_speed; //in miles per hour ofc
};

class airplane : public vehicle
{
public:
    //CTOR
    airplane(): vehicle(), wings(4){}
    //MODIFCATION MEMBER FUNCTIONS

protected:
    int wings;
};

#endif // AIRPLANE_H
