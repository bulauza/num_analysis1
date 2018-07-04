#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define PAIRS 3

int main(void)
{
	char *list[MAX];
	int listed = 0;

	int num[MAX] = {};
	char ch;
	int i;

	int fg = 1;
	int error = 1;

	int sum = 0;

	FILE *fp;
	FILE *fp1;

	if( (fp = fopen("textdata_symbol_replace.txt", "r")) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}
	if( (fp1 = fopen("textdata_three_pairs.txt", "w") ) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}

	while(error){

		 for(i = 0; i < PAIRS; i++){

			if( ( ch = tolower(fgetc(fp)) ) == EOF){
				error = 0;
				break;
			}

			if(fg){
				list[listed] = (char *)malloc( sizeof(char)*(PAIRS+1) );
				fg = 0;
			}

			if(ch == ' '){
				*(list[listed]+i) = '_';
				sum++;
			}
			else if(isalpha(ch)){
				*(list[listed]+i) = ch;
				sum++;
			}
			else i--;	//もう一回読み込み
		}

		for(i = 0, fg = 1; i < listed && error; i++){
			if(strcasecmp(list[i], list[listed]) == 0){
				num[i]++;
				listed--;	//帳尻合わせ
				fg = 0;
				break;
			}
		}
		listed++;
	}

	for(i = 0; i < listed-1; i++){
		fprintf(fp1, "%-10s%-10d\t%f\n", list[i], num[i]+1, (double)(num[i]+1)*100/sum);
		free(list[i]);
	}

	fclose(fp);
	fclose(fp1);

	printf("\n(Fin)\n\n");


	return 0;
}
