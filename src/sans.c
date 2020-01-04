#include <stdio.h>
#include <string.h>

#include "rqs.c"

/* makeGoldenNumDate */
int GND(struct Sans sans){
    int num = 0;
    num += sans.year * 10000;
    num += sans.month * 100;
    num += sans.day;
    return num;
}

/* makeGoldenNumTime */
float GNT(int H, int M){
    int num = 0;
    num += H * 100;
    num += M;
    return num;
}

int isSansFit(int slnNum, struct Sans sans){
    struct Sans sanses[1000];
    char fileName[50];
    int i;
    sprintf(fileName, "data/saloon %d.txt", slnNum);

    FILE *p = fopen(fileName, "r");

    for (i = 0; feof(p) == 0; i++)
    {        
        fscanf(p, "%s %d %d %d %d %d %d %d %d %d", sanses[i].filmName, &sanses[i].sits, &sanses[i].year, &sanses[i].month, &sanses[i].day, &sanses[i].SH, &sanses[i].SM, &sanses[i].EH, &sanses[i].EM, &sanses[i].posLeft);
    }
    
    fclose(p);

    for (size_t j = 0; j < i; j++)
    {
        if (GND(sans) == GND(sanses[j]))
        {
            if (GNT(sans.SH, sans.SM) >= GNT(sanses[j].SH, sanses[j].SM) || GNT(sans.EH, sans.EM) <= GNT(sanses[j].EH, sanses[j].EM))
            {
                return 0;
            }
        }
    }
    
    return 1;
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
        puts("Please recheck the date and times of your new sans, It's interfacing with others...");
    }
    
}

void showSaloonSans(int slnNum){
    struct Sans sans;
    struct Sans sanses[1000];
    int sns[1000] = {0}, snsCp[1000] = {0};
    int inds[1000] = {0};
    char fileName[50];
    int i, cnt = 0;
    sprintf(fileName, "data/saloon %d.txt", slnNum);

    FILE *p = fopen(fileName, "r");

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %d %d %d %d %d %d %d %d %d", sans.filmName, &sans.sits, &sans.year, &sans.month, &sans.day, &sans.SH, &sans.SM, &sans.EH, &sans.EM, &sans.posLeft);
        //printf("%s sits: %d %d-%d-%d from %d:%d to %d:%d positions left: %d\n", sans.filmName, sans.sits, sans.year, sans.month, sans.day, sans.SH, sans.SM, sans.EH, sans.EM, sans.posLeft);
        sanses[i] = sans;
        sns[i] = GND(sans);
        snsCp[i] = sns[i];
    }

    quicksort(snsCp, 0, i-1);
    /* snsCp */
    for (size_t j = 0; j < i; j++)
    {
        /* sns */
        for (size_t c = 0; c < i; c++)
        {
            if(snsCp[j] == sns[c]){
                inds[cnt] = c;
                cnt++;  
            }
        }
        
    }
    
    for (size_t j = 0; j < i; j++)
    {
        printf("%s sits: %d %d-%d-%d from %d:%d to %d:%d positions left: %d\n", sanses[inds[j]].filmName, sanses[inds[j]].sits, sanses[inds[j]].year, sanses[inds[j]].month, sanses[inds[j]].day, sanses[inds[j]].SH, sanses[inds[j]].SM, sanses[inds[j]].EH, sanses[inds[j]].EM, sanses[inds[j]].posLeft);

    }
    
    fclose(p);    
}