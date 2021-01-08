#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string S, T = "_";
	getline(cin, S);
	int A = S.length(), i, SN = 0, CA = 0;
	for(i = 1; i < A; i++){
		if(S[i] >= 65 && S[i] <= 90){
			S[i] = S[i] + 32;
			S.insert(i, T);
			A++;
		}
		else if(S[i] == '_'){
			S.erase(i, 1);
			S[i] = S[i] - 32;
		}
	}
	cout << S << endl;
	return 0;
}