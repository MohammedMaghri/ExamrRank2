#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1,&string,1);
}
int lencount(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++;
    }
    return index ;
}
void stringfincder(char *string , char *lockfor)
{
    int index = 0;
    int increment = 0 ;
    while (string[increment])
    {
        if (string[increment] == lockfor[index])
        {
            index++;
        }
        increment++ ; 
    }
    if (index == lencount(lockfor))
    {
        write(1, "1", 1);
    }
    else
        write(1, "0", 1);

}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        paste('\n');
        return 0 ;
    }
    stringfincder(av[2] , av[1]);
    paste('\n');
}