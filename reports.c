#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "validation.h"

void displayAllReports(){
    int c; do{
        printf("\n=== REPORTS ===\n1.Employee Payroll\n2.Budget Summary\n3.Supplier List\n4.Asset Value\n5.All\n6.Back\nChoice: "); c=readInt();
        if(c==1 || c==5){
            printf("\n===== EMPLOYEE REPORT =====\n");
            float total=0; for(int i=0;i<employeeCount;i++) total+=employees[i].totalSalary;
            printf("Employees: %d | Total Payroll: N$%.2f\n",employeeCount,total);
        }
        if(c==2 || c==5){
            printf("\n===== BUDGET REPORT =====\n");
            float a=0,e=0; for(int i=0;i<budgetCount;i++){a+=budgets[i].allocated; e+=budgets[i].expenditure;}
            printf("Allocated: N$%.2f | Spent: N$%.2f | Remaining: N$%.2f\n",a,e,a-e);
        }
        if(c==3 || c==5) printf("\n===== SUPPLIER REPORT =====\nTotal Suppliers: %d\n",supplierCount);
        if(c==4 || c==5){
            float v=0; for(int i=0;i<assetCount;i++) v+=assets[i].value;
            printf("\n===== ASSET REPORT =====\nTotal Assets: %d | Total Value: N$%.2f\n",assetCount,v);
        }
    }while(c!=6);
}