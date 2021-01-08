#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int BANYAK, i, SUM = 0;
	cin >> BANYAK;
	int ISI[BANYAK];
	for(i = 0; i < BANYAK; i++){
		cin >> ISI[i];
		SUM = SUM + ISI[i];
	}
	cout << SUM << endl;
	return 0;
}