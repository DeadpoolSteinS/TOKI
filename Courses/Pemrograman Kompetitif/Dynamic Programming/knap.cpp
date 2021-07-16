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

int N, K, W[2001], H[2001], total[100][2001];

void knapsack(int i){
	for(int j = 0; j <= N; j++){
		total[i][j] = total[i-1][j];
		if(j >= W[i])
			total[i][j] = max(total[i][j], total[i-1][j-W[i]]+H[i]);
	}
}

int main(){
	scan(N); scan(K);
	int ans[K+1];
	for(int i = 1; i <= K; i++){
		scan(W[i]); scan(H[i]);
		knapsack(i);
	}
	int j, idx = 0;
	for(j = N; j > 0; j--){
		if(total[K][j-1] != total[K][N])
			break;
	}
	for(int i = K; i > 0 && j > 0; i--){
		if(total[i][j] != total[i-1][j]){
			ans[idx] = i;
			idx++;
			j -= W[i];
		}
	}
	for(int i = idx-1; i >= 0; i--)
		printf("%d\n", ans[i]);
	return 0;
}