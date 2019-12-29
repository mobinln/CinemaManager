#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#include "../src/config.c"
#include "../src/saloon.c"
#include "../src/film.c"
#include "../src/sans.c"

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
/*
void delete(){
    int id, i;
    struct Person pers[100] = {0};
    struct Person per;
    FILE *p = fopen(FNAME, "r+");
    printf("Enter the ID: ");
    scanf("%d", &id);

    for(i=0; feof(p) == 0; i++)
    {
        fscanf(p, "%d %s %s %d", &per.id, per.fname, per.lname, &per.age);
        if (per.id != id)
        {
            pers[i].id = per.id;
            strcpy(pers[i].fname, per.fname);
            strcpy(pers[i].lname, per.lname);
            pers[i].age = per.age;
        }
    }
    fclose(p);

    p = fopen("data.txt", "w");
    for (size_t j = 0; j < i; j++)
    {
        if(pers[j].age != 0)
            fprintf(p, "%d %s %s %d\n", pers[j].id, pers[j].fname, pers[j].lname, pers[j].age);
    }
    fclose(p);
}
*/
/*
void search(){
    struct Person per;
    int id, flag=0;
    FILE *p = fopen(FNAME, "r");
    printf("Eneter ID: ");
    scanf("%d", &id);

    for (size_t i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%d %s %s %d", &per.id, per.fname, per.lname, &per.age);
        if (per.id == id)
        {
            printf("%d %s %s %d", per.id, per.fname, per.lname, per.age);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Not found, Try to insert that or try again..\n");
    }
    fclose(p);
}
*/
/*
void update(){
    int id, i, flag=0;
    struct Person pers[100] = {0};
    struct Person per;
    FILE *p = fopen(FNAME, "r+");
    printf("Enter ID: ");
    scanf("%d", &id);

    printf("Enter Name: ");
    scanf("%s %s", per.fname, per.lname);
    printf("Enter Age: ");
    scanf("%d", &per.age);

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%d %s %s %d", &pers[i].id, pers[i].fname, pers[i].lname, &pers[i].age);
    }
    
    for (size_t j = 0; j < i; j++)
    {
        if (pers[j].id == id)
        {
            strcpy(pers[j].fname, per.fname);
            strcpy(pers[j].lname, per.lname);
            pers[j].age = per.age;
            flag = 1;   
        }
    }
    printAll(p);
    
    fclose(p);
}
*/

void showSans(int saloonNum){
    struct Sans sans;
    
    char fileName[15] = {'\0'};
    sprintf(fileName, "%s %d.txt", "saloon", saloonNum);

    int i;

    FILE *p = fopen(fileName, "r");

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %s %s %s %d", sans.filmName, sans.date, sans.timeStart, sans.timeEnd, &sans.posLeft);
        printf("%s %s %s %s %d", sans.filmName, sans.date, sans.timeStart, sans.timeEnd, sans.posLeft);
    }

    fclose(p);
}