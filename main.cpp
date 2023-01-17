#include <iostream>
using namespace std;
#include "json.h"
using namespace crab::json;

void test()
{
    Json j1;
    Json j2 = true;
    Json j3 = 1111;
    Json j4 = 1.111;
    Json j5 = "c++";

    bool b = j2;
    int i = j3;
    double d = j4;
    const string &s = j5;
}
int main()
{
    test();
    return 0;
}