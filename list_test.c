#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{

    printf("wassup");

    char item1[] = "Hi";
    char item2[] = "Hey";
    char item3[] = "Hola";
    char item4[] = "Salut";

    //First test of list implementation
    list *test1 = create_list();
    add_to_list(test1, item1);
    //print_list(test1);

    /*
    add_to_list(list *ll, char *item)
    remove_from_list(list *ll)
    print_list(list *ll)
    flush_list(list *ll)
    free_list(list *ll)

    */

        return 0;
}
