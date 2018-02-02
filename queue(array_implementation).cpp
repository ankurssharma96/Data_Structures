#include<iostream>
using namespace std;
class queue{
	int q[5];
	int rear=-1;
	int front=-1;
	public:
		void queue_insert(int item){
			if((front==0 && rear==(4)) || front==rear+1){
				cout<<"Overflow..."<<endl;
				return;
			}
			if(front==-1){
				front=rear=0;
			}
			else{
				rear=(rear+1)%5;
			}
			q[rear]=item;
		}
		void queue_delete(){
			if(front==-1){
				cout<<"underflow"<<endl;
				return;
			}
			int item=q[front];
			if(front==rear){
				front=rear=-1;
			}
			else
				front=front+1;
		}
		void display(){
			if(front==-1){
				cout<<"queue empty"<<endl;
			}
			else{
				int temp=front;
				while(temp!=rear){
					cout<<q[temp]<<" ";
					temp=(temp+1)%5;
				}
				cout<<q[rear];
			}
		}
};
int main(){
	queue qu; char cho='y';
	while(cho=='y' || cho=='Y'){
		cout<<"\nEnter your choice :\n";
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter item to be inserted: ";
				int item;
				cin>>item;
				qu.queue_insert(item);
				break;
			}
			case 2:{
				qu.queue_delete();
				break;
			}
			case 3:{
				qu.display();
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
