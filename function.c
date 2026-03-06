#include "apc.h"
#include <string.h>



int sign = 0, i = 0;
int read_and_validate(int argc, char *argv[])
{
	if(argc == 4)
	{
		if(*argv[2] == '+' || *argv[2] == '-' || *argv[2] == 'x' || *argv[2] == '/')
		{
			while(argv[1][i] != '\0')
			{
				if(argv[1][i] >= '0' && argv[1][i] <= '9')
				{
					i++;
				}
				else
				{
					printf("Enter 0 - 9 Digits only in Operand 1 !\n");
					return FAILURE;
				}
			}
		 	i = 0;
			while(argv[3][i] != '\0')
			{	
				if(argv[3][i] >= '0' && argv[3][i] <= '9')
				{
					i++;
				}
				else
				{
					printf("Enter 0 - 9 Digits only in Operand 2 !\n");
					return FAILURE;
				}
			}
			return SUCCESS;
		}
		else
		{
			printf("Invalid Operator\n please use : +, -, x, /.\n");
			return FAILURE;
		}
	}
	else
	{
		printf("ERROR: Please provide proper arguments\n");
		printf("Ex:- ./a.out 123 + 456\n");
		return FAILURE;
	}
}


void print_list(Dlist *head1)
{
	/* Cheking the list is empty or not */
	if (head1 == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
		
    	while (head1)		
    	{
	    	/* Printing the list */
	    	printf("%d", head1 -> data);
	   	 	/* Traversing in forward direction */
	    	head1 = head1 -> next;
    	}
    	printf("\n");
	}
}


void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])

{
    int i = 0;
    
    
    while (argv[1][i] != '\0')
    {
        int element = argv[1][i] - '0'; 

        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        new->data = element;
        new->prev = *tail1;
        new->next = NULL;

        if (*head1 == NULL)
        {
            *head1 = new;
            *tail1 = new;
        }
        else
        {
            (*tail1)->next = new;
            *tail1 = new;
        }

        i++;
    }

    
    i = 0;
    while (argv[3][i] != '\0')
    {
        int element = argv[3][i] - '0';

        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        new->data = element;
        new->prev = *tail2;
        new->next = NULL;

        if (*head2 == NULL)
        {
            *head2 = new;
            *tail2 = new;
        }
        else
        {
            (*tail2)->next = new;
            *tail2 = new;
        }

        i++;
    }
}


int insert_first(Dlist **headR, Dlist **tailR, int *data)
{
		Dlist *new = malloc(sizeof(Dlist));
    	if(new == NULL)
    	{
        	return FAILURE;
    	}
    	
    	new -> data = *data;
    	new -> prev = NULL;
    	new -> next = *headR;
		
   	 	if(*headR == NULL)
    	{
        	*headR = new;
        	*tailR = new;
    	}
		else
		{
    		(*headR) -> prev = new;
    		*headR = new;
		}
}

int insert_last(Dlist **headR, Dlist **tailR, int *data)
{
	Dlist *new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		return FAILURE;
	}

	new -> data = *data;
	new -> prev = *tailR;
	new -> next = NULL;

	if(*headR == NULL)
	{
		*headR = new;
		*tailR = new;
	}
	else
	{
		(*tailR) -> next = new;
		*tailR = new;
	}

}

int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    while(*head != NULL)
    {
        *tail = (*tail) -> prev;
        if(*tail == NULL)
        {
            free(*head);
            *head = NULL;
            return SUCCESS;
        }
        free((*tail) -> next);
        
    }
}





