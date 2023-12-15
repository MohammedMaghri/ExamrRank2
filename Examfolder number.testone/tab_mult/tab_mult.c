#include <stdio.h>
#include <unistd.h>

void paste (char string)
{
    write(1,&string,1);
}
void putnbr(int number)
{
    if (number < 0)
    {
        paste('-');
        number *= 1;
    }
    else if (number < 10)
    {
        paste(number + '0');
    }
    else if (number >= 10)
    {
        putnbr(number / 10 );
        putnbr(number % 10);
    }
}
int ft_atoi(char *string)
{
    int index = 0 ;
    int negat = 1 ;
    int number = 0 ;
    while (string[index] == ' '  ||  (string[index] >= 9 && string[index] <= 13))
        index++ ;
    while (string[index] == '-' || string[index] == '+')
    {
        if (string[index] == '-')
            negat *= -1 ;
        index++ ;
    }
    while (string[index] >= '0' && string[index] <= '9')
    {
        number = (number * 10) + string[index] - '0';
        index++ ;
    }
    return (number * negat);
}

int main(int argc , char **argv)
{
    if (argc != 2)
    {
        paste('\n');
        return (0);
    }
    int index = 1 ;
    int number = ft_atoi(argv[1]);
    while (index <= 9 )
    {
        putnbr(index);
        paste(' ');
        paste('x');
        paste(' ');
        putnbr(number); 
        paste(' ');
        paste ('=');
        paste(' ');
        putnbr(number * index);
        paste('\n');
        index++;
    }
}