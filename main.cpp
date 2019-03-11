#include "add.h"

#include <iostream>

// comentar a linha abaixo para desabilitar debug
//#define ENABLE_DEBUG

// Evitar este tipo de macro de substituição
#define MY_NAME "caiorrs"

// definição object-like, é aceitável usar
#define USE_YEN
// define não importa onde é escrito, pois o pre-processador ignora o código C
// diretivas para o pre processador valem a partir do momento que são declaradas

// compilacao condicional

#define PRINT_CAIO

void funcao()
{
#ifdef PRINT_CAIO
    // será compilado
    std::cout << "PRINT_CAIO";
#endif

#ifdef PRINT_SOMETHING
    // não será compilado
    std::cout << "PRINT_SOMETHING";
#endif

#ifdef PRINT_SOMETHING_ELSE
    // será compilado
    std::cout << "PRINT_SOMETHING_ELSE";
#endif

#if 0
    std::cout << "NAO SEREI COMPILADO";
#endif
}

// Prototipo
//void imprimeTela();

void imprimeTela()
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "imprimeTela chamada\n";
#endif
    std::cout << "FUNCAO imprimeTela\n";
    std::cout << MY_NAME;
}

int getValueFromUser()
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "getValueFromUser chamada\n";
#endif
    int input{};
    std::cout << "Digite um inteiro: ";
    std::cin >> input;

    return input;
}

void printAdd(int x, int y)
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "printAdd chamada\n";
#endif
    std::cout << x << " + " << y << " = " << x + y << '\n';
}

void printDouble(int num)
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "printDouble chamada\n";
#endif
    std::cout << num << " vezes 2 igual " << num * 2 << '\n';
}

// int add(int x, int y)
// {
//     return x + y;
// }

// int add(int x, int y); // desnecessario agora pois usei #include "add.h"

int multiply(int z, int w)
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "multiply chamada\n";
#endif
    return z * w;
}

int main()
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "main chamada\n";
#endif

    // Inicialização direta - melhor performance
    //int variavel(10);

    // Copy initialization
    //int variavel2 = 10;

    // Brace initialization (Uniform initialization) - aoo tentar atribuir um valor incompativel com o tipo é gerado um warning
    //int variavel3{5};
    //int variavel4{}; // Inicializa com 0 ou vazio, dependendo do tipo de variavel

    float a, b, soma, subtracao, multiplicacao, divisao;

    std::cout << "Digite o primeiro valor: ";
    std::cin >> a;

    // std é o namespace, cout é uma função desse namespace

    std::cout << "Digite o segundo valor: ";
    std::cin >> b;

    soma = a + b;
    subtracao = a - b;
    multiplicacao = a * b;
    divisao = a / b;

    std::cout << "Soma = " << soma << '\n'; // \n é melhor pois não faz flush. cout já faz flush, e endl tambem, sendo desnecessario
    std::cout << "Subtracao = " << subtracao << '\n';
    std::cout << "Multiplicacao = " << multiplicacao << std::endl;
    std::cout << "Divisao = " << divisao << std::endl;

    int variavel5;

    std::cout << "O valor de variavel5 eh: " << variavel5 << '\n';

    // int x{ 2 };             // initialize variable x with value 2
    // int y{ 2 + 3 };         // initialize variable y with value 5
    // int z{ (2 * 3) + 4 };   // initialize variable z with value 10
    // int w{ y };             // initialize variable w with value 5 (the current value of variable y)

    imprimeTela();

    int num{getValueFromUser()};
    printDouble(num);
    // ou
    //
    //printDouble(getValueFromUser());

    int x{getValueFromUser()};
    int y{getValueFromUser()};

    printAdd(x, y);

    // someFunction(a(), b()); // a() or b() may be called first

    // forma de forçar ordem de execução
    // int a{ a() }; // a() will always be called first
    // int b{ b() }; // b() will always be called second
    // someFunction(a, b); // it doesn't matter whether a or b are copied first because they are just values

    std::cout << add(1, multiply(2, 3)) << '\n'; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n';      // evaluates 1 + (2 + 3)

    return 0;
}