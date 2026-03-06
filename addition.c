#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

/* Function to add two large numbers using doubly linked list */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    int carry = 0, sum, rem, num1, num2;
    Dlist *temp1 = *tail1;  
    Dlist *temp2 = *tail2;  

    //Loop until both numbers are finished
    while(temp1 != NULL || temp2 != NULL)
    {
        
        if(temp1 == NULL)
        {
            num1 = 0;
            num2 = temp2->data;
            temp2 = temp2->prev; 
        }
        
        else if(temp2 == NULL)
        {
            num1 = temp1->data;
            num2 = 0;
            temp1 = temp1->prev; 
        }
        else
        {
            num1 = temp1->data;
            num2 = temp2->data;
            temp1 = temp1->prev; 
            temp2 = temp2->prev; 
        }
        
        //Perform digit-wise addition
        sum = num1 + num2 + carry; 
        rem = sum % 10;  
        carry = sum / 10; 
        insert_first(headR, tailR, &rem); 
    }

    
    if(carry > 0)
    {
        insert_first(headR, tailR, &carry); 
    }

    return SUCCESS; 
}
