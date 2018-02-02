#include<iostream>
using namespace std;
//Function for insertion sort as per required in shell sort...
//To exactly perform the insertion sort, substitute gap by 1...
void insertion_sort(int *arr,int size,int gap){
	if(size==0){
		cout<<"NO ELEMENT FOUND!";
		exit(0);	
	}
	for(int i=0;i<gap;i++){
		for(int j=i+gap;j<size;j=j+gap){
			int key=arr[j];
			int k=j-gap;
			while(k>=i && key<arr[k]){
				arr[k+gap]=arr[k];
				k=k-gap;
			}
			arr[k+gap]=key;
		}
	}
}
int main(){
	int ar[]={35,33,42,10,14,19,27,44};
	int size=sizeof(ar)/sizeof(int);
	int gap=size/2;
	while(gap>=1){
		insertion_sort(&ar[0],size,gap);
		gap=gap/2;
	}
	for(int i=0;i<size;i++){
		cout<<ar[i]<<" ";
	}
}
