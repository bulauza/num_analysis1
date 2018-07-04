#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define OUTPUT 100

long int char_counter(FILE *fp);
long int char_counter(FILE *fp){

	long int char_count = 0;

	fseek(fp, 0, SEEK_END);
	char_count = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	return char_count;
}

int main(void)
{

	char ch;			//ファイルから読んだ文字を格納
	long int char_count = 0;	//ファイルの全文字数.　改行文字含む.
	long int random = 0;		//乱数格納
	int i = 0;			//ループカウンタ

	FILE *fp;


	if( (fp = fopen("textdata_symbol_replace.txt", "r") ) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}

	char_count = char_counter(fp);

	srand((unsigned int)time(NULL));

	for(i = 0; i < OUTPUT; i++){		//OUTPUTの数、文字を出力

		random = (long)( rand() / (double)RAND_MAX * char_count);

		fseek(fp, random, SEEK_SET);				//先頭からrandom番目にアクセス

		if(isalpha(ch = toupper(fgetc(fp)) ) || ch == ' '){	//アルファベットもしくは記号の時出力
			printf("%c", ch);
		}
		else {							//やり直し
			i--;
		}
	}

	printf("\n\n");
	fclose(fp);

	return 0;
}
