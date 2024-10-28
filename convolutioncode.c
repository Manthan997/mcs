// convolution code

#include <stdio.h>

void main()
{
    int t[5]={1,0,1,0,0};
    
    // // uncomment for taking the user input
    // printf("Enter 5 binary values (0 or 1):\n");
    // for (int i = 0; i < 5; i++) {
    //     scanf("%d", &t[i]);
    // }
    printf("\ninput sequence: %d%d%d%d%d", t[0], t[1], t[2], t[3], t[4]);
    
    printf("\nconvlution code: ");
    int i,j,u1,u2,x1=0,x2=0,x3=0;
        for(i=0;i<=4;i++)
    {
        x1=t[i];
        u1=x1^x2^x3;
        u2=x1^x3;
        printf("%d",u1);
        printf("%d",u2);
        x3=x2;
        x2=x1;
    }
    
}