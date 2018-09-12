
#include <iostream>
#include <iomanip>
#include "state_machine.h"

//static int sm::table[MAX_ROWS][MAX_COLUMNS];

int sm::STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

sm::STokenizer::STokenizer(){
    input = "";
    make_table();
    current_pos = 0;
}

sm::STokenizer::STokenizer(const string& s): STokenizer(){
    input = s;
}

void sm::STokenizer::make_table(){
    mark_table(0, MAX_ROWS-1, 1, MAX_COLUMNS-1, -1);
}

void sm::STokenizer::mark_table(int row, int start, int end, int state){
    mark_table(row, row, start, end, state);
}

void sm::STokenizer::mark_table(int start_row, int end_row, int start, int end, int state){
    for(int r = start_row; r <= end_row; r++){
        for(int c = start; c <= end; c++){
            _table[r][c] = state;
        }
    }
}

void sm::STokenizer::get_table(int t[][MAX_COLUMNS]){
    for(int r = 0; r < MAX_ROWS; r++){
        for(int c = 0; c < MAX_COLUMNS; c++)
            t[r][c] = _table[r][c];
    }
}

void sm::STokenizer::print_table() const{
    for(int r = 0; r < MAX_ROWS; r++){
        for(int c = 0; c < MAX_COLUMNS; c++){
            std::cout << std::setw(3) << this->
                         _table[r][c];
        }
        std::cout << endl;
    }
}

bool sm::STokenizer::get_token(){
    char* c; //character walker
    unsigned int last_success = current_pos;
    cout << endl;
    for(c = &input[current_pos]; *c != NULL; c++)
        cout << setw(2) << *c;
}

void sm::STokenizer::set_string(const string& s){
    input = s;
    current_pos = 0;
}
