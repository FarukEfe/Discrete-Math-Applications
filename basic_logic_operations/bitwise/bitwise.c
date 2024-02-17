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
    // Get bitwise and/or/xor values
    
    long int bit_and = logical_and(bitwise1,bitwise2);
    long int bit_or = logical_or(bitwise1,bitwise2);
    long int bit_xor = logical_xor(bitwise1,bitwise2);

    // Turn them back in numbers & final display
    printf("Your numbers were: %d and %d respectively.\n",n1,n2);
    printf("In binary, that makes %ld and %ld\n",bitwise1,bitwise2);
    printf("Their bitwise AND: %ld. As a decimal that is: %d\n",bit_and,to_decimal(bit_and));
    printf("Their bitwise OR: %ld. As a decimal that is: %d\n",bit_or,to_decimal(bit_or));
    printf("Their bitwise XOR: %ld. As a decimal that is: %d\n",bit_xor,to_decimal(bit_xor));
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
        larger = b2, smaller = b1;
    }

    int decimal_step = 0; // Current step in the decimal
    int r1, r2; // Remainder of both binaries
    bool p1, p2; // Boolean translations of remainders
    int dec_val; // Propositional integer value of p1 and p2
    long int total = 0;

    while (larger > 0) {
        // Find decimal place
        r1 = larger % 10, r2 = smaller % 10;
        // Convert to boolean type
        p1 = r1, p2 = r2;
        dec_val = (p1 & p2); // Logic AND
        // Add biwise value of decimal to total
        total += dec_val * pow(10,decimal_step);
        // Reduce numbers and increase decimal step
        larger /= 10, smaller /= 10;
        decimal_step++;
    }

    return total;
}

int logical_or(int b1, int b2) {
    int larger = b1, smaller = b2;
    if (larger < smaller) {
        larger = b2, smaller = b1;
    }

    int decimal_step = 0; // Current step in the decimal
    int r1, r2; // Remainder of both binaries
    bool p1, p2; // Boolean translations of remainders
    int dec_val; // Propositional integer value of p1 and p2
    long int total = 0;

    while (larger > 0) {
        // Find decimal place
        r1 = larger % 10, r2 = smaller % 10;
        // Convert to boolean type
        p1 = r1, p2 = r2;
        dec_val = (p1 | p2); // Logic OR
        // Add biwise value of decimal to total
        total += dec_val * pow(10,decimal_step);
        // Reduce numbers and increase decimal step
        larger /= 10, smaller /= 10;
        decimal_step++;
    }

    return total;
}

int logical_xor(int b1, int b2) {
    int larger = b1, smaller = b2;
    if (larger < smaller) {
        larger = b2, smaller = b1;
    }

    int decimal_step = 0; // Current step in the decimal
    int r1, r2; // Remainder of both binaries
    bool p1, p2; // Boolean translations of remainders
    int dec_val; // Propositional integer value of p1 and p2
    long int total = 0;

    while (larger > 0) {
        // Find decimal place
        r1 = larger % 10, r2 = smaller % 10;
        // Convert to boolean type
        p1 = r1, p2 = r2;
        dec_val = (p1 ^ p2); // Logic XOR
        // Add biwise value of decimal to total
        total += dec_val * pow(10,decimal_step);
        // Reduce numbers and increase decimal step
        larger /= 10, smaller /= 10;
        decimal_step++;
    }

    return total;
}