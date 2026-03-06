#include "apc.h"

//remove leading zeros
int delete_zero(Dlist **headR)
{
    Dlist *temp = *headR;

    //Start from the first digit of the result
    while (temp != NULL && temp->data == 0)
    {
        *headR = temp->next;  
        if (*headR != NULL)
        {
            (*headR)->prev = NULL;  
        }
        free(temp);  
        temp = *headR;  
    }

   //If all digits were zeros
    if (*headR == NULL)
    {
        int zero = 0;
        insert_first(headR, headR, &zero);
    }

    return SUCCESS;
}

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    int borrow = 0, num1, num2, sub;
    extern int sign;  

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    
    Dlist *t1 = *head1, *t2 = *head2;
    int len1 = 0, len2 = 0;

    //Find Lengths of Both Numbers
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

    //If equal length, compare digit by digit from head
    if (len1 == len2) {
        t1 = *head1;
        t2 = *head2;
        while (t1 && t2) 
        {
            if (t1->data > t2->data) 
            break;
            if (t1->data < t2->data) 
            {
                sign = 1;
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    //If second number is larger - result is negative    
    } else if (len1 < len2) 
    {
        sign = 1;  
    }

    //If result is negative, swap numbers so we always subtract bigger − smaller
    //swap
    if (sign == 1) {
        Dlist *temp;
        temp = *head1; *head1 = *head2; *head2 = temp;
        temp = *tail1; *tail1 = *tail2; *tail2 = temp;
        temp1 = *tail1;
        temp2 = *tail2;
    }

   
    while (temp1 != NULL || temp2 != NULL) 
    {
        num1 = (temp1 != NULL) ? temp1->data : 0;
        num2 = (temp2 != NULL) ? temp2->data : 0;

        //Apply previous borrow
        if (borrow == 1) 
        {
            if (num1 == 0) 
            {
                num1 = 9;
            } 
            else 
            {
                num1 -= 1;
                borrow = 0;
            }
        }
        //Borrow if needed
        if (num1 < num2) {
            num1 += 10;
            borrow = 1;
        }
        //Subtract and store result digit
        sub = num1 - num2;
        insert_first(headR, tailR, &sub);
        
        //Move to next digits
        if (temp1 != NULL) 
        temp1 = temp1->prev;
        if (temp2 != NULL) 
        temp2 = temp2->prev;
    }

    
    delete_zero(headR);

    if (sign == 1) {
        printf("-");
    }

    return SUCCESS;
}



