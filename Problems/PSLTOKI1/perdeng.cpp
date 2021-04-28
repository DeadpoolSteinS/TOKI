#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int A, B, kali = 0, mod, ulo, bunshin;
    cin >> A >> B;
    bunshin = B;
    while(A > 0){
        mod = A % 10;
        B = bunshin;
        while(B > 0){
            ulo = B % 10;
            kali += mod * ulo;
            B/=10;
        }
        A/=10;
    }
    cout << kali << endl;
    return 0;
}