#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, lawan, tukar = 0;
    scanf("%d", &N);
    int D[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &D[i]);
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
    printf("%d\n", tukar);
    return 0;
}