// biblioteca com a função swap
#include <algorithm> // ou <utility> se for C++11
// função swap está em algorithm
#include <iostream>

int main()
{
    int x = 2;
    int y = 4;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';

    const int length = 5;
    int array[length] = {30, 50, 20, 10, 40};

    for (int startIndex = 0; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }

    for (int index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << "\n";

    array[0] = 30;
    array[1] = 50;
    array[2] = 20;
    array[3] = 10;
    array[4] = 40;

    std::sort(array, array + length);
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << ' ';
    }

    return 0;
}