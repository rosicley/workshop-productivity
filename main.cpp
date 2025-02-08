#include <iostream>

#include "src/LinearSolver.hpp"
#include "src/Utils.hpp"

int main()
{
    Eigen::MatrixXd A(2, 2);
    A << 2, 3, 4, 7;
    fmt::print(blue | italic, "Matriz A definida.\n");

    Eigen::VectorXd b(2);
    b << 5, 9;
    fmt::print(blue | italic, "Vetor b definido.\n");

    fmt::print(yellow, "Resolvendo o sistema linear: A * x = b.\n");
    Eigen::VectorXd solution = LinearSolver::solve(A, b);

    fmt::print(green | bold, "Solução do sistema: x = {}.\n", vectorToString(solution));

    return 0;
}
