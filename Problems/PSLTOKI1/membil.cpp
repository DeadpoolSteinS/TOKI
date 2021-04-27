#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, bilangan, balik;
    cin >> N;
    while(N--){
        balik = 0;
        cin >> bilangan;
        while(bilangan > 0){
            balik = (balik * 10 + bilangan % 10);
            bilangan /= 10;
        }
        cout << balik << endl;
    }
    return 0;
}