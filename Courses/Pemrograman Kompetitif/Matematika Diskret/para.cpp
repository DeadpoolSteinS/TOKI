#include <cstdio>
#include <string>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

template <typename T> void print(T angka){
	string s; if(angka == 0){pc('0'); return;}
	while(angka){s += (angka % 10) + '0'; angka /= 10;}
	for(int i = s.size()-1; i >= 0; i--) pc(s[i]);
}

int fpb(int a, int b){
	if(b == 0)
		return a;
	return fpb(b, a%b);
}

int kpk(int a, int b){
	return (a*b)/fpb(a, b);
}

int main(){
	int N, D, nilai = 1;
	scan(N);
	while(N--){
		scan(D);
		nilai = kpk(nilai, D);
	}
	print(nilai);
	printf("\n");
	return 0;
}