#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Elem
{
    int num;
    struct Elem *next;
} Elem;

void AddBeg( Elem **st, Elem **pt)
{

    Elem *dd = (Elem*)malloc(sizeof(Elem));
    printf("\n\tNum            |");
    scanf("%d", &dd->num);
    if ( *st == NULL)
    {
        dd->next = NULL;
        *st = dd;
        *pt = dd;
    }
    else
    {
        dd->next = *st;
        *st = dd;
    }
    

}
void AddEnd( Elem **st, Elem **pt)
{

    Elem *dd = (Elem*)malloc(sizeof(Elem));
    printf("\n\tNum            |");
    scanf("%d", &dd->num);
    if ( *st == NULL)
    {
        dd->next = NULL;
        *st = dd;
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
    Elem *st, *pt, *dd;
    st = NULL;
    pt = NULL;
    int n ;
    printf("Enter n ");
    scanf("%d",&n);
    for (int  i = 0; i < n; i++)
    {
        if(i%2 == 0)
            AddBeg(&st,&pt);
        else
            AddEnd(&st,&pt);
    }
    pt = st;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", pt->num);
        pt = pt->next;
    }
    int middle_el;
    if( n%2 == 0 )
    {
        middle_el = n/2;
    }
    else
    {
        middle_el = n/2 + 0.5;
    }
    pt = st;
    for (int i = 0; i < middle_el +1; i++)
    {
        if(i + 1 == middle_el)
        {
            dd = pt->next;
            pt->next = pt->next->next;
            
        // pt = pt->next;
        free(dd);
        break;
        }
        pt = pt->next;
    }
    printf("\ndelete middle element");
    pt = st;
    for (int i = 0; i < n-1; i++)
    {
        printf("\n\t%d ", pt->num);
        pt = pt->next;
    }
    
    getch();
    return 0;
}