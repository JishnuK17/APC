#include "apc.h"

int compare_lists(Dlist *h1, Dlist *h2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = h1, *t2 = h2;

    while (t1) 
    { 
        len1++; 
        t1 = t1->next; 
    }
    while (t2) 
    { 
        len2++; 
        t2 = t2->next; 
    }

    if (len1 > len2) 
        return 1;
    if (len1 < len2) 
        return -1;

    while (h1 && h2)
    {
        if (h1->data > h2->data) 
           return 1;
        if (h1->data < h2->data) 
           return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;
}


int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *cur = *head1;

    Dlist *remH = NULL, *remT = NULL;   // current remainder
    Dlist *tmpH = NULL, *tmpT = NULL;   // temp for subtraction

    while (cur)
    {
        int d = cur->data;
        insert_last(&remH, &remT, &d);

        // remove leading zeros from remainder
        while (remH && remH->data == 0 && remH != remT)
        {
            Dlist *t = remH;
            remH = remH->next;
            remH->prev = NULL;
            free(t);
        }

        int q = 0;

        // while remainder >= divisor
        while (compare_lists(remH, *head2) >= 0)
        {
            subtraction(&remH, &remT, head2, tail2, &tmpH, &tmpT);
            delete_list(&remH, &remT);
            remH = tmpH;
            remT = tmpT;
            tmpH = tmpT = NULL;
            q++;
        }

        insert_last(headR, tailR, &q);
        cur = cur->next;
    }

    // remove leading zeros in quotient
    while (*headR && (*headR)->data == 0 && *headR != *tailR)
    {
        Dlist *t = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(t);
    }

    delete_list(&remH, &remT);
    return SUCCESS;
}

