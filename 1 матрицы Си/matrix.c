#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "funk.h"
void print_all(int** mat, int r);
int main(){
	int z, r; // z номер операции, которую нужно произвести r размер матрицы
	printf("Введите 1 чтобы сгенерировать матрицу 2 чтобы ввести руками 3 чтобы считать матрицы из файла\n");
	scanf("%d", &z);
	if(z != 1 && z != 2 && z!= 3) return -1;
	int** A; int** B; // матрицы А и B
	printf("введите размер матрицы\n");
	scanf("%d",&r);
	A = malloc(r*sizeof(int*)); B = malloc(r*sizeof(int*));
	if(z == 1){// генериция рандомной матрицы
		srand(time(NULL));	
		//printf("матрица А\n");
		for(int y = 0;y<r;y++){
			A[y] = (int*)malloc(r*sizeof(int));
			B[y] = (int*)malloc(r*sizeof(int));
			for(int x = 0; x<r;x++){
				A[y][x] = 0 + rand() % 10;
				B[y][x] = 0 + rand() % 10;
			}
		}
	}else if(z == 2){ // считывание матрицы с клавиатуры
		printf("Введите матрицу А\n");
		for(int y = 0; y<r; y++){
			A[y] = (int*)malloc(r*sizeof(int));
			for(int x = 0; x < r;x++){
				scanf("%d", &A[y][x]);	
			}
		}
		printf("ВВедите матрицу B\n");
		for(int y = 0; y< r;y++){
			B[y] = (int*)malloc(r*sizeof(int));
			for(int x = 0; x < r;x++){
				scanf("%d",&B[y][x]);
			}
		}
	}else if(z == 3){ // считываем матрицу их файла
		FILE* file = fopen("mat.txt","rb"); // считывание данных из файла
		fseek(file,0,SEEK_END); //передвигааем в конец
		long size = ftell(file);  //получаем номер последнего элемеента
		//возвращаемся назад
    	rewind(file);
		char* jk;
    	jk = malloc(sizeof(char)*size);
    	int ou = fread(jk,sizeof(char)*size, size,file);
		fclose(file);
		bool b = false , pee = false; // для переключения на считывание матрицы B 
		char loc[10];// локальная переменная которая переводит строку в число и записывает в матрицу
		int x = 0, y = 0;
		A[y] = (int*)malloc(r*sizeof(int));
		B[y] = (int*)malloc(r*sizeof(int));
		for(int i = 0; i < size; i++){
			if (b){ // считывание и записывание матрицы B
				if (jk[i] != ' ' && jk[i] != '\n')  loc[strlen(loc)] = jk[i]; 
				else{
					B[y][x] = atoi(loc);
					if(x == (r - 1)){
						x = 0;
						y++;
						B[y] = (int*)malloc(r*sizeof(int));
					}else{
						x++;
					}
					memset(loc,0,sizeof(loc)); // обнуляем строку loc
				}
			}else{ // считывание и записывание матрицы А
				if (jk[i] != ' ' && jk[i] != '\n') loc[strlen(loc)] = jk[i]; 
				else{
					A[y][x] = atoi(loc);
					if(x == (r - 1)){
						x = 0;
						y++;
						A[y] = (int*)malloc(r*sizeof(int));
					}else{
						x++;
					}
					memset(loc,0,sizeof(loc)); // обнуляем строку loc
				}
			}
			if (jk[i] == '\n' && jk[i+1] == '\n' && pee == false){// два \n - значит матрица кончилась и идёт след. здесь определяется окончание матрицы  
				b = true;
				x = 0;
				y = 0;
				pee = true;
				i++;
			} 
		} 
	}
	// printf("всё ок = %d\n",opr(A,B, r));
	printf("Матрица А\n");
	print_all(A,r);
	printf("Матрица B\n");
	print_all(B,r);
	//printf("Результат сложения матриц A и B\n");
	//print_all(sum(A, B, r),r);
	printf("Результат умножения матриц A и B\n");
	print_all(ymno(A, B, r),r);
	printf("Определитель матрицы A\n");
	printf("%d\n",opr(A, r));
	printf("транспонированная матрица A\n");
	print_all(transpon(A, r),r);
	printf("A^-1\n");
	print_all(obr(A, B, r),r);
	return 0;
}
void print_all(int** mat,int r){
	for(int y = 0; y< r; y++){
		for(int x = 0; x < r;x++){
			printf("%d ", mat[y][x]);
		}
		printf("\n");
	}
}

