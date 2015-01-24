#include <stdlib.h>
#include ".\linkedList.h"
/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
 // TODO To be implemented
    
    //first � un puntatore al primo elemento lista
    // temp � un nodo generico
    LLElement * temp;   
    temp=(LLElement *)malloc(sizeof(LLElement)); 
    
    if(temp!=NULL){
       temp=(LLElement *)malloc(sizeof(LLElement));
       temp->key=key;
       temp->next=first;
    }
    return (temp);
}

/*
  * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    // TODO To be implemented
    
    LLElement ** temp;
    LLElement * new;  // nuovo vagone di coda
    new=(LLElement *)malloc(sizeof(LLElement));
    temp=&first;
  
     while (*temp!=NULL){
        temp=&(*temp)->next;  
    }
 
     new->next=NULL;
     new->key=key;
     *temp=new;
    return (first);  // ritorna il puntatore iniziale della lista 

}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    // TODO To be implemented

    LLElement * new;
    LLElement * temp;
    LLElement * scambia;
    new=(LLElement*)malloc(sizeof(LLElement)); 
    new->key=key;
    int i=0;
    temp=first;
    
    while (i<(position-1))
    {
        temp=temp->next;
        i++;
    }
    
    scambia=temp->next;
    temp->next=new;
    new->next=scambia;

//    free(scambia);
    return (first);
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    // TODO To be implemented

    int i=0;
    LLElement * temp;
    temp=first;
    while (temp!=NULL){
                      //scorro la lista
        temp=temp->next;  
        i++; 
    }
    return (i);
}   
/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {
    // TODO To be implemented

    LLElement * temp;
    temp = first;
    int i=0;
    while (i<position)
    {
        temp=temp->next;
        i++;
    }
    return (temp->key);
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    LLElement * temp;
    int size;
    int i=0;
    size = LLSize(first);
    temp = first;
    while (i<startPosition)
    {
        temp = temp->next;
        i++;
    }       
    while (startPosition<size)
    {   
        if (temp->key == key){
            return(startPosition);
        }
        else{
            temp=temp->next;
            startPosition++;
/*
            if(temp->next == NULL){
                return -1;
*/
            }
        }
    }

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    // TODO To be implemented
    LLElement *temp;
    temp=first;
    first=first->next;
    free(temp);
    return (first);
    
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) {
    // TODO To be implemented

     LLElement ** temp;
     temp=&first;
     while ((*temp)->next!=NULL){
        temp=&(*temp)->next;  
    }
     *temp=NULL;
    free(*temp);
    return (first);

}
/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    // TODO To be implemented
    int i=0;
    LLElement * prox;
    LLElement ** temp;
    
    temp = &first;
    
    while (i < position){
        temp=&((*temp)->next);
        i++;
    }
    prox = (*temp)->next;
    free(temp);
    *temp=prox;
    return (first);
}
