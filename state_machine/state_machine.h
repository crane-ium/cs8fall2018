#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <iostream>

using namespace std;

const int MAX_COLUMNS = 10;
const int MAX_ROWS = 6;

namespace sm{

    class Token{

    };

    class STokenizer{
    public:
        //CTORs
        STokenizer();
        STokenizer(const string& s);
        //BIG 3

        //MOD MEMBER FUNCS
        void get_table(int t[][MAX_COLUMNS]); //if you wanted to set a completely new table
        void set_string(const string& s); //sets our input to a new string
        bool get_token(); //returns if there is a token in string[current_pos:]
        //CONST MEMBER FUNCS
        void print_table() const;
    private:
        string input;
        unsigned int current_pos;
        static int _table[MAX_ROWS][MAX_COLUMNS]; //static across all instances
        void make_table();
        void mark_table(const int row, int start, int end, int state);
        void mark_table(int start_row, int end_row, int start, int end, int state);
    };

//    bool get_token(const string &block, int _table[][MAX_COLUMNS], int &pos, int &token);
//    static int table[MAX_ROWS][MAX_COLUMNS];

}

#endif // STATE_MACHINE_H
