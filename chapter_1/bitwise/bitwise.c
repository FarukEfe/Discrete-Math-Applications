#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h> 

// Function declarations
int to_binary();
int to_decimal();
int logical_and();
int logical_or();
int logical_xor();


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
    
    long int bit_and = logical_and(bitwise1,bitwise2);
    long int bit_or = 0;
    long int bit_xor = 0;

    printf("%ld\n",bit_and);
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

int to_decimal(long int binary) {
    int decimal_step = 0;
    int total = 0;
    int rem;

    while (binary > 0) {
        rem = binary % 10;
        total += rem * pow(2,decimal_step);
        binary /= 10; 
        decimal_step++;
    }
    return total;
}

int logical_and(int b1, int b2) {

    int larger = b1, smaller = b2;
    if (larger < smaller) {
        larger, smaller = smaller, larger;
    }

    int decimal_step = 0; // Current step in the decimal
    int r1, r2; // Remainder of both binaries
    bool p1, p2; // Boolean translations of remainders
    int dec_val; // Propositional integer value of p1 and p2
    long int total = 0;

    printf("Large: %d Small: %d\n",larger,smaller);
    while (larger > 0) {
        // Find decimal place
        r1, r2 = larger % 10, smaller % 10;
        // Convert to boolean type
        p1, p2 = r1, r2;
        dec_val = (p1 && p2);
        printf("Current Decimal Value for %d and %d: %d\n",p1,p2,dec_val);
        total += dec_val * pow(10,decimal_step);
        //larger -= r1,smaller -= r2;
        larger /= 10, smaller /= 10;
        printf("Large: %d Small: %d\n",larger,smaller);
        decimal_step++;
    }
    return total;
}

int logical_or(int b1, int b2) {

}

int logical_xor(int b1, int b2) {

}