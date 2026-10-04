#include <stdio.h>
#include "../assets.h"

int main(void) {
    Asset assets[MAX_ASSETS];
    int   assetCount = 0;
    int   choice;

    do {
        printf("\n--- TEST: ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Asset Summary\n");
        printf("5. Exit Test\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1: addAsset(assets, &assetCount); break;
            case 2: displayAssets(assets, assetCount); break;
            case 3: searchAssetMenu(assets, assetCount); break;
            case 4:
                if (assetCount == 0) printf("No assets.\n");
                else {
                    printf("Total:   N$%.2f\n", getTotalAssetValue(assets, assetCount));
                    printf("Average: N$%.2f\n", getAverageAssetValue(assets, assetCount));
                    printf("Highest: N$%.2f\n", getHighestAssetValue(assets, assetCount));
                    printf("Lowest:  N$%.2f\n", getLowestAssetValue(assets, assetCount));
                }
                break;
            case 5: printf("Exiting test.\n"); break;
            default: printf("Invalid.\n");
        }
    } while (choice != 5);

    return 0;
}