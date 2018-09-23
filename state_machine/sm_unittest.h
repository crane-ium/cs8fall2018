#ifndef SM_UNITTEST_H
#define SM_UNITTEST_H

#include <iostream>
#include "state_machine.h"
#include "smtoken.h"
#include "ftokenizer.h"

class sm_unittest
{
public:
    sm_unittest(){}
    void run_unittest();
    void print();
    void set_str(const string& s);
    void ftoken_print(const string& file, bool b);
private:
    string str;
    sm::STokenizer machine;
    sm::SToken stoken;
};

#endif // SM_UNITTEST_H
