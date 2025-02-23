#define WHITE_TXT 0x07

void k_clear_screen();
unsigned int k_printf(char *message, unsigned int line);
void K_calc_print(int a, int b, unsigned int line);

void k_main()
{
    k_clear_screen();
    k_printf("Helloworld kernel", 0);

    K_calc_print(5, 5, 2);
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

unsigned int k_printf(char *message, unsigned int line)
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
        
    }
    return(1);
}

void int_to_str(int num, char *str)
{
    int i = 0, j, temp;
    int is_negative = 0;

    if (num == 0) 
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }

    if (is_negative)
    {
        str[i++] = '-';
    }

    str[i] = '\0';

    for (j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void K_calc_print(int a, int b, unsigned int line)
{
    char result_str[20];

    int sum = a + b;
    k_printf("Sum: ", line);
    int_to_str(sum, result_str);
    k_printf(result_str, line + 1);

    int diff = a - b;
    k_printf("Subtracao: ", line + 2);
    int_to_str(diff, result_str);
    k_printf(result_str, line + 3);
}