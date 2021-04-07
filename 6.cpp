// lets say the addresses of the nodes of our linked list are
// A->B->C->D
// xor_val = (address of prev node ^ address of next node)

// Now lets suppose we are at index C and want to go to index D
// so address D = (C->xor_val ^ B)
// proof : D = (B^D)^B
//         D = B^B^D
//         D = 0^D
//         D = D
//         LHS = RHS


struct XListNode{
    int val;
    XListNode* xor_val;
    
    XListNode(int val){
        this->val = val;
        this->xor_val = NULL;
    }
    
};

XListNode* XOR(XListNode* node1, XListNode* node2){
    return (XListNode*)(uintptr_t(node1) ^ uintptr_t(node2));
}

class implement{
public :
    
    implement(){
      
    } 
    
  //add elements to the linked List
    XListNode* add(XListNode* head, int val){
        XlistNode* node = new XlistNode(val);
        
        node->xor_val = XOR(NULL, head);
        
        if(head){
            head->xor_val = XOR(node, XOR(head->xor_val, NULL));
        }
        
        head = node;
        
        return head;
    }
    
    //get the element at index i of the linked List
    int get(XListNode* head, int index){
        int i=1;
        
        XListNode* temp = head;
        XListNode* prev = NULL;  //we will keep track of an prev point to xor the current xor_val to get to the next node
        
        while(temp && i<index){
            XListNode* next = XOR(prev, temp->xor_val);
            prev = temp;
            temp = next;
        }
        
        return temp ? temp->val : -1;
    }
};

