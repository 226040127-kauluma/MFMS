#include <stdio.h>
#include "validation.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "employees.h"
/* TODO: add #include "reports.h" once their owner fix them */

static void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

static void notReady(const char *moduleName)
{
    printf("\n%s is not connected yet.\n", moduleName);
}

int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    int choice;

    do {
        displayMainMenu();
        choice = getMenuChoice(1, 6);

        switch (choice) {
            case 1: notReady("Employee Management");         break;
            case 2: budgetMenu();                            break;
            case 3: supplierMenu(suppliers, &supplierCount); break;
            case 4: handleAssetMenu(assets, &assetCount);    break;
            case 5: notReady("Reports");                     break;
            case 6: printf("\nGoodbye.\n");                  break;
        }
    } while (choice != 6);

    return 0;
}