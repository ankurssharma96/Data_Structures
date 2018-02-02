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
    	for(int i=top;i>=0;i--)
	    cout <<stk[i];
    }
};
 
int main()
{
 	int ch;
    string q;
    cin>>q;
    int len=q.length();
    char qrev[len];
    for(int i=0;i<len;i++){
    	if(q[i]=='(')
    		qrev[len-i-1]=')';
    	else if(q[i]==')')
    		qrev[len-i-1]='(';
    	else qrev[len-i-1]=q[i];
	}
	for(int i=0;i<len;i++){
		q[i]=qrev[i];
	}   
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
