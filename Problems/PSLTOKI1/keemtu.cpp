#include <cstdio>
using namespace std;

void emtu(int N){
	long a, b, c, hasil;
	a = N / 4;
	b = N / 7;
	c = N / 28;
	hasil = a*2*(a+1) + b*7*(b+1)/2 - c*14*(c+1);
	printf("%lu\n", hasil);
}

int main(){
	int T, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		emtu(N);
	}
	return 0;
}