#include <stdio.h>
#include <stddef.h>

#include "src/file.c"

int main(){
    
    char cmd=0, temp=0;
    writeSetting();
    
    if(isExist("data/setting.txt")){
        printf("Hello, Welcome to the cinema manager\nWhat do you want to do?\nmanage cinema(1) or buy ticket(2)?\n");
        scanf("%c", &cmd);
        if (cmd == '1')
        {
            printf("For managing saloons (1), Managing saloons sans (2), Managing Films (3)\n");
            scanf("%c", &cmd);
            scanf("%c", &cmd);

            if (cmd == '1')
            {
                showSaloons();
                printf("Do you want to delete a saloon (1) or add a saloon(2)?\n");
                scanf("%c", &cmd);
                scanf("%c", &cmd);
                if (cmd == '1')
                {
                    puts("Wich saloon do you want to remove ?");
                    scanf("%d", &temp);
                    removeSaloon(temp);
                }
                else if(cmd == '2'){
                    createSaloon();
                    puts("Created succesfuly..");
                }
                else{
                    printf("try again...");
                }
            }
            else if(cmd == '2'){ 
                struct Sans sans;
                int saloonNum;
                char cmd;
                
                printf("Enter saloon number : ");
                scanf("%d", &saloonNum);

                showSaloonSans(saloonNum);

                printf("OK, Now for add (1), remove (2), update (3)\n");

                scanf("%c", &cmd);
                scanf("%c", &cmd);

                if (cmd == '1')
                {
                    printf("Enter name of movie : ");
                    scanf("%s", sans.filmName);
                    printf("Number of sits : ");
                    scanf("%d", &sans.sits);
                    printf("Enter date of show : ");
                    scanf("%d %d %d", &sans.year, &sans.month, &sans.day);
                    printf("Enter time of start : ");
                    scanf("%d %d", &sans.SH, &sans.SM);
                    printf("Enter time of end : ");
                    scanf("%d %d", &sans.EH, &sans.EM);
                    printf("Enter Positions Left : ");
                    scanf("%d", &sans.posLeft);
                    addSansToSaloon(saloonNum, sans);
                }
                else if(cmd == '2')
                {
                    /* remSansFromSaloon(saloonNum); */
                }
                else if(cmd == '3')
                {
                    /* updateAnExitingSansInSaloon(saloonNum); */
                }
            }
            else if(cmd == '3'){
                showFilmList();
                puts("For adding a new movie (1), Removing (2) and for Updating an excisting movie (3)");
                scanf("%c", &cmd);
                scanf("%c", &cmd);
                if (cmd == '1')
                {
                    struct Film film;

                    printf("Enter name of movie : ");
                    scanf("%s", film.name);
                    printf("Enter Hour and Minutes : ");
                    scanf("%d %d", &film.lenHour, &film.lenMin);
                    printf("Enter a summerize (max 250 chars), please replace spaces with dash (-) : ");
                    scanf("%s", film.summerize); 
                    printf("Finaly enter gender of movie : ");
                    scanf("%s", film.gen);

                    addMovie(film);
                }
                else if (cmd == '2')
                {
                    struct Film film;

                    puts("Enter film name : ");
                    scanf("%s", film.name);

                    remMovie(film);
                }
                else if (cmd == '3')
                {
                    struct Film film;
                    char name[30];
                    puts("Enter the name of movie you want to update : ");
                    scanf("%s", name);

                    printf("Enter Hour and Minitue : ");
                    scanf("%d %d", &film.lenHour, &film.lenMin);
                    printf("Enter summrize : ");
                    scanf("%s", film.summerize);
                    printf("Enter gender : ");
                    scanf("%s", film.gen);

                    upMovie(name, film);
                }
                else
                {
                    puts("Try again...");
                }
            }
            else{
                printf("try again..");
            }
        }
        else if (cmd == '2')
        {
            /* buyTicket */ 
        }
        else
        {
            printf("try again.");
        }
    }
    else
    {
        printf("This is first time you open this app\n");
        createSettings();
        createSaloon(1);
        createFilms();
        puts("We make some initializes now you can use app, Please reopen");
    }

}