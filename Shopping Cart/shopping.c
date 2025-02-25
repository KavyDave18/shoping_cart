#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10


struct Product {
    char name[50];
    float price;
    int quantity;
};


void addItem(struct Product cart[], int *itemCount);
void viewCart(struct Product cart[], int itemCount);
void removeItem(struct Product cart[], int *itemCount);

int main() {
    struct Product cart[MAX_ITEMS];
    int itemCount = 0;  
    int choice;

    do {

        printf("\n--- Simple Shopping Cart ---\n");
        printf("1. Add Item to Cart\n");
        printf("2. View Cart\n");
        printf("3. Remove Item from Cart\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(cart, &itemCount);
                break;
            case 2:
                viewCart(cart, itemCount);
                break;
            case 3:
                removeItem(cart, &itemCount);
                break;
            case 4:
                printf("Exiting the shopping cart system. Goodbye!\nThanks for visit\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


void addItem(struct Product cart[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Your cart is full. You cannot add more items.\n");
        return;
    }

    struct Product newItem;
    printf("\nEnter the name of the product: ");
    scanf(" %[^\n]", newItem.name);  
    printf("Enter the price of the product: ");
    scanf("%f", &newItem.price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newItem.quantity);

    cart[*itemCount] = newItem;  
    (*itemCount)++;  

    printf("\nProduct added successfully!\n");
}


void viewCart(struct Product cart[], int itemCount) {
    if (itemCount == 0) {
        printf("\nYour cart is empty.\n");
        return;
    }

    float totalPrice = 0.0;
    printf("\n--- Your Cart ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Product: %s\n", cart[i].name);
        printf("Price: RS.%.2f\n", cart[i].price);
        printf("Quantity: %d\n", cart[i].quantity);
        printf("Total: RS.%.2f\n\n", cart[i].price * cart[i].quantity);

        totalPrice += cart[i].price * cart[i].quantity;  
    }

    printf("Total Cost: $%.2f\n", totalPrice);
}


void removeItem(struct Product cart[], int *itemCount) {
    if (*itemCount == 0) {
        printf("\nYour cart is empty. No items to remove.\n");
        return;
    }

    char itemName[50];
    printf("\nEnter the name of the product to remove: ");
    scanf(" %[^\n]", itemName);

    int found = 0;
    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(cart[i].name, itemName) == 0) {
            found = 1;

            for (int j = i; j < *itemCount - 1; j++) {
                cart[j] = cart[j + 1];
            }
            (*itemCount)--;  
            printf("\nProduct removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in your cart.\n");
    }
}
