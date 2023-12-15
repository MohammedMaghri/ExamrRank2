#include <stdio.h>
#include <unistd.h>

void paste(char string)
{
    write(1,&string,1);
}
int check(char string)
{
    if (string == ' ')
        return 0;
    if (string == '\t')
        return 0;
    return 1 ;
}
int lencount(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
int wordcount(char *string)
{
    int index = 0;
    int counter = 0 ;
    int total = lencount(string);
    while (index < total)
    {
        if (check(string[index]) == 0)
        {
            index++ ; 
        }
        else if (check(string[index]) == 1)
        {
            counter++ ;
            while(check(string[index]) == 1)
            {
                index++;
            }
        }
    }
    return counter ;
}
void firstword(char *string)
{
    int index = 0 ;
    while ( string[index] && check(string[index]) == 0)
        index++ ;
    while (string[index] && check(string[index]) == 1)
    {
        paste(string[index]);
        index++ ;
    }
    return ;
}  
int main(int argc , char **argv)
{
    int res ;
    if (argc != 2)
    {
        paste('\n');
        return (0);
    }
    firstword(argv[1]);
    paste('\n');
}