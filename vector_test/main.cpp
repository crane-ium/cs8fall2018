#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1, v2;
    vector<vector<int>> v3;
//    v1.assign(10, 1);
//    v2 = v1;
//    v1[0] = 5;
//    v1.assign(10, 1);
//    v3.push_back(v1);
//    v3.assign(10, v1);
//    cout << v3[0][0] << endl;
//    cout << v3.size() << endl;
//    v3[0].assign(10,8);
//    cout << v3[0][4] << endl;
////    v3[0].insert(v1.begin(),7);
//    v3[0].resize(15);
//    for(int i = 0; i < 30; i ++)
//        cout << setw(3) << i;
//    cout << endl;
    string s;
    cin >> s;
    for(int i = 0; s[i] != NULL; i++){
        v1.push_back(s[i]);
    }
    cout << "done\n";
    for(int i = 0; i < v1.size(); i++)
        cout << setw(3) << v1[i];
    cout << endl;
    for(int r = 0; r < v3.size(); r++){
        for(int c = 0; c < v3[r].size(); c++)
            cout << setw(3) << v3[r][c];
        cout << endl;
    }
//    cout << v2[1];
}
