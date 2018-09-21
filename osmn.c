#include <stdio.h>

#define MAX_ARRAY 101

int checkBalance(int left, int right, int bst[MAX_ARRAY], int leftIndice);

int main(void)
{
    int tests, elements, leftLeave, rightLeave, tmptest;
    scanf("%d", &tests);
    while (tests--)
    {
        int bst[MAX_ARRAY] = {0};
        scanf("%d", &elements);
        tmptest = elements;
        if (elements < 2)
        {
            scanf("%d", &leftLeave);
            printf("T\n");
            continue;
        }
        if (!(elements % 2)) // If it is pair
        {
            scanf("%d", &leftLeave);
            bst[elements - 1] = -1;
            elements--;
        }
        while (elements-- > 1)
        {
            scanf("%d", &leftLeave);
            scanf("%d", &rightLeave);
            elements--;
            bst[((elements - 1) / 2)] = checkBalance(leftLeave, rightLeave, bst, elements);

            printf("elements %d %d\n", bst[((elements - 1) / 2)], ((elements - 1) / 2));

            if (bst[((elements - 1) / 2)] > 1 || bst[((elements - 1) / 2)] < -1)
            {
                printf("F\n");
                break;
            }
        }
        int x;
        for (x = 0; x < tmptest; x++)
            printf("%d|%d ", bst[x], tmptest);
        if (bst[((elements - 1) / 2)] > 1 || bst[((elements - 1) / 2)] < -1)
            printf("F\n");
        else
            printf("T\n");
    }
    return 0;
}

int checkBalance(int left, int right, int bst[MAX_ARRAY], int leftIndice)
{
    int result = 0;
    result = bst[leftIndice + 1] - bst[leftIndice];
    if (left < 0)
        result--;
    if (right < 0)
        result++;
    printf("Result %d ", result);
    return result;
}