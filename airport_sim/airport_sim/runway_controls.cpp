#include "runway_controls.h"

//l_time: landing time
//t_time: takeoff time
//l_prob: landing probability
//t_prob: takeoff probability
//f_limit: fuel limit
//t_total: total time
runway_controls::control_values::control_values(unsigned int l_time,
                                unsigned int t_time,
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


