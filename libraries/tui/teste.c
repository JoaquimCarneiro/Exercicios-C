#include <stdio.h>
#include "tui.h"

#define OPTION_SIZE 50
#define N_OPTIONS 5

int main(){
	char options[N_OPTIONS][OPTION_SIZE] = {
		"Opção 1",
		"opção 2",
		"opção 3",
		"opção 4",
		"opção 5"
	};
	menu(96, '#', "Teste de Menu", 50, 5, options, 0, 1);
	return 0;
}
