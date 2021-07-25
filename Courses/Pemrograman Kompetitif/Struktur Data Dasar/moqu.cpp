#include <iostream>
#include <deque>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, A, B;
	bool reverse = false;
	string perintah;
	deque <int> arr;
	scan(N);
	while(N--){
		cin >> perintah;
		if(perintah == "add"){
			scan(A); scan(B);
			if(reverse)
				arr.insert(arr.begin(), B, A);
			else
				arr.insert(arr.end(), B, A);
			cout << arr.size() << endl;
		}
		else if(perintah == "del"){
			scan(B);
			if(reverse){
				cout << arr.back() << endl;
				arr.erase(arr.end()-B, arr.end());
			}
			else{
				cout << arr.front() << endl;
				arr.erase(arr.begin(), arr.begin()+B);
			}
		}
		else if(perintah == "rev")
			reverse = (reverse ? false : true);
	}
	return 0;
}