#include <iostream>
#include <string>
#include <string_view>

extern int string_viewTest();

void f_ref(const std::string& s) // 단순히 상수 참조로 가져옴
{
    std::cout << s << "\n";
}

void f_view(std::string_view sv) // String_view를 사용하여 가져옴
{
    std::cout << sv << "\n";
}


int string_viewTest()
{
    std::string s =  "Alice";
    f_ref(s);
    f_ref("Bob"); // 상수 참조일 경우에는 가능함 (lifeTime을 연장해주기 떄문임)

    f_view(s);
    f_view("Bob");
    f_view(std::string_view("Key=value").substr(0, 3));

    // std::string_view sv bad;
    //
    // {
    //     std::string temp = "tmp";
    //     bad = temp; // temp가 파괴된다면 Bad는 댕글링 상태가 됌
    // }
}

