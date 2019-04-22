#include <iostream>

int main()
{
    int array[5] = {9, 7, 5, 3, 1};

    std::cout << "Element 0 has address: " << &array[0] << '\n';

    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    int *ptr = array;
    std::cout << *ptr << '\n';

    int value = 7;
    ptr = &value;

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';

    return 0;
}