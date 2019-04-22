#include <iostream>
#include <typeinfo>
#include <cstddef> // pra macro NULL

int main()
{
    int x = 5;
    std::cout << x << '\n';
    std::cout << &x << '\n';
    std::cout << *(&x) << '\n';

    // ja no caso de uma função retornar um ponteiro é melhor
    // int* funcao();

    int value = 5;
    int *ptr = &value; // endereco de value

    std::cout << &value << '\n';
    std::cout << ptr << '\n';

    int iValue = 5;
    double dValue = 7.0;
    // variavel e ponteiro devem ser do mesmo tipo
    int *iPtr = &iValue;    // declaracao recomendada
    double *dPtr = &dValue; // para ponteiros

    int y(4);
    std::cout << typeid(&y).name() << '\n'; // Pi = Pointer to integer

    int value2 = 5;
    std::cout << &value2 << '\n';
    std::cout << value2 << '\n';

    int *ptr2 = &value2;
    std::cout << ptr2 << '\n';
    std::cout << *ptr2 << '\n';

    int value3 = 5;
    int value4 = 7;

    int *newPtr;

    newPtr = &value3;
    std::cout << *newPtr << '\n';

    newPtr = &value4;
    std::cout << *newPtr << '\n';

    *newPtr = 10;
    std::cout << value4 << '\n'; // value4 foi alterado por meio de ponteiros

    // Null Pointers -> são avaliados para false em booleanos
    float *fPtr{0};
    // ou
    // float *fPtr;
    // fPtr = 0;
    // ou
    // float *fPtr{NULL};
    // a partir de C++11
    // float *fPtr{nullptr};

    if (fPtr)
    {
        std::cout << "This is a non-null pointer\n";
    }
    else
    {
        std::cout << "This is a null pointer\n";
    }

    return 0;
}