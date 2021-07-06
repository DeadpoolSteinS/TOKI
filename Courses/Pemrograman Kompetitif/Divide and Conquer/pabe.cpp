#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int digit[6];
bool sejuta = false;

ll kali(ll a, ll b){
	ll c = a * b;
	if(c >= 1000000)
		sejuta = true;
	return (c % 1000000);
}

ll pangkat(ll a, ll b){
	if(b == 0)
		return 1;
	else{
		ll cek = pangkat(a, b/2);
		if(b%2 == 0)
			return (kali(cek, cek));
		else
			return (kali(a, kali(cek, cek)));
	}
}

int main(){
	ll A, B, hasil;
	scan(A); scan(B);
	hasil = pangkat(A, B);
	if(sejuta){
		for(int i = 0; hasil > 0; i++){
			digit[i] = hasil % 10;
			hasil /= 10;
		}
		for(int i = 5; i >= 0; i--)
			printf("%d", digit[i]);
		printf("\n");
	}
	else
		printf("%lld\n", hasil);
	return 0;
}