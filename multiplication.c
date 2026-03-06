#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, Dlist **headR2, Dlist **tailR2)
{
int count = 0, carry = 0, mul, num1, num2, res;
    int flag = 0;  

    //Used to check if first partial product or not.
    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;

    Dlist *temp1 = *tail1;  
    Dlist *temp2 = *tail2;  

    
    while(temp2 != NULL)
    {
        carry = 0;  

        
        while(temp1 != NULL)
        {
            num1 = temp1->data;
            num2 = temp2->data;

           //multiplication
            mul = num1 * num2 + carry;
            res = mul % 10;  
            carry = mul / 10; 

            temp1 = temp1->prev; 

            //goes directly into result list
            if(count == 0)
            {
                insert_first(headR, tailR, &res);  
            }
            //go into temporary list
            else
            {
                insert_first(headR2, tailR2, &res);  
                flag = 1;  
            }
        }

        //Store any remaining carry at front of the partial product
        if (carry > 0)
        {
            if (count == 0)
            {
                insert_first(headR, tailR, &carry);
            }
            else
            {
                insert_first(headR2, tailR2, &carry);
                flag = 1;
            }
        }

        
        if(flag == 1)
        {
            
            int i;
            //adding zeros when shifting rows
            for(i = 0; i < count; i++)
            {
                int add_zero = 0;
                insert_last(headR2, tailR2, &add_zero);
            }

            
            if(addition(headR, tailR, headR2, tailR2, &temp_head, &temp_tail) == SUCCESS)
            {
                //clean old lists
                delete_list(headR, tailR);
                delete_list(headR2, tailR2);
                *headR = temp_head;
                *tailR = temp_tail;
                temp_head = NULL;
                temp_tail = NULL;
            }
            flag = 0;  
        }

        //Move to next digit of second number and increase shift
        temp2 = temp2->prev;
        temp1 = *tail1;  
        count++;  

    }
}
