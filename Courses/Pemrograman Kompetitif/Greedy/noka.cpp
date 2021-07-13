#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define mp make_pair
#define ll unsigned long long
#define pb push_back

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

ll n, arr[11], freq[11], k, min1, min2, index1, index2, total;

void move(int x, ll harga){
	for(int i = n; i > x && k > 0; i--){
		ll c = arr[i] - harga;
		ll bag = k / c;
		bag = min(bag, freq[x]);
		ll biaya = bag * c;
		if(bag && k >= biaya){
			freq[i] += bag;
			freq[x] -= bag;
			k -= biaya;
		}
	}
}

void minimum(){
	min1 = arr[0];
	index1 = 0;
	min2 = arr[1];
	index2 = 1;
	for(int i = 1; i <= n; i++){
		if(arr[i] <= min1){
			min1 = arr[i];
			index1 = i;
		}
	}
	for(int i = 2; i <= n; i++){
		if(arr[i] <= min2){
			min2 = arr[i];
			index2 = i;
		}
	}
}

int main(){
	fill(freq, freq+11, 0);
	fill(arr, arr+11, 1);
	scan(n);
	for(int i = 0; i <= n; i++)
		scan(arr[i]);
	scan(k);
	minimum();
	printf("%lld-%lld\n", min1, min2);
	bool by1 = k < min1;
	bool by2 = k < min2;
	if(by1)
		printf("0\n");
	else if(by2)
		printf("1\n0\n0\n");
	else{
		if(n == 0){
			min2 = arr[0];
			index2 = 0;
		}
		if(min1 == min2){
			freq[index1] += k / min1;
			k %= min1;
			total = freq[index1];
			move(index2, min2);
		}
	}
	return 0;
}