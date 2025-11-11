//
// Created by chanbin on 25. 11. 11..
//


// TODO:  Template의 기본적인 구조는 아래와 같습니다.
// template<typename T [parameter]>
// [return type] function_name(T a [argument])
// {
//     ...
// }

// Template에서 타입임을 알리기 위해 Typeanme이나 class 키워드를 사용합니다.
template<typename T>
static T const& max(T const& a, T const &b)
{
    return a > b ? a : b;
}

template<class T>
static T const& min(T const & a,T const & b)
{
    return a < b ? a : b;
}

void test()
{
    max<int>(10, 20);
    max<float>(1.f, 3.f);
    max<double>(1.1, 1.2);
}

