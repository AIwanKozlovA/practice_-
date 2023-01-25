#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
char* concat(char *s1, char *s2){
        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      
        char *result = malloc(len1 + len2 + 1);
        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }
        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    
        return result;
}
int main(int argc, char* argv[]){
    if (argc == 3){
    char* nf;
    char s;
    //printf("Введите имя файла для удаления слов из него\n");
    //scanf("%s",&nf);
    //printf("%c\n",nf);
    nf = argv[1];
    FILE * file = fopen(nf,"rb");
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
    //scanf("%c\n",&s);
    //printf("%s", jk);
    char* istr = strtok (jk," ");
    char* ob = "";
    //printf("Введите символ, все слова начиная с которого будут\n");
    //scanf("%c",&s);
    s = argv[2][0];
    //printf ("%s\n",istr);
    
    while (istr != NULL){
        // Вывод очередной выделенной части
        //rintf ("%s\n",istr);
        if(istr[0] != s){
            //strncat(ob,istr,70);
            ob = concat(ob," ");
            ob = concat(ob,istr);
            //printf ("%s %c\n",istr, s);
            //snprintf(ob, sizeof(ob)+sizeof(istr), "%s%s",ob,istr);
        }
        //printf ("%s %c\n",istr,s);
        // Выделение очередной части строки
        istr = strtok (NULL," ");
    }
    FILE* file1 = fopen(nf,"w");
    fwrite(ob,sizeof(char),strlen(ob),file1);
    fclose(file1);
    printf("%s\n",ob);
    }else printf("Вы не ввели нужное число аргументов через argv!!!\n");
    return 0;
}