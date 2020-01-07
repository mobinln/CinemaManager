#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#include "../src/config.c"
#include "../src/saloon.c"
#include "../src/film.c"
#include "../src/sans.c"
#include "../src/ticket.c"

char* makeFileName(int saloonNum){
    char fileName[15];
    sprintf(fileName, "%s %d.txt", "saloon", saloonNum);
    return fileName;
}
int isExist(const char *fname){
    FILE *p;
    if ((p = fopen(fname, "r")))
    {
        fclose(p);
        return 1;
    }
    return 0;
}
void createSettings(){
    FILE *p = fopen("setting.txt", "w");
    fclose(p);
}
void writeSetting(){
    char fName[30];
    int i = 1;
    FILE *p = fopen("data/setting.txt", "w");
    sprintf(fName, "data/saloon %d.txt", 1);
    
    while (isExist(fName))
    {
        sprintf(fName, "data/saloon %d.txt", i);
        if (isExist(fName))
        {
            sprintf(fName, "data/saloon %d.txt", i+1);
            if (!isExist(fName))
            {
                fprintf(p, "saloon-%d", i);
            }
            else
            {
                fprintf(p, "saloon-%d\n", i);
            }
            
        }
        i++;
    }

    fclose(p);
}