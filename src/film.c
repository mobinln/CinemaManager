#include <stdio.h>

void createFilms(){
    FILE *p = fopen("films.txt", "w");
    fclose(p);
}