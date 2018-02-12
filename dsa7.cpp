#include <iostream>
using namespace std;

int main(){
	int n;
	int A[100];
	int E[100],O[100];
	cin >> n;
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<n;i++){
		E[i] = 0;
		O[i] = 0;
	}
	int i=0,j=0;
	for(int k=0;k<n;k++){
		if(A[k]%2==0){
			E[i] = A[k];
			i++;
		}
		else{
			O[j] = A[k];
			j++;
		}
	}
	int ne = i, no = j;
	i=0;j=0;
	for(int i=0;i<ne;i++) cout << E[i] << " ";
	for(int j=0;j<no;j++) cout << O[j] << " ";
	return 0;
}