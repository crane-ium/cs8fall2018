#include "runway_controls.h"

runway_controls::runway_controls(unsigned int t_time,
                                unsigned int l_time,
                                 double l_prob,
                                 double t_prob,
                                 unsigned int f_limit,
                                 unsigned int t_total){
    takeoff_time = t_time;
    landing_time = l_time;
    takeoff_probability = t_prob;
    landing_probability = l_prob;
    fuel_limit = f_limit;
    total_time = t_total;
}
