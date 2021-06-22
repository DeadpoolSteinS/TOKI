#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int R, C, bawah;
char matrix[20][8];

void runtuh(int x, int y){
	if((matrix[x+1][y] == '0') && (x+1 < R)){
		matrix[x][y] = '0';
		matrix[x+1][y] = '1';
		runtuh(x+1, y);
	}
}

int main(){
	scan(R); scan(C);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			scanf(" %c", &matrix[i][j]);
	//penginputan
	do{
		bawah = 0;
		for(int i = 0; i < R; i++){
			bool hilang = true;
			for(int j = 0; j < C; j++)
				if(matrix[i][j] == '0'){
					hilang = false;
					break;
				}
			//pengecekan penuh tiap baris
			if(hilang){
				bawah = i;
				for(int j = 0; j < C; j++)
					matrix[i][j] = '0';
			}//penghilangan baris penuh
		}
		for(int i = bawah-1; i >= 0; i--)
			for(int j = 0; j < C; j++)
				if(matrix[i][j] == '1')
					runtuh(i, j);//peruntuhan

	}while(bawah > 0);

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}//menampilkan hasil
	return 0;
}