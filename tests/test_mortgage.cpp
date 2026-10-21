#include <stdexcept>

// Declaração da função core que criámos no src/mortgage.cpp
double mortgage(int gender, int age, double salary);

// Constantes para os testes (combinando com a nossa implementação)
const int GENDER_MALE = 1;
const int GENDER_FEMALE = 2;

// 1. Boundary Value Testing (Teste de Limites)
TEST(MortgageTest, MaleYoungBoundary) {
    // Testando o limite inferior de idade para Male (18 anos) com fator 75
    // Salário: 5000 * 75 = 375000
    EXPECT_EQ(mortgage(GENDER_MALE, 18, 5000.0), 375000.0);
}

TEST(MortgageTest, FemaleUpperBoundary) {
    // Testando o limite superior válido para Female (50 anos) com fator 35
    // Salário: 4000 * 35 = 140000
    EXPECT_EQ(mortgage(GENDER_FEMALE, 50, 4000.0), 140000.0);
}

// 2. Robustness Testing (Casos Inválidos e Exceções)
TEST(MortgageTest, InvalidAgeUnder18) {
    // Invalid Cases: Age 17[cite: 3]
    EXPECT_THROW(mortgage(GENDER_MALE, 17, 5000.0), std::invalid_argument);
}

TEST(MortgageTest, InvalidSalaryNegative) {
    // Invalid Cases: Salary -1[cite: 3]
    EXPECT_THROW(mortgage(GENDER_MALE, 30, -1.0), std::invalid_argument);
}

TEST(MortgageTest, InvalidSalaryOverLimit) {
    // Invalid Cases: Salary 10001[cite: 3]
    EXPECT_THROW(mortgage(GENDER_FEMALE, 30, 10001.0), std::invalid_argument);
}

TEST(MortgageTest, FemaleSpecifiedHandlingException) {
    // Invalid Cases: Female age 51-55 - specified handling[cite: 3]
    EXPECT_THROW(mortgage(GENDER_FEMALE, 52, 4000.0), std::domain_error);
}
