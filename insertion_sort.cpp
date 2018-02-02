#include<iostream>
using namespace std;
void insertion_sort(int *arr,int size){
	for(int j=1;j<size;j++){
		int key=arr[j];
		int i=j-1;
		while(i>=0 && key<arr[i]){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
}
int main(){
	int ar[]={35,33,42,10,14,19,27,44};
	int size=sizeof(ar)/sizeof(int);
	insertion_sort(&ar[0],size);
		
	for(int i=0;i<size;i++){
		cout<<ar[i]<<" ";
	}
}
