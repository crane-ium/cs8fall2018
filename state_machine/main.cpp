#include "sm_unittest.h"
#include "ftokenizer.h"

using namespace std;

int main(){
    sm_unittest tester;
    tester.run_unittest(); //Runs the unittest instance

    //A copy pasted function from my sm_unittest::ftoken_print
    //Just wanted to place a copy here so it's easily seen
    //slight modifications made
    string file_location = "../state_machine/solitude.txt";
    int count = 0;
    sm::FTokenizer file_toke;
    file_toke.set_string(file_location);
    for(sm::SToken stoken; file_toke.more();){
        file_toke >> stoken;
        if(stoken.type_string() == "ALPHA"){
            count++;
        }
    }
    cout << __FUNCTION__ << " is complete\n";
    cout << "Alpha Count: " << count << endl;
}
