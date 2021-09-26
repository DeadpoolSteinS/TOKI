#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
}nilaiMatkul;

typedef struct{
	nilaiMatkul kontainer;
	int prev;
	int next;
}elemen;

typedef struct{
	int first;//awal data
	int tail;//akhir data
	elemen data[10];
}list;

void createList(list *L){
	(*L).first = -1;
	(*L).tail = -1;
	for(int i = 0; i < 10; i++){
		(*L).data[i].prev = -2;
		(*L).data[i].next = -2;
	}
}

int countElement(list L){
	int hasil = 0;
	if(L.first != -1){
		int bantu = L.first;
		while(bantu != -1){
			hasil++;
			bantu = L.data[bantu].next;
		}
	}
	return hasil;
}

int emptyElement(list L){
	int hasil = -1;
	if(countElement(L) < 10){
		int ketemu = 0;
		int i = 0;
		while((ketemu == 0) && (i < 10)){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}
			else
				i++;
		}
		// for(int i = 0; i < 10; i++){
		// 	if(L.data[i].next == -2){
		// 		hasil = i;
		// 		break;
		// 	}
		// }
	}
	return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
	if(countElement(*L) < 10){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nim, nim);
		strcpy((*L).data[baru].kontainer.nama, nama);
		strcpy((*L).data[baru].kontainer.nilai, nilai);
		if((*L).first == -1){
			(*L).data[baru].prev = -1;
			(*L).data[baru].next = -1;
			(*L).tail = baru;
		}//-1 dan -2 mewakili apa???
		else{
			(*L).data[baru].prev = -1;
			(*L).data[baru].next = (*L).first;
			(*L).data[(*L).first].prev = baru;
		}
		(*L).first = baru;
	}
	else
		printf("sudah tidak dapat ditambah\n");
}

void addAfter(int before, char nim[], char nama[], char nilai[], list *L){
	if(countElement(*L) < 10){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nim, nim);
		strcpy((*L).data[baru].kontainer.nama, nama);
		strcpy((*L).data[baru].kontainer.nilai, nilai);
		if((*L).data[before].next != -1){
			(*L).data[baru].prev = before;
			(*L).data[baru].next = (*L).data[before].next;
			(*L).data[before].next = baru;
			(*L).data[(*L).data[baru].next].prev = baru;
		}
		else{
			(*L).data[baru].prev = before;
			(*L).data[before].next = baru;
			(*L).data[baru].next = -1;
			(*L).tail = baru;
			printf("Beng\n");
		}
	}
	else
		printf("sudah tidak dapat ditambah\n");
}

void addLast(char nim[], char nama[], char nilai[], list *L){
	if((*L).first == -1)
		addFirst(nim, nama, nilai, L);
	else
		addAfter((*L).tail, nim, nama, nilai, L);
}

void delFirst(list *L){
	if((*L).first != -1){
		int hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = -1;
			(*L).tail = -1;
		}
		else{
			(*L).first = (*L).data[(*L).first].next;
			(*L).data[(*L).first].prev = -1;
		}
		(*L).data[hapus].prev = -2;
		(*L).data[hapus].next = -2;
	}
	else
		printf("list kosong\n");
}

void delAfter(int before, list *L){
	int hapus = (*L).data[before].next;
	if(hapus != -1){
		if((*L).data[hapus].next == -1){
			(*L).tail = before;
			(*L).data[before].next = -1;
		}
		else{
			(*L).data[before].next = (*L).data[hapus].next;
			(*L).data[(*L).data[hapus].next].prev = before;
		}
		(*L).data[hapus].prev = -2;
		(*L).data[hapus].next = -2;
	}
}

void delLast(list *L){
	if((*L).first != -1){
		if(countElement(*L) == 1)
			delFirst(L);
		else
			delAfter((*L).data[(*L).tail].prev, L);
	}
	else
		printf("list kosong\n");
}

void printElement(list L){
	if(L.first != -1){
		int bantu = L.first;
		for(int i = 1; bantu != -1; i++){
			printf("elemen ke : %d\n", i);
			printf("nim : %s\n", L.data[bantu].kontainer.nim);
			printf("nama : %s\n", L.data[bantu].kontainer.nama);
			printf("nilai : %s\n", L.data[bantu].kontainer.nilai);
			printf("next : %d\n", L.data[bantu].next);
			printf("------------\n");
			bantu = L.data[bantu].next;
		}
	}
	else
		printf("list kosong\n");
}

void delAll(list *L){
	for(int i = countElement(*L); i >= 1; i--)
		delLast(L);
}

int main(){
	list L;
	createList(&L);
	printElement(L);
	printf("============\n");
	addFirst("1", "Orang_1", "A", &L);
	addFirst("3", "Orang_3", "A", &L);
	addAfter(L.first, "2", "Orang_2", "A", &L);
	// addLast("3", "Orang_3", "A", &L);
	printElement(L);
	printf("============\n");
	// delLast(&L);
	delAfter(L.first, &L);
	delFirst(&L);
	printElement(L);
	printf("============\n");
	return 0;
}