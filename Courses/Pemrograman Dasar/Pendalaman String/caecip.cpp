#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string S;
	int K, i, j;
	cin >> S >> K;
	for(i = 0; i < S.length(); i++){
		S[i] = S[i] - 26 + K;
		if(S[i] < 97)
			S[i] = S[i] + 26;
	}
	cout << S << endl;
	return 0;
}