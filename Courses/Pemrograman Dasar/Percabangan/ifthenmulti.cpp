#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int ANGKA;
	cin >> ANGKA;
	if(ANGKA > 0 && ANGKA % 2 == 0)
		cout << ANGKA << endl;
	return 0;
}