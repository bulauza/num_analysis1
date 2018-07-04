#include <stdio.h>
#include <ctype.h>

#define SELECT 3

int main(void)
{
	int ch;					//読み込んだ文字コードを格納
	int counter[256] = {};			//文字コードと対応

	/*long int counter_total_ch = 0;*/		//全文字数をカウント. 出現割合を算出する用.　課題には必要ないのでコメントアウト.

	FILE *fp;

	switch(SELECT){
		case 1 :
			if( (fp = fopen("textdata_symbol_replace.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 2 :
			if( (fp = fopen("textdata2_symbol_replace.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 3 :
			if( (fp = fopen("textdata3_symbol_replace.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 4 :
			if( (fp = fopen("textdata4_symbol_replace.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		default : 
			puts("\nCan't find it");
			return 0;
	}

	while( (ch = toupper(fgetc(fp)) ) != EOF){	//アルファベットをカウント. すべて大文字としてカウント
		if(ch != '\n'){
		//	counter_total_ch++;

			if(ch == ' '){			//空白はアンダースコアとしてカウント
				counter['_']++;
				continue;
			}

			counter[ch]++;
		}
	}

	for(ch = 0; ch < 256; ch++){
		if(counter[ch] > 0){
			printf("  %-5c%-10d\n",ch , counter[ch]);
			/*printf("  %-5c%-10d\t%f\n",ch , counter[ch], (double)(counter[ch]*100)/counter_total_ch);*/	//出現割合(%)も表示.
		}
	}

	fclose(fp);

	return 0;
}
