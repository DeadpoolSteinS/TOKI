#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, M, bx, by, kx, ky, lb, lk, samax, samay, luas;
char denah[500][500];
bool seri = false;

void wilayah(int x, int y){
	if((!seri) && (x >= 0) && (x < M) && (y >= 0) && (y < N) && (denah[x][y] != '#')){
		if(x == samax && y == samay){
			seri = true;
			return;
		}
		luas++;
		denah[x][y] = '#';
		wilayah(x, y+1);
		wilayah(x, y-1);
		wilayah(x+1, y);
		wilayah(x-1, y);
	}
}

int main(){
	scan(N); scan(M);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++){
			scanf(" %c", &denah[i][j]);
			if(denah[i][j] == 'B'){
				bx = i;
				by = j;
			}
			if(denah[i][j] == 'K'){
				kx = i;
				ky = j;
				samax = i;
				samay = j;
			}
		}
	luas = 0; wilayah(bx, by); lb = luas;
	if(seri){
		printf("SERI\n");
		return 0;
	}
	samax = -1; samay = -1;
	luas = 0; wilayah(kx, ky); lk = luas;
	if(lb > lk)
		printf("B %d\n", lb-lk);
	else
		printf("K %d\n", lk-lb);
	return 0;
}