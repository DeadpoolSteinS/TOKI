#include <cstdio>
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	// printf("jakarta\n");
	// printf("bawah\n");
	// printf("venusaur\n");
	// printf("lapar\n");
	// printf("sepertujuh\n");
	return 0;
}