#include <cstdio>
using namespace std;

int main(){
	int N, hasil = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		hasil += i*i;
	printf("%d\n", hasil);
	return 0;
}