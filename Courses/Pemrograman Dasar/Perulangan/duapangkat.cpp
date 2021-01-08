#include <iostream>

using namespace std;

int main(){
    int N, B = 0, i, P = 1;
    cin >> N;
    if(N == 1)
        B = 1;
    for(i = 0; i < 16; i++){
        P = P * 2;
        if(N == P)
            B = 1;
    }
    if(B == 1)
        cout << "ya" << endl;
    else
        cout << "bukan" << endl;
    return 0;
}