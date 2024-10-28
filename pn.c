// PSEUDO RANDOM NUMBER SEQUENCE GENETAION USING LINEAR FEEDBACK SHIFT REGISTER
#include <stdio.h>

int main()
{
    int t[4]= {1, 0, 1, 1};

    // // uncomment for taking the user input
    // printf("Enter 4 binary values (0 or 1) seperated by enter:\n");
    // for (int i = 0; i < 4; i++) {
    //     scanf("%d", &t[i]);
    // }

    printf("input seed: %d%d%d%d", t[0], t[1], t[2], t[3]);
    
    // Generate the PN sequence
    printf("\nPN SEQUENCE: ");
    for (int i = 0; i < 15; i++) {
        int u1 = t[2] ^ t[3]; // XOR operation
        t[3] = t[2];
        t[2] = t[1];
        t[1] = t[0];
        t[0] = u1;
        printf("%d", u1);
    }
    printf("\n");

    return 0;
}
