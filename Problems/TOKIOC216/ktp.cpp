#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, id = 0;
    cin >> N;
    int B[N];
    pair <int, int> A[N];//agar berhubungan
    for(int i = 0; i < N; i++){
        cin >> B[i];
        A[i].second = i;
    }
    if(N == 5){
        cout << "0 1 2 3 4" << endl;
        return 0;//persamaan tidak memenuhi untuk N = 5
    }
    for(int i = 0; i < N; i++){
        A[(id + 5) % N].first = B[(id + 1) % N] - B[id] + A[id].first;
        id = (id + 5) % N;
    }
    sort(A, A + N);//yang disorting adalah integer first
    for(int i = 0; i < 5; i++){
        cout << A[i].second;
        if(i != 4)
            cout << " ";
    }
    cout << endl;
    return 0;
}