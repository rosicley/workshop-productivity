#include <catch2/catch_all.hpp>

#include <eigen3/Eigen/Dense>
#include <fmt/format.h>
#include <string>

#include "../src/LinearSolver.hpp"
#include "../src/Utils.hpp"

using Catch::Approx;

TEST_CASE("LinearSolver resolves a valid system", "[LinearSolver]")
{
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

TEST_CASE("LinearSolver throws exception on dimension mismatch", "[LinearSolver]")
{
    Eigen::MatrixXd A(2, 2);
    A << 1, 2, 3, 4;
    Eigen::VectorXd b(3);
    b << 1, 2, 3;

    // Verifica se a exceção SystemSizeMismatchException é lançada
    REQUIRE_THROWS_AS(LinearSolver::solve(A, b), SystemSizeMismatchException);
}

TEST_CASE("LinearSolver throws exception on singular matrix", "[LinearSolver]")
{
    Eigen::MatrixXd A(2, 2);
    A << 1, 2, 2, 4;
    Eigen::VectorXd b(2);
    b << 3, 6;

    // Nesse caso, como o sistema possui infinitas soluções, nosso solver deve lançar exceção
    REQUIRE_THROWS_AS(LinearSolver::solve(A, b), NoSolutionException);
}

TEST_CASE("vectorToString produces expected output", "[vectorToString]")
{
    Eigen::VectorXd vec(3);
    vec << 1, 2, 3;
    std::string expected = "{1, 2, 3}";
    std::string result = vectorToString(vec);
    REQUIRE(result == expected);
}
