//
// Created by chanbin on 25. 11. 11..
//

// TODO: Callable
// Callable이란, 이름 그대로 호출 할 수 있는 모든 것을 의미함
// 대표적인 예시로는 함수를 들 수 있음

#include <iostream>

// struct S
// {
//     void operator() (int a,int b)
//     {
//         std::cout << "a + b = " << a + b << std::endl;
//     }
// };
//
// int main()
// {
//     S some_obj;
//     some_obj(10,20);
// }


#include <iostream>
#include <functional>
#include <string>

// std::function에는 모든 Callable을 담을 수 있습니다.

// int some_func(const std::string &a)
// {
//     std::cout << "Func1 호출!" << a << std::endl;
//     return 0;
// }
//
// struct S
// {
//     void operator()(char c)
//     {
//         std::cout << "Func2 호출!" << c << std::endl;
//     }
// };
//

// int main()
// {
//      // Callbale
//     std::function<int(const std::string&)> f1 = some_func;
//     std::function<void(char)> f2 = S();
//     std::function<void()> f3 = []()
//     {
//         std::cout << "Func3 호출!" << std::endl;
//     };
//
//     f1("hello");
//     f2('c');
//     f3();
// }

// 멤머함수들을 함수 객체로 - mem_fn
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <vector>
//
//
// using std::vector;
//
// int main()
// {
//     vector<int> a(1);
//     vector<int> b(2);
//     vector<int> c(3);
//     vector<int> d(4);
//
//     vector<vector<int>> container;
//
//     container.push_back(a);
//     container.push_back(b);
//     container.push_back(c);
//     container.push_back(d);
//
//     vector<int> size_vec(4);
//
//      // 클래스 객체 내에 존재하는 함수를 사용해야 할 때는 std::mem_fn을 사용한다
//     std::transform(container.begin(), container.end(), size_vec.begin(), std::mem_fn(&vector<int>::size));
//
//     for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr)
//     {
//         std::cout << "벡터 크기 :: " << *itr << std::endl;
//     }
// }
//

//
// #include <iostream>
// #include <functional>
//
// void add(int x, int y)
// {
//     std::cout << x << " + " << y << " = " << x + y << std::endl;
// }
//
// void subtract(int x, int y)
// {
//     std::cout << x << " - " << y << " = " << x - y << std::endl;
// }
//
// int main()
// {
//     // std::bind 어떤 함수에 어떤 파라미터들을 넣을 것인지 고정으로 할 것인지 순서를 바꿀 것인지 등의 로직이 가능함
//     auto add_with_2 = std::bind(add, 2, std::placeholders::_1);
//
//     add_with_2(3);
//     add_with_2(3,4);
//
//     // 아래의 경우 minus의 연산을 하는 것을 1번째 파라미터를 2로 고정 시키고 1번째 파라미터를 2번째 파라미터로 인식한다는 뜻임;
//     auto subtract_from_2 = std::bind(subtract, 2, std::placeholders::_1);
//
//     // 아레의 경우 negate(부정?) 1번째와 2번째 인자의 순서를 바꿈
//     auto negate = std::bind(subtract, std::placeholders::_2, std::placeholders::_1);
//
//     // 2 - 3
//     subtract_from_2(3);
//     // 2 - 4
//     negate(4, 2);
// }


#include <iostream>
#include <functional>

struct S
{
    int data;

    // data를 파라미터로 받아서 초기화 리스트로 정의함
    S(int data_) : data(data_)
    {
        std::cout << "일반 생성자" << std::endl;
    }

    //  S객체를 참조로 받아서 하나의 객체를 복사함
    S(const S &s)
    {
        std::cout << "복사 생성자 호출!" << std::endl;
        data = s.data;
    }

    // S객체를 이동시켜서 data만을 넣고 객체를 복사하지 않고 이동의 개념
    S(S&& s)
    {
        std::cout << "이동 생성자 호출!" << std::endl;
        data = s.data;
    }
};

// 참조로 s1과 s2 instance를 받은 다음 s1에 s2.data + 3의 값을 대입시킴
void do_something(S& s1, const S& s2)
{
    s1.data = s2.data + 3;
}

int main()
{
    // Instance 생성
    S s1(1), s2(2);

    // Before printing
    std::cout << "Before : " << s1.data << std::endl;

    // 기본 첫번째 객체를 s1으로 고정 그 다음 들어오는 첫번째 파라미터를 두번째 알규먼트로 bind 되도록 함
    // const 참조의 경우 cref를 사용하면 됌
    auto do_something_with_s1 = std::bind(do_something, std::ref(s1), std::placeholders::_1);

    // s1.data가 5 됌
    do_something_with_s1(s2);

    std::cout << "After :: " << s1.data << std::endl;
}

