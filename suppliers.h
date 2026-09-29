#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#define MAX_SUPPLIERS 100
struct Supplier { int id; char name[50]; char email[50]; char phone[20]; char town[30]; };
extern struct Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;
void addSupplier(); void displaySuppliers(); void searchSupplier(); void displaySupplierMenu();
#endif