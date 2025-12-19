#pragma once

#include "utils/macros.hpp"
#include <iostream>
#include <string>
#include <functional>
#include <stdexcept>

constexpr double EPS{ 1e-10 };

void EqualOrThrow(
    std::string const& message,
    double a, 
    double b
);

/**
 * @brief Test functions that catch exceptions, and prints status updates
 * 
 * @param name name of tested module
 * @param fTest function that includes tests
 */
void RunTest
(
    std::string const& name,
    std::function<void()> const& fTest
);