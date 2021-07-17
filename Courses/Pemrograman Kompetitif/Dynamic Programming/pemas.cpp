#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int solve(int N){
	if(N >= 12)
		return (solve(N/2) + solve(N/3) + solve(N/4));
	else
		return N;
}

int main(){
	int N;
	scan(N);
	printf("%d\n", solve(N));
	return 0;
}