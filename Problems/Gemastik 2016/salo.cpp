#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int L, B, place = -1, i;
		cin >> L >> B;
		for(i = 1; place < 0; i++)
			place = 3*i - L + min(B, 2*i) - 2*B + 1;
		cout << i-1 << endl;
	}
	return 0;
}