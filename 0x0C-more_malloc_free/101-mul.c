#include <main.h>
#include <stdlib.h>
#include <stdio.h>

int find_len(const char *str);
char *create_xarray(int size);
const char *iterate_zeroes(const char *str);
int get_digit(char c);
void get_prod(char *prod, const char *mult, int digit, int zeroes);
void add_nums(char *final_prod, const char *next_prod, int next_len);

/**
 * find_len - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_len(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

/**
 * create_xarray - Creates an array of chars and initializes it with
 *                 the character 'x'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 *
 * Description: If there is insufficient space, the
 *              function exits with a status of 98.
 * Return: A pointer to the array.
 */
char *create_xarray(int size)
{
    char *array = malloc((size + 1) * sizeof(char));
    if (array == NULL)
    {
        printf("Error\n");
        exit(98);
    }
    for (int i = 0; i < size; i++)
        array[i] = 'x';
    array[size] = '\0';
    return array;
}

/**
 * iterate_zeroes - Iterates through a string of numbers containing
 *                  leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
const char *iterate_zeroes(const char *str)
{
    while (*str && *str == '0')
        str++;
    return str;
}

/**
 * get_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 *
 * Description: If c is a non-digit, the function
 *              exits with a status of 98.
 * Return: The converted int.
 */
int get_digit(char c)
{
    if (!isdigit(c))
    {
        printf("Error\n");
        exit(98);
    }
    return c - '0';
}

/**
 * get_prod - Multiplies a string of numbers by a single digit.
 * @prod: The buffer to store the result.
 * @mult: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 *
 * Description: If mult contains a non-digit, the function
 *              exits with a status value of 98.
 */
void get_prod(char *prod, const char *mult, int digit, int zeroes)
{
    int mult_len = find_len(mult) - 1;
    mult += mult_len;

    for (; zeroes > 0; zeroes--)
        *prod++ = '0';

    int carry = 0;
    for (; mult_len >= 0; mult_len--, mult--, prod--)
    {
        if (!isdigit(*mult))
        {
            printf("Error\n");
            exit(98);
        }

        int num = (*mult - '0') * digit + carry;
        *prod = num % 10 + '0';
        carry = num / 10;
    }

    if (carry)
        *prod = carry + '0';
}

/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_prod: The buffer storing the running final product.
 * @next_prod: The next product to be added.
 * @next_len: The length of next_prod.
 */
void add_nums(char *final_prod, const char *next_prod, int next_len)
{
    int carry = 0;
    while (*final_prod != 'x')
        final_prod++;

    while (*next_prod != 'x')
    {
        int num = (*final_prod - '0') + (*next_prod - '0') + carry;
        *final_prod = num % 10 + '0';
        carry = num / 10;
        final_prod--;
        next_prod++;
        next_len--;
    }

    for (; next_len >= 0 && *next_prod != 'x'; next_len--)
    {
        int num = (*next_prod - '0') + carry;
        *final_prod = num % 10 + '0';
        carry = num / 10;
        final_prod--;
        next_prod--;
    }

    if (carry)
        *final_prod = carry + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or one number
 *              contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    if (argv[1][0] == '0')
        argv[1] = iterate_zeroes(argv[1]);
    if (argv[2][0] == '0')
        argv[2] = iterate_zeroes(argv[2]);
    if (argv[1][0] == '\0' || argv[2][0] == '\0')
    {
        printf("0\n");
        return 0;
    }

    int size = find_len(argv[1]) + find_len(argv[2]);
    char *final_prod = create_xarray(size);
    char *next_prod = create_xarray(size);

    int zeroes = 0;
    for (int index = find_len(argv[2]) - 1; index >= 0; index--)
    {
        int digit = get_digit(argv[2][index]);
        get_prod(next_prod, argv[1], digit, zeroes++);
        add_nums(final_prod, next_prod, size - 1);
    }

    int output_started = 0;
    for (int index = 0; final_prod[index] != '\0'; index++)
    {
        if (final_prod[index] != 'x')
        {
            putchar(final_prod[index]);
            output_started = 1;
        }
        else if (output_started)
        {
            putchar(final_prod[index]);
        }
    }
    putchar('\n');

    free(next_prod);
    free(final_prod);

    return 0;
}

