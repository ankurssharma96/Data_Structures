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
		newnode->next=head;
	}
	else{
		struct node *temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		newnode->next=head;
		head=newnode;
		temp->next=head;
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
		newnode->next=head;
	}
	else{
		struct node* ptr=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=head;
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
		newnode->next=head;
		return;
	}
	else if(pos==1){
		struct node* ptr=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		newnode->next=head;
		head=newnode;
		ptr->next=head;
		return;
	}
	struct node* ptr=head;
	struct node* q;
	int temp=1;
	while(temp<pos){
		q=ptr;
		ptr=ptr->next;
		temp++;
		if(ptr==head && temp<pos){
			cout<<"Position not found.\n";
			return;
		}
		
	}
	q->next=newnode;
	newnode->next=ptr;
}

void delete_at_beg(){
	struct node* temp=head;
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr=head;
	if(ptr->next==head){
		free(ptr);
		head=NULL;
		return;
	}
	while(ptr->next!=head){
		ptr=ptr->next;
	}

	head=head->next;
	ptr->next=head;
	free(temp);	
}

void delete_at_end(){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr=head;
	if(ptr->next==head){
		free(ptr);
		head=NULL;
		return;
	}
	struct node* q=head;
	while(ptr->next!=head){
		q=ptr;
		ptr=ptr->next;
	}
	q->next=head;
	free(ptr);
}

void delete_at_pos(int pos){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* ptr1=head;
	while(ptr1->next!=head){
		ptr1=ptr1->next;
	}
	
	if(pos==1){
		struct node* ptr=head;
		if(head==ptr->next){
			head=NULL;
			free(ptr);
			return;
		}
		head=ptr->next;
		free(ptr);
		ptr1->next=head;
		return;
	}
	struct node* ptr=head;
	struct node* q=head;
	int ctr=1;
	while(ctr<=pos){
		if(ptr==head && ctr!=1){
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
	if(head==NULL){
		cout<<"List empty...\n";
		return;
	}
	struct node* ptr=head;
	if(ptr->next==head){
		cout<<ptr->data<<" ";
		cout<<endl;
		return;
		}
	while(ptr->next!=head){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<ptr->data<<" ";
	cout<<endl;
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
			default :{
				cout<<"Enter correct choice"<<endl;
				break;
			}
		}
		cout<<"Press y to continue...";
		cin>>cho;	
	}
	
}
