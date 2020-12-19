#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string S;
	cin >> S;
	int A = S.length(), i;
	for(i = 0; i < A; i++){
		if(S[i] >= 97 && S[i] <= 122){
			S[i] = S[i] - 32;
		}
		else{
			S[i] = S[i] + 32;
		}
	}
	cout << S << endl;
	return 0;
}