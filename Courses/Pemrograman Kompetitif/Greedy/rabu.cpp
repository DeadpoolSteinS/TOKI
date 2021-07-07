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

bool comp(int a, int b){
	return a > b;
}

int main(){
	int N, B, total = 0, i;
	scan(N); scan(B);
	int tinggi[N];
	for(i = 0; i < N; i++)
		scan(tinggi[i]);
	sort(tinggi, tinggi+N, comp);
	for(i = 0; total < B; i++)
		total += tinggi[i];
	printf("%d\n", i);
	return 0;
}