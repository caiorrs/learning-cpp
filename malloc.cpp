#include <iostream>

int main()
{
    int *ptr = new int; // pede para o SO, SO retorna ponteiro para posição no heap

    *ptr = 9;

    // ou
    int *ptr1 = new int(5);
    int *ptr2 = new int{6};

    // pra liberar
    delete ptr;
    ptr = 0; // nullpointer
    delete ptr1;
    ptr1 = 0;
    delete ptr2;
    ptr2 = 0;

    // caso o SO não consiga retornar uma posicao para a variavel
    // acontecerá uma exceção. Alternativa para não gerar exceção
    int *value = new (std::nothrow) int;
    if (!value)
    {
        //lidar com o erro
        std::cout << "Could not allocate memory\n";
    }

    // alocar memoria caso nao tenha sido alocada - ponteiro = 0 ou ponteiro = null
    if (!ptr)
    {
        ptr = new int;
    }

    // arrays
    std::cout << "Enter a positive integer: ";
    int lenght;
    std::cin >> lenght;

    int *array = new int[lenght]; // poderia ser new[lenght] int tambem
    std::cout << "I just allocated an array of integers of length " << lenght << '\n';
    array[0] = 5;

    delete[] array;
    array = 0;

    int fixedArray[5] = {9, 7, 5, 3, 1};     // initialize a fixed array in C++03
    int *array2 = new int[5]{9, 7, 5, 3, 1}; // initialize a dynamic array in C++11
    int fixedArray2[5]{9, 7, 5, 3, 1};       // initialize a fixed array in C++11
    char fixedArray3[14]{"Hello, world!"};   // initialize a fixed array in C++11

    return 0;
}
