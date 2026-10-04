#include <stdio.h>
#include "validation.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "employees.h"
#include "reports.h"

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

static void reportsMenu(int employeeCount, Supplier suppliers[],
                        int supplierCount, Asset assets[], int assetCount)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("                REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        choice = getMenuChoice(1, 5);

        switch (choice) {
            case 1: displayEmployeeReport(employeeCount);            break;
            case 2: displayBudgetReport();                           break;
            case 3: displaySupplierReport(suppliers, supplierCount); break;
            case 4: displayAssetReport(assets, assetCount);          break;
            case 5: printf("\nReturning to main menu...\n");         break;
        }
    } while (choice != 5);
}

int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    int employeeCount = 0;

    int choice;

    do {
        displayMainMenu();
        choice = getMenuChoice(1, 6);

        switch (choice) {
            case 1: notReady("Employee Management");         break;
            case 2: budgetMenu();                            break;
            case 3: supplierMenu(suppliers, &supplierCount); break;
            case 4: handleAssetMenu(assets, &assetCount);    break;
            case 5: reportsMenu(employeeCount, suppliers, supplierCount,
                                assets, assetCount);
                    break;
            case 6: printf("\nGoodbye.\n");                  break;
        }
    } while (choice != 6);

    return 0;
}
