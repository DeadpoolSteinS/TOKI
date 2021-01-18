#include <iostream>

using namespace std;

int N, CATAT[100], A;
bool PERNAH[100];

void tulis(int KEDALAMAN){
	if(KEDALAMAN >= N){
		for(int i = 1; i < (N - 1); i++){
			if((CATAT[i] < CATAT[i - 1] && CATAT[i] < CATAT[i + 1])
			|| (CATAT[i] > CATAT[i - 1] && CATAT[i] > CATAT[i + 1]))
				A = 1;
			else{
				A = 0;
				break;
			}
		}
		if(A == 1 || N == 2 || N == 1){
			for(int i = 0; i < N; i++)
				cout << CATAT[i];
			cout << endl;
		}
	}
	else{
		for(int i = 1; i <= N; i++){
			if(!PERNAH[i]){
				PERNAH[i] = true;
				CATAT[KEDALAMAN] = i;
				tulis(KEDALAMAN + 1);
				PERNAH[i] = false;
			}
		}
	}
}

int main(){
	cin >> N;
	tulis(0);
	return 0;
}