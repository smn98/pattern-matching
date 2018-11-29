#include<stdio.h>
#include<string.h>

void naive(char* text, char* pattern){
	int m = strlen(text);
	int n = strlen(pattern);
	
	for(int i=0; i<=m-n; i++){
		int j=0;
		for(j=0;j<n;j++)
			if(text[i+j] != pattern[j])
				break;
		
		if(j==n)
			printf("Pattern found at index: %d\n", i);		
	}
}

int main(){
	char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    naive(txt, pat); 
    return 0; 
}
