#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

const ll maks = 1e12;
ll N, M, X, Y, a[262144];

ll bawah(){
	ll kiri = 1, kanan = maks, cek, total, baki = -1;
	while(kiri < kanan){
		total = 0;
		cek = (kiri+kanan) / 2;
		for(int i = 0; i < N; i++)
			total += cek/a[i];
		if(total < M)
			kiri = cek+1;
		else{
			kanan = cek;
			if(total == M)
				baki = cek;
		}
	}
	return baki;
}

ll atas(){
	ll kiri = X, kanan = maks, cek, total;
	while(kiri < kanan){
		total = 0;
		cek = (kiri+kanan+1) / 2;
		for(int i = 0; i < N; i++)
			total += cek/a[i];
		if(total > M)
			kanan = cek-1;
		else
			kiri = cek;
	}
	return kiri+1;
}

int main(){
	scan(N); scan(M);
	for(int i = 0; i < N; i++)
		scan(a[i]);
	X = bawah();
	if(X == -1)
		printf("0\n");
	else{
		Y = atas();
		printf("%lld\n", Y-X);
	}
	return 0;
}