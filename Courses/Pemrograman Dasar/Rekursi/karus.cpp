#include <iostream>

using namespace std;

int main(){
	string S;
	cin >> S;
	int A = S.length(), i, X = 0;
	for(i = 0; i < A; i++){
		if(S[i] != S[A - i - 1]){
			X = 1;
			break;
		}
	}
	if(X == 0)
		cout << "YA" << endl;
	else
		cout << "BUKAN" << endl;
	return 0;
}