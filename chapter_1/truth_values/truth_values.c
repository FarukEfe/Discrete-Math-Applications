#include <stdio.h>
#include <stdbool.h>

int main() {

    bool p;
    bool q;
    // Use temporary integers to store bool values
    int temp1;
    int temp2;

    printf("Enter 0 or 1 for p: ");
    scanf("%d", &temp1);
    printf("\nEnter 0 or 1 for q: ");
    scanf("%d", &temp2);

    p = temp1;
    q = temp2;


    bool conjunction = p && q;
    bool dysjunction = p || q;
    bool conditional = (p) ? q : true;
    bool biconditional = (p == q);

    printf("\n");
    
    printf("p and q: %d\n",conjunction);
    printf("p or q: %d\n",dysjunction);
    printf("if p then q: %d\n",conditional);
    printf("q only and only if p: %d\n",biconditional);
    
    printf("\n");
    return 1;
}