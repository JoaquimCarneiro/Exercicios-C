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
void menu(int largura, char caractere, char *titulo, int espacoAntes, int espacoDepois);