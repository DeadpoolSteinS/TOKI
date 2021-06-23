#include <iostream>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	string cari, daftar;
	cin >> cari;
	int N; scan(N);
	if(cari[cari.length()-1] == '*'){
		while(N--){
			cin >> daftar;
			bool benar = true;
			for(int j = 0; cari[j] != '*'; j++){
				if(daftar[j] != cari[j]){
					benar = false;
					break;
				}
			}
			if(benar)
				cout << daftar << endl;
		}
	}//asterisk di akhir
	else if(cari[0] == '*'){
		while(N--){
			cin >> daftar;
			bool benar = true;
			for(int j = 0; cari[cari.length()-j-1] != '*'; j++){
				if(daftar[daftar.length()-j-1] != cari[cari.length()-j-1]){
					benar = false;
					break;
				}
			}
			if(benar)
				cout << daftar << endl;
		}
	}//asterisk di awal
	else{
		while(N--){
			cin >> daftar;
			if(cari.length()-1 > daftar.length())
				continue;
			bool benar = true;
			for(int j = 0; cari[j] != '*'; j++){
				if(daftar[j] != cari[j]){
					benar = false;
					break;
				}
			}//cek kiri asterisk
			if(!benar)
				continue;
			for(int j = 0; cari[cari.length()-j-1] != '*'; j++){
				if(daftar[daftar.length()-j-1] != cari[cari.length()-j-1]){
					benar = false;
					break;
				}
			}//cek kanan asterisk
			if(benar)
				cout << daftar << endl;
		}
	}//asterisk di tengah
	return 0;
}