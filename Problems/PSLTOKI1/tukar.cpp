#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, tukar = 0, cek;
    scanf("%d", &N);
    int D[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &D[i]);
    for(int i = 1; i < N; i++){
        cek = i;
        while(cek >= 1 && D[cek] < D[cek-1]){
            swap(D[cek], D[cek-1]);
            tukar++;
            cek--;
        }
    }
    printf("%d\n", tukar);
    return 0;
}