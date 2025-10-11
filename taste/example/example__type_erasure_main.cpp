#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/comprehension/strange__comprehension__parser.h"
//#include "example__type_erasure.h"
#include "example__space_transformation_3.h"

#include <iostream>
#include <algorithm>
#include <fstream>

struct implement
{
    // implement() = default;
    // implement(implement const&) = delete;

    auto x() const -> int const & { return x_; }
    auto x() -> int & { return x_; }

    inline void display(example::button b) const
    {
        std::cout << "display: " << x_ << std::endl;
    }

    inline void inc()
    {
        std::cout << "inc: " << x_ << " -> " << (x_ + 1) << std::endl;
        ++x_;
    }

    inline void operator++()
    {
        std::cout << "operator++: " << x_ << " -> " << (x_ + 1) << std::endl;
        ++x_;
    }

    inline void operator--(int)
    {
        std::cout << "operator--: " << x_ << " -> " << (x_ - 1) << std::endl;
        x_--;
    }

    inline void push()
    {
        std::cout << "push: " << x_ << " -> " << (x_ - 1) << std::endl;
        --x_;
    }

    inline void dec()
    {
        std::cout << "dec: " << x_ << " -> " << (x_ - 1) << std::endl;
        --x_;
    }

    inline int get() const
    {
        std::cout << "get: " << x_ << std::endl;
        return x_;
    }

private:
    int x_ = 0;
};

template<typename Datatype>
struct implement_template
{
    // implement() = default;
    // implement(implement const&) = delete;

    auto x() const -> Datatype const & { return x_; }
    auto x() -> Datatype & { return x_; }

    inline void display(example::button b) const
    {
        std::cout << "display: " << x_ << std::endl;
    }

    inline void inc()
    {
        std::cout << "inc: " << x_ << " -> " << (x_ + 1) << std::endl;
        ++x_;
    }

    inline void operator++()
    {
        std::cout << "operator++: " << x_ << " -> " << (x_ + 1) << std::endl;
        ++x_;
    }

    inline void operator--(int)
    {
        std::cout << "operator--: " << x_ << " -> " << (x_ - 1) << std::endl;
        x_--;
    }

    inline void push()
    {
        std::cout << "push: " << x_ << " -> " << (x_ - 1) << std::endl;
        --x_;
    }

    inline void dec()
    {
        std::cout << "dec: " << x_ << " -> " << (x_ - 1) << std::endl;
        --x_;
    }

    inline Datatype get() const
    {
        std::cout << "get: " << x_ << std::endl;
        return x_;
    }

private:
    Datatype x_ = 0;
};

void increment(example::number & num)
{
    num.inc();
}

namespace strange
{

template<>
struct reflection<implement>
{
    static inline auto name() -> std::string
    {
        return "implement";
    }
};

template<typename Datatype>
struct reflection<implement_template<Datatype>>
{
    static inline auto name() -> std::string
    {
        return "implement_template<" + reflection<Datatype>::name() + ">";
    }
};

}

int main()
{
    auto i1 = strange::forward_iterator<int>{};
    auto i2 = strange::forward_iterator<int>{};
    i1._static<strange::forward_iterator<int>>();
    std::swap(i1, i2);
    for (auto op : strange::reflection<std::vector<int>>::operations())
    {
        std::cout << op << std::endl;
    }
    std::cout << strange::reflection<std::vector<int>>::name() << std::endl;
    std::cout << strange::reflection<strange::vector_<std::vector<int>, true, int>>::name() << std::endl;
    std::cout << strange::vector_<std::vector<int>, true, int>::_name_ << std::endl;
    std::cout << strange::vector_<std::vector<int>, true, int>::_cat_ << std::endl;

    auto v1 = strange::vector_<std::vector<int>, true, int>::_make_();
    auto v2 = strange::vector<int>::_make(1,2,3);
    auto v3 = strange::vector_<std::vector<double>, true, double>::_make_(1.0,2.0,3.0);
    v1._thing().push_back(123);
    v2.push_back(123);
    v3._thing().push_back(123.0);
    std::cout << v1._name_ << std::endl;
    std::cout << v1._cat_ << std::endl;
    std::cout << v2._name() << std::endl;
    std::cout << v2._cat() << std::endl;
    std::cout << v3._name() << std::endl;
    std::cout << v3._cat() << std::endl;
    v3._cats();

    auto w1 = example::widget::_make<implement>();
    w1.inc();
    auto w2 = ++w1;
    w1.display(example::button());
    w2.display(example::button());
    w2.inc();
    w1.display(example::button());
    w2.display(example::button());

    auto b1 = example::button::_make<implement>()--;
    if (b1._something())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }
    b1.push();

    w1 = b1;
    b1 = w1._static<example::button>();
    if (b1._valid())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    if (w1._static<example::number>()._valid())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    if (w1._dynamic<example::number>()._something())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    std::cout << w1._error("help!") << std::endl;
    std::cout << w1._error() << std::endl;

    auto n1 = example::number::_make<implement>();
    n1.inc();
    n1.dec();

    auto wn1 = example::widget_number::_make<implement>();
    wn1.inc();
    wn1.display(example::button());

    example::number wn2 = wn1;
    wn2.inc();

    example::widget wn3 = wn1;
    wn3.inc();
    wn3.display(example::button());

    wn1.display(example::button());
    increment(wn1);
    wn1.display(example::button());

    increment(wn2);

    auto ni1 = example::numeric<>::_make<implement>();
    ni1.inc();
    auto ni2 = ni1;
    ni2.x() = 2;
    std::cout << ni1.get() << ni1.x() << ni2.x() << std::endl;

    auto wt = example::widget::_make<implement_template<int>>();
    auto bt = example::button::_make<implement_template<int>>()--;
    auto nt = example::number::_make<implement_template<int>>();
    auto wnt = example::widget_number::_make<implement_template<int>>();
    auto nit = example::numeric<>::_make<implement_template<int>>();

    auto params = strange::vector<strange::parameter>::_make();
    for (auto & param : params)
    {
        std::cout << "param: " << param.name() << std::endl;
    }

    std::ifstream ifs{"example__parser_input.h", std::ios::binary};
    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker(it);
    strange::comprehension::parser parser(toker);
    auto space = parser.parse();
    if (space._valid())
    {
        std::cout << "valid space:" << std::endl;
        std::cout << space.name() << std::endl;
    }
    else
    {
        std::cout << "invalid space: " << space._error() << std::endl;
    }
    auto tok = strange::token::_make();
    std::cout << tok._name() << std::endl;

    return 0;
}

#include <string>
namespace syntax
{
namespace strange
{
namespace comprehension
{
enum class cls;
}
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
#include "example__parser_input.h"
#pragma GCC diagnostic pop
}
