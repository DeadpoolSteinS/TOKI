#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, batu;
	cin >> T;
	while(T--){
		cin >> batu;
		if(batu % 6 == 0)
			cout << "TIDAK" << endl;
		else
			cout << "YA" << endl;
	}
	return 0;
}