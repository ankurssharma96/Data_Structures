#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
	struct node* prev;
}*head=NULL;

void insert_at_beg(int item){
	struct node* newnode=(struct node*) malloc (sizeof(struct node));
	if(!newnode){
		cout<<"Memory not available.\n";
		return;
	}
	newnode->data=item;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		head->prev=newnode;
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
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
	}
	else{
		struct node* ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=ptr;
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
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
	else if(pos==1){
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		return;
	}
	struct node* ptr=head;
	int temp=1;
	while(temp<pos){
		if(ptr->next==NULL){
			newnode->prev=ptr;
			ptr->next=newnode;
			return;
		}
		ptr=ptr->next;
		temp++;
	}
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
	newnode->next=ptr;
	ptr->prev=newnode;
}

void delete_at_beg(){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	struct node* temp=head;
	if(temp->next==NULL){
		head=NULL;
		free(temp);
		return;
	}
	head=head->next;
	head->prev=NULL;
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
	while(ptr->next){
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
}

void delete_at_pos(int pos){
	if(head==NULL){
		cout<<"List is empty...\n";
		return;
	}
	if(pos==1){
		struct node* ptr=head;
		if(ptr->next==NULL){
			head=NULL;
			free(ptr);
			return;
		}
		head=ptr->next;
		head->prev=NULL;
		free(ptr);
		return;
	}
	struct node* ptr=head;
	int ctr=1;
	while(ctr<pos){
		if(ptr==NULL){
			cout<<"Position not found...\n";
			return;
		}
		ptr=ptr->next;
		ctr++;
	}
	if(ptr->next==NULL){
		ptr->prev->next=NULL;
		free(ptr);
		return;
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
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
