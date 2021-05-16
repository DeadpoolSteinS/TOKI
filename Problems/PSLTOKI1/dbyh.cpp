#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while (!isdigit(input)){if (input == '-') kali = -1; input = gc();}
	while(isdigit(input))angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, bil, dua = 0, i;
	scan(N);
	bool ada[N];
	memset(ada, 0, sizeof(ada));
	for(i = 0; i < N-2; i++){
		scan(bil);
		ada[bil-1] = true;
	}
	i = 0;
	while(i < N && dua < 2){
		if(!ada[i]){
			printf("%d\n", i+1);
			dua++;
		}
		i++;
	}
	return 0;
}