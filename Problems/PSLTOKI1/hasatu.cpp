#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N, M, maks = 0, jumlah;
	cin >> N >> M;
	int hadiah[N];
	for(int i = 0; i < N; i++){
		cin >> hadiah[i];
		if(i < M)
			maks += hadiah[i];
	}
	jumlah = maks;
	for(int i = 1; i <= (N-M); i++){
		jumlah += (hadiah[i+M-1] - hadiah[i-1]);
		maks = max(maks, jumlah);
	}
	cout << maks << endl;
	return 0;
}