#include <iostream>
#include <cstring>
using namespace std;

bool sama(char K[200]){
	int panjang = strlen(K);
	for(int i = 0; i <= (panjang - 2) / 2; i++)
		if(K[i] != K[panjang - i - 1])
			return false;
	return true;
}

int main(){
	char K[200];
	while(cin >> K)
		if(sama(K))
			cout << K << " ";
	return 0;
}