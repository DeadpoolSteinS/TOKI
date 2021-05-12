#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int kali = 0;
    char A[10], B[10];
    scanf("%s %s", A, B);
    for(int i = strlen(A)-1; i >= 0; i--)
        for(int j = strlen(B)-1; j >= 0; j--)
            kali += (A[i] - '0') * (B[j] - '0');
    printf("%d\n", kali);
    return 0;
}