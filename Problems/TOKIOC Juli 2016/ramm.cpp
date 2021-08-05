#include <cstdio>
using namespace std;

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	int N, T, rammon, banyak = 0;
	scan(N);
	double damage[N][N], total[N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			scanf("%lf", &damage[i][j]);
	}
	scan(T);
	for(int i = 0; i < T; i++){
		scan(rammon);
		for(int j = 0; j < N; j++){
			if(i == 0)
				total[j] = damage[j][rammon-1];
			else
				total[j] *= damage[j][rammon-1];
			if(i == T-1)
				if(total[j] >= 2)
					banyak++;
		}
	}
	printf("%d\n", banyak);
	return 0;
}