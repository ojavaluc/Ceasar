#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encrypt(string text, int key);

int main(int argc, string argv[])
{
    // Verifica se o usuário forneceu exatamente um argumento (a chave)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifica se a chave é um número positivo
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converte a chave para um inteiro
    int key = atoi(argv[1]);

    // Solicita o texto simples ao usuário
    string plaintext = get_string("plaintext: ");

    // Criptografa o texto
    printf("ciphertext: ");
    encrypt(plaintext, key);
    printf("\n");

    return 0;
}

void encrypt(string text, int key)
{
    // Itera por cada caractere do texto
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Verifica se o caractere é uma letra
        if (isalpha(text[i]))
        {
            // Criptografa letras maiúsculas
            if (isupper(text[i]))
            {
                printf("%c", (text[i] - 'A' + key) % 26 + 'A');
            }
            // Criptografa letras minúsculas
            else if (islower(text[i]))
            {
                printf("%c", (text[i] - 'a' + key) % 26 + 'a');
            }
        }
        // Mantém o caractere inalterado se não for uma letra
        else
        {
            printf("%c", text[i]);
        }
    }
}
