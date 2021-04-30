#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string K;
	bool polindrom;
	while(cin >> K){
		polindrom = true;
		for(int i = 0; i <= (K.length() - 2) / 2; i++)
			if(K[i] != K[K.length() - i - 1])
				polindrom = false;
		if(polindrom)
			cout << K << " ";
	}
	cout << endl;
	return 0;
}