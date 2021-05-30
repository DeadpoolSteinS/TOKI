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

int N, M, K, minim, maxim;
char denah[100][100];

int main(){
	scan(N); scan(M); scan(K);
	minim = N<M ? N:M;
	maxim = N>M ? N:M;
	if((N+M-2*minim+1)/2 > K-minim){
		printf("TIDAK\n");
		return 0;
	}
	printf("YA\n");
	for(int i = 0; i < minim; i++){
		denah[i][i] = 'X';
		K--;
	}
	for(int i = ((maxim-minim)%2 == 1 ? minim:minim+1); i < maxim; i+=2){
		if(N < M)
			denah[0][i] = 'X';
		else
			denah[i][0] = 'X';
		K--;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(denah[i][j] == 'X')
				printf("X");
			else{
				if(K != 0){
					printf("X");
					K--;
				}
				else
					printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}