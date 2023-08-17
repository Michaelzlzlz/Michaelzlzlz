#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N   100

typedef struct person {
	char *name;
	struct person *next;
} person;

person *create (char *name){
	person *i = (person*)malloc(sizeof(person));
	if(i==NULL){
        printf("Error! No memory allocated!\n");
        exit(1);
    }
    i->name = strdup(name);
	i->next = NULL;
	return i;
}

void command_4_display(person *start){
	person *i = start;
	for ( ; i != NULL; i=i->next){
		if (i->name != NULL)
            printf("\nName: %s", i->name);
	}
}

void command_5_search(person *start){
    char name_S[N];
	person *i = start;
	int n=0;
	printf("\nEnter name:\n");
	if(fgets(name_S, N, stdin) != NULL){
        for ( ; i != NULL; i=i->next ){
            if (strcmp(name_S, i->name)==0){
                n++;
                printf("\n->Name: %s", i->name);
            }
        }
    }
    if (n==0)
        printf("Not found.\n");
    else
        printf("\nFound elements: %d\n", n);
}

void command_6_release(person *start){
	person *i = start;
	person *next = NULL;
	for ( ; i != NULL ; i = next){
		next = i->next;
		free(i->name);
		free(i);
	}
}

int main()
{
    person *start_p = NULL;
    person *i_p = NULL;
	person *next_p = NULL;
	char name[N];
    char prikaz;
    printf("1.Create the first item in the list.\n");
    printf("2.Add an item to the end of the list.\n");
    printf("3.Remove item from end of list.\n");
    printf("4.Watch the list.\n");
    printf("5.Delete the entire list.\n");
    printf("6.Search for an item in a list.\n");
    printf("7.Quit the program.\n");
    printf("------------------------------------\n");
    while(1){
        printf( "\nEnter command:" );
        prikaz = getche();

        switch (prikaz){

                case '1':
                    if (start_p == NULL){
                        printf( "\nEnter name:\n-\n" );
                        if(fgets(name, N, stdin) != NULL){
                            next_p = create(name);
                            start_p = next_p;
                            i_p = next_p;
                            printf( "Successfully recorded!!!\n\n" );
                        }
                    }
                    else
                        printf( "\nError! Press 6 to clear the list.\n" );
                    break;

                case '2':
                    if (i_p != NULL){
                        printf( "\nEnter name:\n-\n" );
                        if (fgets(name, N, stdin) != NULL){
                            next_p = create(name);
                            i_p->next = next_p;
                            printf( "Successfully recorded!!!\n\n" );
                            i_p=next_p;
                        }
                    }
                    else
                        printf( "\nError! Press 1 to create the first item.\n" );
                    break;

                case '3':
                    if (start_p != NULL){
                        if (start_p->next==NULL){
                            command_6_release(start_p);
                            i_p = NULL;
                            next_p = NULL;
                            start_p = NULL;
                            printf( "\nSuccessfully cleaned!!!\n\n" );
                        }
                        else {
                            i_p=start_p;
                            while (i_p->next != NULL){
                                if (i_p->next != next_p)
                                    i_p=i_p->next;
                                else {
                                    free(next_p->name);
                                    free(next_p);
                                    i_p->next = NULL;
                                    next_p =i_p;
                                    printf( "\nSuccessfully cleaned!!!\n\n" );
                                }
                            }
                        }
                    }
                    else
                        printf( "\nError. The list is empty.\n\n" );
                    break;

                case '4':
                    command_4_display(start_p);
                    printf( "\nSuccessfully completed!!!\n\n" );
                    break;
            
                case '5':
                    command_6_release(start_p);
                    i_p = NULL;
                    next_p = NULL;
                    start_p = NULL;
                    printf( "\nSuccessfully cleaned!!!\n\n" );
                    break;

                case '6':
                    command_5_search(start_p);
                    printf( "\nSearch completed!!!\n\n" );
                    break;

                case '7':
                    command_6_release(start_p);
                    return 0;

                default:
                     printf( "\n Invalid input. Press 1-7 to execute the command. \n" );
        }
    }
}
