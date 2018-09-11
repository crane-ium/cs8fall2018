#include <iostream>
#include "runway_controls.h"
#include "airplane.h"
#include "../../snq/my_queue.h"

using namespace std;

namespace foo{
class bar{
public:
    bar():x(1){}
    int get_x(){
        return x;
    }
private:
    int x;
};
}

int main()
{
    runway::control_values cv(5,
                               15,
                               0.10,
                               0.08,
                               20,
                               1440);
    Queue<airplane*> q_l; //landing sim
    Queue<airplane*> q_t; //takeoff sim
    runway::bool_checker toff_bool(cv.get_t_prob());
    runway::bool_checker land_bool(cv.get_l_prob());

    unsigned int landed_planes = 0;
    unsigned int takeoff_planes = 0;
    unsigned int crashed_planes = 0;

    unsigned int landing_time;
    unsigned int takeoff_time;

    runway::averager avg_landing_time;
    runway::averager avg_takeoff_time;

    //runs sim over whole time constraint
    for(int s = 1; s <=cv.get_t_total(); s++){
        if(q_l.get_size() > 0 && toff_bool.query()){ //checking to move plane to runway
            landing_time = s - q_l.top()->get_start_time();
            //This accounts only for planes able to be moved to takeoff
            //Therefore, all crashed planes are automatically removed out
            //until an eligible plane or queue is empty
            while(landing_time >= cv.get_f_limit()){
                q_l.pop();
                crashed_planes++;
                if(q_l.get_size() > 0)
                    landing_time = s - q_l.top()->get_start_time();
                else
                    break;
            }
            if(q_l.get_size() > 0){
                q_l.pop();
                avg_landing_time.add_number(landing_time);
                q_t.push(new airplane(s));
                landed_planes++;
            }
        }
        if(land_bool.query()){//checking for landing planes
            q_l.push(new airplane(s));
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
