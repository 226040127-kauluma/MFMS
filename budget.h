#ifndef BUDGET_H
#define BUDGET_H
#define MAX_BUDGETS 50
struct Budget { char department[50]; float allocated, expenditure, remaining; char status[20]; };
extern struct Budget budgets[MAX_BUDGETS];
extern int budgetCount;
void addBudget(); void displayBudgets(); void checkOverBudget(); void displayBudgetMenu();
#endif