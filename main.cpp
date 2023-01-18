#include <iostream>
using namespace std;
#include "json.h"
using namespace crab::json;

void test()
{
    /*     Json j1;
        Json j2 = true;
        Json j3 = 1111;
        Json j4 = 1.111;
        Json j5 = "c++";

        bool b = j2;
        int i = j3;
        double d = j4;
        const string &s = j5; */

    /*     Json arr;
        arr[0] = true;
        arr[1] = 111;
        arr.append(1.23);
        arr.append("c++");
        std::cout << arr.str() << std::endl;

        bool b = arr[0];
        int i = arr[1];
        double d = arr[2];
        const string &s = arr[3]; */

    /*     Json obj;
        obj["bool"] = true;
        obj["int"] = 111;
        obj["double"] = 1.11;
        obj["str"] = "c++";

        std::cout << obj.str() << std::endl; */

    /*     Json arr;
        arr[0] = true;
        arr[1] = 111;
        arr[2] = 1.11;
        arr[3] = "c++";
        for (auto it = arr.begin(); it != arr.end(); it++)
        {
            std::cout << it->str() << std::endl;
        } */

    Json arr;
    arr[0] = true;
    arr[1] = 111;
    arr[2] = 1.11;
    arr[3] = "c++";
    std::cout << arr.has(0) << std::endl;
    std::cout << arr.has(4) << std::endl;
    arr.remove(0);
    std::cout << arr.has(0) << std::endl;

    Json obj;
    obj["bool"] = true;
    obj["int"] = 111;
    obj["double"] = 1.11;
    obj["str"] = "c++";
    std::cout << obj.has("bool") << std::endl;
    std::cout << obj.has("xxx") << std::endl;
    obj.remove("bool");
    std::cout << obj.has("bool") << std::endl;
}
int main()
{
    test();
    return 0;
}