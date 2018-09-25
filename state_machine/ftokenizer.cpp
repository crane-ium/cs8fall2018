#include "ftokenizer.h"

#define file_set(f) ifile_location= f; ifile.open(f);

sm::FTokenizer::FTokenizer(const string& file):FTokenizer(){
    file_set(file); //set file location and open file
}

void sm::FTokenizer::set_string(const string& file){
    if(ifile.is_open())
        ifile.close();
    file_set(file);//set file location and open file
}

bool sm::FTokenizer::get_next_token(){
//    string temp = "";
    if(ifile.is_open()){
        ifile.seekg(0, ifile.end);
        int ifile_length = ifile.tellg();
        ifile.seekg(0, ifile.beg);
//        if(!(ifile >> block))
//            return false;
//        temp += block;
//        while(temp.length() <= BUFFER_MAX){ //create a string until 1000
//            if(ifile >> block) //read the next block from the file
//                temp += " " + block;
//            else
//                break;
//        }
        delete[] cstr;
        ifile.read(cstr, 1000);
//        cout << ifile.gcount() << " : " << ifile_length << endl;
        cout << cstr << endl;

        if(ifile)
            stizer.set_string(cstr); //set the stokenizer string
        else{
//            ifile.read(cstr, ifile.gcount()-10);
            stizer.set_string(cstr);
            return false;
        }
        return true;
    }else
        return false;

}

bool sm::FTokenizer::more(){
    if(stizer.more() || get_next_token()){ //check more first because getting a new string
        return true;
    }else{
        ifile.close();
        return false;
    }
}
