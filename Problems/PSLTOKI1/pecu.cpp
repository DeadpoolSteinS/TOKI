#include <cstdio>
using namespace std;

int main(){
	int K, i = 0, pecahan[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	scanf("%d", &K);
	while(K){
		if(K >= pecahan[i]){
			printf("%d %d\n", pecahan[i], K/pecahan[i]);
			K %= pecahan[i];
		}
		i++;
	}
	return 0;
}