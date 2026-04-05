#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "../../../../sauce/strange/strange.h"
#include "../../../../sauce/strange/implementation/baggage/strange__implementation__baggage.h"
#include "../../../../sauce/strange/implementation/graph/strange__implementation__graph.h"

#include <thread>
#include <chrono>

#include "taste__currants.cpp"

int main(int argc, char** argv)
{
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run();
    stlab::pre_exit();
    return res;
}
