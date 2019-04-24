#include <iostream>

int main()
{
    // pointing to const vars
    const int value = 5;
    const int *ptr = &value; // trata value como const
    // independente de value ter sido declarada como const ou nao
    // ex
    int value2 = 10;
    const int *ptr2 = &value2;
    // não é possível fazer *ptr2 = 11;
    // mas pode-se fazer
    value2 = 11;

    // ponteiro constante
    int value3 = 20;
    int *const ptr3 = &value3;
    // ptr3 nao pode receber outro endereço
    // ptr3 = value // erro
    // mas o valor contido no endereço apontado pode ser alterado
    // ex
    value3 = 21;
    *ptr3 = 22;

    // A non-const pointer can be redirected to point to other addresses.
    // A const pointer always points to the same address, and this address can not be changed.
    // A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
    // A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.

    // int value = 5;
    // const int *ptr1 = &value; // ptr1 points to a "const int", so this is a pointer to a const value.
    // int *const ptr2 = &value; // ptr2 points to an "int", so this is a const pointer to a non-const value.
    // const int *const ptr3 = &value; // ptr3 points to a "const int", so this is a const pointer to a const value.

    return 0;
}