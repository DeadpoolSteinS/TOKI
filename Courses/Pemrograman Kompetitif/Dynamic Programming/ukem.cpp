#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

const int maks = 50001;
int N, K, minimal[maks], jenis[500];

int solve(){
	minimal[0] = 0;
	for(int i = 1; i <= K; i++){
		int terkecil = maks;
		for(int j = 0; j < N; j++){
			if(i >= jenis[j])
				terkecil = min(terkecil, minimal[i-jenis[j]]+1);
		}
		minimal[i] = terkecil;
	}
	return minimal[K];
}

int main(){
	scan(N);
	for(int i = 0; i < N; i++)
		scan(jenis[i]);
	scan(K);
	int hasil = solve();
	if(hasil != maks)
		printf("%d\n", hasil);
	else
		printf("-1\n");
	return 0;
}