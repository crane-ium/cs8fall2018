#ifndef RUNWAY_CONTROLS_H
#define RUNWAY_CONTROLS_H


class runway_controls
{
public:
    runway_controls(unsigned int t_time, unsigned int l_time, double l_prob, double t_prob, unsigned int f_limit, unsigned int t_total);

private:
    unsigned int takeoff_time, landing_time, fuel_limit, total_time;
    double takeoff_probability, landing_probability;
};

#endif // RUNWAY_CONTROLS_H
