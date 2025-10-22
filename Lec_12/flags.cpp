/*
Here we simply want to see how to activate the NDEBUG flag so asserts are ignored.
Usee g++ -o flags.out flags.cpp -DNDEBUG
*/
#include <iostream>
#include <cassert>
#define height 480
int width = 12;
int main()
{
    int x=3;
    int y=4;
    assert(x==y);
    std::cout<<"Line after assert should come only in NDEBUG mode";
}