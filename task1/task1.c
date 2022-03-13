#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void printM(int* in, int n)
{
    printf("%d", in[0]);
    for(int i = 1; i < n; i++)
        printf(" + %d", in[i]);
    printf("\n");
}

int decompose(int n, int coeff)
{
    int MAX = 0;
    for(int m = 2; m <= n; m++)
    {
        int* terms = (int*)calloc(m, sizeof(int));

        for(int j = 0; j < m - 1; j++)
            terms[j] = 1;
        terms[m - 1] = n - m + 1;

        if(terms[m - 1] <= coeff)
            if(MAX < m)
                MAX = m;
                //printM(terms, m);
    
        while(terms[m - 1] - terms[0] > 1)
        {
            int i = m - 2, sum = 0;

            for(i; i > 0; i--)
                if(terms[m-1] - terms[i] >= 2)
                    break;

            terms[i]++;
            for(int j = i; j < m - 1; j++)
                terms[j] = terms[i];

            for(int j = 0; j < m - 1; j++)
                sum += terms[j];
        
            terms[m - 1] = n - sum;

            if(terms[m - 1] <= coeff)
                if(MAX < m)
                    MAX = m;
        }
        free(terms);
    }
    return MAX;
}

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        printf("No arguments\n");
        exit(-1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int n = atoi(argv[3]);

    int A = decompose(a, n);
    int B = decompose(b, n);

    if (A > B)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}