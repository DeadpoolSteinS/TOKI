#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

typedef struct{
	char id[5];
	int satu, dua, tiga;
}olimpiade;

bool compare(olimpiade a, olimpiade b){
	if(a.tiga != b.tiga)
		return (a.tiga > b.tiga);
	else if(a.dua != b.dua)
		return (a.dua > b.dua);
	else
		return (a.satu > b.satu);
}

int main(){
	int T;
	scan(T);
	while(T--){
		int N, M;
		scan(N); scan(M);
		char cek[5];
		scanf("%s", cek);

		olimpiade peserta[N];
		for(int i = 0; i < N; i++){
			scanf("%s", peserta[i].id);
			scan(peserta[i].satu); scan(peserta[i].dua); scan(peserta[i].tiga);
		}
		sort(peserta, peserta+N, compare);

		bool ya = false;
		for(int i = 0; i < M; i++)
			if(strcmp(peserta[i].id, cek) == 0){
				printf("YA\n");
				ya = true;
				break;
			}
		if(!ya)
			printf("TIDAK\n");
	}
	return 0;
}