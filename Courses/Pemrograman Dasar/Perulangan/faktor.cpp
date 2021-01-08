#include <iostream>

using namespace std;

int main(){
    int N, i;
    cin >> N;
    int K[N];
    for(i = N; i > 0; i--){
        if(N % i == 0)
            cout << i << endl;
    }
    return 0;
}