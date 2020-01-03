/* faze 2
struct Saloon
{
    int id;
    struct sans[];
};
*/
struct Film
{
    char name[30];
    int lenHour;
    int lenMin;
    char summerize[250];
    char gen[50];
};

struct Sans
{
    char filmName[30];
    int sits;
    //char date[11];
    int year, month, day;
    //char timeStart[6];
    int SH, SM;
    //char timeEnd[6];
    int EH, EM;
    int posLeft;
};

