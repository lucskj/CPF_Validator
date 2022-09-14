#include <stdio.h>

int * intToArray(int);

int main(int argc, char const *argv[]) {
    int cpf;
    printf("Digite o CPF, com números apenas: ");
    int qtdInput = scanf("%d", &cpf);

    switch (qtdInput) {
        case 1: ;
            int firstResult, secondResult, *digits;
            digits = intToArray(cpf);

            for (int i = 0; i < 11; i++ ) {
                printf( "%d\n", digits[i]);
            }
            /*
            firstResult = checkFirstDigit(digits);
            if (firstResult == 1) {
                secondResult = checkSecondDigit(digits);
            }

            if (secondResult == 1) {
                printf("CPF Válido.");
            }
            else {
                printf("CPF Inválido");
            }*/

            break;
        default:
            printf("Entrada inválida.");
    }


    return 0;

    
}

int checkFirstDigit(int cpf) {}

int * intToArray(int n)
{
    static int digits[11];
    int digit;
    int i = 0;

    do {
        digit = n % 10;
        digits[i] = digit;
        i++;
    } while ((n/=10) > 0);

    return digits;
}