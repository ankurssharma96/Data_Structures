#include<iostream>
using namespace std;
class stack
{
	public:
	char stk[100];
	int top;
    stack()
	{
 	   top=-1;
    }
    char toop(){
    	return stk[top];
	}
	void push(char x)
	{
	    stk[++top]=x;
	}
    char pop()
    {
        return stk[top--];
    }
    void display()
    {
    	for(int i=0;i<=top;i++)
	    cout <<stk[i];
    }
};
 
int main()
{
    int ch;
    string q;
    cin>>q;
    stack st;
    stack p;
    st.push('(');
    for(int i=0;i<q.size();i++){
    	if(q[i]=='+'||q[i]=='-'||q[i]=='*'||q[i]=='/'||q[i]=='^'||q[i]=='('||q[i]==')'){
    		if(q[i]=='('){
    			st.push(q[i]);
			}
			else if(q[i]==')'){
				while(st.toop()!='(')  {
					ch=st.pop();   
					p.push(ch);
				}
				st.pop();
			}
			else if(st.toop()=='^'){
    			ch=st.pop();   
				p.push(ch);	
				st.push(q[i]);	
			}
			else if((st.toop()=='*' || st.toop()=='/') && q[i]!='^'){
    			ch=st.pop();   
				p.push(ch);		
				st.push(q[i]);	
			}
			else if((st.toop()=='+' || st.toop()=='-') && (q[i]!='^' && q[i]!='*' && q[i]!='/')){
    			ch=st.pop();   
				p.push(ch);	
				st.push(q[i]);	
			}
			else{
				st.push(q[i]);
			}
		}
		else{
			p.push(q[i]);
		}
	}
	while(st.toop()!='('){
		ch=st.pop();   
		p.push(ch);
	}
	st.pop();
	p.display();
}
