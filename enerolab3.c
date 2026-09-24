#include <stdio.h>

int main() {
    // Variables for grocery
    char product[100][100];
    int quantity[100];
    float price[100];
    
    float total = 0.00;
    float discount = 0.00;
    float finalTotal;
    float payment;
    float change;
    
    int moreItems;
    int status;
    int itemCount = 0;
    int totalItems = 0;
    int nextCustomer;

    // Loop for multiple customers
    do {
        // Reset values for new customer
        total = 0.00;
        discount = 0.00;
        finalTotal = 0.00;
        itemCount = 0;
        totalItems = 0;

        printf("\n==================================================\n");
        printf("              GIANNE'S GROCERY STORE\n");
        printf("==================================================\n");
        
        // Enter grocery items
        do {
            printf("Enter product name: ");
            scanf(" %99[^\n]", product[itemCount]);

            printf("Enter quantity: ");
            scanf("%d", &quantity[itemCount]);

            printf("Enter price: ");
            scanf("%f", &price[itemCount]);

            // Calculate total
            total = total + (quantity[itemCount] * price[itemCount]);

            // Count total quantity of items
            totalItems = totalItems + quantity[itemCount];

            itemCount++;

            printf("Are there more items? (1 = Yes, 0 = No): ");
            scanf("%d", &moreItems);

            printf("\n");

        } while (moreItems == 1);

        // Ask for customer status
        printf("Customer status:\n");
        printf("1 - PWD\n");
        printf("2 - Senior Citizen\n");
        printf("3 - Pregnant\n");
        printf("4 - None of the above\n");
        printf("Enter status: ");
        scanf("%d", &status);

        // Apply discount
        if (status == 1) {
            discount = total * 0.05;
        }
        else if (status == 2) {
            discount = total * 0.20;
        }
        else if (status == 3) {
            discount = 30.00;
        }
        else {
            discount = 0.00;
        }

        finalTotal = total - discount;

        if (finalTotal < 0) {
        finalTotal = 0;
    }
        // Display total items and cost (Order Summary)
        printf("\n================  ORDER  SUMMARY  ================\n");
       
        // Customer status
        if (status == 1) {
            printf("\nCustomer status: PWD\n");
        }
        else if (status == 2) {
            printf("\nCustomer status: Senior Citizen\n");
        }
        else if (status == 3) {
            printf("\nCustomer status: Pregnant\n");
        }
        else {
            printf("\nCustomer status: None of the above\n");
        }

        printf("Total items purchased: %d\n", totalItems);
        printf("Total cost before discount: %.2f\n", total);
        printf("Discount applied: %.2f\n", discount);
        printf("Total cost: %.2f\n", finalTotal);
        printf("Enter payment amount: ");
        scanf("%f", &payment);

        change = payment - finalTotal;


        // Receipt
        printf("\n================ CUSTOMER RECEIPT ================\n");

        printf("%-30s %-10s %-10s\n", "Item", "Quantity", "Price");
        printf("--------------------------------------------------\n");

        for (int i = 0; i < itemCount; i++) {
            printf("%-30s %-10d %.2f\n",
                product[i],
                quantity[i],
                price[i]);
        }

        printf("--------------------------------------------------\n");
        printf("%-42s", "Total cost: ");
        printf("%.2f\n", finalTotal);

        // Customer status
        if (status == 1) {
            printf("Customer status: PWD\n\n");
        }
        else if (status == 2) {
            printf("Customer status: Senior Citizen\n\n");
        }
        else if (status == 3) {
            printf("Customer status: Pregnant\n\n");
        }
        else {
            printf("Customer status: None of the above\n\n");
        }

        printf("Total items purchased: %d\n", totalItems);
        printf("Total cost before discount: %.2f\n", total);
        printf("Discount applied: %.2f\n", discount);

        printf("Payment amount: %.2f\n", payment);
        printf("Change: %.2f\n", change);

        printf("\nThank you for shopping with us!\n");
        printf("==================================================\n");

            // Ask for next customer
        printf("Press 1 for next customer, 0 to exit: ");
        scanf("%d", &nextCustomer);

    } while (nextCustomer == 1);

    printf("\nProgram ended. Have a nice day!\n");

    return 0;
}