# Define a versão mínima do CMake necessária para o projeto
cmake_minimum_required(VERSION 3.22)

# Define o nome do projeto
project(workshop)

# Define o padrão C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra os pacotes necessários
find_package(fmt REQUIRED)
find_package(Eigen3 REQUIRED)

# Adiciona subdiretório
add_subdirectory(src)

# Define o arquivo principal
set(MAIN_CPP_FILE "main.cpp")

# Adiciona o executável
add_executable(
    ${PROJECT_NAME}
    ${MAIN_CPP_FILE}
    ${CXX_SOURCE_FILES}
)

# Define as dependências do executável
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    fmt::fmt
    Eigen3::Eigen
)

##############
### Testes ###
##############

# Habilita o CTest
enable_testing()

# Encontra o pacote Catch2 (versão 3 REQUIRED)
find_package(Catch2 3 REQUIRED)

# Cria o executável de testes
add_executable(tests_runner "tests/main.cpp" ${CXX_SOURCE_FILES})

target_link_libraries(tests_runner PRIVATE Catch2::Catch2WithMain Eigen3::Eigen fmt::fmt)

# Integra o Catch2 com o CTest para descoberta automática dos testes
include(CTest)
include(Catch)
catch_discover_tests(tests_runner)
