#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while (!isdigit(input)){if (input == '-') kali = -1; input = gc();}
	while(isdigit(input))angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, T, bil[8000], cari;

bool find(){
	int i = 0, j = N-1;
	while(i < j){
		if(bil[i] + bil[j] == cari)
			return true;
		else if(bil[i] + bil[j] < cari)
			i++;
		else
			j--;
	}
	return false;
}

int main(){
	scan(N); scan(T);
	for(int i = 0; i < N; i++)
		scan(bil[i]);
	sort(bil, bil+N);
	while(T--){
		scan(cari);
		if(find())
			printf("YA\n");
		else
			printf("TIDAK\n");
	}
	return 0;
}