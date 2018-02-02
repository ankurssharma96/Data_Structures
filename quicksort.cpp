#include<iostream>
using namespace std;
int partition(int *ar,int low,int high){
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(ar[j]<=ar[high]){
			i++;
			swap(ar[i],ar[j]);
		}
	}
	swap(ar[i+1],ar[high]);
	return i+1;
}
void quicksort(int *ar,int low,int high){
	if(low<high){
		int pivot=partition(ar,low,high);
		quicksort(ar,low,pivot-1);
		quicksort(ar,pivot+1,high);
	}
	
}
int main(){
	int ar[]={5,70,85,25,15,6,4,99};
	int low,high,pivot;
	low=0;
	high=sizeof(ar)/sizeof(int);
	high=high-1;
	quicksort(ar,low,high);
	for(int i=0;i<=high;i++){
		cout<<ar[i]<<" ";
	}
}
