#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define M 100

int main()
{

	int i, x;

	srand( (unsigned)time(NULL) );
	for( i = 0; i < N; i++){

		x = (int)( rand() / (double)RAND_MAX * M);
		printf("%d\n", x);
	}

	return 0;
}
//unic
