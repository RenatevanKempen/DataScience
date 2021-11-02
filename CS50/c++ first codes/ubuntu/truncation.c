#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get numbers from users
    int x = get_int(" x: ");
    int y = get_int(" y: ");

    //divide and print
    float z = (float) x / (float) y;
    printf("%f\n", z);
}