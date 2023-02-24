#include <stdio.h>
#include "funk.h"
#include <stdlib.h>
int** sum(int** A,int** B, int r){ // сложение матриц
	int** C;
	C = malloc(r * sizeof(int*));
	for(int y = 0; y < r;y++){
		C[y] = (int*)malloc(r * sizeof(int));
		for(int x = 0; x < r; x++){
			C[y][x] = A[y][x] + B[y][x];
		}
	}
	return C;
}
int** ymno(int** A,int** B, int r){ // умножение матриц
	int** C;
	C = malloc(r * sizeof(int*));
	for(int y = 0; y < r;y++){
		C[y] = (int*)malloc(r * sizeof(int));
		for(int x = 0; x < r; x++){
			C[y][x] = 0;
			for(int s = 0; s< r;s++){
				C[y][x] += A[y][s] * B[s][x];
			}
		}
	}
	return C;
}
int** ob_matr(int ** a, int n, int x){ // обрезание матрицы
    int** res = (int **)malloc((n - 1) * sizeof(int *));
    for (int i = 0; i < n - 1; ++i)
        res[i] = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k){
            if (j == x){
                --k;
                continue;
            }
            res[i - 1][k] = a[i][j];
        }
    return res;
}
int opr(int** A, int r){ // нахождение определителя
	if (r == 1)
        return A[0][0];
    if (r == 2)
        return (A[1][1] * A[0][0]) - (A[0][1] * A[1][0]);
    int ans = 0, sig = 1;
    for (int i = 0; i < r; ++i){
		// print_all(matr(A, r, i),r-1);
        ans += (sig * A[0][i] * opr(ob_matr(A, r, i),r - 1));
        sig *= -1;
    }
    return ans;
}
int** transpon(int** A, int r){ // транспонирование матрицы
	int** B;
	B = malloc(r*sizeof(int*));
	for(int y = 0; y< r; y++){
		B[y] = (int*)(malloc(r*sizeof(int)));
		for(int x = 0;x < r;x++){
			B[y][x] = A[x][y];
		}
	}
	return B;
}
int** obr(int** A,int** B, int r){ // нахождение обратной матрицы
	int opre = opr(A,r);
	for(int y = 0;y < r;y++){
		for(int x = 0; x < r;x++){
			A[y][x] *= opre;
		}
	}
	return A;
}

