#include <stdio.h>

int main()
{
    int assetID[100];
    char assetName[100][50];
    char assetType[100][30];
    float purchaseValue[100];
    char department[100][30];
    char condition[100][30];

    int choice;
    int count = 0;
    int searchID;
    int found;
    int i;

    {
        printf("\n====================================\n");
        printf("       ASSET MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter Asset ID: ");
            scanf("%d", &assetID[count]);

            printf("Enter Asset Name: ");
            scanf(" %[^\n]", assetName[count]);

            printf("Enter Asset Type: ");
            scanf(" %[^\n]", assetType[count]);

            printf("Enter Purchase Value: N$");
            scanf("%f", &purchaseValue[count]);

            printf("Enter Department: ");
            scanf(" %[^\n]", department[count]);

            printf("Enter Condition: ");
            scanf(" %[^\n]", condition[count]);

            count++;

            printf("\nAsset added successfully!\n");
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("\nNo assets have been registered.\n");
            }
            else
            {
                printf("\n========== REGISTERED ASSETS ==========\n");

                for (i = 0; i < count; i++)
                {
                    printf("\nAsset %d\n", i + 1);
                    printf("Asset ID: %d\n", assetID[i]);
                    printf("Asset Name: %s\n", assetName[i]);
                    printf("Asset Type: %s\n", assetType[i]);
                    printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
                    printf("Department: %s\n", department[i]);
                    printf("Condition: %s\n", condition[i]);
                }
            }
        }

        else if (choice == 3)
        {
            printf("\nEnter Asset ID to search: ");
            scanf("%d", &searchID);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (assetID[i] == searchID)
                {
                    printf("\n========== ASSET FOUND ==========\n");
                    printf("Asset ID: %d\n", assetID[i]);
                    printf("Asset Name: %s\n", assetName[i]);
                    printf("Asset Type: %s\n", assetType[i]);
                    printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
                    printf("Department: %s\n", department[i]);
                    printf("Condition: %s\n", condition[i]);

                    found = 1;
                }
            }

            if (found == 0)
            {
                printf("\nAsset not found.\n");
            }
        }

        else if (choice == 4)
        {
            printf("\nExiting Asset Management System...\n");
        }

        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
