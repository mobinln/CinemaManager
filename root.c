#include <stdio.h>
#include <stddef.h>

#include "src/file.c"

int main(){
    
    char cmd=0, temp=0;
    writeSetting();
    if(isExist("data/setting.txt")){
        printf("Hello, Welcome to the cinema manager\nWhat do you want to do?\nmanage cinema(1) or but ticket(2)?\n");
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
                    printf("Enter a summerize (max 250 chars) : ");
                    scanf("%s", film.summerize);
                    printf("Finaly enter gender of movie : ");
                    scanf("%s", film.gen);

                    addMovie(film);
                }
                else if (cmd == '2')
                {
                    /* remMovie */
                }
                else if (cmd == '3')
                {
                    /* uptMovie */
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