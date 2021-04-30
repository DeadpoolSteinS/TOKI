#include <bits/stdc++.h>
using namespace std;

void emtu(int N){
	long long a, b, c, hasil;
	a = N / 4;
	b = N / 7;
	c = N / 28;
	hasil = b*7*(b+1)/2 + a*2*(a+1) - c*14*(c+1);
	cout << hasil << endl;
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		emtu(N);
	}
	return 0;
}