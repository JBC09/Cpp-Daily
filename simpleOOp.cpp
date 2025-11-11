//
// Created by chanbin on 25. 11. 10..
//

#include <iostream>


// 상수 int형을 타입으로하는 pointer
// const int* p : “가리키는 값을 못 바꿈”
// int를 타입으로하는 상수 포인터
// int* const p : “포인터 자체를 못 바꿈(재지정 불가)”


// Class OOP (Object oriented Programing)

struct Engine
{
    int id = 1;
};

class X
{
    const int name_size;
    Engine& engine;
public:
    X(Engine& e) : name_size(20), engine( e ){}; // Initialization List
    void print() const
    {
        std::cout << name_size << std::endl;
    }
};


class Y
{
    const int name_size = 20;
    Engine& engine;
public:
    Y(Engine& e) : engine(e){};
    void print() const { std::cout << name_size << " / " << engine.id << "\n"; }
};

int oopMain()
{
    Engine e{42};
    X x(e);
    x.print();

    Y y(e);
    y.print();
}


