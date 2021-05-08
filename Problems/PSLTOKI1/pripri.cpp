#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector <int> prima;
	int M, N, nol, banyak;
	bool prime, ada = false;
	cin >> M >> N;
	for(int i = M; i <= N; i++){
		prime = true;
		for(int j = 2; j <= sqrt(i); j++)
			if(i % j == 0){
				prime = false;
				break;
			}
		if(prime)
			prima.push_back(i);
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
					cout << prima[i] << " " << prima[j] << endl;
					ada = true;
				}
			}
	if(!ada)
		cout << "TIDAK ADA" << endl;
	return 0;
}