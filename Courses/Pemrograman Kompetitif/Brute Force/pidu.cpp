#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, skor[5], mungkin[5];
bool benar;

void brute(int one, int two){
	if(benar)
		return;//menghentikan proses jika terbukti benar
	bool bisa = true;
	if(two == N){
		for(int i = 0; i < N; i++){
			if(skor[i] != mungkin[i]){
				bisa = false;
				break;
			}
		}//cek kesamaan
		if(bisa)
			benar = true;
	}//semua pertandingan selesai
	else{
		mungkin[one] += 3;
		if(two != N-1)
			brute(one, two+1);
		else
			brute(one+1, one+2);
		mungkin[one] -= 3;
		//---------one menang----------//

		mungkin[two] += 3;
		if(two != N-1)
			brute(one, two+1);
		else
			brute(one+1, one+2);
		mungkin[two] -= 3;
		//---------two menang----------//

		mungkin[one]++;
		mungkin[two]++;
		if(two != N-1)
			brute(one, two+1);
		else
			brute(one+1, one+2);
		mungkin[one]--;
		mungkin[two]--;
		//------------seri-------------//
	}
}

int main(){
	int T;
	scan(T);
	while(T--){
		scan(N);
		for(int i = 0; i < N; i++)
			scan(skor[i]);
		benar = false;
		brute(0, 1);
		if(benar)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}