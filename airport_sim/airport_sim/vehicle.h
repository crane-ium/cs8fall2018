#ifndef VEHICLE_H
#define VEHICLE_H

//arbitrary class to be inherited by airplane
//This will practice inheritance
class vehicle
{
public:
    vehicle(): wheels(4), doors(2), windows(8), max_speed(100){}
    double get_max_speed_mph();
    double get_max_speed_kmph();

protected:
    int wheels, doors, windows;
private:
    double max_speed; //in miles per hour ofc
};

#endif // VEHICLE_H
