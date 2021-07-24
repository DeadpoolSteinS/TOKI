#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

ll maksimal = 0, banyak[505][505];
int V, H, N, V1, H1, V2, H2, batu[505][505];

ll solve(int A, int B){
	if(B > H || B < 1 || A >= V)
		return 0;
	if(banyak[A][B] > -1)
		return banyak[A][B];
	if(batu[A+1][B] == 0)
		return (banyak[A][B] = solve(A+1, B));
	int P = B-1, Q = B+1;
	while(batu[A+1][P] == 1)
		P--;
	while(batu[A+1][Q] == 1)
		Q++;
	return (banyak[A][B] = 1 + solve(A+1, P) + solve(A+1, Q));
}

int main(){
	memset(banyak, -1, sizeof(banyak));
	scan(V); scan(H); scan(N);
	for(int i = 1; i <= N; i++){
		scan(V1); scan(H1); scan(V2); scan(H2);
		for(int j = V1; j <= V2; j++){
			for(int k = H1; k <= H2; k++){
				batu[j][k] = 1;
			}
		}
	}
	for(int i = 1; i <= H; i++)
		maksimal = max(maksimal, solve(0, i));
	printf("%lld\n", maksimal);
	return 0;
}