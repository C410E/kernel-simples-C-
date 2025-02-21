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
    
}