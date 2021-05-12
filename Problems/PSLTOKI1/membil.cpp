#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int N, i;
    char balik[8];
    scanf("%d", &N);
    while(N--){
        scanf("%s", balik);
        for(i = strlen(balik)-1; i >= 1; i--)
            if(balik[i] != '0')
                break;
        for(i = i; i >= 0; i--)
            printf("%c", balik[i]);
        printf("\n");
    }
    return 0;
}