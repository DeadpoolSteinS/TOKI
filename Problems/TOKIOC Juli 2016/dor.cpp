#include <iostream>
#include <vector>
using namespace std;
#define gc getchar_unlocked
#define pb push_back

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N;
	scan(N);
	int ans[N+1] = {};
	vector <int> arr;
	for(int i = 1; i <= N; i++)
		arr.pb(i);
	while(arr.size() >= 3){
		vector <int> ask;
		for(int i = 0; i < 3; i++){
			ask.pb(arr.front());
			arr.erase(arr.begin());
		}
		printf("%d\n", ask.size());
		for(int i = 0; i < ask.size(); i++){
			printf("%d", ask[i]);
			if(i < ask.size()-1)
				printf(" ");
		}
		printf("\n");
		string ret;
		cin >> ret;
		if(ret == "SSC"){
			ans[ask[0]] = ans[ask[1]] = 1;
			arr.pb(ask[2]);
		}
		else{
			for(int i = 0; i < 3; i++)
				ans[ask[i]] = (ret[i] == 'S');
		}
	}
	if(arr.size() == 2){
		printf("2\n");
		printf("%d %d\n", arr.front(), arr.back());
		string ret;
		cin >> ret;
		ans[arr.front()] = (ret.front() == 'S');
		printf("2\n");
		printf("%d %d\n", arr.back(), arr.front());
		cin >> ret;
		ans[arr.back()] = (ret.front() == 'S');
	}
	else if(arr.size() == 1){
		printf("2\n");
		cout << arr.front() << " " << ((arr.front() == 1) ? 2 : 1) << endl;
		string ret;
		cin >> ret;
		ans[arr.front()] = (ret.front() == 'S');
	}
	printf("-1\n");
	for(int i = 1; i <= N; i++)
		printf((ans[i]) ? "J" : "R");
	printf("\n");
	return 0;
}

// Code by Berted
// https://tlx.toki.id/profiles/Berted