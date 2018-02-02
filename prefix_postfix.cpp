#include<iostream>
#include<string>
using namespace std;
class stack
{
	public:
	string stk[100];
	int top;
    stack()
	{
 	   top=-1;
    }
    string toop(){
    	return stk[top];
	}
	void push(string x)
	{
	    stk[++top]=x;
	}
    string pop()
    {
        return stk[top--];
    }
    void display()
    {
    	for(int i=top;i>=0;i--)
	    cout <<stk[i];
    }
};
 
int main()
{
	string post;
	cin>>post;
	stack operand;
	stack st;
	for(int i=post.length()-1;i>=0;i--){
		if(post[i]=='+'|| post[i]=='-'|| post[i]=='*'|| post[i]=='/'|| post[i]=='^'){
			string op1=st.pop();
			string op2=st.pop();
			char t=post[i];
			string operat(1,t);
			string conc=op1+op2+operat;
			st.push(conc);
		}
		else{
			char t=post[i];
			string temp(1,t);                                                              
			st.push(temp);
		}
	}
	st.display();
}
