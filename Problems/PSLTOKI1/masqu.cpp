#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long T, N;
	cin >> T;
	while(T--){
		cin >> N;
		cout << (N*N*N+N) / 2 << endl;
	}
	return 0;
}