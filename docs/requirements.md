# Software Requirements Specification (SRS) - Mortgage Calculator

Este documento lista os requisitos do sistema de hipoteca, seguindo o padrão INCOSE (formato EARS).

## 1. Requisitos Funcionais (Cálculo Base)
* **REQ-001:** O Sistema de Hipoteca deve calcular o valor da hipoteca aplicando estritamente a equação: `Mortgage = Salary * Factor`.

## 2. Regras de Fatores por Gênero e Idade
* **REQ-002:** Quando o gênero for "Male" (Masculino) e a idade for maior ou igual a 18 e menor ou igual a 35 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 75.
* **REQ-003:** Quando o gênero for "Male" (Masculino) e a idade for maior ou igual a 36 e menor ou igual a 45 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 55.
* **REQ-004:** Quando o gênero for "Male" (Masculino) e a idade for maior ou igual a 46 e menor ou igual a 55 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 30.
* **REQ-005:** Quando o gênero for "Female" (Feminino) e a idade for maior ou igual a 18 e menor ou igual a 30 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 70.
* **REQ-006:** Quando o gênero for "Female" (Feminino) e a idade for maior ou igual a 31 e menor ou igual a 40 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 50.
* **REQ-007:** Quando o gênero for "Female" (Feminino) e a idade for maior ou igual a 41 e menor ou igual a 50 anos, o Sistema de Hipoteca deve definir o fator de cálculo como 35.

## 3. Restrições e Tratamento de Exceções
* **REQ-008:** Se o gênero for "Male" (Masculino) e a idade fornecida for menor que 18 ou maior que 55 anos, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
* **REQ-009:** Se o gênero for "Female" (Feminino) e a idade fornecida for menor que 18 ou maior que 55 anos, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
* **REQ-010:** Se o gênero for "Female" (Feminino) e a idade for maior ou igual a 51 e menor ou igual a 55 anos, então o Sistema deve rejeitar o cálculo e lançar uma exceção específica informando que não há fator de cálculo definido para esta condição.
* **REQ-011:** Se o salário fornecido for menor que $0 ou maior que $10.000, então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
* **REQ-012:** Se o gênero fornecido for diferente de "Male" ou "Female", então o Sistema deve rejeitar a entrada e lançar a exceção de entrada inválida.
