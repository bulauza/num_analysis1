#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char DAT[10000000];
int DAT_SIZE;

char STR[10000][20+1];
int COUNT[10000];
int STR_SIZE;

int inp();
int one();
int four();
int five();
int six();
int seven1();
int seven2();
int save(char *str);
int outp();

int main(int argc, char *argv[])
{
    inp();
    if(strcmp(argv[1], "-1")==0){
    one();
    outp();
    }
    if(strcmp(argv[1], "-4")==0){   
    four();
    outp();
    }
    if(strcmp(argv[1], "-5")==0){
    five();
    outp();
    }
    if(strcmp(argv[1], "-6")==0){
    six();
    }
    if(strcmp(argv[1], "-s1")==0){
    seven1();
    }
    if(strcmp(argv[1], "-s2")==0){
    seven2();
    }
}

int inp()
{
    int c=0;
    int i=0;
    while(1){
    c=getchar();
    if(c==EOF){
    break;
    }
    if(c==' '){
    DAT[i]='_';
    i++;
    continue;
    }
    if(c=='\n'){
    DAT[i]='_';
    continue;
    }
    if(isalpha(c)){
    DAT[i]=c;
    i++;
    } else {
    }
    }
    DAT_SIZE=i;
}

int one()
{
    int i;
    char str[1+1];
    for(i=0; i<DAT_SIZE; i++){
    str[0]=DAT[i];
    str[1]='\0';
    save(str);
    }
}

int four()
{
    int i;
    char str[2+1];
    for(i=0; i<DAT_SIZE-1; i++){
    str[0]=DAT[i];
    str[1]=DAT[i+1];
    str[2]='\0';
    save(str);
    }
}

int five()
{
    int i;
    char str[3+1];
    for(i=0; i<DAT_SIZE-2; i++){
    str[0]=DAT[i];
    str[1]=DAT[i+1];
    str[2]=DAT[i+2];
    str[3]='\0';
    save(str);
    }
}

int six()
{
    int i;
    int k;
    srand((unsigned)time(NULL));
    printf("\n");
    for(i=0; i<100; i++){
    k=rand()%DAT_SIZE;
        if(DAT[k]=='_'){
        printf("%c", ' ');
        } else {
        printf("%c", DAT[k]);
        }
    }
}

int seven1()
{
    int i;
    int k;
    int A;
    srand((unsigned)time(NULL));
    printf("\n");
    k=rand()%(DAT_SIZE-1);
    if(DAT[k]=='_'){
    printf("%c", ' ');
    } else {
    printf("%c", DAT[k]);
    }
    if(DAT[k+1]=='_'){
    printf("%c", ' ');
    } else {
    printf("%c", DAT[k+1]);
    }
    i=2;
    A=DAT[k+1];
    while(1){
    k=rand()%(DAT_SIZE-1);
    for(k=k+1; k<DAT_SIZE-1; k++){
        if(DAT[k]==A){
        if(DAT[k+1]=='_'){
            printf("%c", ' ');
            i++;
        } else {
            printf("%c", DAT[k+1]);
            i++;
        }
        if(i<100){
            A=DAT[k+1];
            break;
        } else {
            printf("\n\n");
            return 0;
        }
        }
    }
    }
}

int seven2()
{
    int i;
    int k;
    int A;
    int B;
    srand((unsigned)time(NULL));
    printf("\n");
    k=rand()%(DAT_SIZE-3);
    if(DAT[k]=='_'){
    printf("%c", ' ');
    } else {
    printf("%c", DAT[k]);
    }
    if(DAT[k+1]=='_'){
    printf("%c", ' ');
    } else {
    printf("%c", DAT[k+1]);
    }
    if(DAT[k+2]=='_'){
    printf("%c", ' ');
    } else {
    printf("%c", DAT[k+2]);
    }
    i=3;
    A=DAT[k+1];
    B=DAT[k+2];
    while(1){
    k=rand()%(DAT_SIZE-3);
    for(k=k+1; k<DAT_SIZE-3; k++){
        if(DAT[k]==A && DAT[k+1]==B){
        if(DAT[k+2]=='_'){
            printf("%c", ' ');
            i++;
        } else {
            printf("%c", DAT[k+2]);
            i++;
        }
        if(i<100){
            A=DAT[k+1];
            B=DAT[k+2];
            break;
        } else {
            printf("\n\n");
            return 0;
        }
        }
    }
    }
}

int save(char *str)
{
    int i;
 
    for(i=0; i<STR_SIZE; i++){
    if(strcmp(STR[i], str)==0){
        COUNT[i]++;
        return 0;
    }
    }
    strcpy(STR[STR_SIZE], str);
    COUNT[STR_SIZE]=1;
    STR_SIZE++;
}

int outp()
{
    int i;
 
    printf("\n");
    for(i=0; i<STR_SIZE; i++){
    printf("%s %06d\n" , STR[i], COUNT[i]);
    }
    printf("\n");
}
