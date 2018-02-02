#include<iostream>
using namespace std;
int main()
{
	cout<<"Please input he length of array less than 50"<<endl;
	int n;
	cin>>n;
	int arr[50];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	char cha='Y';
		do{
		cout<<"1.Press 1 for insertion."<<endl;
		cout<<"2.Press 2 for deletion."<<endl;
		cout<<"3.Press 3 for search."<<endl;
		int ch;
		cin>>ch;
		switch(ch){
			case 1:{
				int num;
				cout<<"Enter value to be inserted."<<endl;
				cin>>num;
				if(n>49){
					cout<<"Array limit exceeded."<<endl;
				}
				else{
					arr[n]=num;
					n++;
				}
				for(int i=0;i<n;i++){
					cout<<arr[i]<<" ";
				}
				break;
			}
			case 2:{
				cout<<"Enter value to be deleted.";
				int num;
				int temp=1;
				cin>>num;
				for(int i=0;i<n;i++){
					if(arr[i]==num){
						for(int j=i;j<n-1;j++){
							arr[j]=arr[j+1];
						}
						temp=0;
						n--;
					}
				}
				if(temp==1){
					cout<<"Element not found."<<endl;
					}
				for(int i=0;i<n;i++){
					cout<<arr[i]<<" ";
				}
				break;
			}
			case 3:{
				cout<<"Enter value to be searched:"<<endl;
				int num;
				cin>>num;
				for(int i=0;i<n;i++){
					if(arr[i]==num){
					cout<<"Value found at: "<<i+1<<" index."<<endl;
					}
				}
				break;
			}
			
		}
		cout<<"Press Y/y to repeat above steps."<<endl;
		cin>>cha;
	}while(cha=='Y' || cha=='y');
}
