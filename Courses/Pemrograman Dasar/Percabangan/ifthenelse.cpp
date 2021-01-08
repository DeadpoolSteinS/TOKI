#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int ANGKA;
	cin >> ANGKA;
	if(ANGKA > 0)
		cout << "positif" << endl;
	else if(ANGKA < 0)
		cout << "negatif" << endl;
	else
		cout << "nol" << endl;
	return 0;
}