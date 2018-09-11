#include <cassert>
#include "runway_controls.h"

//l_time: landing time
//t_time: takeoff time
//l_prob: landing probability
//t_prob: takeoff probability
//f_limit: fuel limit
//t_total: total time

using namespace runway;

control_values::control_values(unsigned int l_time,
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

takeoff_sim::takeoff_sim(){
    wait_time = 0;
}

void takeoff_sim::sim_second(){
    wait_time++;
}

landing_sim::landing_sim(unsigned int f){
    wait_time = 0;
    fuel_limit = f;
    crashed = false;
}

void landing_sim::sim_second(){
    if(!is_crashed())
        wait_time++;
    else
        crashed = true;
}

bool_checker::bool_checker(double p){
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_checker::query() const{
#include <cstdlib>
    return (rand() < probability * RAND_MAX);
}

averager::averager(){
    count = 0;
    total = 0;
}

void averager::add_number(double val){
    total += val;
    count++;
}

double averager::average() const{
    assert(get_count() > 0);
    return (total/count);
}






