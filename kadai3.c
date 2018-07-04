#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300000

int main(void)
{
	char word[20];		//ファイルから読み込んだ文字を格納
	int len = 0;		//読み込んだ文字の長さを格納

	char *list[MAX];	//読み込んだ単語をリスト
	int listed = 0;		//リスト済の数

	int num[MAX] = {};	//リスト単語の出現数

	int i;
	int fg = 1;

	FILE *fp;
	FILE *fp1;

	if( (fp = fopen("textdata_symbol_replace.txt", "r") ) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}
	if( (fp1 = fopen("textdata_word_analysis.txt", "w") ) == NULL) {
		fprintf(stderr, "Failed to open file．\n");
		return 0;
	}

	while((fscanf(fp, "%s", word) != EOF)){

		for(i = 0; i < listed; i++){			//リストに保存された文字列と比較
			if(strcasecmp(list[i], word) == 0){	//存在したら新規登録のフラグを折り、回数+1
				num[i]++;
				fg = 0;
			}

		}
		if(fg){						//リストに新規登録
			len = strlen(word);			//単語の長さ測定
			if(len > 20){	continue;
			}

			list[listed] = (char *)malloc( sizeof(char)*(len+1) );
			strcpy(list[listed], word);
			listed++;
		}
		fg = 1;
		i++;
	}

	for(i = 0; i < listed; i++){
		fprintf(fp1, "%-30s%d\n", list[i], num[i]+1);
		free(list[i]);
	}

	printf("(Fin)\n");

	fclose(fp1);
	fclose(fp);

	return 0;
}
