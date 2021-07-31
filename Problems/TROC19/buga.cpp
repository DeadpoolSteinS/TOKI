#include <bits/stdc++.h>
using namespace std;

int main(){
	int P, Q;
	cin >> P >> Q;
	int hasil = P*P + Q*Q + 1;
	if(hasil % 4 != 0)
		printf("-1\n");
	else
		cout << hasil/4 << endl;
	return 0;
}