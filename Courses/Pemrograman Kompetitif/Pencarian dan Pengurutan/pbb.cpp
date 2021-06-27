#include <cstdio>
#include <string>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

template <typename T> void print(T angka){
	string s; if(angka == 0){pc('0'); return;}
	while(angka){s += (angka % 10) + '0'; angka /= 10;}
	for(int i = s.size()-1; i >= 0; i--) pc(s[i]);
}

const int batas = 1e5+1;
ll bebek[batas];

int lower(ll a, ll N){
	int i = 0, indeks, simpan = N+1;
	while(i <= N){
		indeks = (ll)(i+N)/2;
		if(a < bebek[indeks]){
			simpan = indeks;
			if(a >= bebek[indeks-1])
				break;
			N = indeks-1;
		}
		else
			i = indeks+1;
	}
	return simpan;
}

int upper(ll a, ll N){
	int i = 0, indeks, simpan = 0;
	while(i <= N){
		indeks = (ll)(i+N)/2;
		if(a >= bebek[indeks]){
			simpan = indeks+1;
			if(a < bebek[indeks+1])
				break;
			i = indeks+1;
		}
		else
			N = indeks-1;
	}
	return simpan;
}

int main(){
	int N, Q;
	scan(N);
	for(ll i = 0; i < N; i++)
		scan(bebek[i]);
	scan(Q);
	ll X, Y;
	while(Q--){
		scan(X); scan(Y);
		print(upper(Y, N-1)-lower(X, N-1)); printf("\n");
	}
	return 0;
}