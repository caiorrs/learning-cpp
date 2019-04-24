#include <iostream>
#include <vector>

int main()
{
    int myArr[] = {7, 6, 5, 4, 3, 2, 1};

    for (int number : myArr)
    {
        std::cout << number << ' ';
    }

    for (auto number : myArr) // tipo auto é interessante nesse caso
    {
        std::cout << number << ' ';
    }

    for (auto &number : myArr) // nao irá copiar cada elemento para number a cada iteracao
    {
        std::cout << number << ' ';
        // é possível alterar o valor no array por estar usando referência
    }

    for (const auto &number : myArr)
    {
        std::cout << number << ' ';
        // NÃO É POSSÍVEL alterar o valor no array por estar usando referência const
    }

    // for each funciona com diversas estruturas parecidas com vetores
    // std::vector, listas  encadeadas, árvores e maps

    std::vector<int> fibonacci = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    for (const auto &number : fibonacci)
    {
        std::cout << number << ' ';
    }

    return 0;
}