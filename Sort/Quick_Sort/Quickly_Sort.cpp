#include<iostream>

using std::cout;
using std::endl;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *arr,int front,int end){
	int pivot = arr[end];
	int i = front - 1;
	for(int j=front;j<end;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	i++;
	swap(&arr[i],&arr[end]);
	return i;
}

void QuickSort(int *arr,int front,int end){
	if(front < end){
		int pivot = Partition(arr,front,end);
		QuickSort(arr,front,pivot-1);
		QuickSort(arr,pivot+1,end);
	}
}

void PrintArray(int *arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<< " ";
	}
	cout<< endl;
}

int main(){
	int arr[] = {9,5,11,2,12,1,3,7,8,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"original:\n"<<endl;
	PrintArray(arr,n);
	QuickSort(arr,0,n-1);
	cout<<"sorted:\n";
	PrintArray(arr,n);
	return 0;
} 

















