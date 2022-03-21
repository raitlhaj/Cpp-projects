
 #include<iostream>
 
 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        int i=0,nb=0,l=0;
        ListNode *first= new ListNode();
        ListNode *last= new ListNode();
        ListNode *tmp= new ListNode();
        
        //nb elements
        while(last)
        {
            last=last->next;
            nb++;
        }
        
        if(nb<=k)
            l=k;
        else if(k==0 )
            return head;
        else
            l=nb%k;
        
        if(!head || !head-> next ) return head;
        else
        {
               tmp=head;
               first=head;
                while(i<l)
                {
                    first=new ListNode();
                    last=tmp;                //first element
                    //search for the last 
                        while(last->next && last->next->next)
                        {
                            last=last->next;
                            nb++;
                        }
                    first->val=last->next->val;
                    first->next =tmp;  //secend element
                    last->next=nullptr;
                    

                    tmp=first;

                    i++;    
                } 

            
        }
            
        
       
        return first;
    }
};

int main()
{
    ListNode *mylist,*T;
    Solution s;
    int *T =new T[]{1,2,3};

    mylist=s.rotateRight(T,2);

    return 0;
}