#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	ll N, A, B, total = 0, mod;
	vector <int> cek;
	bool naik = true, turun = true;
	scan(N);
	if(N%2 == 0)
		return 0;
	for(int i = 0; i < N; i++){
		scan(A);
		if(i > 0){
			if(naik && A < B)
				naik = false;
			else if(turun && A > B)
				turun = false;
			mod = __gcd(mod, A);
		}
		else
			mod = A;
		B = A;
		total += A;
		cek.pb(A*A);
	}
	cek.resize(distance(cek.begin(), unique(cek.begin(), cek.end())));
	sort(cek.begin(), cek.end());
	for(int i = cek.size()-1; i >= 2; i--){
		int l = 0;
		int r = i-1;
		while(l < r){
			if(cek[l] + cek[r] == cek[i])
				return 0;
			(cek[l] + cek[r] < cek[i]) ? l++ : r--;
		}
	}// cek triple phitagoras
	if(!naik && !turun && 999999999%mod != 0)
		printf("%lld\n", total);
	return 0;
}