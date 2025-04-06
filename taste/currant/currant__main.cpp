#include <stlab/concurrency/concurrency.hpp>
#include <stlab/pre_exit.hpp>
#include <iostream>

int main()
{
    std::cout << "currant\n";

    stlab::pre_exit();
    return 0;
}
