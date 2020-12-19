#include <iostream>

using namespace std;

int main(){
	int A, B, K, x, i;
	cin >> A >> B >> K >> x;
	int F = x;
	for(i = 0; i < K; i++){
		F = A * F + B;
		F = abs(F);
	}
	cout << F << endl;
	return 0;
}