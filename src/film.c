#include <stdio.h>
#include <string.h>

void createFilms(){
    FILE *p = fopen("films.txt", "w");
    fclose(p);
}

void showFilmList(){
    struct Film film = {0}, temp = {0};
    FILE *p = fopen("data/films.txt", "r");

    for (size_t i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %d %d %s %s", film.name, &film.lenHour, &film.lenMin, film.summerize, film.gen);
        if (film.lenHour != 0)
        {
            /*fscanf(p, "%s %d %d %s %s", temp.name, &temp.lenHour, &temp.lenMin, temp.summerize, temp.gen);
            if (temp.lenHour != 0)
            {
                printf("%s %d : %d %s %s\n", film.name, film.lenHour, film.lenMin, film.summerize, film.gen);
                printf("%s %d : %d %s %s\n", temp.name, temp.lenHour, temp.lenMin, temp.summerize, temp.gen);
                continue;
            }
            else
            {
                printf("%s %d : %d %s %s\n", film.name, film.lenHour, film.lenMin, film.summerize, film.gen);
                break;
            }*/
            printf("%s %d : %d %s %s\n", film.name, film.lenHour, film.lenMin, film.summerize, film.gen);
        }
        else
        {
            puts("No movies yet...");
        }
    }

    fclose(p);
}

void addMovie(struct Film film){
    FILE *p =  fopen("data/films.txt", "a+");
    fprintf(p, "\n%s %d %d %s %s", film.name, film.lenHour, film.lenMin, film.summerize, film.gen);
    fclose(p);
}

void remMovie(struct Film film){
    struct Film temp[1000];
    int i;
    FILE *p = fopen("data/films.txt", "r+");

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %d %d %s %s\n", temp[i].name, &temp[i].lenHour, &temp[i].lenMin, temp[i].summerize, temp[i].gen);
    }
    
    fclose(p);

    p = fopen("data/films.txt", "w");

    for (size_t j = 0; j < i; j++)
    {
        if (strcmp(temp[j].name, film.name))
        {
            fprintf(p, "\n%s %d %d %s %s", temp[j].name, temp[j].lenHour, temp[j].lenMin, temp[j].summerize, temp[j].gen);
        }
    }
    
    fclose(p);
    puts("Removed successfuly");
}

void upMovie(char name[], struct Film film){
    struct Film films[1000];
    int i;
    FILE *p = fopen("data/films.txt", "r+");

    for (i = 0; feof(p) == 0; i++)
    {
        fscanf(p, "%s %d %d %s %s", films[i].name, &films[i].lenHour, &films[i].lenMin, films[i].summerize, films[i].gen);
    }
    
    fclose(p);

    for (size_t j = 0; j < i; j++)
    {
        if (strcmp(films[j].name, name) == 0)
        {
            strcpy(films[j].gen, film.gen);
            films[j].lenHour = film.lenHour;
            films[j].lenMin = film.lenMin;
            strcpy(films[j].summerize, film.summerize);
        }
    }

    p = fopen("data/films.txt", "w");

    for (size_t j = 0; j < i; j++)
    {
        fprintf(p, "\n%s %d %d %s %s", films[j].name, films[j].lenHour, films[j].lenMin, films[j].summerize, films[j].gen);
    }
    
    fclose(p);
    puts("Updated successfuly..");
}