cmake_minimum_required(VERSION 3.14)
project(MortgageSoftware)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Descarrega o Google Test automaticamente
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Cria uma biblioteca com a sua função core (Fase 4)
add_library(MortgageLib src/mortgage.cpp)

# Compila o executável de testes e liga o Google Test (Fase 5)
add_executable(MortgageTests tests/test_mortgage.cpp)
target_link_libraries(MortgageTests MortgageLib gtest_main)

# Regista os testes para o CTest
include(GoogleTest)
gtest_discover_tests(MortgageTests)
