#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{   
    // Script
    char logic[100];
    // Booleans
    bool p;
    bool q;
    // Use temporary integers to store bool values
    int temp1;
    int temp2;

    // Get boolean input
    printf("Enter 0(False) or 1(True) for p: ");
    scanf("%d", &temp1);
    printf("\nEnter 0(False) or 1(True) for q: ");
    scanf("%d", &temp2);

    // Get script and turn to prolog
    printf("Enter your logic script using 'T' 'F' 'p' 'q' 'and' 'or' 'xor' 'if' 'then' 'not'.\n");
    printf("Make sure to bracket according to priority of operation (no larger than 100 characters):\n");
    scanf(" %[^\n]", logic);

}