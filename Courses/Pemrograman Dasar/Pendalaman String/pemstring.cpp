#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string S, T;
	int A, B, i, j, X, H = 1;
	cin >> S >> T;
	B = T.length();
	while(H == 1){
		A = S.length();
		H = 0;
		for(i = 0; i < A - B + 1; i++){
			X = 0;
			for(j = 0; j < B; j++){
				if(S[i + j] == T[j]){
					X++;
				}
			}
			if(X == B){
				S.erase (i, B);
				i--;
				H = 1;
			}
		}
	}
	cout << S << endl;
	return 0;
}