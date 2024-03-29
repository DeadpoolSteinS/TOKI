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
	int N, angka;
	string perintah;
	deque <int> arr;
	scan(N);
	while(N--){
		cin >> perintah;
		if(perintah != "pop_front" && perintah != "pop_back"){
			scan(angka);
			if(perintah == "push_back")
				arr.push_back(angka);
			else if(perintah == "push_front")
				arr.push_front(angka);
		}
		else{
			if(perintah == "pop_front")
				arr.pop_front();
			else if(perintah == "pop_back")
				arr.pop_back();
		}
	}
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	return 0;
}