//Source file for the C-string linked list data structure for storing character strings

#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Allocates and initializes a new list*/
list *create_list(){
    list *list = malloc(sizeof(list));
    return list;
}

/* Adds item to end of the list. This function allocates a
* new buffer and copies the string from item (use malloc, strlen, and strncpy; or try strdup).
* Returns 0 if successful, non-zero otherwise. */

int add_to_list(list *ll, char *item){
    node *newNode = malloc(sizeof(*newNode));


    //compute length of string and assign it to the new node's value
   
    int len = strlen(item);
    char *sstring = newNode->value;
    sstring = malloc(len + 1); //allocate memory for the string
    strncpy(sstring, item, len + 1); //store the new string into the new node's value 

    newNode -> next = NULL; //create node struct for new item
    node *lastItem = ll -> tail; //grab the last item in list

    lastItem = malloc(sizeof(lastItem)); //change the last item next pointer to point to new item
    lastItem ->next = newNode;
        
    ll -> tail = newNode; //Update the list's tail
    return 0;
}

/* Removes the string from the front of the list and
* returns a pointer to it. The caller is expected to free
* the string returned when finished with it. */
char *remove_from_list(list *ll){
    node *removing = ll -> head;

    char *toDelete = removing->value; //string of item in front of list
    ll ->head = removing ->next; //set the head of the list as the item to be removed next 
    free(removing); //frees the node of the item to be deleted
    return toDelete; //return the pointer to the string at the front of the list
}

/* Prints every string in the list, with a new line
* character at the end of each string */
void print_list(list *ll){
    node *current = ll -> head;
    while (current -> next != NULL){
        printf(current -> value, "\n");
        current = current -> next;
    }
}

/* Flushes (clears) the entire list and re-initializes the
* list. The passed pointer ll should still point to a
* valid, empty list when this function returns. Any memory
* allocated to store items in the list should be freed. */
void flush_list(list *ll){

    node *current = ll -> head;
    node *next;
    while (current != NULL ){
        next = current -> next;
        free(current);
        current = next;
    }
    free(next); 
    free(ll);

    ll = create_list();
}

/* De-allocates all data for the list. Ensure all memory
* allocated for this list is freed, including any
* allocated strings and the list itself.*/

void free_list(list *ll){
    node *current = ll->head;
    node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->value);
        free(current); 
        current = next;
    }
    free(next);
    free(ll);
}
