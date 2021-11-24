#include<stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(){

    float Ms[3][3]= {{1,2,3},
                    {4,2,1},
                    {6,8,4}};

    float Md[3][3]={{0,0,0},
                    {0,0,0},
                    {0,0,0}};


    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t", Ms[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t", Md[i][j]);
        }
        printf("\n");
    }

    syscall(448, Ms, Md, sizeof(Md));


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t", Ms[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t", Md[i][j]);
        }
        printf("\n");
    }

    return 0;
}
