#include <cstdio>
using namespace std;

int main(){
	long T, N;
	scanf("%ld", &T);
	while(T--){
		scanf("%ld", &N);
		printf("%ld\n", (N*N*N+N) / 2);
	}
	return 0;
}