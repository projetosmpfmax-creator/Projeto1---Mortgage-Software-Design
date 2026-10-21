# Matriz de Rastreabilidade (Traceability Matrix)

| ID do Requisito | Descrição Resumida | Função C++ (Implementação) | ID do Teste | Caso de Teste (Google Test) |
| :--- | :--- | :--- | :--- | :--- |
| **REQ-001** | Cálculo da equação Base | `calculateMortgage` / `mortgage` | TC-001 a TC-008 | Todos os testes de limites válidos e de sucesso |
| **REQ-002** | Fator 75 (Male, >=18 e <=35) | `selectFactor` | **TC-001** | `MortgageTest.TC001_MaleYoungBoundary` |
| **REQ-003** | Fator 55 (Male, >=36 e <=45) | `selectFactor` | **TC-002** | `MortgageTest.TC002_MaleMidBoundary` |
| **REQ-004** | Fator 30 (Male, >=46 e <=55) | `selectFactor` | **TC-003** | `MortgageTest.TC003_MaleOldBoundary` |
| **REQ-005** | Fator 70 (Female, >=18 e <=30) | `selectFactor` | **TC-004** | `MortgageTest.TC004_FemaleYoungBoundary` |
| **REQ-006** | Fator 50 (Female, >=31 e <=40) | `selectFactor` | **TC-005** | `MortgageTest.TC005_FemaleMidBoundary` |
| **REQ-007** | Fator 35 (Female, >=41 e <=50) | `selectFactor` | **TC-006** | `MortgageTest.TC006_FemaleOldBoundary` |
| **REQ-008** | Exceção: Male <18 ou >55 | `validateInputs` | **TC-009** | `MortgageTest.TC009_InvalidAgeMale` |
| **REQ-009** | Exceção: Female <18 ou >55 | `validateInputs` | **TC-010** | `MortgageTest.TC010_InvalidAgeFemale` |
| **REQ-010** | Exceção: Female >=51 e <=55 | `selectFactor` | **TC-011** | `MortgageTest.TC011_FemaleSpecifiedHandling` |
| **REQ-011** | Validação: Salário Limites Válidos e Inválidos | `validateInputs` | **TC-007**, **TC-008**, **TC-012** | `TC007_ValidSalaryZero`, `TC008_ValidSalaryMax`, `TC012_InvalidSalaryLimits` |
| **REQ-012** | Exceção: Gênero Inválido | `validateInputs` | **TC-013** | `MortgageTest.TC013_InvalidGender` |
