#include <stdio.h>
int main(void)
{
    int integerType;
    float floatType;
    long longType;
    long long longerType;
    char charType;

    // Sizeof operator is used to evaluate the size of a variable
    printf ("Size of char: %i byte(s)\n", sizeof(char));
    printf("Size of int: %i byte(s)\n",sizeof(int));
    printf("Size of long int: %i byte(s)\n", sizeof(long));
    printf("Size of long long int: %i byte(s)\n", sizeof(double));
    printf("Size of float: %i bytes\n",sizeof(float));

    return (0);
}
