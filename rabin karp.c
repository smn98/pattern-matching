#include<stdio.h>
#include<string.h>
#include<math.h>
#define d 256

void rabin(char* text, char* pattern, int q){
	
	int n = strlen(text);
	int m = strlen(pattern);
	int h = pow(d,m-1);
	h = h%q;
	int p = 0;
	int t = 0;
	
	for(int i=0; i<m; i++){
		p = (d*p + pattern[i])%q;
		t = (d*t + text[i])%q;
	}
	
	for(int i=0; i<=n-m; i++){
		if(p == t){
			int j=0;
			for(j=0; j<m; j++)
				if(text[i+j] != pattern[j])
					break;	
			if(j==m)
				printf("Pattern found at index: %d\n", i);		
		}
		t = (d*(t - text[i]*h) + text[i+m])%q;
		if(t<0)
			t = t + q;
	}
}

int main(){
	char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    int q = 101;
    rabin(txt, pat, q); 
    return 0; 
}
