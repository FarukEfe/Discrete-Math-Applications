#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> 

int to_binary();

int main() {

    int n1;
    int n2;

    long int bitwise1;
    long int bitwise2;

    // Get number inputs
    printf("Enter 1st number: ");
    scanf("%d", &n1);
    printf("\nEnter 2nd number: ");
    scanf("%d", &n2);
    // Turn input numbers into base-2
    bitwise1 = to_binary(n1);
    bitwise2 = to_binary(n2);
    printf("%ld\n",bitwise1);
    printf("%ld\n",bitwise2);
    // Get bitwise and/or/xor values

    // Turn them back in numbers
}

int to_binary(int n) {

    int binary_num = 0;
    int highest_bit = floor(log2(n));

    while (n > 0) {
        n -= pow(2,highest_bit);
        binary_num += pow(10,highest_bit);
        highest_bit = floor(log2(n));
    }

    return binary_num;
}
