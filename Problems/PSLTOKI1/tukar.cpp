#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, tukar = 0;
    bool ada = true;
    cin >> N;
    int D[N];
    for(int i = 0; i < N; i++)
        cin >> D[i];
    while(ada == true){
        ada = false;
        for(int i = 0; i < (N-1); i++)
            if(D[i] > D[i+1]){
                swap(D[i], D[i+1]);
                tukar++;
                ada = true;
            }
    }
    cout << tukar << endl;
    return 0;
}