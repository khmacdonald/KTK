/*
    Defines the functions that work with a basically defined linked list.  I
    don't think these functions are thread safe, so use with caution.
 */

#include <stdlib.h>

#include "ktk_error.h"
#include "ktk_linked_list.h"

/**
 * @brief Creates a linked list node containing the data passed to function
 *
 * @param data - pointer to data for the node to contain
 *
 * @return A pointer to a linked list node if successful
 * @return NULL pointer if failure
 */
pKTK_LL_NODE KtkCreateNode( void * data )
{
    pKTK_LL_NODE new_node = (pKTK_LL_NODE)calloc(1,sizeof(*new_node));
    
    if ( NULL!=new_node )
    {
        // set data structure values; initialize as a circular list
        new_node->blink = new_node;
        new_node->flink = new_node;
        new_node->data = data;
    }
    
    return new_node;
}

/**
 * @brief Treats the list as a stack and pops the head off the stack.  The
 *        forward link of the head becomes the head of the stack after pop.
 *
 * @param popped_node - this is where the popped node is upon return
 * @param head - the linked list off which to pop the head
 *
 * @return _KTK_SUCCESS if the node is successfully popped
 * @return _KTK_BADARGS if the arguments are not valid
 */
ktk_error_t KtkPopLL( pKTK_LL_NODE popped_node, pKTK_LL_HEAD head )
{
    ktk_error_t retval = _KTK_SUCCESS;
    
    if ( (NULL!=popped_node) && (NULL!=head) )
    {
        /* pop head off linked list */
        popped_node = head;
        
        /* adjust pointers for node removal */
        if ( head != head->flink )
        {
            /*
                        blink - head - flink
                        
                becomes
                
                        popped_node
                        blink - flink
             */
            head = popped_node->flink;          // the new head is the flink
            head->blink = popped_node->blink;   // the blink to the head is the blink to the popped node
            popped_node->blink->flink = head;   // the flink to the head's blink is the head
            
            /* isolate popped node */
            popped_node->flink = popped_node;   // set blink to itself
            popped_node->blink = popped_node;   // set flink to itself
        }
    }
    else
    {
        retval = _KTK_BADARGS;
    }
    return retval;
}


























