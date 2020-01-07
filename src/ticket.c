#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

// to dollors :)
#define baseTicketPrice 2;

void buyTicket(char finame[], char lname[],int sansNum, int slnNum, int tNums){
    struct Sans sanses[1000] = {0};
    char fname[50];
    int i, price = 0;
    sprintf(fname, "data/saloon %d.txt", slnNum);

    FILE *p = fopen(fname, "r");

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %d %d %d %d %d %d %d %d %d", sanses[i].filmName, &sanses[i].sits, &sanses[i].year, &sanses[i].month, &sanses[i].day, &sanses[i].SH, &sanses[i].SM, &sanses[i].EH, &sanses[i].EM, &sanses[i].posLeft);
    }
    
    fclose(p);

    if (sanses[sansNum].posLeft != 0)
    {
        sanses[sansNum].posLeft -= tNums;
        price += tNums * baseTicketPrice;

        p = fopen(fname, "w");

        for (size_t j = 0; j < i; j++)
        {
            fprintf(p, "\n%s %d %d %d %d %d %d %d %d %d", sanses[j].filmName, sanses[j].sits, sanses[j].year, sanses[j].month, sanses[j].day, sanses[j].SH, sanses[j].SM, sanses[j].EH, sanses[j].EM, sanses[j].posLeft);
        }

        fclose(p);
        printf("Thank you for choosing our cinema dear %s %s. This is your bill : %d", finame, lname, price);
    }
    else
    {
        puts("Unfortunately there is no positions left here..");
    }
    
}