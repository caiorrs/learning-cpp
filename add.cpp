#include "add.h"
#include <iostream>

// comentar a linha abaixo para desabilitar debug
//#define ENABLE_DEBUG

int add(int x, int y)
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "add chamada\n";
#endif
    return x + y;
}