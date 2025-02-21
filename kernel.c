#define WHITE_TXT 0x07

void k_clear_screen();
unsigned int k_print(char *message, unsigned int line);

void k_main()
{
    k_clear_screen();
    k_print("Helloworld kernel", 0);
}

void k_clear_screen()
{
    char *vidmen = (char *) 0xb8000;
    unsigned int i = 0;
    while(i < (80 * 25 * 2)) 
    {
        vidmen[i] = ' ';
        i++;
        vidmen[i] = WHITE_TXT;
        i++;
    }
}

unsigned int k_print(char *message, unsigned int line)
{
    char *vidmen = (char *) 0xb8000;
    unsigned int i = 0;

    i = (line * 80 * 2);

    while (*message != 0)
    {
        if (*message == '\n')
        {
            line++;
            i = (line * 80 * 2);
            *message++;
        } else {
            vidmen[i] = *message;
            *message++;
            i++;
            vidmen[i] = WHITE_TXT;
            i++;
        }
        return(1);
    }
    
}

//ld: aviso: não foi possível localizar símbolo de entrada _start; usando o padrão 0000000000100000
//ld: kernel.o: na função "k_main":
//kernel.c:(.text+0xe): referência não definida para "_GLOBAL_OFFSET_TABLE_"
//ld: kernel.o: na função "k_clear_screen":
//kernel.c:(.text+0x3d): referência não definida para "_GLOBAL_OFFSET_TABLE_"
//ld: kernel.o: na função "k_print":
//kernel.c:(.text+0x88): referência não definida para "_GLOBAL_OFFSET_TABLE_"