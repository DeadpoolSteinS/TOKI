#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, batu, total = 0;
	vector <int> berat;
	scan(N);
	while(N--){
		scan(batu);
		while(!berat.empty() && berat.back() <= batu){
			berat.pop_back();
			if(berat.size() == 0)
				total += batu;
			else
				total += min(berat.back(), batu);
		}
		berat.push_back(batu);
	}
	while(berat.size() >= 2){
		berat.pop_back();
		total += berat.back();
	}
	printf("%d\n", total);
	return 0;
}