#include "revert_list.h"
NODE ListRevert(NODE node){
	NODE pre=node;
	NODE current=node->next;
	NODE last=node->next->next;
	pre->next=nullptr;
	while(last!=nullptr){
		current->next=pre;
		pre=current;
		current=last;
		last=last->next;
	}
	current->next=pre;
	node=current;
	return node;
		
}
void DisList(NODE p){
	cout<<"ListRevert \n";
	while(p!=nullptr){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<"\n";
}
void TestListRevert(){
	
	NODE head=new struct Node;
	NODE p=head;
	for(int i=0;i<10;i++){
		
		NODE temp=new struct Node;
		temp->data=i;	
		p->next=temp;
		p=temp;
	}	
	head=ListRevert(head);
	DisList(head);
	

}
