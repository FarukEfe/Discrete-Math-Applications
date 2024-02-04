#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{   
    /*
    Write in file the statements below in the prolog file:
    ~P :- not P.
    P ^ Q :- P and Q.
    P v Q :- P or Q.
    P => Q :- P implies Q.
    P <=> Q :- P equivalent Q.
    */
    FILE *fptr;
    // Open db.pl file to store query
    fptr = fopen("db.pl", "w");
    if (fptr == NULL) {
        printf("Prolog file failed to open.\n");
        return 0;
    }
    // Write simplified prolog query
    fprintf(fptr,"~P :- not P.\nP ^ Q :- P and Q.\nP v Q :- P or Q.\nP => Q :- P implies Q.\nP <=> Q :- P equivalent Q.");
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
    printf("Enter the script. You can use the following words:\n");
    printf("not p\np and q\np or q\np implies q\np equivalent q\n");
    printf("Make sure to nest your statement accordingly to avoid syntax errors (max 100 characters)\n");
    scanf(" %[^\n]", logic);
    // Call system to execute commands
    system("swipl -s db.pl");
    system(logic);

    // Use PWI_Prolog calls to evaluate term using PL_call(term_t,module_t);
    // First check exceptions with PL_exception(term_t);

}