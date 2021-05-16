#include <cstdio>
#include <cctype>
using namespace std;
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while (!isdigit(input)){if (input == '-') kali = -1; input = gc();}
	while(isdigit(input))angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int T, batu;
	scan(T);
	while(T--){
		scan(batu);
		if(batu % 6 == 0)
			printf("TIDAK\n");
		else
			printf("YA\n");
	}
	return 0;
}