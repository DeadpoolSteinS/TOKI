#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000000007;

ll mul(ll a, ll b){
	return ((a%mod) * (b%mod)) % mod;
}

ll sum(ll a, ll b){
	return ((a%mod) + (b%mod)) % mod;
}

ll sub(ll a, ll b){
	return ((a%mod) - (b%mod) + mod) % mod;
}

int main(){
	int R, L, X, Y;
	cin >> R >> L >> X >> Y;
	int mins = min(R, L);
	int maks = max(R, L);
	ll ans = 0, C[maks+1][maks+1], P[maks+1][maks+1];
	if((X <= mins) && (Y <= mins)){
		for(int i = 0; i <= maks; i++){
			for(int j = i; j <= maks; j++){
				if(i == 0){
					P[j][i] = 1;
					C[j][i] = 1;
				}
				else if(j == i){
					P[j][i] = mul(j, P[j-1][i-1]);
					C[j][i] = 1;
				}
				else{
					P[j][i] = mul(j, P[j-1][i-1]);
					C[j][i] = sum(C[j-1][i], C[j-1][i-1]);
				}
			}
		}
		ans = mul(C[maks][X], P[mins][X]);
		ll res = mul(C[maks][Y], P[mins][Y]);
		for(int i = 2; i <= min(X, Y); i+=2)
			res = sum(res, mul(C[X][i], mul(C[maks-i][Y-i], P[mins-i][Y-i])));
		for(int i = 1; i <= min(X, Y); i+=2)
			res = sub(res, mul(C[X][i], mul(C[maks-i][Y-i], P[mins-i][Y-i])));
		ans = mul(ans, res);
	}
	cout << ans << endl;
	return 0;
}

// Code by coderbodoh
// https://tlx.toki.id/profiles/coderbodoh