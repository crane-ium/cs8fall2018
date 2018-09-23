#include "sm_unittest.h"
#include <chrono>

using namespace std;
using chrono::high_resolution_clock;

void sm_unittest::ftoken_print(const string& file, bool b){
    //file: is the string file location
    //b: true or false if to display information on all the alpha tokens
    string file_location = file;
    int count = 0;
    sm::FTokenizer file_toke;
    file_toke.set_string(file_location);
    for(sm::SToken stoken; file_toke.more();){
        file_toke >> stoken;
        if(stoken.type_string() == "ALPHA"){
            count++;
            if(b) //check to display or not
                cout << setw(10) << stoken.type_string() << setw(10) << stoken << endl;
        }
    }
    cout << __FUNCTION__ << " is complete\n";
    cout << "Alpha Count: " << count << endl;
}

void sm_unittest::print(){
    cout << "String: " << str << endl;
    machine.set_string(str);
    while(machine.more()){
        machine >> stoken;
        cout << setw(8) << stoken.type_string() << setw(10) << stoken << endl;
    }
    cout << "Done\n\n";
}

void sm_unittest::set_str(const string &s){
    str = s;
    print();
}

void sm_unittest::run_unittest(){
    //https://stackoverflow.com/questions/36042637/how-to-calculate-execution-time-in-milliseconds
    //time measuring in milliseconds
    auto start_time = chrono::high_resolution_clock::now();

    set_str(""); //test empty string
    set_str("&"); //single unknown
    set_str("<>|~"); //multiple unkno=wns
    set_str("1"); //single digit
    set_str("-3.1415926");
    set_str("12,345,6789.0.5");
    set_str("123:50:59, 80:61 12:16am 00:00pm 1:32 1:70pm 13:00 12:12");
    set_str("End of test!");

    auto end_time = chrono::high_resolution_clock::now();
    cout << "Milliseconds to complete stokenizer tasks: ";
    auto time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
    cout << time << endl << endl;

    start_time = chrono::high_resolution_clock::now();

    ftoken_print("../state_machine/solitude.txt",false);
    ftoken_print("../state_machine/work_report.txt", true);
    ftoken_print("../state_machine/console_output.txt", false);

    end_time = chrono::high_resolution_clock::now();
    cout << "Milliseconds to complete stokenizer tasks: ";
    time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
    cout << time << endl << endl;
}
