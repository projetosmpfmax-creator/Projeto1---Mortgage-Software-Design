# Matriz de Rastreabilidade (Traceability Matrix)

| ID do Requisito | Descrição Resumida | Função C++ (Implementação) | Nome do Teste (Google Test) |
| :--- | :--- | :--- | :--- |
| **REQ-001** | Cálculo base (Salary * Factor) | `calculateMortgage` / `mortgage` | *Todos os testes de sucesso* |
| **REQ-002** | Fator 75 (Male, 18-35) | `selectFactor` | `MortgageTest.MaleYoungBoundary` |
| **REQ-007** | Fator 35 (Female, 41-50) | `selectFactor` | `MortgageTest.FemaleUpperBoundary` |
| **REQ-008** | Exceção: Idade < 18 | `validateInputs` | `MortgageTest.InvalidAgeUnder18` |
| **REQ-010** | Exceção Domínio: Female 51-55 | `selectFactor` | `MortgageTest.FemaleSpecifiedHandlingException` |
| **REQ-011** | Exceção: Salário fora dos limites | `validateInputs` | `MortgageTest.InvalidSalaryNegative` / `InvalidSalaryOverLimit` |
