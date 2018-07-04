#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 200000
#define OUTPUT 97

int main(void)
{

	char ch1, ch2, ch_A, ch_temp;		//文字格納

	long sum_char = 0;	//全文字数
	long random = 0;

	FILE *fp;
	FILE *fp1;
	int fg = 1;
	int i = 0;
	int j = 0;

	if( (fp = fopen("textdata_symbol_replace.txt", "r")) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}
	if( (fp1 = fopen("textdata_three_rewrite.txt", "w")) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	sum_char = ftell(fp);		//全文字数を調べる　\nも含む
	fseek(fp, 0, SEEK_SET);

	srand((unsigned int)time(NULL));

	for(i = 0; i < 1; i++){

		//random = (rand()%sum_char) + 1;
		random = (long)( rand() / (double)RAND_MAX * sum_char);

		fseek(fp, random, SEEK_SET);	//ランダムアクセス

		if( random < (sum_char-2) ){
		
			if(isalpha(ch1 = toupper(fgetc(fp)) ) || ch1 == ' '){
				fprintf(fp1,"%c", ch1);
				printf("%c", ch1);
			}
			if(isalpha(ch2 = toupper(fgetc(fp)) ) || ch2 == ' '){
				fprintf(fp1,"%c", ch2);
				printf("%c", ch2);
			}
			if(isalpha(ch_A = toupper(fgetc(fp)) ) || ch_A == ' '){
				fprintf(fp1,"%c", ch_A);
				printf("%c", ch_A);
			}
		}

		for(j = 0; j < OUTPUT; j++){
			random = (long)( rand() / (double)RAND_MAX * sum_char);

			fseek(fp, random, SEEK_SET);

			while( ( ch_temp = toupper(fgetc(fp)) ) != EOF && (sum_char-1) > ftell(fp)){			//最後まで走査し
				if( ch_A == ch_temp ){									//見つかったなら
					if( (ch_temp = toupper(fgetc(fp)) )!= EOF && (ch_A = toupper(fgetc(fp)) )!= EOF){
						//fprintf(fp1,"%c", ch_temp);
						//fprintf(fp1,"%c", ch_A);
						printf("%c", ch_temp);
						printf("%c", ch_A);
						break;
					}
				}
			}
		}
	}

	printf("\n");
	fclose(fp1);
	fclose(fp);

	return 0;
}
