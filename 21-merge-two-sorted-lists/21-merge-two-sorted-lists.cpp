/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode=new ListNode(-1);
        
        ListNode* res=dummyNode;
        
        ListNode* p1=list1;
        ListNode*p2=list2;
        
        
        while(p1!=NULL && p2!=NULL)
        {
           if(p1->val<p2->val)
           {
               ListNode* addingNode=new ListNode(p1->val);
                res->next=addingNode;
               res=res->next;
               p1=p1->next;
               
           }
            else
                
            {
                ListNode* addingNode=new ListNode(p2->val);
                
                res->next=addingNode;
                res=res->next;
                p2=p2->next;
                
                
            }
        }
       if(p1!=NULL )
           res->next=p1;
        
        if(p2!=NULL)
            res->next=p2;
        
        
        return dummyNode->next;
        
    }
};