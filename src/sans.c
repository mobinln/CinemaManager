#include <stdio.h>
#include <string.h>

int isSansFit(int slnNum, struct Sans sans){
    struct Sans sanses[1000];
    char fileName[50];
    int i;
    sprintf(fileName, "data/saloon %d.txt", slnNum);

    FILE *p = fopen(fileName, "r");

    for (i = 0; feof(p) == 0; i++)
    {        
        fscanf(p, "%s %d %d %d %d %d %d %d %d %d", sans.filmName, &sans.sits, &sans.year, &sans.month, &sans.day, &sans.SH, &sans.SM, &sans.EH, &sans.EM, &sans.posLeft);
    }
    
    
}

/* makeGoldenNumDate */
int makeGND(struct Sans sans){
    int num = 0;
    num += sans.year * 10000;
    num += sans.month * 100;
    num += sans.day;
    return num;
}

/* makeGoldenNumTime */
int makeGNT(int H, int M){
    int num = 0;
    num += H * 100;
    num += M;
    return num;
}

void addSansToSaloon(int slnNum, struct Sans sans){
    char fileName[50];
    sprintf(fileName, "data/saloon %d.txt", slnNum);
    if (isSansFit(slnNum, sans))
    {
        FILE *p = fopen(fileName, "a");

        fprintf(p, "\n%s %d %d %d %d %d %d %d %d %d", sans.filmName, sans.sits, sans.year, sans.month, sans.day, sans.SH, sans.SM, sans.EH, sans.EM, sans.posLeft);

        fclose(p);
        puts("Added successfily..");
    }
    else
    {
        puts("There are a problem...");
    }
    
}