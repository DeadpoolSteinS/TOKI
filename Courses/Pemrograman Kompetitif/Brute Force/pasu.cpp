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

int M, N, cek, rata, sisa, suara[10001], indeks[21], batas[21];
bool benar = false;

int main(){
	scan(M);
	for(int i = 0; i < M; i++)
		scan(suara[i]);
	scan(N);
	sort(suara, suara+M);
	sisa = M%N;
	rata = M/N;
	if(sisa == 0){
		for(int i = 1; i < N; i++){
			printf("%d", suara[rata*i]);
			if(i < N-1)
				printf(" ");
		}
		printf("\n");
		return 0;
	}
	for(int i = 0; i < N; i++){
		if(i < N-sisa) indeks[i] = rata;
		else indeks[i] = rata+1;
	}
	do{
		benar = true;
		cek = 0;
		for(int i = 0; i < N-1; i++){
			cek += indeks[i];
			if(suara[cek] == suara[cek-1]){
				benar = false;
				break;
			}
			batas[i] = suara[cek];
		}
	}while(!benar && next_permutation(indeks, indeks+N));
	for(int i = 0; i < N-1; i++){
		printf("%d", batas[i]);
		if(i < N-2)
			printf(" ");
	}
	printf("\n");
	return 0;
}