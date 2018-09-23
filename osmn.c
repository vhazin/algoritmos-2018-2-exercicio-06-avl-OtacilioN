#include <stdio.h>

#define MAX_ARRAY 102
#define LESS_UNBALANCED_TREE 4

int getFatherHeight(int left, int right, int nodeHeight[MAX_ARRAY], int leftIndice);

int main(void)
{
    int tests, elements, node, iterator;
    scanf("%d", &tests);
    while (tests--)
    {
        int nodeHeight[MAX_ARRAY] = {0};
        int bsts[MAX_ARRAY];
        int flag = 0;
        scanf("%d", &elements);
        if (elements < LESS_UNBALANCED_TREE)
        {
            while (elements--)
            {
                scanf("%d", &node);
            }
            printf("T\n");
            continue;
        }

        for (iterator = 0; iterator < elements; iterator++)
        {
            scanf("%d", &bsts[iterator]);
            if (bsts[iterator] < 0)
                nodeHeight[iterator] = -1;
        }

        if (!(elements % 2)) // If it is pair
        {
            elements--;
            nodeHeight[((elements - 1) / 2)] = 1;
        }
        while (elements-- > 1)
        {
            elements--;
            if (nodeHeight[((elements - 1) / 2)] >= 0)
                nodeHeight[((elements - 1) / 2)] = getFatherHeight(bsts[elements], bsts[elements + 1], nodeHeight, elements);

            if (nodeHeight[elements + 1] - nodeHeight[elements] > 1 || nodeHeight[elements + 1] - nodeHeight[elements] < -1)
            {
                printf("F\n");
                flag++;
                break;
            }
        }
        if (!flag)
            printf("T\n");
    }
    return 0;
}

int getFatherHeight(int left, int right, int nodeHeight[MAX_ARRAY], int leftIndice)
{
    int result = 0;
    result = nodeHeight[leftIndice + 1] > nodeHeight[leftIndice] ? nodeHeight[leftIndice + 1] : nodeHeight[leftIndice];
    if (result || left > 0 || right > 0) // If has child sum +1
        result++;
    return result;
}