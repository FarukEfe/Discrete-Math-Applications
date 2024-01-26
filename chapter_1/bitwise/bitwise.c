#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> 

char* to_binary();

int main() {

    int n1;
    int n2;

    char* bitwise1;
    char* bitwise2;

    // Get number inputs
    printf("Enter 1st number: ");
    scanf("%d", &n1);
    printf("\nEnter 2nd number: ");
    scanf("%d", &n2);
    // Turn input numbers into base-2
    bitwise1 = to_binary(n1);
    bitwise2 = to_binary(n2);
    printf(bitwise1);
    printf(bitwise2);
    // Get bitwise and/or/xor values

    // Turn them back in numbers
}

char* to_binary(int n) {

    if (n < 1) {
        return "";
    }

    // Finds highest bit needed to represent the data
    int highest_bit = floor(log2(n)) + 1;
    // Highest exponent of 2 that is smaller than n
    int highest_two_n = pow(2,highest_bit);
    // Remainder after subtracting highest exponent of 2 smaller than n
    int remainder = n - highest_two_n;
    // Find highest bit of remainder
    int next_high_bit = floor(log2(remainder)) + 1;
    // Subtract first high-bit from that of the remainder (zeroes in-between)
    int num_zeroes = highest_bit-next_high_bit-1;
    // Generate zeroes
    char zeroes[num_zeroes];
    for (int a=0;a<num_zeroes;a++) {
        zeroes[a] = '0';
    }
    // Concatenate
    return strcat(strcat("1",zeroes),to_binary(remainder));
}
