#include <iostream>
using namespace std;

int step1(int L[],int R[],int n){
	int nl = n,nr = n,i=0,j=0,stud_in=0,max=-1,time=0;
	while(i<nl && j<nr){
		if(L[i]<R[j]){
			stud_in++;
			if(stud_in>max){
				max = stud_in;
				time = i;
			}
			i++;
		}
		else{
			stud_in--;
			j++;
		}
	}
	return time;
}
int main(){
	int n; cin >> n;
	int A[100],B[100];
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<n;i++) cin >> B[i];
	int stud_in = step1(A,B,n);
	int max = -1;
	cout << A[stud_in];

	return 0;	
}