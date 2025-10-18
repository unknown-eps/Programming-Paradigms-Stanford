#include <iostream>
/*
This shows that all manipulations are done via pointers we can modify the undelying memory addressses arbitrarily.
*/
struct frac
{
    int num;
    int den;
};

int main()
{
    struct frac cur;
    cur.num = 10;
    cur.den = 12;
    std::cout << "Den has value" << cur.den << std::endl;

    ((struct frac *)(&cur.den))->num = 22;
    std::cout << "Changed den value to " << cur.den << std::endl;
    return 0;
}