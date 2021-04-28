#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int A, B, C, daper[6], perda[6], banyak[5], biaya = 0;
    cin >> A >> B >> C;
    for(int i = 0; i < 6; i+=2){
        cin >> daper[i] >> daper[i+1];
        perda[i] = daper[i];
        perda[i+1] = daper[i+1];
    }
    sort(perda, perda+6);
    for(int i = 0; i < 5; i++){
        banyak[i] = 0;
        for(int j = 0; j < 6; j+=2)
            if(daper[j] <= perda[i] && daper[j+1] >= perda[i+1])
                banyak[i]++;
        if(banyak[i] == 1)
            biaya = biaya + A*(perda[i+1] - perda[i]);
        else if(banyak[i] == 2)
            biaya = biaya + B*(perda[i+1] - perda[i])*2;
        else if(banyak[i] == 3)
            biaya = biaya + C*(perda[i+1] - perda[i])*3;
    }
    cout << biaya << endl;
    return 0;
}