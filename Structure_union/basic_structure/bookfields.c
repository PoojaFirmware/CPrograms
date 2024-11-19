// Create a structure for a book with fields like title, author, and price, and assign values to them.

#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    float price;
}books;

int main()
{
    // Assign the values
    strcpy(books.author, "Saker");
    books.price = 67.84;
    strcpy(books.title, "One Thing");

    printf("Book information:\n");
    printf("Title of the book: %s\n", books.title);
    printf("Book author: %s\n", books.author);
    printf("Book price: %.1f\n", books.price);
}
