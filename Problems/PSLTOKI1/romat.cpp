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
	int N;
	bool nol = true, sempu = true, lapu = true, dutu = true;
	scan(N); scan(N);
	int matrix[N][N], matrix0[N][N], matrix90[N][N], matrix180[N][N], matrix270[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scan(matrix0[i][j]);
			matrix90[j][N-i-1] = matrix0[i][j];
			matrix180[N-i-1][N-j-1] = matrix0[i][j];
			matrix270[N-j-1][i] = matrix0[i][j];
		}
	scan(N); scan(N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scan(matrix[i][j]);
			if(matrix[i][j] != matrix0[i][j] && nol)
				nol = false;
			if(matrix[i][j] != matrix90[i][j] && sempu)
				sempu = false;
			if(matrix[i][j] != matrix180[i][j] && lapu)
				lapu = false;
			if(matrix[i][j] != matrix270[i][j] && dutu)
				dutu = false;
		}
	if(nol)
		printf("0\n");
	else if(sempu)
		printf("90\n");
	else if(lapu)
		printf("180\n");
	else if(dutu)
		printf("270\n");
	else
		printf("tidak sama\n");
	return 0;
}