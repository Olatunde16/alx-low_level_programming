#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	n = rand();
	srand(time(0));

	if(n > 0){
	printf("%d is positive\n", n);
	}

	else if(n = 0){
	printf("%d is zero\n", n);
	}

	else if(n < 0){
	printf("%d is negative\n", n);
        }

	else {
	printf("%d\n", n);
	}

	return(0);
}
