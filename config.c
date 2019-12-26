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
    char con[50];
};

struct Sans
{
    char filmName[30];
    char date[11];
    char timeStart[6];
    char timeEnd[6];
    int posLeft;
};

