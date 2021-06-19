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
string key[128*128];

bool homogen(int R, int C, int bujsang){
	for(int i = R; i < bujsang+R; i++)
		for(int j = C; j < bujsang+C; j++)
			if(matrix[i][j] != matrix[R][C])
				return false;
	return true;
}

void quadtree(int R, int C, int bujsang, string letak){
	if(homogen(R, C, bujsang)){
		if(matrix[R][C] == 1){
			key[indeks] = "1"+letak;
			indeks++;
		}
	}
	else{
		quadtree(R, C, bujsang/2, letak+"0");
		quadtree(R, C+(bujsang/2), bujsang/2, letak+"1");
		quadtree(R+(bujsang/2), C, bujsang/2, letak+"2");
		quadtree(R+(bujsang/2), C+(bujsang/2), bujsang/2, letak+"3");
	}
}

int main(){
	int R, C, maks, bujsang = 2;
	scan(R); scan(C);
	maks = max(R, C);
	while(bujsang < maks)
		bujsang *= 2;
	for(int i = 0; i < bujsang; i++){
		for(int j = 0; j < bujsang; j++){
			matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			scan(matrix[i][j]);
		}
	}
	quadtree(0, 0, bujsang, "");
	printf("%d\n", indeks);
	for(int i = 0; i < indeks; i++){
		printf("%s\n", key[i].c_str());
	}
	return 0;
}