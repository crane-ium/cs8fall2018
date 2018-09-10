#ifndef RUNWAY_CONTROLS_H
#define RUNWAY_CONTROLS_H

#include <cstdlib>

namespace runway_controls{
    //Runs sim of the runway
    class takeoff_sim{
    public:
        takeoff_sim(unsigned int s = 60);
        void sim_second(); //sims a second
        void start_sim();
        bool is_busy() const {return (current_time_seconds > 0);}

    private:
        unsigned int run_time_length_seconds;
        unsigned int current_time_seconds;
    };

    //Checks whether the probability is true for that query based on % chance
    class bool_checker{
    public:
        bool_checker(double p = 0.5); //ctor
        bool query() const; //returns true p*100% of the time
    private:
        double probability;
    };

    class averager{
    public:
        averager(); //ctor
        void add_number(double val);
        std::size_t get_count() const {return count;}
//        unsigned int get_count() const {return count;}
    private:
        std::size_t count;
//        unsigned int count;
        double total;
    };

    class control_values
    {
    public:
        control_values(unsigned int t_time, unsigned int l_time, double l_prob, double t_prob, unsigned int f_limit, unsigned int t_total);

    private:
        unsigned int takeoff_time, landing_time, fuel_limit, total_time;
        double takeoff_probability, landing_probability;
    };
}
#endif // RUNWAY_CONTROLS_H
