/* Chapter 9 Recursive FUnctions
 *
 * This is a single file containing  multiple examples of recursion
 *
 * Below are projects from Data Structures and Other Objects
 *  from end of chapter 9 pg 470
 * */
#include <iostream>
#include <iomanip>
#include <cassert>
#include <random>
#include <time.h>

using namespace std;

//---------- 9.1 -----------------
void R1_start(int limit); //It's better readability to start a recursive call elsewhere
void R1_levels(int count, int limit); //recursive function
void indent(int count); //couts spaces to indent
//---------- 9.2 -----------------
void R2_start(string prefix, unsigned int levels); //Calls our recursive func
void R2_box(string prefix, unsigned int levels); //Recursive function
//---------- 9.3 -----------------
void R3_start(string first, string second);
void R3_first_second(string first, string second);
//---------- 9.4 -----------------
void R4_start();
unsigned int R4_boxes(string box);
//---------- 9.5 -----------------
void R5_start(unsigned int n);
double R5_sumover(unsigned int n);
//---------- 9.16 -----------------
void R16_start();
bool R16_guess(unsigned int low, unsigned int high);

//------- main: call all our recursive functions --------
int main()
{
    R1_start(5);
    R2_start("Box:",2);
    R3_start("CAT","MAN");
    R4_start();
    R5_start(4);
    R16_start();
    R16_start();
}

//---------- 9.1 -----------------
void R1_start(int limit){
    R1_levels(0, limit);
}
void R1_levels(int count, int limit){
    assert(limit >= 0);
    indent(count);
    cout << "This was written by call number " << count << endl;
    if(count < limit)
        R1_levels(count+1, limit); //recursive call
    indent(count);
    cout << "This ALSO written by call number " << count << endl;
}
void indent(int count){
    for(int i = 0; i < count; i++)
        cout << " ";
}
//--------- 9.2 ------------------
void R2_start(string prefix, unsigned int levels){
    assert(levels > 0 && levels <= 9);
    R2_box(prefix, levels);
}
void R2_box(string prefix, unsigned int levels){
    if(levels==0){
        cout << prefix << endl;
        return;
    }
    for(int i = 1; i <= 9; i++)
        R2_box(prefix + char('0' + i) + ".", levels-1);
}
//---------- 9.3 -----------------
void R3_start(string first, string second){
    R3_first_second(first, second);
}
void R3_first_second(string first, string second){
    if(first.length() == 0){
        cout << second << endl;
        return;
    }
    for(int i = 0; i < first.length(); i++){
        string temp;
        //add first portion of substr before first[i]
        temp += first.substr(0, i);
        //add second portion of substr after first[i]
        temp += first.substr(i+1, first.length() - 1 - i);
        R3_first_second(temp, first[i] + second);
    }
}
//---------- 9.4 -----------------
void R4_start(){
    unsigned int box_count;
    box_count = R4_boxes("");
    cout << box_count << endl;
}
unsigned int R4_boxes(string box){
    unsigned int input, boxes;
    if(box.length() > 0)
        cout << "~In box " << box << "~" << endl;
    cout << "How many boxes do you see?\nBoxes: ";
    try{
        cin >> input;
        box += (box.length()>0)?("."):("");
        boxes = 0;
        for(int i = 0; i < input; i++)
            boxes += R4_boxes(box + char('0' + i+1));
        return boxes + input;
    }catch(...){
        return 0;
    }

}
//---------- 9.5 -----------------
void R5_start(unsigned int n){
    double answer;
    answer = R5_sumover(n);
    cout << "R5 total of n="<<n<<" is: " << answer << endl;
}
double R5_sumover(unsigned int n){
    if(n==0)
        return 0;
    return (double)1/n + R5_sumover(n-1);
}
//---------- 9.16 -----------------
void R16_start(){
    srand(time(NULL));
    R16_guess(1, 100);
}
bool R16_guess(unsigned int low, unsigned int high){
    unsigned int input;
    static unsigned int rn;
    if(rn == 0)
        rn = rand() % (high - low) + low;
    try{
        cout << "Between " << low << " and " << high << " (inclusive)" << endl;
        cout << "What is your guess?\n Input: ";
        cin>>input;
        cout << "(REAL ANSWER HEHE ;) ): " << rn << endl;
        if(input==rn){
            cout << "~Your guess was correct!~\n";
            rn = 0;
            return true;
        }else if(input < low || input > high){
            cout << "Not within the range\n";
            return R16_guess(low, high);
        }else if(input > rn){
            cout << "  Lower, try again :)\n";
            return R16_guess(low, input-1); //recursive call
        }else if(input < rn){
            cout << "  Higher, try again :)\n";
            return R16_guess(input+1, high); //recursive call
        }
    }catch(...){
        cout << " OOPSIE input!\n";
        return R16_guess(low, high);
    }
}
