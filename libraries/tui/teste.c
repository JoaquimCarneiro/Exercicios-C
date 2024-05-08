#include <stdio.h>
#include "tui.h"

int main(){
	int option_size = 50, n_options = 5;
	char options[n_options][option_size] = {
		"Opção 1",
		"opção 2",
		"opção 3",
		"opção 4",
		"opção 5"
	};
	menu(96, '#', "Teste de Menu", 50, 5, options, 0, 1);
	return 0;
}
