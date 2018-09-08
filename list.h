//Header file for the C-string linked list data structure for storing character strings
#ifndef LIST_H_
#define FOO_H_

//Definition of node struct
typedef struct node {
    char *value;
    struct node *next; 
} node;  

//Definition of list struct
typedef struct list {
    node *head;
    node *tail;
} list;

/* Allocates and initializes a new list*/
list * create_list();

/* Adds item to end of the list. This function allocates a* new buffer and copies the string from item (use malloc,* strlen, and strncpy; or try strdup).* Returns 0 if successful, non-zero otherwise. */
int add_to_list(list *ll, char *item);    

/* Removes the string from the front of the list and* returns a pointer to it. The caller is expected to free* the string returned when finished with it. */
char *remove_from_list(list *ll);   

/* Prints every string in the list, with a new line* character at the end of each string */
void print_list(list *ll);     


/* Flushes (clears) the entire list and re-initializes the* list. The passed pointer llshould still point to a* valid, emptylistwhen this function returns. Any memory* allocated to store items in the listshould be freed. */
void flush_list(list *ll);     


/* De-allocates all data for the list. Ensure all memory* allocated for this list is freed, including any* allocated strings and the list itself.*/
void free_list(list *ll);

#endif
