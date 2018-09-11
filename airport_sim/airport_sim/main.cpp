#include <iostream>
#include "runway_controls.h"
#include "airplane.h"
#include "../../snq/my_queue.h"

using namespace std;

static const bool DEBUG = false;

int main()
{
    runway::control_values cv(5, //landing time
                               15, //takeoff time
                               0.10, //landing prob
                               0.08, //takeoff prob
                               20, //fuel limit
                               1440); //total time
    Queue<airplane*> q_l; //landing sim
    Queue<airplane*> q_w; //waiting sim, after landing before takeoff
    Queue<airplane*> q_t; //takeoff sim
    runway::bool_checker toff_bool(cv.get_t_prob());
    runway::bool_checker land_bool(cv.get_l_prob());
    runway::airplane_sim l_sim(cv.get_l_time());
    runway::airplane_sim t_sim(cv.get_t_time());

    unsigned int landed_planes = 0;
    unsigned int takeoff_planes = 0;
    unsigned int crashed_planes = 0;

    unsigned int landing_time;
    unsigned int takeoff_time;

    runway::averager avg_landing_time;
    runway::averager avg_takeoff_time;

    //runs sim over whole time constraint
    for(int s = 1; s <=cv.get_t_total(); s++){
        //sim takeoff timer
        if(q_t.get_size() > 0){
            if(t_sim.is_busy()){
                t_sim.sim_second();
                if(!t_sim.is_busy()){ //Plane took off
                    if(DEBUG)
                        cout << "Takeoff time: " << takeoff_time << endl;
                    t_sim.sim_reset();
                    takeoff_time = s - q_t.top()->get_start_time();
                    q_t.pop();
                    avg_takeoff_time.add_number(takeoff_time);
                    takeoff_planes++;
                }
            }else{
                t_sim.sim_reset();
                t_sim.sim_second();
            }
        }
        if(q_w.get_size() > 0 && toff_bool.query()){ //checking to move plane to runway
            q_w.pop();
            q_t.push(new airplane(s));
        }
        if(q_l.get_size() > 0){ //landing airplanes
            if(!l_sim.is_busy())
                l_sim.sim_reset();
            l_sim.sim_second();
            if(!l_sim.is_busy()){
                //This accounts only for planes able to be moved to takeoff
                //Therefore, all crashed planes are automatically removed out
                //until an eligible plane or queue is empty
                landing_time = s - q_l.top()->get_start_time();
                while(landing_time > cv.get_f_limit()){
                    if(DEBUG)
                        cout << "(crash) Landing time: " << landing_time << endl;
                    q_l.pop();
                    crashed_planes++;
                    if(q_l.get_size() > 0)
                        landing_time = s - q_l.top()->get_start_time();
                    else
                        break;
                }
                if(q_l.get_size() > 0){
                    if(DEBUG)
                        cout << "(good) Landing time: " << landing_time << endl;
                    avg_landing_time.add_number(landing_time);
                    q_l.pop();
                    q_w.push(new airplane(s));
                    landed_planes++;
                }
            }
        }
        if(land_bool.query()){//checking for landing planes
            if(DEBUG)
                cout << "Arrived at " << s << endl;
            q_l.push(new airplane(s));
            if(!l_sim.is_busy())
                l_sim.sim_reset();
        }
    }
    cout << "=====================================" << endl;
    cout << "time to take off       : " << cv.get_t_time() << endl;
    cout << "Time to land           : " << cv.get_l_time() << endl;
    cout << "Probability of landing : " << cv.get_l_prob() << endl;
    cout << "Probability of takeoff : " << cv.get_t_prob() << endl;
    cout << "Fuel limit (crash time): " << cv.get_f_limit() << endl;
    cout << "Total sim time         : " << cv.get_t_total() << endl;
    cout << endl << endl << "............................." << endl;
    cout << "Planes landed   : " << landed_planes << endl;
    cout << "Planes took off : " << takeoff_planes << endl;
    cout << "Planes crashed  : " << crashed_planes << endl;
    cout << "Avg landing wait time: " << avg_landing_time.average() << endl;
    cout << "Avg takeoff wait time: " << avg_takeoff_time.average() << endl;
    cout << "Planes in landing queue: " << q_l.get_size() << endl;
    cout << "Planes in takeoff queue: " << q_t.get_size() << endl;
}
