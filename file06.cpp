#include <iostream>
#include <vector>
#define print(s) std::cout << s << std::endl;

void g (std::vector<int>& a, std::vector<int>& b)
{
    a = b;
}

int main ()
{
    std::vector<int> my_vec1(2);
    std::vector<int> my_vec2(2);
    g (my_vec1, my_vec2);
}
