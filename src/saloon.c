#include <stdio.h>

int makeNewSaloonNumber(){
    char saloon[15], lastSaloon[15];
    writeSetting();
    FILE *p = fopen("data/setting.txt", "r");
    fscanf(p, "%s", lastSaloon);
    for (size_t i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s", saloon);
    }
    return (saloon[7] - '0')+1;
}

void createSaloon(){
    char fName[30];
    int saloonNum = makeNewSaloonNumber();
    //printf("%d", saloonNum);
    sprintf(fName, "data/saloon %d.txt", saloonNum);
    FILE *p = fopen(fName, "w");
    fclose(p);

    p = fopen("data/setting.txt", "w");
    char salN[11];
    sprintf(salN, "saloon %d", saloonNum); 
    fprintf(p, "%s\n", salN);
    fclose(p);

    writeSetting();
}

void insertSansToSaloon(int saloonNum){
    char fName[15];
    sprintf(fName, "%s %d.txt", "saloon", saloonNum);
}

void showSaloons(){
    char sals[20] = {0};
    FILE *p = fopen("data/setting.txt", "r");
    for (size_t i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s", sals);
        printf("%s\n", sals);
        
    }
    fclose(p);
}

void removeSaloon(int saloonNum){
    char fName[30];
    sprintf(fName, "data/saloon %d.txt", saloonNum);
    if (remove(fName) == 0)
    {
        puts("Removed successfuly..");
        writeSetting();
    }
    else{
        puts("Unable to remove this file");
    }
}