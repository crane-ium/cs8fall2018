/*Fractals: Use recursion to create a fractal
 *
 * This will split a line in half and move the midpoint up/down
 * There are n^2 occurences, where n is the number of recursive calls made
 *
 * The flow of this assignment is that of a balanced binary tree
 * */

#include <iostream>
#include <iomanip>
#include <random>
#include <cassert>
#include <time.h>

void start_fractal(double lh, double rh, double width, double epsilon);
void random_fractal(double lh, double rh, double width, double epsilon, double x);
void display(double height, double x);

using namespace std;

int main()
{
    srand(time(NULL));
    double lh, rh;
    lh = 0;
    rh = 2;
    start_fractal(lh, rh, 16, 1);
}

void display(double height, double x){
    cout << setprecision(3) << fixed;
    cout << "Height: " << left << setw(8) << height;
    cout << "X: " << setw(8) << x << endl;
}

void start_fractal(double lh, double rh, double width, double epsilon){
    //Base function
    assert(width > 0);
    assert(epsilon > 0);

    display(lh, 0);

    random_fractal(lh, rh, width, epsilon, width);
}
void random_fractal(double lh, double rh, double width, double epsilon, double x){
    /* Recursive function
     * */
    double mid_height;

    if(width <= epsilon){
        display(rh, x); //Display the values of the rhs (x,y) point
    }else{
        mid_height = (lh + rh)/2;
        mid_height += 1 - 2*((double)rand() / RAND_MAX);
        cout << "Before recursive calls - right endpoint = (x, y): (" \
             << x << ", " << rh << ")" << endl;
        random_fractal(lh, mid_height, width/2, epsilon, x - width/2);
        random_fractal(mid_height, rh, width/2, epsilon, x);

    }
}
