#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"
struct Employee employees[MAX_EMPLOYEES];
int employeeCount=0;

void addEmployee(){
    if(employeeCount>=MAX_EMPLOYEES){printf("Limit reached!\n"); return;}
    printf("\n--- Add Employee ---\n");
    employees[employeeCount].id=1001+employeeCount;
    printf("Name: "); readString(employees[employeeCount].name,50);
    printf("Department: "); readString(employees[employeeCount].department,30);
    printf("Basic Salary: "); employees[employeeCount].basicSalary=readFloat();
    printf("Housing: "); employees[employeeCount].housingAllowance=readFloat();
    printf("Transport: "); employees[employeeCount].transportAllowance=readFloat();
    employees[employeeCount].totalSalary=employees[employeeCount].basicSalary+employees[employeeCount].housingAllowance+employees[employeeCount].transportAllowance;
    printf("Added ID %d Total N$%.2f\n",employees[employeeCount].id,employees[employeeCount].totalSalary);
    employeeCount++;
}
void displayEmployees(){
    if(employeeCount==0){printf("No employees.\n"); return;}
    printf("\n%-6s %-20s %-12s %-10s\n","ID","Name","Dept","Total");
    for(int i=0;i<employeeCount;i++) printf("%-6d %-20s %-12s %-10.2f\n",employees[i].id,employees[i].name,employees[i].department,employees[i].totalSalary);
}
void searchEmployee(){
    char term[50]; printf("Search name: "); readString(term,50);
    int found=0;
    for(int i=0;i<employeeCount;i++){
        if(strstr(employees[i].name,term)!=NULL || strcmp(employees[i].name,term)==0){
            printf("Found: %d %s %s N$%.2f\n",employees[i].id,employees[i].name,employees[i].department,employees[i].totalSalary);
            found=1;
        }
    }
    if(!found) printf("Not found.\n");
}
void displayEmployeeMenu(){
    int c; do{
        printf("\n=== EMPLOYEE ===\n1.Add\n2.Display\n3.Search\n4.Back\nChoice: "); c=readInt();
        switch(c){case 1:addEmployee();break;case 2:displayEmployees();break;case 3:searchEmployee();break;}
    }while(c!=4);
}