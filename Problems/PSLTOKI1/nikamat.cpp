#include <cstdio>
using namespace std;

int main(){
    int A, B;
    char op;
    scanf("%d %c %d", &A, &op, &B);
    if(op == '+')
        printf("%d\n", A + B);
    else if(op == '-')
        printf("%d\n", A - B);
    else if(op == '*')
        printf("%d\n", A * B);
    else if(op == '<')
        printf(A < B ? "benar\n" : "salah\n");
    else if(op == '>')
        printf(A > B ? "benar\n" : "salah\n");
    else
        printf(A == B ? "benar\n" : "salah\n");
    return 0;
}