#include <stdio.h>
#include <stdbool.h>

int main(){
	
	int n = getchar() - '0';
	getchar();
	
	int prvo = -1;
	// ne deklarirajmo brez inicializacije ker dobi neko naključno vrednost ki je v pomnilniku
	bool vsaEnaka = true;
	
	for(int i = 0; i < n; i++){
		int stevilo = getchar() - '0';
		getchar();
		
		if(i == 0){
			prvo = stevilo;
		}
		else if(stevilo != prvo){
			vsaEnaka = false;
			break;
		}
		
	}
	
	putchar(vsaEnaka ? '1' : '0');
	putchar('\n');	
	return 0;
}
