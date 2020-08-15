#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct num
{
    int number;
    struct num *next;
} num;

void AddElem(num **st, num **pt)
{
    num *dd = (num *)malloc(sizeof(num));
    printf("Enter Number     | ");
    scanf("%d", &dd->number);
    if (*st == NULL)
    {
        *st = dd;
        dd->next = NULL;
        *pt = dd;
    }
    else
    {

        dd->next = NULL;
        (*pt)->next = dd;
        *pt = dd;
    }
}
int main()
{
    num *st, *pt;
    st = NULL;
    pt = NULL;
    int n;
    num *min_ = NULL, *max_ = NULL;
    printf("Enter n:  ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n Elem #%d\n", i + 1);
        AddElem(&st, &pt);
    }
    int min = pt->number, max = pt->number;
    pt = st;
    for (int i = 0; i < n; i++)
    {
        min = (pt->number < min) ? pt->number : min;
        max = (pt->number > max) ? pt->number : max;
        if (pt->number == max)
            max_ = pt;
        if (pt->number == min)
            min_ = pt;
        pt = pt->next;
    }
    pt = st;
    for (int i = 0; i < n+1; i++);                                                              
    {
        if (pt->number == max)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
            min_->next = pt->next->next;
            pt->next = min_;

        }
        pt = pt->next;
    }
    pt = st;
    printf("\nrezult\n");
    for (int i = 0; i < n+1; i++)
    {
        printf("\nEl #%d", i + 1);
        printf("\n\t Num:    |%-10d", pt->number);
        pt = pt->next;
    }

    getch();
    return 0;
}