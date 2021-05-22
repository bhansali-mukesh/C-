#include<stdio.h>

int main()
{
        int i,j,temp,precision;
        float Number, Average, Matrix[4][4];
        float Logic_Array[4][4] = {{12,-6,-14,8},{-3,2,-2,3},{-4,-1,1,4},{-5,5,15,-15}};

        printf("Enter a Number: ");
        scanf("%f",&Number);
        printf("\n\n");

        Average = Number/4.0;
        temp = Average;

        if(Average > temp)
                precision = 2;
        else
                precision = 0;

        for(i=0; i<4; i++)
        {
                for(j=0; j<4; j++)
                {
                        Matrix[i][j] = Average + Logic_Array[i][j];
                }
        }

        for(i=0; i<4; i++)
        {
                for(j=0; j<4; j++)
                {
                        printf("%.0f\t",Matrix[i][j]);
                }
                printf("\n");
        }

        printf("\n\nIt's Nice Man.\n");
        return 0;
}
