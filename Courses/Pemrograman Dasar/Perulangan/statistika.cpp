#include <iostream>

using namespace std;

int main(){
    int N, i, A = -100000, B = 100000;
    cin >> N;
    int K[N];
    for(i = 0; i < N; i++){
        cin >> K[i];
        if(K[i] > A)
            A = K[i];
        if(K[i] < B)
            B = K[i];
    }
    cout << A << " " << B << endl;
    return 0;
}