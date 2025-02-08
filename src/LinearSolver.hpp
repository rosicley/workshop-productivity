#pragma once

#include <eigen3/Eigen/Dense>

#include "Exception.hpp"

class LinearSolver
{
public:
    static Eigen::VectorXd solve(const Eigen::MatrixXd &A, const Eigen::VectorXd &b);
};
