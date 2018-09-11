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

    for(int s = 1; s <=cv.get_t_total(); s++){

    }
}
