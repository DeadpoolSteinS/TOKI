#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int ANGKA;
	cin >> ANGKA;
	if(ANGKA > 0 && ANGKA < 10)
		cout << "satuan" << endl;
	else if(ANGKA >= 10 && ANGKA < 100)
		cout << "puluhan" << endl;
	else if(ANGKA >= 100 && ANGKA < 1000)
		cout << "ratusan" << endl;
	else if(ANGKA >= 1000 && ANGKA < 10000)
		cout << "ribuan" << endl;
	else
		cout << "puluhribuan" << endl;
	return 0;
}