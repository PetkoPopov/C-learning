
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <istream>
#include <cstring>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

template<typename T>
void print(const vector<T> &v) {
    cout << "alfavit remain \n";
    for (auto c : v) {
        cout << c << " ";
    }

}

vector<char> makeAlfavit() { 
    vector<char> alfavit;
    for (int i = 35; i < 126; i++) {
        char c = (char) i;
        alfavit.push_back(c);
       
    }
//    vector<char> ptr_ = & alfavit ;
    return alfavit;
}

int main() {
//         vector<char>* ptr = makeAlfavit();
//         for(unsigned i = 0; i <91 ; i++){
//         cout<<ptr->at(i);
//         }
//         
//         cout<<endl<<ptr->at(22);
//         return 0;
    
//    vector<char> vec ={'d','j','k'};
//   
//    vector<char>* ptr=& vec;
//    vector<char>::iterator it=vec.begin();
//    
//    int pi= 3;
//    int * ptr_pi=&pi;
////    cout<< ptr_pi<<" <--ptr_pi "<<*ptr_pi<<" <==*ptr_pi \n =================";
//    vector<string>  bukva;
//    bukva.push_back("nachalo");
//    bukva.push_back("po");
//    bukva.push_back("yui");
//    string* ptr_bukva = & bukva[0];
//    
//    cout<<*ptr_bukva<<endl;
//    ptr_bukva++;
//    cout<<*ptr_bukva<<endl;
//    ptr_bukva++;
//    cout<<*ptr_bukva;
//    
//    
//         return 0;
    cout << "insert states \n";
    string input;
    getline(cin, input);

    vector<char> alfavit = makeAlfavit();
    vector<vector<char>> alfavit_state;
    while (input != "#end") {
        if (input == "#reset") {
            alfavit = alfavit_state.front();
            alfavit_state.clear();

        } else if (input == "#undo") {
            alfavit = alfavit_state.back();
            alfavit_state.pop_back();

        } else {
            char word;
            istringstream strm(input);
            while (strm >> word) {
                vector<char>::iterator it;
                for (it = alfavit.begin(); it != alfavit.end(); it++) {

                    if (*it == word) {
                        alfavit.erase(it);
                        alfavit_state.push_back(alfavit);
                        break;
                    }
                }
            }
        }
        print<char>(alfavit);
        cout << endl;
        getline(cin, input);
        cout << "==============================" << endl;


    }
    return 0;
}

