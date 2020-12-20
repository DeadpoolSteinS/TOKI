#include <iostream>

using namespace std;

int main(){
	long int N, i = 0, B = 0, S, A[50];
	cin >> N;
	while(N > 0){
		A[i] = N % 2;
		N = N / 2;
		i++;
	}
	int P = i;
	for(i = P - 1; i >= 0; i--){
		cout << A[i];
	}
	cout << endl;
	return 0;
}