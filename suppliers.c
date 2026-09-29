#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "validation.h"
struct Supplier suppliers[MAX_SUPPLIERS];
int supplierCount=0;

void addSupplier(){
    if(supplierCount>=MAX_SUPPLIERS){printf("Limit reached!\n");return;}
    printf("\n--- Add Supplier ---\n");
    suppliers[supplierCount].id=5001+supplierCount;
    printf("Name: "); readString(suppliers[supplierCount].name,50);
    printf("Email: "); readString(suppliers[supplierCount].email,50);
    printf("Phone: "); readString(suppliers[supplierCount].phone,20);
    printf("Town: "); readString(suppliers[supplierCount].town,30);
    supplierCount++; printf("Supplier added!\n");
}
void displaySuppliers(){
    if(supplierCount==0){printf("No suppliers.\n");return;}
    printf("\n%-6s %-20s %-25s %-15s\n","ID","Name","Email","Town");
    for(int i=0;i<supplierCount;i++) printf("%-6d %-20s %-25s %-15s\n",suppliers[i].id,suppliers[i].name,suppliers[i].email,suppliers[i].town);
}
void searchSupplier(){
    char t[50]; printf("Search name/town: "); readString(t,50);
    int f=0; for(int i=0;i<supplierCount;i++) if(strstr(suppliers[i].name,t) || strcmp(suppliers[i].town,t)==0){printf("Found %d %s (%s)\n",suppliers[i].id,suppliers[i].name,suppliers[i].town); f=1;}
    if(!f) printf("Not found.\n");
}
void displaySupplierMenu(){
    int c; do{ printf("\n=== SUPPLIER ===\n1.Add\n2.Display\n3.Search\n4.Back\nChoice: "); c=readInt();
    switch(c){case 1:addSupplier();break;case 2:displaySuppliers();break;case 3:searchSupplier();break;}
    }while(c!=4);
}