#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "state_machine.h"

using namespace std;

int main()
{
    sm::STokenizer st("Hello, World!");
    st.print_table();
    st.get_token();
}
