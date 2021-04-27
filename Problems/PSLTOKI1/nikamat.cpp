#include <bits/stdc++.h>
using namespace std;

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int A, B;
    char op;
    cin >> A >> op >> B;
    if(op == '+')
        cout << A + B;
    else if(op == '-')
        cout << A - B;
    else if(op == '*')
        cout << A * B;
    else if(op == '<')
        cout << (A < B ? "benar" : "salah");
    else if(op == '>')
        cout << (A > B ? "benar" : "salah");
    else
        cout << (A == B ? "benar" : "salah");
    cout << endl;
    return 0;
}