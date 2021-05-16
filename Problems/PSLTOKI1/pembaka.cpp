#include <cstdio>
#include <cstring>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N;
	scan(N);
	int P[N];
	for(int i = 0; i < N; i++)
		scan(P[i]);
	for(int i = 0; i < N-1; i++)
		if(P[i] >= P[i+1]){
			printf("%d\n", i+1);
			while((P[i] > P[i+1]) && (i < N-1))
				i++;
		}
	if(P[N-1] >= P[N-2] || N == 1)
		printf("%d\n", N);
	return 0;
}