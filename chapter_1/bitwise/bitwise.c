#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> 

int to_binary();
int to_decimal();

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
    /*
    long int bit_and;
    long int bit_or;
    long int bit_xor;

    long int decimal_step = 0;

    while (pow(10,decimal_step) < bitwise1) {

    }*/
    // Turn them back in numbers
    printf("%d\n",to_decimal(bitwise1));
    printf("%d\n",to_decimal(bitwise2));
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

int to_decimal(int binary) {
    long int decimal_step = 0;
    int total = 0;
    int step_tenth, rem;

    while (binary > 0) {
        rem = binary % 10;
        total += rem * pow(2,decimal_step);
        binary /= 10; 
        decimal_step++;
    }
    return total;
}
