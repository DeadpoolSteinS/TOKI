#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	int N, Q;
	scan(N); scan(Q);
	int L[N+1] = {}, curPos[N+1] = {};
	ll SL[N+1] = {};
	for(int i = 1; i <= N; i++){
		int X;
		scan(X);
		L[i] = max(L[i-1], curPos[X]);
		SL[i] = SL[i-1] + L[i];
		curPos[X] = i;
	}
	for(int i = 0; i < Q; i++){
		int l, r, p;
		scan(l); scan(r);
		ll res = (ll)r*(r+1)/2 - (ll)l*(l-1)/2;
		p = lower_bound(L+l, L+r+1, l-1) - L;
		res -= (ll)(l-1)*(p-l) + SL[r] - SL[p-1];
		printf("%lld\n", res);
	}
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	int N, Q;
	scan(N); scan(Q);
	int T[N+1] = {}, X[N+1] = {};
	ll prefix[N+1] = {};
	bool used[N+1] = {};
	for(int  i = 1; i <= N; i++)
		scan(T[i]);
	int l = 1, r = 1;
	used[T[l]] = true;
	while(l <= N){
		if(r+1 <= N && !used[T[r+1]]){
			r++;
			used[T[r]] = true;
		}
		else{
			used[T[l]] = false;
			X[l] = r; l++;
		}
	}
	for(int i = 1; i <= N; i++)
		prefix[i] = prefix[i-1] + X[i] - i + 1;
	while(Q--){
		scan(l); scan(r);
		int batas = upper_bound(X+l, X+r+1, r) - X;
		ll ans = prefix[batas-1] - prefix[l-1];
		int sisa = r - batas + 1;
		ans += 1LL * sisa*(sisa+1)/2;
		printf("%lld\n", ans);
	}
	return 0;
}
*/