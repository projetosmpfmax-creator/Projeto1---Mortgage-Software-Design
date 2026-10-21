#include <gtest/gtest.h>
#include <stdexcept>

// Declaração da função core
double mortgage(int gender, int age, double salary);

// Constantes de género
const int GENDER_MALE = 1;
const int GENDER_FEMALE = 2;
const int GENDER_INVALID = 3;

// ==========================================
// TESTES DE SUCESSO (CÁLCULO E FATORES)
// ==========================================

// REQ-001 e REQ-002: Male (18 a 35 anos) - Fator 75
TEST(MortgageTest, MaleYoungBoundary) {
    // Limite inferior (18)
    EXPECT_EQ(mortgage(GENDER_MALE, 18, 5000.0), 375000.0);
    // Limite superior (35)
    EXPECT_EQ(mortgage(GENDER_MALE, 35, 5000.0), 375000.0);
}

// REQ-003: Male (36 a 45 anos) - Fator 55
TEST(MortgageTest, MaleMidBoundary) {
    EXPECT_EQ(mortgage(GENDER_MALE, 36, 4000.0), 220000.0);
    EXPECT_EQ(mortgage(GENDER_MALE, 45, 4000.0), 220000.0);
}

// REQ-004: Male (46 a 55 anos) - Fator 30
TEST(MortgageTest, MaleOldBoundary) {
    EXPECT_EQ(mortgage(GENDER_MALE, 46, 6000.0), 180000.0);
    EXPECT_EQ(mortgage(GENDER_MALE, 55, 6000.0), 180000.0);
}

// REQ-005: Female (18 a 30 anos) - Fator 70
TEST(MortgageTest, FemaleYoungBoundary) {
    EXPECT_EQ(mortgage(GENDER_FEMALE, 18, 3000.0), 210000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 30, 3000.0), 210000.0);
}

// REQ-006: Female (31 a 40 anos) - Fator 50
TEST(MortgageTest, FemaleMidBoundary) {
    EXPECT_EQ(mortgage(GENDER_FEMALE, 31, 5000.0), 250000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 40, 5000.0), 250000.0);
}

// REQ-007: Female (41 a 50 anos) - Fator 35
TEST(MortgageTest, FemaleOldBoundary) {
    EXPECT_EQ(mortgage(GENDER_FEMALE, 41, 4000.0), 140000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 50, 4000.0), 140000.0);
}

// ==========================================
// TESTES DE EXCEÇÃO (ROBUSTEZ E LIMITES)
// ==========================================

// REQ-008: Male com idade inválida (<18 ou >55)
TEST(MortgageTest, InvalidAgeMale) {
    EXPECT_THROW(mortgage(GENDER_MALE, 17, 5000.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_MALE, 56, 5000.0), std::invalid_argument);
}

// REQ-009: Female com idade inválida (<18 ou >55)
TEST(MortgageTest, InvalidAgeFemale) {
    EXPECT_THROW(mortgage(GENDER_FEMALE, 17, 4000.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 56, 4000.0), std::invalid_argument);
}

// REQ-010: Female entre 51 e 55 anos (Exceção de domínio)
TEST(MortgageTest, FemaleSpecifiedHandlingException) {
    EXPECT_THROW(mortgage(GENDER_FEMALE, 51, 4000.0), std::domain_error);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 55, 4000.0), std::domain_error);
}

// REQ-011: Salário fora dos limites (<0 ou >10000)
TEST(MortgageTest, InvalidSalaryLimits) {
    EXPECT_THROW(mortgage(GENDER_MALE, 30, -1.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 30, 10001.0), std::invalid_argument);
}

// REQ-012: Género inválido
TEST(MortgageTest, InvalidGender) {
    EXPECT_THROW(mortgage(GENDER_INVALID, 30, 5000.0), std::invalid_argument);
}
