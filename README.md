# Projeto 1 - Mortgage Software Design

Este repositório contém a implementação de um sistema de cálculo de hipotecas, desenvolvido em C++ com foco em testes unitários e rastreabilidade de requisitos.

## 📂 Estrutura do Repositório

*   **/docs:** Especificação de requisitos funcionais e de exceções detalhados no padrão INCOSE (formato EARS).
*   **/src:** Código-fonte principal da aplicação em C++, dividido em funções modulares para validação de entradas, seleção de fatores e cálculo final.
*   **/tests:** Suíte de testes unitários desenvolvida com **Google Test**, cobrindo testes de limite (Boundary Value) e de robustez (casos inválidos e exceções).
*   **/.github/workflows:** Pipeline de Integração Contínua (CI) configurada via GitHub Actions para compilação e execução automatizada dos testes a cada novo commit.

## 🚀 Tecnologias Utilizadas

*   **Linguagem:** C++
*   **Testes:** Google Test (gtest)
*   **Automação de Build:** CMake
*   **CI/CD:** GitHub Actions

## ⚙️ Como executar os testes localmente

Para compilar e rodar os testes na sua máquina, certifique-se de ter o CMake instalado e execute os seguintes comandos na raiz do projeto:

```bash
cmake -B build
cmake --build build
cd build
ctest --output-on-failure
