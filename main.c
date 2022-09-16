#include <stdio.h>

int checkFirstDigit(char *);
int checkSecondDigit(char *);

int main(int argc, char const *argv[]) {
    char cpf[12] = {0};
    int firstResult, secondResult;

    printf("Digite o CPF, com numeros apenas: ");
    fgets(cpf, sizeof(cpf), stdin);
    
    firstResult = checkFirstDigit(cpf);
    switch (firstResult) {
    case 0:
        printf("CPF Invalido.");
        break;
    case 1:
        secondResult = checkSecondDigit(cpf);
        switch (secondResult) {
        case 1:
            printf("CPF Valido.");
            break;
        default:
            printf("CPF Invalido.");
            break;
        }
        break;
    }

    return 0;
}

int checkFirstDigit(char *cpf) {
    int totalSum = 0;
    int i, partialResult, factor;

    for (i = 0, factor = 10; i < 9; i++, factor--) {
        int currentNumber = cpf[i] - '0';
        currentNumber *= factor;
        totalSum += currentNumber;
    }

    if ((totalSum % 11) < 2) {
        partialResult = 0;
    }
    else {
        partialResult = 11 - partialResult; 
    }

    if (partialResult == (cpf[9] - '0')) {
        return 1;
    }

    return 0;
}

int checkSecondDigit(char *cpf) {
    int totalSum = 0;
    int i, partialResult, factor;

    for (i = 0, factor = 11; i < 10; i++, factor--) {
        int currentNumber = cpf[i] - '0';
        currentNumber *= factor;
        totalSum += currentNumber;
    }

    if ((totalSum % 11) < 2) {
        partialResult = 0;
    }
    else {
        partialResult = 11 - partialResult;
    }

    if (partialResult == cpf[10] - '0') {
        return 1;
    }
    
    return 0;
}