#include "LinearSolver.hpp"

Eigen::VectorXd LinearSolver::solve(const Eigen::MatrixXd &A, const Eigen::VectorXd &b)
{
    if (A.rows() != A.cols() || A.rows() != b.size())
    {
        throw SystemSizeMismatchException("O tamanho da matriz e do vetor não são compatíveis.");
    }

    Eigen::FullPivLU<Eigen::MatrixXd> lu(A);
    if (!lu.isInvertible())
    {
        throw NoSolutionException("O sistema não possui solução única (a matriz não é invertível).");
    }

    return lu.solve(b);
}
