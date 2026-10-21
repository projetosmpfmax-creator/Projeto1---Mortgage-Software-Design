#include <gtest/gtest.h>
#include <stdexcept>

// Declaração da função core que será testada
double mortgage(int gender, int age, double salary);

// Constantes para os géneros validados pelo sistema
const int GENDER_MALE = 1;
const int GENDER_FEMALE = 2;
const int GENDER_INVALID = 3;

// ==========================================
// TESTES DE SUCESSO (CÁLCULO E FATORES)
// ==========================================

// TC-001: Cobre REQ-001 e REQ-002 (Male, 18 a 35 anos, Fator 75)
TEST(MortgageTest, TC001_MaleYoungBoundary) {
    // Limite inferior (18)
    EXPECT_EQ(mortgage(GENDER_MALE, 18, 5000.0), 375000.0);
    // Limite superior (35)
    EXPECT_EQ(mortgage(GENDER_MALE, 35, 5000.0), 375000.0);
}

// TC-002: Cobre REQ-003 (Male, 36 a 45 anos, Fator 55)
TEST(MortgageTest, TC002_MaleMidBoundary) {
    // Limite inferior (36) e superior (45)
    EXPECT_EQ(mortgage(GENDER_MALE, 36, 4000.0), 220000.0);
    EXPECT_EQ(mortgage(GENDER_MALE, 45, 4000.0), 220000.0);
}

// TC-003: Cobre REQ-004 (Male, 46 a 55 anos, Fator 30)
TEST(MortgageTest, TC003_MaleOldBoundary) {
    // Limite inferior (46) e superior (55)
    EXPECT_EQ(mortgage(GENDER_MALE, 46, 6000.0), 180000.0);
    EXPECT_EQ(mortgage(GENDER_MALE, 55, 6000.0), 180000.0);
}

// TC-004: Cobre REQ-005 (Female, 18 a 30 anos, Fator 70)
TEST(MortgageTest, TC004_FemaleYoungBoundary) {
    // Limite inferior (18) e superior (30)
    EXPECT_EQ(mortgage(GENDER_FEMALE, 18, 3000.0), 210000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 30, 3000.0), 210000.0);
}

// TC-005: Cobre REQ-006 (Female, 31 a 40 anos, Fator 50)
TEST(MortgageTest, TC005_FemaleMidBoundary) {
    // Limite inferior (31) e superior (40)
    EXPECT_EQ(mortgage(GENDER_FEMALE, 31, 5000.0), 250000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 40, 5000.0), 250000.0);
}

// TC-006: Cobre REQ-007 (Female, 41 a 50 anos, Fator 35)
TEST(MortgageTest, TC006_FemaleOldBoundary) {
    // Limite inferior (41) e superior (50)
    EXPECT_EQ(mortgage(GENDER_FEMALE, 41, 4000.0), 140000.0);
    EXPECT_EQ(mortgage(GENDER_FEMALE, 50, 4000.0), 140000.0);
}

// ==========================================
// TESTES DE LIMITES DE SALÁRIO (FRONTEIRAS)
// ==========================================

// TC-007: Cobre limite inferior exato do REQ-011 (Salário = 0)
TEST(MortgageTest, TC007_ValidSalaryZero) {
    EXPECT_EQ(mortgage(GENDER_MALE, 30, 0.0), 0.0);
}

// TC-008: Cobre limite superior exato do REQ-011 (Salário = 10000)
TEST(MortgageTest, TC008_ValidSalaryMax) {
    EXPECT_EQ(mortgage(GENDER_MALE, 30, 10000.0), 750000.0);
}

// ==========================================
// TESTES DE EXCEÇÃO (ROBUSTEZ E CASOS INVÁLIDOS)
// ==========================================

// TC-009: Cobre REQ-008 (Male com idade < 18 ou > 55)
TEST(MortgageTest, TC009_InvalidAgeMale) {
    EXPECT_THROW(mortgage(GENDER_MALE, 17, 5000.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_MALE, 56, 5000.0), std::invalid_argument);
}

// TC-010: Cobre REQ-009 (Female com idade < 18 ou > 55)
TEST(MortgageTest, TC010_InvalidAgeFemale) {
    EXPECT_THROW(mortgage(GENDER_FEMALE, 17, 4000.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 56, 4000.0), std::invalid_argument);
}

// TC-011: Cobre REQ-010 (Female entre 51 e 55 anos - exceção de domínio)
TEST(MortgageTest, TC011_FemaleSpecifiedHandling) {
    EXPECT_THROW(mortgage(GENDER_FEMALE, 51, 4000.0), std::domain_error);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 55, 4000.0), std::domain_error);
}

// TC-012: Cobre casos fora do REQ-011 (Salário < 0 ou > 10000)
TEST(MortgageTest, TC012_InvalidSalaryLimits) {
    EXPECT_THROW(mortgage(GENDER_MALE, 30, -1.0), std::invalid_argument);
    EXPECT_THROW(mortgage(GENDER_FEMALE, 30, 10001.0), std::invalid_argument);
}

// TC-013: Cobre REQ-012 (Género diferente de Male e Female)
TEST(MortgageTest, TC013_InvalidGender) {
    EXPECT_THROW(mortgage(GENDER_INVALID, 30, 5000.0), std::invalid_argument);
}
