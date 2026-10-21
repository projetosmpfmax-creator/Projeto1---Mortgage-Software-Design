#include <stdexcept>

// Definindo constantes para o gênero para atender ao REQ-012, pois foi exigido 'int gender' na assinatura da função.
const int GENDER_MALE = 1;
const int GENDER_FEMALE = 2;

// 1. Função de Validação de Entradas
bool validateInputs(int gender, int age, double salary) {
    // REQ-011: Se o salário fornecido for menor que 0 ou maior que 10.000, o Sistema deve rejeitar a entrada.
    if (salary < 0 || salary > 10000) {
        return false; 
    }

    // REQ-012: Se o gênero fornecido for diferente de "Male" (1) ou "Female" (2), o Sistema deve rejeitar a entrada.
    if (gender != GENDER_MALE && gender != GENDER_FEMALE) {
        return false;
    }

    // REQ-008: Se o gênero for "Male" e a idade fornecida for menor que 18 ou maior que 55 anos, rejeitar a entrada.
    if (gender == GENDER_MALE && (age < 18 || age > 55)) {
        return false;
    }

    // REQ-009: Se o gênero for "Female" e a idade fornecida for menor que 18 ou maior que 55 anos, rejeitar a entrada.
    if (gender == GENDER_FEMALE && (age < 18 || age > 55)) {
        return false;
    }

    return true; // Entradas válidas
}

// 2. Função de Seleção do Fator
double selectFactor(int gender, int age) {
    // REQ-010: Se o gênero for "Female" e a idade estiver entre 51 e 55 anos, lançar exceção específica.
    if (gender == GENDER_FEMALE && age >= 51 && age <= 55) {
        throw std::domain_error("REQ-010: Nao ha fator de calculo definido para esta faixa etaria (Female, 51-55).");
    }

    if (gender == GENDER_MALE) {
        // REQ-002: Quando o gênero for "Male" e a idade entre 18 e 35 anos, aplicar fator 75.
        if (age >= 18 && age <= 35) return 75.0;
        
        // REQ-003: Quando o gênero for "Male" e a idade entre 36 e 45 anos, aplicar fator 55.
        if (age >= 36 && age <= 45) return 55.0;
        
        // REQ-004: Quando o gênero for "Male" e a idade entre 46 e 55 anos, aplicar fator 30.
        if (age >= 46 && age <= 55) return 30.0;
    } 
    else if (gender == GENDER_FEMALE) {
        // REQ-005: Quando o gênero for "Female" e a idade entre 18 e 30 anos, aplicar fator 70.
        if (age >= 18 && age <= 30) return 70.0;
        
        // REQ-006: Quando o gênero for "Female" e a idade entre 31 e 40 anos, aplicar fator 50.
        if (age >= 31 && age <= 40) return 50.0;
        
        // REQ-007: Quando o gênero for "Female" e a idade entre 41 e 50 anos, aplicar fator 35.
        if (age >= 41 && age <= 50) return 35.0;
    }
    
    return 0.0;
}

// 3. Função de Cálculo Matemático
double calculateMortgage(double salary, double factor) {
    // REQ-001: O Sistema deve calcular o valor da hipoteca aplicando estritamente a equação: Mortgage = Salary * Factor.
    return salary * factor;
}

// 4. Função Principal de Orquestração (Core Function)
double mortgage(int gender, int age, double salary) {
    // Aplica o lançamento da exceção std::invalid_argument exigido no caso a validação falhe
    // Isso engloba os tratamentos de exceção dos requisitos REQ-008, REQ-009, REQ-011 e REQ-012.
    if (!validateInputs(gender, age, salary)) {
        throw std::invalid_argument("Invalid input");
    }
    
    // Aciona a lógica de negócio dos fatores (REQ-002 a REQ-007) e a exceção de domínio (REQ-010).
    double factor = selectFactor(gender, age);
    
    // Retorna o resultado do requisito fundamental (REQ-001).
    return calculateMortgage(salary, factor);
}
