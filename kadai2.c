#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int select = 0;		//解析対象判断フラグ
	FILE *fp;
	FILE *fp1;

	puts("\nWhich book do you want to analyze?");
	printf("\n 1: Dracula\n 2: Grimm stories(English)\n 3: Grimm stories(German)\n 4: Bible\n-> ");
	scanf("%d", &select);

	switch(select){
		case 1 :
			if( (fp = fopen("textdata.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			if( (fp1 = fopen("textdata_symbol_replace.txt", "w")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 2 :
			if( (fp = fopen("textdata2.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}
			if( (fp1 = fopen("textdata2_symbol_replace.txt", "w")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 3 :
			if( (fp = fopen("textdata3.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}
			if( (fp1 = fopen("textdata3_symbol_replace.txt", "w")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		case 4 :
			if( (fp = fopen("textdata4.txt", "r")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}
			if( (fp1 = fopen("textdata4_symbol_replace.txt", "w")) == NULL) {
				fprintf(stderr, "Failed to open file．\n");
				return 0;
			}

			break;

		default : 
			puts("\nCan't find it");
			return 0;
	}

	while((ch = fgetc(fp)) != EOF){

		if(ch == '\n'){
			fprintf(fp1,"%c", ch);
		}
		else if(isalpha(ch)){
			fprintf(fp1,"%c", ch);
		}
		else{
			fprintf(fp1," ");
		}
	}

	fclose(fp1);
	fclose(fp);

	return 0;
}
