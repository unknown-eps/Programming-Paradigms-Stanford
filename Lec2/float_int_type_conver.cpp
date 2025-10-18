/*  
We can see that float to int conversion is explicit conversion.
This conversion truncates the decimal part to the nearest integer towards zero.

A direct conversion of raw bytes gives a different integer value.
*/
#include <iostream>

int main(int argc, char *argv[])
{
    float f = 3.14f;
    int i = static_cast<int>(f); // Explicit conversion from float to int
    int d = *(int *)&f;
    std::cout << "Float value: " << f << std::endl;
    std::cout << "Converted int value: " << i << std::endl;
    std::cout << "Bitwise converted int value: " << d << std::endl;
    return 0;
}