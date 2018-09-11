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
    airplane(unsigned int t): vehicle(), wings(4), start_time(t){}
    //MODIFCATION MEMBER FUNCTIONS
    //CONSTANT MEMBER FUNCTIONS
    unsigned int get_start_time() const { return start_time;}
protected:
    int wings;
    unsigned int start_time;
};

#endif // AIRPLANE_H
