#include <stdio.h>	// predprocesorju pove naj vključi to datoteko (nadomesti to vrstico z vsebino)

int main(){
	
	int prvo = getchar() - '0';
	getchar();
	int drugo = getchar() - '0';
	
	int vsota = (prvo + drugo) % 10;
	
	putchar('0' + vsota);
	putchar('\n');
	
	return 0;
}


