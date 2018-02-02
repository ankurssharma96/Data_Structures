#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node *head1=NULL,*head2=NULL;

void insert_at_end1(int item){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	if(head1==NULL){
		head1=newnode;
	}
	else{
		struct node* ptr=head1;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}

void insert_at_end2(int item){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	if(head2==NULL){
		head2=newnode;
	}
	else{
		struct node* ptr=head2;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}


void delete_at_end1(){
	if(head1==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr=head1;
	if(ptr->next==NULL){
		head1=NULL;
		free(ptr);
		return;
	}
	struct node* q=head1;
	while(ptr->next){
		q=ptr;
		ptr=ptr->next;
	}
	q->next=NULL;
	free(ptr);
}
void delete_at_end2(){
	if(head2==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr=head2;
	if(ptr->next==NULL){
		head2=NULL;
		free(ptr);
		return;
	}
	struct node* q=head2;
	while(ptr->next){
		q=ptr;
		ptr=ptr->next;
	}
	q->next=NULL;
	free(ptr);
}

void traversal(){
	struct node* ptr=head1;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void merge_list(){
	struct node* ptr1=head1;
	struct node* ptr2=head2;
	struct node* temp;
	if(ptr2->data<ptr1->data){
		while(ptr2 && ptr2->data<ptr1->data){
			temp=ptr2;
			ptr2=ptr2->next;
		}
		temp->next=head1;
		head1=head2;
	}
	while(ptr2 && ptr1){
		if(ptr2->data > ptr1->data && ptr1->next==NULL){
			ptr1->next=ptr2;
			return;
		}
		else if(ptr2->data > ptr1->data && ptr2->data < ptr1->next->data){
			struct node* temp1=ptr2->next;
			ptr2->next=ptr1->next;
			ptr1->next=ptr2;
			ptr2=temp1;
			ptr1=ptr1->next;
		}
		else if(ptr2->data==ptr1->data){
			ptr2=ptr2->next;
		}		
		else
			ptr1=ptr1->next;
		
		if(ptr2 && ptr1==NULL){
			ptr1=head1;
			while(ptr1->next){
				ptr1=ptr1->next;
			}
			ptr1->next=ptr2;
		}
	}
}

	

int main(){
	char cho='y';
	while(cho=='y' || cho=='Y'){
		cout<<"\nEnter your choice :\n";
		cout<<"1.Insert at end of first LL.\n";
		cout<<"2.Delete at end of first LL.\n";
		cout<<"3.Insert at end of second LL.\n";
		cout<<"4.Delete at end of second LL.\n";
		cout<<"5.Merge the two linked lists.\n";		
		cout<<"6.Traversal of first LL.\n";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter item to be inserted: ";
				int item;
				cin>>item;
				insert_at_end1(item);
				break;
			}
			case 2:{
				delete_at_end1();
				break;
			}
			case 3:{
				cout<<"Enter item to be inserted: ";
				int item;
				cin>>item;
				insert_at_end2(item);
				break;
			}
			case 4:{
				delete_at_end2();
				break;
			}
			case 5:{
				cout<<"Merging the two lists... ";
				merge_list();
				break;
			}
			case 6:{
				traversal();
				cout<<endl;
				break;
			}
			default :{
				cout<<"Enter correct choice"<<endl;
				break;
			}
		}
		cout<<"Press y to continue...";
		cin>>cho;
	}
	
}
