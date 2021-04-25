#include <bits/stdc++.h>
using namespace std;

int faktor[10000001];

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 2; i <= 10000000; i++)
        if(!faktor[i])
            for(int j = i; j <= 10000000; j+=i)
                faktor[j] = i;//pengisisan nilai array faktor
    int T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        int kain = 0;
        while(N > 1){
            N /= faktor[N];
            kain++;
        }//penentuan kain keberapa
        cout << (kain == K ? "Ya\n" : "Tidak\n");
    }
    return 0;
}