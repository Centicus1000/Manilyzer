#include "test/test_utils.hpp"

void EqualOrThrow(
    std::string const& message,
    double a, 
    double b
)
{
    if(ABS(a - b) > EPS) 
        throw std::runtime_error(message + ": " 
            + std::to_string(a) + " != " 
            + std::to_string(b)
        );
}

void RunTest
(
    std::string const& name,
    std::function<void()> const& fTest
)
{

    std::cout << "---\nRunnding Tests for '"<<name<<"' \n";
    
    try {

        fTest();

        std::cout << "Tests passed!\n";
        return;
    } catch (const std::exception& e) {
        std::cerr << "Tests failed: " << e.what() << "\n";
        return;
    } catch (...) {
        std::cerr << "Tests failed: ??? \n";
        return;
    }
}