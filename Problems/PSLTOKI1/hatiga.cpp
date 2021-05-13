#include <cstdio>
#include <vector>
using namespace std;
#define pb push_back

int main(){
	int N, kubik = 1, min = 0;
	vector <int> hadiah;
	scanf("%d", &N);
	while(kubik * 3 <= N)
		kubik *= 3;
	while(N){
		for(int i = 0; i < N/kubik; i++){
			hadiah.pb(kubik);
			min++;
		}
		N %= kubik;
		kubik /= 3;
	}
	printf("%d\n", min);
	for(int i = hadiah.size()-1; i >= 0; i--){
		printf("%d", hadiah[i]);
		if(i)
			printf(" ");
	}
	printf("\n");
	return 0;
}