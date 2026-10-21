# Software Requirements Specification (SRS) - Mortgage Calculator

Este documento lista os requisitos do sistema de hipoteca, seguindo o padrão INCOSE (formato EARS).

## 1. Requisitos Funcionais (Cálculo Base)
* **REQ-001:** O Sistema de Hipoteca deve calcular o valor da hipoteca aplicando estritamente a equação: `Mortgage = Salary * Factor`.

## 2. Regras de Fatores por Gênero e Idade
* **REQ-002:** Quando o gênero for "Male" (Masculino) e a idade estiver entre 18 e 35 anos, o Sistema de Hipoteca deve aplicar o fator 75.
* **REQ-003:** Quando o gênero for "Male" (Masculino) e a idade estiver entre 36 e 45 anos, o Sistema de Hipoteca deve aplicar o fator 55.
* **REQ-004:** Quando o gênero for "Male" (Masculino) e a idade estiver entre 46 e 55 anos, o Sistema de Hipoteca deve aplicar o fator 30.
* **REQ-005:** Quando o gênero for "Female" (Feminino) e a idade estiver entre 18 e 30 anos, o Sistema de Hipoteca deve aplicar o fator 70.
* **REQ-006:** Quando o gênero for "Female" (Feminino) e a idade estiver entre 31 e 40 anos, o Sistema de Hipoteca deve aplicar o fator 50.
* **REQ-007:** Quando o gênero for "Female" (Feminino) e a idade estiver entre 41 e 50 anos, o Sistema de Hipoteca deve aplicar o fator 35.

## 3. Restrições e Tratamento de Exceções
* **REQ-008:** Se o gênero for "Male" (Masculino) e a idade fornecida for menor que 18 ou maior que 55 anos, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida (`std::invalid_argument`).
* **REQ-009:** Se o gênero for "Female" (Feminino) e a idade fornecida for menor que 18 ou maior que 55 anos, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida (`std::invalid_argument`).
* **REQ-010:** Se o gênero for "Female" (Feminino) e a idade estiver entre 51 e 55 anos (inclusive), então o Sistema deve rejeitar o cálculo e lançar uma exceção específica informando que não há fator de cálculo definido para esta faixa etária.
* **REQ-011:** Se o salário fornecido for menor que 0 ou maior que 10.000, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida (`std::invalid_argument`).
* **REQ-012:** Se o gênero fornecido for diferente de "Male" ou "Female", então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida (`std::invalid_argument`).
