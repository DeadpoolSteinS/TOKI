#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define ll unsigned long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

ll dp[55];

int main(){
	int N, K;
	scan(N);
	if(N%2 == 1)
		printf("0\n");
	else{
		dp[0] = 1;
		dp[2] = 1;
		for(int i = 4; i <= N; i+=2){
			K = i-2;
			for(int j = 0; j <= K; j+=2)
				dp[i] += dp[j]*dp[K-j];
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}