#include <cstdio>
#include <string>
#include <algorithm>
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

int matrix[128][128], indeks = 0;
char key[128*128][100];

void homogen(int A, int B, int C, int D){
	for(int i = A; i < B; i++)
		for(int j = C; j < D; j++)
			matrix[i][j] = 1;
}

void quadtree(int A, int B, int C, int D, string letak){
	if(key[indeks] == "1" + letak){
		homogen(A, B, C, D);
		indeks++;
	}
	else if(A == B-1 && C == D-1)
		matrix[A][C] = 0;
	else{
		quadtree(A, (A+B)/2, C, (C+D)/2, letak+"0");
		quadtree(A, (A+B)/2, (C+D)/2, D, letak+"1");
		quadtree((A+B)/2, B, C, (C+D)/2, letak+"2");
		quadtree((A+B)/2, B, (C+D)/2, D, letak+"3");
	}
}

int main(){
	int R, C, maks, bujsang = 2, N;
	scan(N);
	for(int i = 0; i < N; i++)
		scanf("%s", key[i]);
	scan(R); scan(C);
	maks = max(R, C);
	while(bujsang < maks)
		bujsang *= 2;
	quadtree(0, bujsang, 0, bujsang, "");
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			print(matrix[i][j]);
			if(j != C-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}