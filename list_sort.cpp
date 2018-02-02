#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
}*head=NULL;

void insert_at_beg(int item){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		newnode->next=head;
		head=newnode;
	}
}

void insert_at_end(int item){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		struct node* ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}

void insert_at_pos(int item, int pos){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
	else if(pos==1){
		newnode->next=head;
		head=newnode;
		return;
	}
	struct node* ptr=head;
	struct node* q;
	int temp=1;
	while(ptr && temp<pos){
		q=ptr;
		ptr=ptr->next;
		temp++;
	}
	q->next=newnode;
	newnode->next=ptr;
	
}

void delete_at_beg(){
	struct node* temp;
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
}

void delete_at_end(){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr=head;
	if(ptr->next==NULL){
		head=NULL;
		free(ptr);
		return;
	}
	struct node* q=head;
	while(ptr->next){
		q=ptr;
		ptr=ptr->next;
	}
	q->next=NULL;
	free(ptr);
}

void delete_at_pos(int pos){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	if(pos==1){
		struct node* ptr=head;
		head=ptr->next;
		free(ptr);
		return;
	}
	struct node* ptr=head;
	struct node* q=head;
	int ctr=1;
	while(ctr<pos){
		if(ptr==NULL){
			cout<<"Position not found...\n";
			return;
		}
		q=ptr;
		ptr=ptr->next;
		ctr++;
	}
	q->next=ptr->next;
	free(ptr);
}

void traversal(){
	struct node* ptr=head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void sort_list(){
	struct node* ptr=head;
	if(ptr->next==NULL){
		return;
	}
	while(ptr){
		struct node* ptr1=head;
		struct node* temp=ptr1->next;
		while(temp){
			if(temp->data < ptr1->data){
				int temp1=ptr1->data;
				ptr1->data=temp->data;
				temp->data=temp1;
			}
			ptr1=ptr1->next;
			temp=temp->next;
		}
		ptr=ptr->next;
	}
}

int main(){
	char cho='y';
	while(cho=='y' || cho=='Y'){
		cout<<"\nEnter your choice :\n";
		cout<<"1.Insert at beginning.\n";
		cout<<"2.Insert at end.\n";
		cout<<"3.Insert at particular position.\n";
		cout<<"4.Delete at beginning.\n";
		cout<<"5.Delete at end.\n";
		cout<<"6.Delete at particular position.\n";
		cout<<"7.Traversal\n";
		cout<<"8.Sort the linked list.\n";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter item to be inserted: ";
				int item;
				cin>>item;
				insert_at_beg(item);
				break;
			}
			case 2:{
				cout<<"Enter item to be inserted: ";
				int item;
				cin>>item;
				insert_at_end(item);
				break;
			}
			case 3:{
				cout<<"Enter item to be inserted: ";
				int item,pos;
				cin>>item;
				cout<<"Enter position of element to be inserted: ";
				cin>>pos;
				insert_at_pos(item,pos);
				break;
			}
			case 4:{
				delete_at_beg();
				break;
			}
			case 5:{
				delete_at_end();
				break;
			}
			case 6:{
				int pos;
				cout<<"Enter position of element to be deleted: ";
				cin>>pos;
				delete_at_pos(pos);
				break;
			}
			case 7:{
				traversal();
				cout<<endl;
				break;
			}
			case 8:{
				sort_list();
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
