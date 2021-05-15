#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define pb push_back

int main(){
	vector <int> prima;
	int M, N, nol, banyak;
	bool prime, ada = false;
	scanf("%d %d", &M, &N);
	for(int i = M; i <= N; i++){
		prime = true;
		for(int j = 2; j <= sqrt(i); j++)
			if(i % j == 0){
				prime = false;
				break;
			}
		if(prime)
			prima.pb(i);
	}
	for(int i = 0; i < prima.size(); i++)
		for(int j = 0; j < prima.size(); j++)
			if(i != j){
				prime = true; banyak = 1; nol = prima[j];
				while(nol != 0){
					nol /= 10;
					banyak *= 10;
				}
				for(int k = 2; k <= sqrt(prima[i]*banyak+prima[j]); k++)
					if((prima[i]*banyak+prima[j]) % k == 0){
						prime = false;
						break;
					}
				if(prime){
					printf("%d %d\n", prima[i], prima[j]);
					ada = true;
				}
			}
	if(!ada)
		printf("TIDAK ADA\n");
	return 0;
}