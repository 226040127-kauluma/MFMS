#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "validation.h"

int main(){
    int choice;
    printf("Welcome to MFMS - Municipal Financial Management System\n");
    do{
        printf("\n========================================\nMUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n========================================\n");
        printf("1. Employee Management\n2. Budget Management\n3. Supplier Management\n4. Asset Management\n5. Reports\n6. Exit\nEnter choice: ");
        choice=readInt();
        switch(choice){
            case 1: displayEmployeeMenu(); break;
            case 2: displayBudgetMenu(); break;
            case 3: displaySupplierMenu(); break;
            case 4: displayAssetMenu(); break;
            case 5: displayAllReports(); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid! Choose 1-6\n");
        }
    }while(choice!=6);
    return 0;
}