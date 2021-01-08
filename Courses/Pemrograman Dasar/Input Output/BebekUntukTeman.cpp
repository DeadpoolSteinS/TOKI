#include <iostream>

using namespace std;

int main(){
	int BILANGAN, PEMBAGI;
	cin >> BILANGAN >> PEMBAGI;
	cout << "masing-masing " << BILANGAN / PEMBAGI << endl << "bersisa " << (BILANGAN % PEMBAGI) << endl;
	return 0;
}