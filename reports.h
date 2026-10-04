#ifndef REPORTS_H
#define REPORTS_H

#include "assets.h"
#include "suppliers.h"

/* ---------- Report summary structures ---------- */

typedef struct {
    int   count;
    float totalSalary;
    float averageSalary;
    float highestSalary;
    float lowestSalary;
    int   highestIndex;      /* position in the employee arrays */
    int   lowestIndex;
} EmployeeSummary;

typedef struct {
    int    departments;
    double totalAllocated;
    double totalSpent;
    double totalRemaining;
    int    exceeded;         /* departments over budget */
} BudgetSummary;

typedef struct {
    int count;
    int locations;           /* number of distinct locations */
} SupplierSummary;

typedef struct {
    int    count;
    double total;
    double average;
    double highest;
    double lowest;
    int    excellent;
    int    good;
    int    fair;
    int    poor;
} AssetSummary;

/* ---------- Summary builders (calculations) ---------- */

EmployeeSummary buildEmployeeSummary(int employeeCount);
BudgetSummary   buildBudgetSummary(void);
SupplierSummary buildSupplierSummary(const Supplier suppliers[], int count);
AssetSummary    buildAssetSummary(Asset assets[], int count);

/* ---------- Report display ---------- */

void reportEmployees(int employeeCount);
void reportBudget(void);
void reportSuppliers(const Supplier suppliers[], int count);
void reportAssets(Asset assets[], int count);
void reportOverview(int employeeCount, const Supplier suppliers[],
                    int supplierCount, Asset assets[], int assetCount);

/* ---------- Reports menu ---------- */

void reportsMenu(int employeeCount, const Supplier suppliers[],
                 int supplierCount, Asset assets[], int assetCount);

#endif /* REPORTS_H */
