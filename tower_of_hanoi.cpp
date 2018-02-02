#include<iostream>
using namespace std;
int count=0;
class stack
{
	public:
	int stk[100];
	int top;
    stack()
	{
 	   top=-1;
    }
    int toop(){
    	return stk[top];
	}
	void push(int x)
	{
	    stk[++top]=x;
	}
    int pop()
    {
        return stk[top--];
    }
    void display()
    {
    	for(int i=0;i<=top;i++)
	    	cout <<stk[i]<<" ";
	    cout<<endl;
    }
};
stack a,b,c;

void toh(int n, stack &beg, stack &aux, stack &end){
	if(n==1){
		int temp=beg.pop();
		end.push(temp);
		count++;
		cout<<endl<<endl<<"After Step : "<<count<<endl;
		cout<<"stack A: "; a.display();
		cout<<"stack B: "; b.display();
		cout<<"stack C: "; c.display();
		return; 
	}
	toh(n-1,beg,end,aux);
	int temp=beg.pop();
	end.push(temp);
	count++;
	cout<<endl<<endl<<"After Step : "<<count<<endl;
	cout<<"stack A: "; a.display();
	cout<<"stack B: "; b.display();
	cout<<"stack C: "; c.display();
	toh(n-1,aux,beg,end);
} 
 
int main(){
	cout<<"Enter the no. of discs: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		a.push(i+1);
	}
	toh(n,a,b,c);
}

