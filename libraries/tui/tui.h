#ifdef _WIN32
    #define CLEARCMD "cls"
#else
    #define CLEARCMD "clear"
#endif

void flushBuffer();
void pausar();
void separador(int largura, char caractere, int espacoAntes, int espacoDepois);
void titulo(int largura, char caractere, char *titulo, int centrar, int espacoAntes, int espacoDepois);
void sub_titulo(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois);
void menu(
            int largura, // largura do menu
            char caractere, // caractere principal construir o menu
            char caractere_sec, // caractere secundário para separadores internos
            char *titulo, // titulo do menu
            int option_size, // necessário para o array options
            int n_options, // numero de opções
            char options[n_options][option_size], // array de opções a apresentar ao utilizador
            int option_type, // se a opção é um numero ou um caractere 0 - numero !0 - alfa
            char exit_option, // char para a opção de saida
            char *exit_text, // texto da opção de saida
            int espacoAntes, // espaços antes do menu
            int espacoDepois // espaços depois do menu
        );