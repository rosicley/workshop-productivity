
#include "Utils.hpp"

std::string vectorToString(const Eigen::VectorXd &vec)
{
    std::string result;
    for (int i = 0; i < vec.size(); ++i)
    {
        result += fmt::format("{}", vec[i]);
        if (i != vec.size() - 1)
        {
            result += ", ";
        }
    }
    return "{" + result + "}";
}
