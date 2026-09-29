#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "validation.h"
struct Asset assets[MAX_ASSETS];
int assetCount=0;

void addAsset(){
    if(assetCount>=MAX_ASSETS){printf("Limit reached!\n");return;}
    printf("\n--- Add Asset ---\n");
    assets[assetCount].id=7001+assetCount;
    printf("Asset name: "); readString(assets[assetCount].name,50);
    printf("Category: "); readString(assets[assetCount].category,30);
    printf("Value N$: "); assets[assetCount].value=readFloat();
    printf("Department: "); readString(assets[assetCount].department,30);
    assetCount++; printf("Asset added!\n");
}
void displayAssets(){
    if(assetCount==0){printf("No assets.\n");return;}
    printf("\n%-6s %-20s %-15s %-12s\n","ID","Name","Category","Value");
    for(int i=0;i<assetCount;i++) printf("%-6d %-20s %-15s %-12.2f\n",assets[i].id,assets[i].name,assets[i].category,assets[i].value);
}
void searchAsset(){
    char t[50]; printf("Search asset: "); readString(t,50);
    int f=0; for(int i=0;i<assetCount;i++) if(strstr(assets[i].name,t)!=NULL){printf("Found %d %s N$%.2f\n",assets[i].id,assets[i].name,assets[i].value); f=1;}
    if(!f) printf("Not found.\n");
}
void displayAssetMenu(){
    int c; do{ printf("\n=== ASSET ===\n1.Add\n2.Display\n3.Search\n4.Back\nChoice: "); c=readInt();
    switch(c){case 1:addAsset();break;case 2:displayAssets();break;case 3:searchAsset();break;}
    }while(c!=4);
}