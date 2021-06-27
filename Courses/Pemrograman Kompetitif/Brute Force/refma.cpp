#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, one[75][75], two[75][75];

void identik(){
	bool a = 1, b = 1, c = 1, d = 1, e = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(a && one[i][j] != two[i][j])
				a = 0;
			if(b && one[i][j] != two[N-i-1][j])
				b = 0;
			if(c && one[i][j] != two[i][N-j-1])
				c = 0;
			if(d && one[i][j] != two[j][i])
				d = 0;
			if(e && one[i][j] != two[N-j-1][N-i-1])
				e = 0;
			if(!a && !b && !c && !d && !e){
				printf("tidak identik\n");
				return;
			}
		}
	}
	if(a)
		printf("identik\n");
	else if(b)
		printf("horisontal\n");
	else if(c)
		printf("vertikal\n");
	else if(d)
		printf("diagonal kanan bawah\n");
	else
		printf("diagonal kiri bawah\n");
}

int main(){
	scan(N); scan(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scan(one[i][j]);
		}
	}
	scan(N); scan(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scan(two[i][j]);
		}
	}
	identik();
	return 0;
}