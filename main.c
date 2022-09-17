#include <stdio.h>
#include <string.h>

int checkFirstDigit(char *);
int checkSecondDigit(char *);
int specificCase(char *);
int validateCPF(char *);

int main(int argc, char const *argv[]) {
    char cpf[12] = {0};

    printf("Digite o CPF, com numeros apenas: ");
    fgets(cpf, sizeof(cpf), stdin);

    switch(validateCPF(cpf)) {
        case 0:
            printf("CPF invalido.");
            break;
        case 1:
            printf("CPF valido.");
            break;
    }

    return 0;
}

int validateCPF(char *cpf) {
    switch (specificCase(cpf)) {
    case 1:
        switch (checkFirstDigit(cpf)) {
        case 1:
            switch (checkSecondDigit(cpf)) {
            case 1:
                return 1;
            }
            break;
        }
        break;
    }

    return 0;
}

int specificCase(char *cpf) {
    for(int i = 0; i < strlen(cpf)-1; i++) {
        if (cpf[i] != cpf[i+1]) {
            return 1;
        }
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
        partialResult = 11 - (totalSum % 11); 
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
        partialResult = 11 - (totalSum % 11);
    }

    if (partialResult == cpf[10] - '0') {
        return 1;
    }
    
    return 0;
}