#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, minimal = 0, maksimal = 0;
		cin >> N;
		while(N--){
			int A, B, C;
			cin >> A >> B >> C;
			minimal += min(min(A, B), C);
			maksimal += max(max(A, B), C);
		}
		cout << minimal << " " << maksimal << endl;
	}
	return 0;
}