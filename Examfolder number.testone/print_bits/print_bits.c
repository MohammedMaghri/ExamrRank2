#include <stdio.h>
#include <unistd.h>
void paste(char string)
{
    write(1,&string,1);
}
void putnbr(int number)
{
    if (number < 0)
    {
        paste(number + '0');
        number *= -1 ;
    }
    else if (number  < 10)
    {
        paste(number + '0');
    }
    else if (number >= 10)
    {
        putnbr(number % 10);
        putnbr(number / 10);
    }
}
void	print_bits(unsigned char octet)
{
    int array[7] ;
    int index  = 0 ;
    while (index < 7)
    {
        array[index] = ((octet >> index) & 1);
        index++;
    }
    while (index >= 0)
    {
        putnbr(array[index]);
        index-- ;
    }
}