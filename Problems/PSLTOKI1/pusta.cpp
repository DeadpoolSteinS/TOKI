#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, lawan, tukar = 0;
    cin >> N;
    int D[N];
    for(int i = 0; i < N; i++)
        cin >> D[i];
    for(int i = 0; i < N; i++){
        lawan = i;
        for(int j = i+1; j < N; j++)
            if(D[lawan] > D[j])
                lawan = j;
        if(lawan != i){
            swap(D[i], D[lawan]);
            tukar++;
        }
    }
    cout << tukar << endl;
    return 0;
}