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
	int N, K;
	scan(N); scan(K);
	int bebek[N];
	for(int i = 0; i < N; i++)
		scan(bebek[i]);
	sort(bebek, bebek+N);
	printf("%d\n", bebek[K-1]);
	return 0;
}