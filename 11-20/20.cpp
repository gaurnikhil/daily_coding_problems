#include <bits/stdc++.h>
#include <time.h>
using namespace std;
 
//Solution1 
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        int len1 = 0;
        int len2 = 0;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1){
            len1++;
            temp1 = temp1->next;
        }
        
        while(temp2){
            len2++;
            temp2 = temp2->next;
        }
        
        int p;
        if(len1 > len2){
            p = len1 - len2;
            temp2 = headB;
            temp1 = headA;
            
            for(int i=0; i<p; i++){
                temp1 = temp1->next;
            }
        }
        else{
            p = len2 - len1;
            temp2 = headB;
            temp1 = headA;
            
            for(int i=0; i<p; i++){
                temp2 = temp2->next;
            }
        }
        
        while(temp1 && temp2){
            if(temp1 == temp2)
                return temp1;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return NULL;
        
    }
//Solution2

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}

