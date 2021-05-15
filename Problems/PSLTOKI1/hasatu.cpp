#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while (!isdigit(input)){if (input == '-') kali = -1; input = gc();}
	while(isdigit(input))angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	long N, M, maks = 0, jumlah;
	scan(N); scan(M);
	int hadiah[N];
	for(int i = 0; i < N; i++){
		scan(hadiah[i]);
		if(i < M)
			maks += hadiah[i];
	}
	jumlah = maks;
	for(int i = 1; i <= (N-M); i++){
		jumlah += (hadiah[i+M-1] - hadiah[i-1]);
		maks = max(maks, jumlah);
	}
	printf("%ld\n", maks);
	return 0;
}