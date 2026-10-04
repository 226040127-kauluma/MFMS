
#ifndef REPORTS_H 
#define REPORTS_H
#include "suppliers.h" 
#include "assets.h"
void displayEmployeeReport(int count);
void displayBudgetReport (void); 
void displaySupplierReport(Supplier suppliers[],int count); 
void displayAssetReport (Asset assets[],int count);
#endif
