#include <stdio.h>
#include <string.h>
#include "validation.h"

int readInt(){
    int v; char b[100];
    while(1){
        if(fgets(b,100,stdin) && sscanf(b,"%d",&v)==1 && v>=0) return v;
        printf("Invalid! Enter a valid number: ");
    }
}
float readFloat(){
    float v; char b[100];
    while(1){
        if(fgets(b,100,stdin) && sscanf(b,"%f",&v)==1 && v>=0) return v;
        printf("Invalid! Enter valid amount: ");
    }
}
void readString(char *dest, int maxLen){
    char b[200];
    fgets(b,200,stdin);
    b[strcspn(b,"\n")]=0;
    if(strlen(b)==0) strcpy(dest,"Unknown");
    else { strncpy(dest,b,maxLen-1); dest[maxLen-1]='\0'; }
}