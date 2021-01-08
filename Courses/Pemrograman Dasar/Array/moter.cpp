#include <iostream>

using namespace std;

int main(){
	int N, i, j, HELP = 0, HASIL, AKHIR, k, A;
	cin >> N;
	int ISI[N];
	for(i = 0; i < N; i++)
		cin >> ISI[i];
	for(i = 0; i < N; i++){
		HASIL = 1;
		A = 0;
		for(j = 0 ;j < i; j++){
			if(ISI[i] == ISI[j]){
				A = 1;
				break;
			}
		}
		if(A == 0){
			for(j = i + 1; j < N; j++){
				if(ISI[i] == ISI[j])
					HASIL++;
			}
		}
		if((HASIL > HELP) || (HASIL == HELP && ISI[i] > ISI[k])){
			AKHIR = ISI[i];
			HELP = HASIL;
			k = i;
		}
	}
	cout << AKHIR << endl;
	return 0;
}