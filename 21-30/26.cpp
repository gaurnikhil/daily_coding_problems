ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        
        ListNode* curr = head;
        
        for(int i=0; i<n-1; i++){
            curr = curr->next;
        }
        
        ListNode* prev = NULL;
        ListNode* node = head;
        
        while(curr->next){
            curr = curr->next;
            prev = node;
            node = node->next;
        }
        
        if(prev == NULL){
            head = head->next;
        }
        else{
            prev->next = node->next;
            node->next = NULL;
        }
        
        return head;
    }