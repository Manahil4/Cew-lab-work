Q1
#include <stdio.h>

void getter(int *a, int *b, int c);
int a, b, c;
int main()
{
    printf("A:");
    scanf("%d", &a);
    printf("B:");
    scanf("%d", &b);

    getter(&a, &b, c);

    printf("Before Swap A is %d and B is %d \nAfter Swap A is %d and B is %d", b, a, a, b);
    return 0;
}
void getter(int *a, int *b, int c)
{
    c = *a;
    *a = *b;
    *b = c;
}
Q2
#include <stdio.h>
char aos[200];

int main() {
    int n, i = 0;

    printf("No of characters in string: ");
    scanf("%d", &n);
    
    // Consume the newline character left in the input buffer
    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("%dth character: ", i);
        scanf(" %c", &aos[i]);
    }

    printf("String in reverse order: ");
    for (int j = n - 1; j >= 0; j--) {
        printf("%c", aos[j]);
    }

    return 0;
}
Q3
#include <stdio.h>

int main() {
    char str[100]; // Define a character array to store the string
    char *ptr;     // Declare a pointer to char

    printf("Enter a string: ");
    gets(str); // Read a string from the user (be cautious, gets() is not safe for input, but it's used here for simplicity)

    // Point the pointer 'ptr' to the beginning of the string
    ptr = str;

    // Print the string using the pointer
    printf("You entered: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++; // Move the pointer to the next character
    }

    return 0;
}
Q4
#include <stdio.h>

int main()
{
    char a[100];
    printf("Array:");
    char *ap = a;
    fgets(ap, 100, stdin);
    char sch;
    printf("Value to be search");
    scanf("%c", &sch);
    char *ps = &sch;
    int i;
    for (i = 0; *ap != '\0'; ++i)
    {
        if (*ap == *ps)
        {
            printf("value found at index %d", i);
            return 0;
        }

        ap = ap + 1;
    }
    printf("value not found");
    return 0;
}
Q5
#include <stdio.h>

int main()
{
    int M1[2][2] = {{1, 2}, {3, 4}};
    int M2[2][2] = {{1, 7}, {8, 9}};
    int *pM1 = &M1[0][0];
    int *pM2 = &M2[0][0];

    int add[2][2];
    int *pa = &add[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            *((pa + i *2)+ j) = *((pM1 + i *2) + j) + *((pM2 + i*2 )+ j);
        }
    }
    for (int h = 0; h < 2; h++)
    {
        for (int k = 0; k < 2; k++)
        {
            printf("%d\t", *(pa+h*2+k));
        }
        printf("\n");
    }
    return 0;
}
