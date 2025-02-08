# 1. Workshop: Melhorando a Produtividade

Este workshop apresenta práticas e ferramentas para otimizar seu fluxo de trabalho. Abordaremos o uso de clusters, integração com VS Code, CMake, Docker, testes automatizados e convenções de commits.

---

# 2. Utilizando um Cluster (Opcional)

*Esta seção é opcional para quem deseja utilizar um cluster durante o workshop.*

## 2.1. Configuração via SSH

1. **Configure o arquivo `~/.ssh/config`:**

   Adicione a seguinte configuração (substitua `ip-do-cluster`, `user` e `porta` pelos valores corretos):

   ```bash
   Host cluster-set
     Hostname ip-do-cluster
     User user
     Port porta
   ```

2. **Conecte-se ao cluster via terminal:**

   ```bash
   ssh cluster-set
   # Digite a senha quando solicitada
   ```

## 2.2. Acessando o Cluster com o VS Code

1. **Inicie o VS Code:**

   ```bash
   code .
   ```

2. **Instale a extensão [Remote - SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh).**

3. **Conecte-se ao cluster:**
   - Clique no ícone no canto inferior esquerdo e selecione `Remote-SSH: Connect to Host...`.
   - Escolha `cluster-set` e digite a senha quando solicitado.
   - Agora você está conectado ao cluster e pode editar os arquivos remotamente. Basta clonar seu repositório e abrir a pasta com `Open Folder`.
   - Se necessário, o VS Code solicitará a reinstalação de algumas extensões no ambiente remoto. Clique em `Install in SSH: cluster-set`.

4. **Para desconectar:**
   - Clique no ícone do canto inferior esquerdo e selecione `Close Remote Connection`.

---

# 3. Requisitos do Workshop

## 3.1. Ferramentas Necessárias

Para participar do workshop, será necessário instalar os seguintes pacotes:

- `git`
- `docker`
- `docker-compose`
- `cmake`
- `make`

> **Observação:** Inicialmente, vamos instalar apenas `git`, `docker` e `docker-compose`.

Execute os comandos abaixo:

```bash
sudo apt-get update -y
sudo apt-get install -y git docker docker-compose

# Adicione seu usuário ao grupo do Docker para não precisar usar 'sudo'
sudo groupadd docker         # (Caso o grupo 'docker' ainda não exista)
sudo usermod -aG docker $USER
newgrp docker
```

## 3.2. Bibliotecas Utilizadas no Código Demo

- [fmt](https://github.com/fmtlib/fmt)
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [Catch2](https://github.com/catchorg/Catch2)

> **Observação:** As bibliotecas `fmt` e `Eigen` serão gerenciadas via CMake ou Docker, conforme as instruções a seguir.

---

# 4. Código Demo

## 4.1. Clonando o Repositório

Clone o repositório do workshop:

```bash
git clone <URL_DO_REPOSITÓRIO>
```

Em seguida, acesse o diretório do projeto:

```bash
cd workshop-productivity
```

## 4.2. Compilando com CMake

O CMake automatiza o processo de compilação do seu código.

### 4.2.1. Exemplo de `CMakeLists.txt`

```cmake
# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(workshop)

# Define o padrão C++ e torna-o obrigatório
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra os pacotes necessários
find_package(fmt REQUIRED)
find_package(Eigen3 REQUIRED)

# Adiciona o executável (adicione outros arquivos fonte se necessário)
add_executable(${PROJECT_NAME} "main.cpp")

# Liga as bibliotecas encontradas ao executável
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt Eigen3::Eigen)
```

### 4.2.2. Compilando pelo Terminal

1. Crie um diretório de compilação e configure o projeto:

   ```bash
   cmake . -B build
   ```

2. Compile o projeto:

   ```bash
   cmake --build build
   ```

> **Atenção:** Se você não tiver as bibliotecas `fmt` e `Eigen` instaladas localmente, a compilação poderá falhar. Nesse caso, siga para a seção Docker.

3. Execute o projeto:

   ```bash
   ./build/workshop
   ```

### 4.2.3. Compilando com o VS Code

1. Instale a extensão [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).
2. Utilize as opções da extensão para compilar e executar o projeto diretamente no VS Code.
3. Você também pode depurar o código adicionando breakpoints na interface do VS Code.

---

# 5. Utilizando o Docker

O Docker permite criar um ambiente de desenvolvimento pré-configurado, evitando problemas com dependências.

## 5.1. Dev Container no VS Code

1. Instale a extensão [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers).
2. No VS Code, clique no ícone do canto inferior esquerdo e selecione `Dev Containers: Reopen in Container`.
3. *Dica:* Se estiver utilizando o cluster e acabou de configurar o Docker, reinicie o VS Code para que ele reconheça as permissões do grupo do Docker.
4. Dentro do container, instale também a extensão [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) e compile o projeto conforme descrito anteriormente.

## 5.2. Usando o Docker Compose via **Terminal**

Se preferir acessar o container pelo terminal, execute:

```bash
# Inicializa o container usando docker-compose
docker-compose run --rm workshop bash

# Dentro do container, compile o projeto:
cmake . -B build && cmake --build build

# Execute o projeto:
./build/workshop
```

---

# 6. Extensões Úteis para o VS Code

- **Code Spell Checker:** [Instalar](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker) – para correção ortográfica.
- **C/C++ Extension Pack:** [Instalar](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) – para desenvolvimento em C/C++.
- **Doxygen:** [Instalar](https://marketplace.visualstudio.com/items?itemName=bbenoist.Doxygen) – para documentação de código.
- **GitHub Copilot:** [Instalar](https://marketplace.visualstudio.com/items?itemName=GitHub.copilot) – para sugestões de código.
  Aproveite os benefícios do [GitHub Education](https://education.github.com/discount_requests/application) para acessar o GitHub Copilot Pro.
- **SonarQube:** [Instalar](https://marketplace.visualstudio.com/items?itemName=SonarSource.sonarlint-vscode) – para análise de código.
- **Git Lens:** [Instalar](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens) – para visualização de informações do Git.

---

# 7. Testes Automatizados com CTest e Catch2 (Bônus)

O `CTest` é uma ferramenta integrada ao CMake para execução de testes, enquanto o `Catch2` é uma biblioteca para testes unitários em C++.

## 7.1. Adicionando Testes ao Projeto

1. **Crie um arquivo de teste:**
   Por exemplo, `tests/main.cpp`, contendo os testes utilizando o `Catch2`.

2. **Exemplo de Teste com Catch2:**

   ```cpp
   #define CATCH_CONFIG_MAIN
   #include <catch2/catch_all.hpp>
   #include <Eigen/Dense>
   #include <fmt/format.h>
   #include <string>
   #include "../src/LinearSolver.hpp"
   #include "../src/Utils.hpp"

   using Catch::Approx;

   TEST_CASE("LinearSolver resolves a valid system", "[LinearSolver]") {
       Eigen::MatrixXd A(2, 2);
       A << 2, 3, 4, 7;
       Eigen::VectorXd b(2);
       b << 5, 9;

       Eigen::VectorXd solution;
       REQUIRE_NOTHROW(solution = LinearSolver::solve(A, b));
       REQUIRE(solution.size() == 2);
       REQUIRE(solution(0) == Approx(4.0));
       REQUIRE(solution(1) == Approx(-1.0));
   }
   ```

3. **Configure os testes no `CMakeLists.txt`:**

   ```cmake
   # Habilita o CTest
   enable_testing()

   # Encontra o pacote Catch2 (versão 3 REQUIRED)
   find_package(Catch2 3 REQUIRED)

   # Cria o executável de testes
   add_executable(tests_runner "tests/main.cpp")
   target_link_libraries(tests_runner PRIVATE Catch2::Catch2WithMain Eigen3::Eigen fmt::fmt)

   # Integra o Catch2 com o CTest
   include(CTest)
   include(Catch)
   catch_discover_tests(tests_runner)
   ```

4. **Compilando e Executando os Testes:**

   ```bash
   cmake . -B build && cmake --build build
   ctest --test-dir build --output-on-failure
   ```

---

# 8. Integração com GitHub Actions (CI/CD)

Você pode automatizar a compilação e execução de testes utilizando o GitHub Actions.

## 8.1. Exemplo de Workflow para testes

Crie um arquivo em `.github/workflows/run-tests.yml`:

```yaml
name: Compile and Run Tests

on:
  pull_request:
    branches:
      - main

jobs:
  build-and-test:
    name: Build and Test
    runs-on: ubuntu-latest
    container:
      image: rosicley/workshop-productivity

    steps:
      - name: Checkout code
        uses: actions/checkout@v4

      - name: Build and Run Tests
        run: |
         cmake . -B build && cmake --build build
         ctest --test-dir build --output-on-failure
```

## 8.2. Exemplo de Workflow para Análise de Código

Crie um arquivo chamado `.github/workflows/cpp-linter.yml` com o seguinte conteúdo:

Este workflow utiliza a ação [cpp-linter-action](https://github.com/cpp-linter/cpp-linter-action) para realizar análise estática do código utilizando o Clang Format e o Clang Tidy.

- **Clang Format:**
  Formata o código conforme um estilo definido. Você pode personalizar a formatação criando um arquivo `.clang-format` com as regras desejadas.

- **Clang Tidy:**
  Realiza a análise estática do código em busca de problemas, como vazamentos de memória e variáveis não utilizadas. Para ajustar as regras, crie um arquivo `.clang-tidy` conforme necessário.

```yaml
name: C/C++ Linter
on:
  pull_request:
    branches:
      - main

jobs:
  cpp-linter:
    runs-on: ubuntu-latest
    container:
      image: rosicley/workshop-productivity

    steps:
      - name: Checkout code
        uses: actions/checkout@v4

      - name: Generate compilation database
        run: cmake . -B build

      - name: Run Clang Format and Clang Tidy
        uses: cpp-linter/cpp-linter-action@v2.13.4
        id: linter
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
        with:
          database: build/
          files-changed-only: false
          format-review: false
          ignore: 'build|cmake-modules|docker'
          passive-reviews: true
          step-summary: true
          style: 'file'
          tidy-checks: ''
          thread-comments: ${{ github.event_name == 'pull_request' && 'update' }}
          version: 19

      - name: Fail fast?!
        if: steps.linter.outputs.checks-failed > 0
        run: exit 1
```

---

# 9. Conventional Commits

Utilize o padrão [Conventional Commits](https://www.conventionalcommits.org/pt-br/v1.0.0/) para padronizar as mensagens de commit.

## 9.1. Exemplos:

- **Evite:**
  ```bash
  git commit -m "up"
  git commit -m "fix"
  git commit -m "testing y"
  git commit -m "working"
  git commit -m "last test"
  ```

- **Prefira:**
  ```bash
  git commit -m "feat: Adiciona funcionalidade X"
  git commit -m "fix: Corrige bug Y"
  git commit -m "docs: Atualiza documentação referente a Z"
  git commit -m "refactor: Refatora código em W"
  git commit -m "test: Adiciona testes para V"
  ```
