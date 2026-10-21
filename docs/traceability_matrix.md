# Matriz de Rastreabilidade (Traceability Matrix)

| ID do Requisito | Descrição Resumida | Função C++ (Implementação) | Nome do Teste (Google Test) |
| :--- | :--- | :--- | :--- |
| **REQ-001** | Cálculo da equação Base | `calculateMortgage` | `MortgageTest.CalculateBaseFormula` |
| **REQ-002** | Fator 75 (Male, >=18 e <=35) | `selectFactor` | `MortgageTest.MaleYoungBoundary` |
| **REQ-003** | Fator 55 (Male, >=36 e <=45) | `selectFactor` | `MortgageTest.MaleMidBoundary` |
| **REQ-004** | Fator 30 (Male, >=46 e <=55) | `selectFactor` | `MortgageTest.MaleOldBoundary` |
| **REQ-005** | Fator 70 (Female, >=18 e <=30) | `selectFactor` | `MortgageTest.FemaleYoungBoundary` |
| **REQ-006** | Fator 50 (Female, >=31 e <=40) | `selectFactor` | `MortgageTest.FemaleMidBoundary` |
| **REQ-007** | Fator 35 (Female, >=41 e <=50) | `selectFactor` | `MortgageTest.FemaleOldBoundary` |
| **REQ-008** | Exceção: Male <18 ou >55 | `validateInputs` | `MortgageTest.InvalidAge_Male` |
| **REQ-009** | Exceção: Female <18 ou >55 | `validateInputs` | `MortgageTest.InvalidAge_Female` |
| **REQ-010** | Exceção: Female >=51 e <=55 | `selectFactor` | `MortgageTest.FemaleSpecifiedHandlingException` |
| **REQ-011** | Exceção: Salário <0 ou >10k | `validateInputs` | `MortgageTest.InvalidSalaryLimits` |
| **REQ-012** | Exceção: Gênero Inválido | `validateInputs` | `MortgageTest.InvalidGender` |
