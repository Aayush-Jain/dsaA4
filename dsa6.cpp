#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void update(char str[]){
	int len = strlen(str);
	str[len+2] = '\0';
	str[len] = ' '; str[len+1] = ' ';
	for(int i=len-1;i>=0;i--) str[i+1] = str[i];
	str[0] = ' ';
}
int main(){
	char str[1000];
	scanf("%[^\n]%*c", str);
	update(str);
	int len = strlen(str);

	int i = len-2;
	while(i>=0){
		if(str[i]==' '){
			int j = i+1;
			while(1){
				if(str[j]==' ') break;
				cout << str[j];
				j++;
			}
			cout << ' ';
		}
		i--;
	}

	
	return 0;
}
