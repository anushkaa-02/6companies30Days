#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        struct Node *p;
       struct Node *q;
       p=head;
       while(1){
           for(int i=0; i<M-1 ;i++){
               if(p==NULL)
                   return;
               p=p->next;
           }
           if(p==NULL)
               return;
           q=p;
           for(int i=0; i<N ;i++){
               if(q==NULL){
                   p->next=NULL;
                   return;
               }
               q=q->next;
           }
           if(q==NULL){
                   p->next=NULL;
                   return;
               }
           p->next=q->next;
           p=q->next;
       }
       return;
    }
};

int main()
{
	int t,n1;
	cin>>t;
	while(t--){
		cin>>n1;
		int m,n;
		cin>>m;
		cin>>n;
		insert (n1);
		Solution ob;
		ob.linkdelete(start,m,n);
		printList(start);
		
	}
	return 0;
}
