#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N, hasil = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
		hasil += i*i;
	cout << hasil << endl;
	return 0;
}