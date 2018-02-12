#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int k=0;
int selectionsort(int A[],int n){
	int i,j,count=0;
	for(i=0;i<n-1;i++){
		int min = i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min]) min = j;
		}
		if(i!=min){
			swap(A,i,min);
			count++;
		}
	}
	return count;
}
int main(){
	int n; scanf("%d",&n);
	int A[100];
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int count = selectionsort(A,n);
	//for(int i=0;i<n;i++) cout << A[i] << " ";

	cout <<endl<< count;
	return 0;
}