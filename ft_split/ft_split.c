#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int checkspace(char string)
{
     if (string == '\t')
        return 0;
    else if (string == ' ')
        return 0;
    else if (string == '\n')
        return 0;
    return 1 ;
}
int count(char *string)
{
    int index =  0;
    int countword = 0 ;
    while (string[index])
    {
        if (checkspace(string[index]) == 0 )
        {
            index++ ;
        }
        else 
        {
            countword++ ;
            while (checkspace(string[index]) == 1)
            {
                index++ ;
            }
        }
    }
    return countword ;
}
int lencount(char *string)
{
    int index = 0 ;
    while (string[index])
    {
        index++ ;
    }
    return index ;
}
char *fillwords(char *string , int start, int end)
{
    int index = 0;
    char *allocation ;
    int total = lencount(string) ;
    allocation = malloc(sizeof(char) * total + 1);
    if (!allocation)
        return (NULL) ;
    while (start < end)
    {
        allocation[index] = string[start] ;
        index++ ;
        start++ ; 
    }
    allocation[index] = '\0';
    return allocation ;
}
char    **ft_split(char *str)
{
    int track = 0;
    int index = 0;
    int end  = 0 ;
    int flag = 0 ;
    int lloop = 0;
    char **allocation ;
    allocation = malloc(sizeof(char**) * count(str) + 1);
    if (!allocation)
        return (NULL);
    while (str[index] && track < count(str))
    { 
        while (str[index] && checkspace(str[index]) == 0)
            index++ ;
        flag = index ;
        while (str[index] && checkspace(str[index]) == 1)
            index++ ;
        end = index ;
        allocation[track] = fillwords(str, flag , index);
            track++ ;
    }
    allocation[track] = NULL;
    return allocation ;
}
int main()
{
    char *string = "                          L" ;
    int word = count(string);
    char **res = ft_split(string);
    int index = 0;
    while (res[index])
    {
         printf("(%s)\n" , res[index]);
         index++ ;
    }
    printf("%d %d " , index , word);
}









