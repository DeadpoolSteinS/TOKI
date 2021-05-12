#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C, daper[6], perda[6], banyak, biaya = 0;
    scanf("%d %d %d", &A, &B, &C);
    for(int i = 0; i < 6; i+=2){
        scanf("%d %d", &daper[i], &daper[i+1]);
        perda[i] = daper[i];
        perda[i+1] = daper[i+1];
    }
    sort(perda, perda+6);
    for(int i = 0; i < 5; i++){
        banyak = 0;
        for(int j = 0; j < 6; j+=2)
            if(daper[j] <= perda[i] && daper[j+1] >= perda[i+1])
                banyak++;
        if(banyak == 1)
            biaya += A*(perda[i+1] - perda[i]);
        else if(banyak == 2)
            biaya += B*(perda[i+1] - perda[i])*2;
        else if(banyak == 3)
            biaya += C*(perda[i+1] - perda[i])*3;
    }
    printf("%d\n", biaya);
    return 0;
}