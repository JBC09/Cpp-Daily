//
// Created by chanbin on 25. 11. 10..
//

#include <iostream>

struct MyStruct
{
    int Number;
    int NotNumber;
};

void IncreaseByValue(MyStruct argument)
{
    argument.Number = argument.Number +1;
}

void IncreaseByPointer(MyStruct* argument)
{
    if (argument)
    {
        argument->Number = argument->Number+1;
    }
}

void IncreaseByRef(MyStruct& argument)
{
    argument.Number = argument.Number +1;
}

int refMain()
{
    MyStruct m{100, 0};

    IncreaseByValue(m);

    std::cout << "After by value        : " << m.Number << "\n";

    IncreaseByPointer(&m);

    std::cout << "After by pointer      : " << m.Number << "\n";

    IncreaseByRef(m);

    std::cout << "After by reference    : " << m.Number << "\n";



////////////////////////////////////////////////////////////////////




    int a = 10;

    int &another_a = a;
    int b = 3;


    std::cout << "초기값 a=" << a << ", b=" << b << "\n";
    std::cout << "&a=" << &a << ", &another_a=" << &another_a << " (주소 동일)\n";


    another_a = b;
    std::cout << "after another_a = b;  a=" << a << ", b =" << b << "\n";



    int* p = &a;
    *p = 42;
    std::cout << "after *p = 42         a=" << a << ", b=" << b << '\n';

    p = &b;
    *p = 99;
    std::cout << "after p = &b; *p = 99;    a=" << a << ", b=" << b << "\n";

    return 0;
}

