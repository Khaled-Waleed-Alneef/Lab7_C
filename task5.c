#include <stdio.h>
#include <string.h>

int N = 0;

typedef struct {
    int bookID, year;
    char title[100], author[100];
    float price;
} Book;

void loadBookData(Book arr[]);
void saveBookData(Book arr[]);
void inputBookData(Book arr[]);
void displayBookData(Book arr[]);
void findBookByID(Book arr[]);
void calculateTotalValue(Book arr[]);

int main() {
    int choice;
    Book arr[100];

    loadBookData(arr);

    while (1) {
        printf("\nLibrary Management System\n1. Add a Book\n2. Display All Books\n3. Search for Book by ID\n4. Calculate Total Value of Books\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBookData(arr);
                saveBookData(arr);
                break;
            case 2:
                displayBookData(arr);
                break;
            case 3:
                findBookByID(arr);
                break;
            case 4:
                calculateTotalValue(arr);
                break;
            case 5:
                return 0;
            default:
                printf("\nWrong Choice !!!");
        }
    }

    return 0;
}

void loadBookData(Book arr[]) {
    FILE *fp = fopen("books.dat", "rb");  // Open in binary mode
    if (fp == NULL) {
        printf("\nNo Existing Data Found\n");
        return;
    }

    
    while (fread(&arr[N], sizeof(Book), 1, fp) == 1) {
        N++;
    }

    fclose(fp);

    if (N == 0) {
        printf("\nNo books were loaded. Check the file format.\n");
    } else {
        printf("\nLoaded %d books successfully.\n", N);
    }
}

void saveBookData(Book arr[]) {
    FILE *fp = fopen("books.dat", "wb");  // Open in binary mode
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Write the number of books first
    for (int i = 0; i < N; i++) {
        fwrite(&arr[i], sizeof(Book), 1, fp);  // Write each book
    }

    fclose(fp);
}

void inputBookData(Book arr[]) {
    printf("Enter Book ID: ");
    scanf("%d", &arr[N].bookID);
    printf("Enter Year: ");
    scanf("%d", &arr[N].year);
    printf("Enter Title: ");
    getchar();
    fgets(arr[N].title, sizeof(arr[N].title), stdin);
    arr[N].title[strcspn(arr[N].title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(arr[N].author, sizeof(arr[N].author), stdin);
    arr[N].author[strcspn(arr[N].author, "\n")] = 0;
    printf("Enter Price: ");
    scanf("%f", &arr[N].price);
    N++;
}

void displayBookData(Book arr[]) {
    printf("\nList of Books:\n");
    for (int i = 0; i < N; i++) {
        printf("ID: %d, Year: %d, Title: %s, Author: %s, Price: %.2f\n", arr[i].bookID, arr[i].year, arr[i].title, arr[i].author, arr[i].price);
    }
}

void findBookByID(Book arr[]) {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < N; i++) {
        if (arr[i].bookID == id) {
            printf("Book found: ID: %d, Year: %d, Title: %s, Author: %s, Price: %.2f\n", arr[i].bookID, arr[i].year, arr[i].title, arr[i].author, arr[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void calculateTotalValue(Book arr[]) {
    float total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i].price;
    }
    printf("Total value of all books: %.2f\n", total);
}
