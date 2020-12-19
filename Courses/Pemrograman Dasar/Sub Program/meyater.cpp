#include <iostream>

using namespace std;

int main(){
	int A, B, C = 0, D = 0, i, j;
	cin >> A >> B;
	while(A % 10 == 0){
		A = A / 10;
	}
	while(B % 10 == 0){
		B = B / 10;
	}
	while(A > 0){
		C = C * 10 + (A % 10);
		A = A / 10;
	}
	while(B > 0){
		D = D * 10 + (B % 10);
		B = B / 10;
	}
	int E = C + D, F = 0;
	while(E > 0){
		F = F * 10 + (E % 10);
		E = E / 10;
	}
	cout << F << endl;
	return 0;
}