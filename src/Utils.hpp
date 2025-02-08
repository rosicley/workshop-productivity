#pragma once

#include <eigen3/Eigen/Dense>
#include <fmt/color.h>
#include <fmt/core.h>

const auto blue = fmt::fg(fmt::color::blue);
const auto yellow = fmt::fg(fmt::color::yellow);
const auto green = fmt::fg(fmt::color::green);
const auto bold = fmt::emphasis::bold;
const auto italic = fmt::emphasis::italic;

std::string vectorToString(const Eigen::VectorXd &vec);
