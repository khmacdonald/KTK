
#ifndef _KTK_LINKED_LIST_H_
#define _KTK_LINKED_LIST_H_

#include "ktk_error.h"

struct linked_list_node
{
    struct linked_list_node * blink;    /**< links to the forward node */
    struct linked_list_node * flink;    /**< links to the backward node */
    void * data;                        /**< the data in the node */
};

typedef struct linked_list_node KTK_LL_NODE, *pKTK_LL_NODE;
typedef struct linked_list_node KTK_LL_HEAD, *pKTK_LL_HEAD;

/**
 * @brief Creates a linked list node containing the data passed to function
 *
 * @param data - pointer to data for the node to contain
 *
 * @return A pointer to a linked list node if successful
 * @return NULL pointer if failure
 */
pKTK_LL_NODE KtkCreateNode( void * data );

/**
 * @brief Treats the list as a stack and pops the head off the stack.  The
 *        forward link of the head becomes the head of the stack after pop.
 *
 * @param popped_node - this is where the popped node is upon return
 * @param head - the linked list off which to pop the head
 *
 *
 */
ktk_error_t KtkPopLL( pKTK_LL_NODE popped_node, pKTK_LL_HEAD head );

/**
 * @brief Pushes data onto a linked list stack
 *
 * @param head - the head of a linked list
 * @param data - the data to be put into a linked list
 *
 * @return 
 */
ktk_error_t KtkPushLL( pKTK_LL_HEAD head, void * data );

#endif