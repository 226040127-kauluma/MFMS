#ifndef ASSETS_H
#define ASSETS_H
#define MAX_ASSETS 100
struct Asset { int id; char name[50]; char category[30]; float value; char department[30]; };
extern struct Asset assets[MAX_ASSETS];
extern int assetCount;
void addAsset(); void displayAssets(); void searchAsset(); void displayAssetMenu();
#endif