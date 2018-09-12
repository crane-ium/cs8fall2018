
#include <iostream>
#include <iomanip>
#include "state_machine.h"

//static int sm::table[MAX_ROWS][MAX_COLUMNS];

int sm::STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

sm::STokenizer::Stokenizer(){
//    _table[MAX_ROWS][MAX_COLUMNS];
    make_table();
    mark_table(0, 1, 5, 8, 1);
}

void sm::STokenizer::set(){
    make_table();
    mark_table(0, 1, 5, 8, 5);
}

void sm::STokenizer::make_table(){
    for(int r = 0; r < MAX_ROWS; r++){
        for(int c = 0; c < MAX_COLUMNS; c++){
            this->_table[r][c] = -1;
        }
    }
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
