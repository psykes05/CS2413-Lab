//Lab1
 
struct ListNode* removeElements(struct ListNode* head, int val) {

    while(head!=NULL && head->val==val){
        struct ListNode* temp=head;
        head=head->next;
        free(temp);

    }
    
    struct ListNode* current= head;
    struct ListNode* previous= NULL;
    
    while(current!=NULL){
        if(current->val==val){
            previous->next = current->next;
            free(current);
            current=previous->next;
            

        }
        else{
            previous=current;
            current=current->next;
        }
 

    }
return head;
}



//Lab2


#include <stdio.h>
#include <stdlib.h>


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        
        prev = current;        
        current = next;        
    }

    return prev;  
}
