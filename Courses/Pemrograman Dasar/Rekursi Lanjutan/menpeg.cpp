#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, i, j, B[10], C[10], k, X;
	cin >> N;
	B[0] = 1;
	C[0] = 0;
	for(i = 1; i < N; i++){
		B[i] = B[i - 1] * 2 + 1;
		C[i] = B[i] / 2;
	}
	for(i = 0; i < B[N - 1]; i++){
		for(j = 0; j < N; j++){
			X = pow(2, (j + 1));
			if((i - C[j]) % X == 0){
				for(k = 0; k < j + 1; k++){
					cout << "*";
				}
				cout << endl;
			}
		}
	}
	return 0;
}