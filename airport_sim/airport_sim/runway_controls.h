#ifndef RUNWAY_CONTROLS_H
#define RUNWAY_CONTROLS_H

#include <cstdlib>

namespace runway_controls{
    //Runs sim of the runway
    class takeoff_sim{
    public:
        //CTORs
        takeoff_sim(unsigned int s = 60);
        //MODIFICATION MEMBER FUNCTIONS
        void sim_second(); //sims a second
        void start_sim(); //resets current time if not busy
        //CONSTANT MEMBER FUNCTION
        bool is_busy() const { //Return whether sim is occupied
                    return (current_time_seconds > 0);}
    private:
        unsigned int run_time_length_seconds; //specified max runtime
        unsigned int current_time_seconds; //time remaining
    };

    //Checks whether the probability is true for that query based on % chance
    class bool_checker{
    public:
        //CTOR
        bool_checker(double p = 0.5); //ctor
        //CONSTANT MEMBER FUNCTION
        bool query() const; //returns true p*100% of the time
    private:
        double probability; //chance of success
    };

    class averager{
    public:
        //CTOR
        averager(); //ctor
        //MOD MEMBER FUNCTIONS
        void add_number(double val);
        //CONST MEMBER FUNCTIONS
        std::size_t get_count() const {return count;} //times numbers were added
//        unsigned int get_count() const {return count;}
    private:
        std::size_t count; //times numbers were added
//        unsigned int count;
        double total; //total of numbers added
    };

    //This class holds all the basic data needed to control the sim
    class control_values{
    public:
        //CTOR
        control_values(unsigned int t_time, unsigned int l_time, double l_prob, double t_prob, unsigned int f_limit, unsigned int t_total);
        //CONSTANT MEMBER FUNCTIONS
        unsigned int get_t_time() const {return takeoff_time;} //takeoff time
        unsigned int get_l_time() const {return landing_time;} //landing time
        unsigned int get_f_limit() const {return fuel_limit;} //fuel limit
        unsigned int get_t_total() const {return total_time;} //total time
        double get_t_prob() const {return takeoff_probability;} //takeoff probability
        double get_l_prob() const {return landing_probability;} //landing probability

    private:
        unsigned int takeoff_time, landing_time, fuel_limit, total_time;
        double takeoff_probability, landing_probability;
    };
}
#endif // RUNWAY_CONTROLS_H
