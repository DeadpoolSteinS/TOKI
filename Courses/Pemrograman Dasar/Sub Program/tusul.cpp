#include <iostream>

using namespace std;

int main(){
	int N, i, T, H, C, D;
	char E, F;
	cin >> N;
	int A[N], B[N];
	for(i = 0; i < N; i++){
		cin >> A[i];
	}
	for(i = 0; i < N; i++){
		cin >> B[i];
	}
	cin >> T;
	for(i = 0; i < T; i++){
		cin >> E >> C >> F >> D;
		C = C - 1;
		D = D - 1;
		if((E == 'A') && (F == 'B')){
			H = A[C];
			A[C] = B[D];
			B[D] = H;
		}
		else if((E == 'A') && (F == 'A')){
			H = A[C];
			A[C] = A[D];
			A[D] = H;
		}
		else if((E == 'B') && (F == 'A')){
			H = B[C];
			B[C] = A[D];
			A[D] = H;
		}
		else{
			H = B[C];
			B[C] = B[D];
			B[D] = H;
		}
	}
	for(i = 0; i < N; i++){
		cout << A[i];
		if(i != N - 1)
			cout << " ";
	}
	cout << endl;
	for(i = 0; i < N; i++){
		cout << B[i];
		if(i != N - 1)
			cout << " ";
	}
	cout << endl;
	return 0;
}