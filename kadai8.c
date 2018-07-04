#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000
#define PAIRS 2		//can't use 0

int main(void)
{
	char *list[MAX];
	int num[MAX] = {};
	char ch;
	int i;
	int listed = 0;
	int fg = 1;
	int fg1 = 0;

	int error = 1;
	double sum = 0;
	FILE *fp;
	FILE *fp1;
	double pi = 0;
	double ent = 0;

	if( (fp = fopen("textdata3_symbol_replace.txt", "r")) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}
	if( (fp1 = fopen("textdata3_entropy.txt", "w") ) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}

	while( (ch = fgetc(fp)) != EOF){
		if(ch != '\n'){
			sum++;
		}
	}

	fseek(fp, 0, SEEK_SET);

	while(error){

		 for(i = 0; i < PAIRS; i++){
			if( (ch = toupper( (fgetc(fp))) ) == EOF){
				error = 0;
				break;
			}

			if(fg){
				list[listed] = (char *)malloc( sizeof(char)*(PAIRS+1) );
				fg = 0;
			}
			if(ch != '\n'){
				*(list[listed]+i) = ch;
			}

			else i--;
		}

		for(i = 0; i < PAIRS; i++){

			if( *(list[listed]+i) != ' '){
				fg1 = 0;
			}
		}

		if(error == 0) break;


		for(i = 0, fg = 1; i < listed && fg1 == 0; i++){
			if(strcmp(list[i], list[listed]) == 0){
				num[i]++;
				fg = 0;
				listed--;	//listed再利用
				break;
			}
		}
		listed++;
	}
	for(i = 0; i < listed-1; i++){

		fprintf(fp1, "%-10s%-10d%f\n", list[i], num[i]+1, (double)(num[i]+1)*100/sum);
		pi = (double)(num[i]+1)/sum;							//割合
		ent -= pi*log2(pi);
		//printf("%f\n", ent);
		free(list[i]);
	}

	fclose(fp);
	fclose(fp1);
	printf("\n%f\n(Fin)\n\n",ent);


	return 0;
}
