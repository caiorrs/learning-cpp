#include <iostream>

// ref é uma referência para o argumento passado, não é uma cópia
void changeN(int &ref)
{
    ref = 6;
}

int main()
{
    // references to non-const values
    int value = 5;
    int &ref = value; //reference to var value

    // references as aliases
    int x = 5;
    int &y = x; // reference to x
    int &z = y; // reference to x

    value = 6;
    ref = 7;

    std::cout << "value = " << value << '\n';
    ++ref;
    std::cout << "value = " << value << '\n';

    // endereçoes de memoria
    std::cout << "Enderecos de memoria\n";
    std::cout << "end. value = " << &value << '\n';
    std::cout << "end. ref = " << &ref << '\n';
    // ambos apontam para o mesmo endereço, é como um apelido diferente para a
    // mesma posição de memória

    int n = 5;
    std::cout << "n before changeN = " << n << '\n';
    changeN(n);
    std::cout << "n after changeN = " << n << '\n';

    int x = 5;
    const int &ref1 = x; // okay, x is a non-const l-value

    const int y = 7;
    const int &ref2 = y; // okay, y is a const l-value

    const int &ref3 = 6; // okay, 6 is an r-value

    int value4 = 5;
    const int &ref4 = value4; // create const reference to variable value

    value4 = 6; // okay, value is non-const
    //ref4 = 7;   // illegal -- ref is const

    return 0;
}