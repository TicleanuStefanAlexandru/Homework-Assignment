#include <stdio.h>
#include <stdlib.h>

// Structure to represent a book
typedef struct {
    int pages;
} Book;

// Function to calculate the sum of pages in an array of books
int totalPages(Book books[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += books[i].pages;
    }
    return total;
}

// Function to find the optimal division of books among employees
void distributeBooks(Book books[], int n) {
    int total_pages = totalPages(books, n);
    float target = total_pages / 3;
    int current_sum = 0;
    int employee_count = 1;

    printf("Division of books:\n");
    printf("Employee 1: ");
    for (int i = 0; i < n; i++) {
        if (current_sum + books[i].pages <= target || employee_count == 3) {
            current_sum += books[i].pages;
            printf("%d ", books[i].pages);
        } else {
            current_sum = books[i].pages;
            employee_count++;
            printf("\nEmployee %d: %d ", employee_count, books[i].pages);
        }
    }
}

int main() {
    int num_books;

    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    Book *books = (Book*)malloc(num_books * sizeof(Book));

    printf("Enter the number of pages for each book:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book %d: ", i + 1);
        scanf("%d", &books[i].pages);
    }

    distributeBooks(books, num_books);

    free(books);

    return 0;
}

