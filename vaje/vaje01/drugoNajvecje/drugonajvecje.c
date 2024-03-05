#include <stdio.h>

int main(){
	
	int n = getchar() - '0';
	getchar();
	
	int najvecje = -1;
	int drugoNajvecje = -1;
	
	for(int i = 0; i < n; i++){
		int novo = getchar() - '0';
		getchar();
		
		if(novo > najvecje){
			drugoNajvecje = najvecje;
			najvecje = novo;
		}
		else if(novo > drugoNajvecje){
			drugoNajvecje = novo;
		}
	}
	
	putchar(drugoNajvecje + '0');
	putchar('\n');
		
	return 0;
}
