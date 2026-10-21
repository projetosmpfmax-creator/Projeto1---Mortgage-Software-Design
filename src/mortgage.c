#include <stdio.h>
#include <string.h>

// Função principal de cálculo da hipoteca
double calculate_mortgage(const char* gender, int age, double salary) {
    
    // REQ-011: Se o salário fornecido for menor que 0 ou maior que 10.000, 
    // então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
    if (salary < 0 || salary > 10000) {
        fprintf(stderr, "Erro (std::invalid_argument): Salario fora dos limites permitidos (0 a 10.000).\n");
        return -1.0; // Retorna -1 para simular a rejeição/exceção
    }

    // REQ-012: Se o gênero fornecido for diferente de "Male" ou "Female", 
    // então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
    if (strcmp(gender, "Male") != 0 && strcmp(gender, "Female") != 0) {
        fprintf(stderr, "Erro (std::invalid_argument): Genero invalido. Deve ser 'Male' ou 'Female'.\n");
        return -1.0;
    }

    int factor = 0;

    // Lógica para o gênero Masculino (Male)
    if (strcmp(gender, "Male") == 0) {
        // REQ-008: Se o gênero for "Male" (Masculino) e a idade fornecida for menor que 18 ou maior que 55 anos, 
        // então o Sistema deve rejeitar a entrada...
        if (age < 18 || age > 55) {
            fprintf(stderr, "Erro (std::invalid_argument): Idade invalida para Male (deve ser entre 18 e 55).\n");
            return -1.0;
        }

        // REQ-002: Quando o gênero for "Male" e a idade estiver entre 18 e 35 anos, aplicar fator 75.
        if (age >= 18 && age <= 35) {
            factor = 75;
        } 
        // REQ-003: Quando o gênero for "Male" e a idade estiver entre 36 e 45 anos, aplicar fator 55.
        else if (age >= 36 && age <= 45) {
            factor = 55;
        } 
        // REQ-004: Quando o gênero for "Male" e a idade estiver entre 46 e 55 anos, aplicar fator 30.
        else if (age >= 46 && age <= 55) {
            factor = 30;
        }
    } 
    // Lógica para o gênero Feminino (Female)
    else if (strcmp(gender, "Female") == 0) {
        // REQ-009: Se o gênero for "Female" (Feminino) e a idade fornecida for menor que 18 ou maior que 55 anos, 
        // então o Sistema deve rejeitar a entrada...
        if (age < 18 || age > 55) {
            fprintf(stderr, "Erro (std::invalid_argument): Idade invalida para Female (deve ser entre 18 e 55).\n");
            return -1.0;
        }

        // REQ-010: Se o gênero for "Female" e a idade estiver entre 51 e 55 anos (inclusive), 
        // então o Sistema deve rejeitar o cálculo e lançar uma exceção específica...
        if (age >= 51 && age <= 55) {
            fprintf(stderr, "Erro Expecifico: Nao ha fator de calculo definido para mulheres na faixa etaria de 51 a 55 anos.\n");
            return -1.0;
        }

        // REQ-005: Quando o gênero for "Female" e a idade estiver entre 18 e 30 anos, aplicar fator 70.
        if (age >= 18 && age <= 30) {
            factor = 70;
        } 
        // REQ-006: Quando o gênero for "Female" e a idade estiver entre 31 e 40 anos, aplicar fator 50.
        else if (age >= 31 && age <= 40) {
            factor = 50;
        } 
        // REQ-007: Quando o gênero for "Female" e a idade estiver entre 41 e 50 anos, aplicar fator 35.
        else if (age >= 41 && age <= 50) {
            factor = 35;
        }
    }

    // REQ-001: O Sistema de Hipoteca deve calcular o valor da hipoteca aplicando estritamente 
    // a equação: Mortgage = Salary * Factor.
    double mortgage = salary * factor;
    
    return mortgage;
}
