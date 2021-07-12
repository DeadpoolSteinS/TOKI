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
	int N, M, total = 0;
	scan(N); scan(M);
	int bebek[N], sepatu[M];
	for(int i = 0; i < N; i++)
		scan(bebek[i]);
	for(int i = 0; i < M; i++)
		scan(sepatu[i]);
	sort(bebek, bebek+N);
	sort(sepatu, sepatu+M);
	while(N && M){
		if(bebek[N-1] == sepatu[M-1] || bebek[N-1] == sepatu[M-1]-1){
			N--;
			M--;
			total++;
		}
		else if(bebek[N-1] > sepatu[M-1])
			N--;
		else
			M--;
	}
	printf("%d\n", total);
	return 0;
}