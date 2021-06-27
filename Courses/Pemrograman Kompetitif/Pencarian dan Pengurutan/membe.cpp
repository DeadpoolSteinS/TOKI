#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

typedef struct{
	int W, C;
	double per;
}beras;

bool comp(beras a, beras b){
	if(a.per > b.per)
		return 1;
	return 0;
}

int main(){
	int N, X, total = 0;
	scan(N); scan(X);
	beras bebek[N];
	double harga = 0;
	for(int i = 0; i < N; i++)
		scan(bebek[i].W);
	for(int i = 0; i < N; i++){
		scan(bebek[i].C);
		bebek[i].per = (double)bebek[i].C/bebek[i].W;
	}
	sort(bebek, bebek+N, comp);
	for(int i = 0; i < N; i++){
		if(total + bebek[i].W <= X){
			total += bebek[i].W;
			harga += bebek[i].C;
		}
		else{
			harga += ((X - total) * bebek[i].per);
			break;
		}
	}
	printf("%.5lf\n", harga);
	return 0;
}