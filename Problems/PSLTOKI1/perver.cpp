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

int main(){
	int T, N;
	scan(T);
	while(T--){
		scan(N);
		bool win = 1;
		int lawan[N], kawan[N];
		for(int i = 0; i < N; i++)
			scan(lawan[i]);
		sort(lawan, lawan+N);
		for(int i = 0; i < N; i++)
			scan(kawan[i]);
		sort(kawan, kawan+N);
		int tengah = N/2;
		for(int i = 0; i <= tengah; i++)
			if(lawan[i] >= kawan[tengah+i-1]){
				win = 0;
				break;
			}
		if(win)
			printf("YA\n");
		else
			printf("TIDAK\n");
	}
	return 0;
}