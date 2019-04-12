#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int test()
{
    if (isLowerVowel('a') != true)
        return 1; // erro
    if (isLowerVowel('q') != false)
        return 2; // erro

    return 0; // tudo certo
}

int main()
{
    std::cout << "Test results\n";
    std::cout << test();

    return 0;
}