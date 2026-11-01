
#include <stdio.h>
#include <string.h>


int main(){
    int choice;
    int quantity;
    int total = 0;
    int price[5] = {100, 150, 80, 120, 50};
    int order[5] = {0, 0, 0, 0, 0};
    char name[30];
    int i;

    float gst;
    float discount;
    float finalBill;

    
    printf("================================\n");
    printf("================================\n");
    printf("   RESTAURANT MANAGEMENT SYSTEM\n");
    printf("================================\n");
    printf("================================\n");

    printf("Enter Customer Name: ");
    fgets(name, sizeof(name), stdin);
    

    for(i = 0; i < 5; i++)
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Burger       - Rs.100\n");
        printf("2. Pizza        - Rs.150\n");
        printf("3. Sandwich     - Rs.80\n");
        printf("4. Pasta        - Rs.120\n");
        printf("5. Cold Drink   - Rs.50\n");
        printf("6. Generate Bill\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 0)
        {
            printf("Thank you!\n");
            break;
        }

        if(choice == 6)
        {
            break;
        }

        if(choice < 1 || choice > 5)
        {
            printf("Invalid Choice!\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        if(quantity <= 0)
        {
            printf("Invalid Quantity!\n");
            continue;
        }

        order[choice - 1] += quantity;

        printf("Item Added Successfully!\n");
    }

    printf("\n========== FINAL BILL ==========\n");
    printf("Customer Name: %s\n", name);

    for(i = 0; i < 5; i++)
    {
        if(order[i] > 0)
        {
            printf("Item %d x %d = Rs.%d\n",
            i + 1, order[i], order[i] * price[i]);

            total = total + order[i] * price[i];
        }
    }

    printf("\nTotal Amount: Rs.%d\n", total);

    discount = 0;

    if(total >= 500)
    {
        discount = total * 10 / 100;
    }

    printf("Discount: Rs.%.2f\n", discount);
    

    gst = (total - discount) * 5 / 100;

    printf("GST : Rs.%.2f\n", gst);

    finalBill = total - discount + gst;

    printf("-------------------------------\n");
    printf("Final Bill: Rs.%.2f\n", finalBill);
    printf("-------------------------------\n");

    printf("Thank You! Visit Again.\n");

    return 0;
}
