#include <cstdio>
//#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int ayam[101], bebek[101];
int jembatan[101][101];

int solve(int x, int y){
	if(jembatan[x][y] > 0)
		return jembatan[x][y];
	else{
		int banyak, maks = 0;
		for(int i = x; i >= 0; i--)
			for(int j = y; j >= 0; j--)
				if(ayam[i] == bebek[j]){
					if(i > 0 && j > 0)
						banyak = 1 + solve(i-1, j-1);
					else
						banyak = 1;
					if(banyak > maks)
						maks = banyak;
				}
		jembatan[x][y] = maks;
		return maks;
	}
}

int main(){
	int N;
	scan(N);
	for(int i = 0; i < N; i++)
		scan(ayam[i]);
	for(int i = 0; i < N; i++)
		scan(bebek[i]);
	printf("%d\n", solve(N-1, N-1));
	return 0;
}

// code by prabowo