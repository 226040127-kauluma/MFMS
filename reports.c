#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

/* ---------- Helpers ---------- */

static int readReportChoice(void)
{
    char line[32];
    char *end;
    long value;

    printf("Enter your choice: ");
    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return 6;   /* input closed: leave the menu */
    }

    value = strtol(line, &end, 10);
    if (end == line || (*end != '\n' && *end != '\0'))
    {
        return -1;
    }
    return (int)value;
}

static void printReportTitle(const char *title)
{
    printf("\n========================================\n");
    printf(" %s\n", title);
    printf("========================================\n");
}

/* ---------- Summary builders ---------- */

EmployeeSummary buildEmployeeSummary(int employeeCount)
{
    EmployeeSummary s = {0};
    int i;
    float salary;

    s.count = employeeCount;
    if (employeeCount <= 0)
    {
        return s;
    }

    for (i = 0; i < employeeCount; i++)
    {
        salary = calculateSalary(basicSalary[i], housingAllowance[i],
                                 transportAllowance[i], otherAllowance[i]);
        s.totalSalary += salary;

        if (i == 0 || salary > s.highestSalary)
        {
            s.highestSalary = salary;
            s.highestIndex = i;
        }
        if (i == 0 || salary < s.lowestSalary)
        {
            s.lowestSalary = salary;
            s.lowestIndex = i;
        }
    }

    s.averageSalary = s.totalSalary / employeeCount;
    return s;
}

BudgetSummary buildBudgetSummary(void)
{
    BudgetSummary s;

    s.departments    = getDepartmentCount();
    s.totalAllocated = getTotalAllocated();
    s.totalSpent     = getTotalExpenditure();
    s.totalRemaining = getTotalRemaining();
    s.exceeded       = countExceededDepartments();
    return s;
}

SupplierSummary buildSupplierSummary(const Supplier suppliers[], int count)
{
    SupplierSummary s = {0};
    int i;
    int j;
    int seen;

    s.count = count;

    for (i = 0; i < count; i++)
    {
        seen = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(suppliers[i].location, suppliers[j].location) == 0)
            {
                seen = 1;
                break;
            }
        }
        if (seen == 0)
        {
            s.locations++;
        }
    }
    return s;
}

AssetSummary buildAssetSummary(Asset assets[], int count)
{
    AssetSummary s = {0};

    s.count = count;
    if (count <= 0)
    {
        return s;
    }

    s.total     = getTotalAssetValue(assets, count);
    s.average   = getAverageAssetValue(assets, count);
    s.highest   = getHighestAssetValue(assets, count);
    s.lowest    = getLowestAssetValue(assets, count);
    s.excellent = countAssetsByCondition(assets, count, "Excellent");
    s.good      = countAssetsByCondition(assets, count, "Good");
    s.fair      = countAssetsByCondition(assets, count, "Fair");
    s.poor      = countAssetsByCondition(assets, count, "Poor");
    return s;
}

/* ---------- Individual reports ---------- */

void reportEmployees(int employeeCount)
{
    EmployeeSummary s;
    int i;
    float salary;

    printReportTitle("EMPLOYEE REPORT");

    if (employeeCount <= 0)
    {
        printf("No employees registered.\n");
        return;
    }

    s = buildEmployeeSummary(employeeCount);

    printf("%-6s %-20s %-15s %15s\n", "ID", "Name", "Department",
           "Salary (N$)");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < employeeCount; i++)
    {
        salary = calculateSalary(basicSalary[i], housingAllowance[i],
                                 transportAllowance[i], otherAllowance[i]);
        printf("%-6d %-20.20s %-15.15s %15.2f\n",
               employeeID[i], employeeName[i], department[i], salary);
    }

    printf("\nTotal Employees:  %d\n", s.count);
    printf("Total Salaries:   N$%.2f\n", s.totalSalary);
    printf("Average Salary:   N$%.2f\n", s.averageSalary);
    printf("Highest Salary:   N$%.2f (%s)\n", s.highestSalary,
           employeeName[s.highestIndex]);
    printf("Lowest Salary:    N$%.2f (%s)\n", s.lowestSalary,
           employeeName[s.lowestIndex]);
}

void reportBudget(void)
{
    /* The budget module already owns its data, so reuse its report. */
    displayBudgetReport();
}

void reportSuppliers(const Supplier suppliers[], int count)
{
    SupplierSummary s;
    int i;

    printReportTitle("SUPPLIER REPORT");

    if (count <= 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    s = buildSupplierSummary(suppliers, count);

    printf("%-6s %-20s %-15s %-15s\n", "ID", "Name", "Phone", "Location");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
    {
        printf("%-6d %-20.20s %-15.15s %-15.15s\n",
               suppliers[i].supplierID, suppliers[i].name,
               suppliers[i].phone, suppliers[i].location);
    }

    printf("\nTotal Suppliers:    %d\n", s.count);
    printf("Distinct Locations: %d\n", s.locations);
}

void reportAssets(Asset assets[], int count)
{
    AssetSummary s;
    int i;

    printReportTitle("ASSET REPORT");

    if (count <= 0)
    {
        printf("No assets registered.\n");
        return;
    }

    s = buildAssetSummary(assets, count);

    printf("%-8s %-18s %-12s %14s %-10s\n", "ID", "Name", "Type",
           "Value (N$)", "Condition");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
    {
        printf("%-8.8s %-18.18s %-12.12s %14.2f %-10.10s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].condition);
    }

    printf("\nTotal Assets:    %d\n", s.count);
    printf("Total Value:     N$%.2f\n", s.total);
    printf("Average Value:   N$%.2f\n", s.average);
    printf("Highest Value:   N$%.2f\n", s.highest);
    printf("Lowest Value:    N$%.2f\n", s.lowest);
    printf("\nCondition Breakdown:\n");
    printf("  Excellent: %d\n", s.excellent);
    printf("  Good:      %d\n", s.good);
    printf("  Fair:      %d\n", s.fair);
    printf("  Poor:      %d\n", s.poor);
}

void reportOverview(int employeeCount, const Supplier suppliers[],
                    int supplierCount, Asset assets[], int assetCount)
{
    EmployeeSummary e = buildEmployeeSummary(employeeCount);
    BudgetSummary   b = buildBudgetSummary();
    SupplierSummary s = buildSupplierSummary(suppliers, supplierCount);
    AssetSummary    a = buildAssetSummary(assets, assetCount);

    printReportTitle("MUNICIPAL OVERVIEW");

    printf("Employees:  %d (total salaries N$%.2f)\n",
           e.count, e.totalSalary);

    printf("Budget:     %d department(s), allocated N$%.2f, spent N$%.2f\n",
           b.departments, b.totalAllocated, b.totalSpent);
    printf("            remaining N$%.2f, over budget: %d\n",
           b.totalRemaining, b.exceeded);
    if (b.totalAllocated > 0)
    {
        printf("            %.1f%% of the total allocation used\n",
               (b.totalSpent / b.totalAllocated) * 100.0);
    }

    printf("Suppliers:  %d in %d location(s)\n", s.count, s.locations);

    printf("Assets:     %d (total value N$%.2f)\n", a.count, a.total);
    if (a.poor > 0)
    {
        printf("            %d asset(s) in Poor condition\n", a.poor);
    }
}

/* ---------- Reports menu ---------- */

void reportsMenu(int employeeCount, const Supplier suppliers[],
                 int supplierCount, Asset assets[], int assetCount)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Municipal Overview\n");
        printf("6. Back to Main Menu\n");

        choice = readReportChoice();

        switch (choice)
        {
            case 1:
                reportEmployees(employeeCount);
                break;
            case 2:
                reportBudget();
                break;
            case 3:
                reportSuppliers(suppliers, supplierCount);
                break;
            case 4:
                reportAssets(assets, assetCount);
                break;
            case 5:
                reportOverview(employeeCount, suppliers, supplierCount,
                               assets, assetCount);
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);
}

