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
        Stokenizer();
        void get_table(int t[][MAX_COLUMNS]);
        void print_table() const;
        void set();
    private:
        string s;
        static int _table[MAX_ROWS][MAX_COLUMNS];
        void make_table();
        void mark_table(const int row, int start, int end, int state);
        void mark_table(int start_row, int end_row, int start, int end, int state);
    };

//    bool get_token(const string &block, int _table[][MAX_COLUMNS], int &pos, int &token);
//    static int table[MAX_ROWS][MAX_COLUMNS];

}

#endif // STATE_MACHINE_H
