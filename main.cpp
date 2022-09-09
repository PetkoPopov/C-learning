
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

vector<char>* makeAlfavit() { 
    vector<char> alfavit;
    for (int i = 35; i < 126; i++) {
        char c = (char) i;
        alfavit.push_back(c);
       
    }
    vector<char> ptr_ = & alfavit ;
    return ptr_;
}

int main() {

    cout << "insert states \n";
    string input;
    getline(cin, input);

    vector<char>* alfavit = makeAlfavit();
    vector<vector<char>*> alfavit_state;
    while (input != "#end") {
        if (input == "#reset") {
//            alfavit = alfavit_state.front();
//            alfavit_state.clear();

        } else if (input == "#undo") {
//            alfavit = alfavit_state.back();
//            alfavit_state.pop_back();

        } else {
            char word;
            istringstream strm(input);
            while (strm >> word) {
                
                for (size_t it =0 ; it != *alfavit->size(); it++) {

                    if (alfavit->at(it) == word) {
                        alfavit->erase(it);
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

