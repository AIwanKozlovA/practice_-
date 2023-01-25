#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main(){
    FILE * file = fopen("ввод.txt","rb");
    //передвигааем в конец
    fseek(file, 0, SEEK_END);
    //получаем номер последнего элемеента
    long size = ftell(file);
    //возвращаемся назад
    rewind(file);
    char* jk;
    jk = malloc(sizeof(char)*size);
    int ou = fread(jk,sizeof(char)*size, size,file);
    fclose(file);

    char* ras = strtok(jk,"\n");//имя файла с раскладкой
    int kolxo = atoi(strtok(NULL,"\n"));// количество ходов
    char* exfile = strtok(NULL,"\n"); //имя выходного файла
    printf("%s %i %s\n",ras,kolxo,exfile);


    //считываем поле
    FILE * f = fopen(ras,"rb");
    //передвигааем в конец
    fseek(f, 0, SEEK_END);
    //получаем номер последнего элемеента
    long size1 = ftell(f);
    //возвращаемся назад
    rewind(f);
    char* po;
    po = malloc(sizeof(char)*size1);
    int oiu = fread(po,sizeof(char)*size1, size1,f);
    //printf("%s\n", po);
    fclose(file);
    // переводим строку в int массив 
    int** p;
    strlen(strtok(po,"\n"));
    int kol = strlen(strtok(po,"\n"));
    printf("Размер = %d\n", kol);
    p = malloc((kol) * sizeof(int*));


    int n = 0, kl,xo;// kol размер поля  kl количество живых клеток xo количество ходов
    xo = kolxo;
    //заполнение
    for(int y=0; y < kol; y++){
        p[y] = (int*)malloc((kol) * sizeof(int));// выделение памяти под каждую строку
        for(int x=0; x < kol + 1; x++){
            if(po[n] == '0' || po[n] == '1'){
                if(po[n] == '0')p[y][x] = 0;
                else if(po[n] == '1')p[y][x] = 1;
                printf("%d",p[y][x]);
            }
            n++;
        }
        printf("\n");
    }
    //обновление
    for(int s = 1;s <= xo; s++){
        sleep(1);
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
    //перевод из int в char для записи в файл
    n = 0;
    for(int y=0; y < kol; y++){
        //p[y] = (int*)malloc((kol) * sizeof(int));// выделение памяти под каждую строку
        for(int x=0; x < kol; x++){
                if(p[y][x] == 0)po[n] = '0';
                else if(p[y][x] == 1)po[n] = '1';
                //printf("%d",p[y][x]);
            n++;
        }
        po[n] = '\n';
        n++;
        //printf("\n");
    }
    //int test[2][2] = {{1,2},{3,4}};
    FILE* f1 = fopen(exfile,"w");
    fwrite(po,sizeof(char),kol*(kol+1),f1);
    fclose(f1);
    return 0;
}