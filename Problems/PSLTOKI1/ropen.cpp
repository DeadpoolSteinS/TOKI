#include <cstdio>
#include <queue>
using namespace std;
#define gc getchar_unlocked
#define f first
#define s second
#define mp make_pair

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N;
char denah[15][15];
bool bol[11][11][11][2][11][2][11][2] = {};
pair <pair <int, int>, int> t[8], buku;
queue <pair <pair <int, int>, int> > abal, jaga;

void add(int a, int b, int c){
	if(denah[a][b] != 'X' && denah[a][b] != '#' && !bol[a][b][t[3].f.s][t[3].s==-1?0:1][t[4].f.s][t[4].s==-1?0:1][t[5].f.s][t[5].s==-1?0:1]){
		bol[a][b][t[3].f.s][t[3].s==-1?0:1][t[4].f.s][t[4].s==-1?0:1][t[5].f.s][t[5].s==-1?0:1] = 1;
		abal.push(mp(mp(a, b), c));
	}
}//gerakan abal

void robotwalk(){
	for(int i = 0; i < jaga.size(); i++){
		int a = jaga.front().f.f;
		int b = jaga.front().f.s;
		int c = jaga.front().s;
		denah[t[i].f.f][t[i].f.s] = '.';
		t[i] = jaga.front();
		if(!((denah[a][b+1] == '#' || b+1>N) && (denah[a][b-1] == '#' || b-1<1))){
			if(denah[a][b+c] == '#' || b+c<1 || b+c>N)
				c = -c;
			denah[a][b] = c == -1?'R':'L';
			denah[a][b+c] = 'X';
			jaga.push(mp(mp(a, b+c), c));
		}
		else
			jaga.push((denah[a][b] = 'X', mp(mp(a, b), c)));
		jaga.pop();
		switch(i){
			case 0 : t[i+3] = jaga.back();
			case 1 : t[i+3] = jaga.back();
			case 2 : t[i+3] = jaga.back();
		}
	}
}//gerakanpenjaga

int main(){
	scan(N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%c", &denah[i][j]);
			if(denah[i][j] == 'T')
				buku = mp(mp(i, j), 0);//tempat buku
			if(denah[i][j] == 'S')
				abal.push(mp(mp(i, j), 0));//tempat abal
			if(denah[i][j] == 'X')
				jaga.push(mp(mp(i, j), 1));
		}
		getchar();
	}
	for(int i = 0; i < 8; i++)
		t[i] = mp(mp(0, 0), 0);//letak penjaga
	while(!abal.empty()){
		robotwalk();
		int gerak = abal.front().s;
		while(gerak == abal.front().s && !abal.empty()){
			int a = abal.front().f.f;
			int b = abal.front().f.s;
			int c = abal.front().s;
			if(a == buku.f.f && b == buku.f.s){
				printf("%d\n", c);
				return 0;
			}
			abal.pop();
			add(a, b, c+1);//diam
			if(a+1 <= N)
				add(a+1, b, c+1);
			if(a-1 >= 1)
				add(a-1, b, c+1);
			if(b+1 <= N && denah[a][b+1] != 'R')//R dan L menunjukan tabrakan
				add(a, b+1, c+1);
			if(b-1 >= 1 && denah[a][b-1] != 'L')
				add(a, b-1, c+1);
		}
	}
	printf("-1\n");
	return 0;
}

//Code by jauhararifin