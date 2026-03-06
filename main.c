#include "apc.h"


int main(int argc, char *argv[])
{
	
	if(read_and_validate(argc, argv)  == SUCCESS)
	{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;
		Dlist *headR2 = NULL, *tailR2 = NULL;

	char operator=argv[2][0];
       
    

		switch (operator)
		{
			case '+':
                                digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the addition operation */
                                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                                print_list(headR);
				break;
			case '-':	
                           digit_to_list(&head1,&tail1,&head2,&tail2,argv);			
				/* call the function to perform the subtraction operation */
				            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                            print_list(headR);
				break;
			case 'x':	
			                 digit_to_list(&head1,&tail1,&head2,&tail2,argv);			
				/* call the function to perform the multiplication operation */
                            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR,&headR2 ,&tailR2 );  
                            print_list(headR);

				break;
			case '/':	
			                 digit_to_list(&head1,&tail1,&head2,&tail2,argv);			
				/* call the function to perform the division operation */
                            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				            print_list(headR);
                
				break;
			default:
				printf("Invalid Input ! Try again...!\n");
				return -1;
		}
		
    }   
return 0;
}
