#ifndef FTOKENIZER_H
#define FTOKENIZER_H

#include <fstream>
#include "state_machine.h"
#include "smtoken.h"

namespace sm{
    class FTokenizer
    {
    public:
        //CTORs
        FTokenizer(){}
        FTokenizer(const string& file); //add with a file
        //MEMBER FUNCS
        void set_string(const string& file); //change or add file
        bool more(); //check if there's more tokens to create, while getting the next block if there's more
        bool get_next_token(); //Find if there's more blocks, and set a new stokenizer
        //FRIEND FUNCS
        friend FTokenizer& operator >> (FTokenizer& lhs, sm::SToken& stoken){
            lhs.stizer >> stoken;
            return lhs;
        }
    private:
        sm::STokenizer stizer; //translates a string into a queue of tokens
        string block; //The next block string from the file
        ifstream ifile; //file stream
        string ifile_location;
    };
}

#endif // FTOKENIZER_H
