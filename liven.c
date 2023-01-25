#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
int main(){
    printf("Введите на сколько клеток сгенерировать игру:\n");
    int kol, n = 0, kl,xo;// kol размер поля  kl количество живых клеток xo количество ходов
    //printf("%d",kol);
    scanf("%d",&kol);
    printf("Введите какое количество ходов нужно сделать:\n");
    scanf("%d",&xo);
    srand(time(NULL));
    kol += 2;
    int** p;
    p = malloc((kol) * sizeof(int*));
    //генерация
    for(int y=0; y < kol; y++){
        p[y] = (int*)malloc((kol) * sizeof(int));// выделение памяти под каждую строку
        for(int x=0; x < kol; x++){
            if ((x == 0) || (x == kol-1) || (y == 0) || (y == kol-1)) p[y][x] = 0;
            else p[y][x] = 0 + rand() % 2;
            printf("%d",p[y][x]);
            n++;
        }
        printf("\n");
    }
    //обновление
    for(int s = 1;s <= xo; s++){
        sleep(3);
        system("clear");
        printf("%d) ход:\n", s);
        for(int y=0; y < kol; y++){
        for(int x=0; x < kol; x++){
            //отмирание
                if((x > 0 && x<kol-1) && (y > 0 && y<kol-1)){
                    //if (p[y][x] == 1) kl++;
                    if (p[y][x-1] == 1) kl++;
                    if (p[y-1][x] == 1) kl++;
                    if (p[y][x+1] == 1) kl++;
                    if (p[y+1][x] == 1) kl++;
                    if (p[y+1][x+1] == 1) kl++;
                    if (p[y-1][x-1] == 1) kl++;
                    if (p[y-1][x+1] == 1) kl++;
                    if (p[y+1][x-1] == 1) kl++;

                    if (kl > 3 && p[y][x] == 1){ 
                        p[y][x] = 0;
                    }else if(kl == 3 && p[y][x] == 0){
                        p[y][x] = 1;
                    }else if(kl == 0 && p[y][x] == 1){
                        p[y][x] = 0;
                    }
                }

            printf("%d",p[y][x]);
            kl = 0;
            //n++;
        }
        printf("\n");
        }
    }
    return 0;
}