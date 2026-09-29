#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "validation.h"
struct Budget budgets[MAX_BUDGETS];
int budgetCount=0;

void addBudget(){
    if(budgetCount>=MAX_BUDGETS){printf("Limit reached!\n"); return;}
    printf("\n--- Add Budget ---\nDept: "); readString(budgets[budgetCount].department,50);
    printf("Allocated: "); budgets[budgetCount].allocated=readFloat();
    printf("Expenditure: "); budgets[budgetCount].expenditure=readFloat();
    budgets[budgetCount].remaining=budgets[budgetCount].allocated-budgets[budgetCount].expenditure;
    if(budgets[budgetCount].remaining<0) strcpy(budgets[budgetCount].status,"OVER BUDGET");
    else strcpy(budgets[budgetCount].status,"WITHIN BUDGET");
    printf("Remaining N$%.2f %s\n",budgets[budgetCount].remaining,budgets[budgetCount].status);
    budgetCount++;
}
void displayBudgets(){
    if(budgetCount==0){printf("No budgets.\n"); return;}
    printf("\n%-15s %-12s %-12s %-12s %-15s\n","Dept","Allocated","Spent","Remaining","Status");
    for(int i=0;i<budgetCount;i++) printf("%-15s %-12.2f %-12.2f %-12.2f %-15s\n",budgets[i].department,budgets[i].allocated,budgets[i].expenditure,budgets[i].remaining,budgets[i].status);
}
void checkOverBudget(){
    int f=0; printf("\n--- Over Budget ---\n");
    for(int i=0;i<budgetCount;i++) if(budgets[i].remaining<0){printf("%s over by N$%.2f\n",budgets[i].department,-budgets[i].remaining); f=1;}
    if(!f) printf("All within budget.\n");
}
void displayBudgetMenu(){
    int c; do{
        printf("\n=== BUDGET ===\n1.Add\n2.Display\n3.Check Over\n4.Back\nChoice: "); c=readInt();
        switch(c){case 1:addBudget();break;case 2:displayBudgets();break;case 3:checkOverBudget();break;}
    }while(c!=4);
}