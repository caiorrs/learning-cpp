#include "add.h"
#include "constants.h"

#include <iostream>
#include <cstdio>
#include <iomanip> // for std::setprecision()
#include <cmath>   // para potenciacao por exemplo

// comentar a linha abaixo para desabilitar debug
//#define ENABLE_DEBUG

// Evitar este tipo de macro de substituição
#define MY_NAME "caiorrs"

// definição object-like, é aceitável usar
#define USE_YEN
// define não importa onde é escrito, pois o pre-processador ignora o código C
// diretivas para o pre processador valem a partir do momento que são declaradas

// compilacao condicional // #ifdef/#ifndef

#define PRINT_CAIO

void divisaoCast()
{
    // divisao de inteiros resulta em inteiro
    // mas ha uma forma de resultar em float
    std::cout << static_cast<double>(5) / 4 << "\n";

    // modulo só funciona com operandos inteiros

    // a partir do C++11 se um dos operandos da divisão for negativo
    // o compilador pode arredondar o resultado para cima ou para baixo
    // no caso do módulo, o resultado pode ser negativo ou positivo
}

void literals()
{
#ifdef ENABLE_DEBUG
    std::cerr << "literals chamada\n"
#endif
        int radius{5};
    double circumference = 2 * radius * constants::pi;
    int a = 5;
    int b = 0xFF;
    int c = 012;    // octal 12, decimal 10
    int d = 0b1010; // 1010 binario, 10 em decimal

    // para valores grandes ou binarios, é possível usar ` como separador visual
    // ex binario 0b0011`1100`0101`1010
    // ex inteiro 1`123`123

    std::cout << a << "\n";
    std::cout << b << "\n";
    // cout imprime como decimal, faz a conversao antes de imprimir

    // modificadores de literais
    // int	u or U	unsigned int
    // int	l or L	long
    // int	ul, uL, Ul, UL, lu, lU, Lu, or LU	unsigned long
    // int	ll or LL	long long
    // int	ull, uLL, Ull, ULL, llu, llU, LLu, or LLU	unsigned long long
    // double	f or F	float
    // double	l or L	long double
}

void readCharInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "readCharInput chamada";
#endif

    std::cout << "Digite um caractere para saber seu correspondente em asc: ";
    char chInput;
    std::cin >> chInput;

    std::cout << "O valor de " << chInput << " em ASCII eh " << static_cast<int>(chInput) << "\n";
}

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

bool isEqual(int x, int y)
{
#ifdef ENABLE_DEBUG
    std::cerr << "isEqual foi chamada\n";
#endif
    return (x == y);
}

void printTypeSizes()
{
#ifdef ENABLE_DEBUG
    std::cerr << "printTypeSizes chamada\n";
#endif
    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "wchar_t: " << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t: " << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t: " << sizeof(char32_t) << " bytes\n";
    std::cout << "short: " << sizeof(short) << " bytes\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "long: " << sizeof(long) << " bytes\n";
    std::cout << "long long: " << sizeof(long long) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "long double: " << sizeof(long double) << " bytes\n";
    // int é signed implicitamente
    // char pode ser signed ou unsigned, normalmente signed
    // prefirir usar signed para evitar problemas
    std::cout << "sizeof: " << sizeof(size_t) << " bytes\n";

    // inteiros de tamanho fixo
    // signed
    // int8_t, int16_t, int32_t, int64_t
    // unsigned
    // uint8_t, uint16_t, uint32_t, uint64_t
    uint8_t teste;
    std::cout << "TAMANHO UINT8: " << sizeof(teste) << " bytes\n";
    // teste para saber se int8 e uint8 são tratados como char ou como int
    uint8_t c1 = 65;
    int8_t c2 = 65;
    std::cout << c1 << "\n";
    std::cout << c2 << "\n";
    // se aparecer A -> trata como char
    // preferencialmente usar int16, para ter certeza que será tratado como inteiro

    // tipos de int mais rápidos com pelo menos x bits
    // int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t
    // uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t

    // menores int com no minimo x bits
    // int_least8_t, int_least16_t, int_least32_t, int_least64_t
    // uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t

    // boas práticas
    int x(5);      // 5 means integer
    double y(5.0); // 5.0 is a floating point literal (no suffix means double type by default)
    float z(5.0f); // 5.0 is a floating point literal, f suffix means float type

    // exibição de ponto flutuante
    std::cout << 5.0 << "\n";
    std::cout << 5.1f << "\n";
    std::cout << 9876543.21 << "\n"; // deve exibir em formato cientifico
    // por padrão cout trunca em 6 digitos significativos
    std::cout << std::setprecision(16); // altera a precisão de cout para 16 digitos significativos
    std::cout << 9876543.21 << "\n";

    // float tem precisao entre 6 e 9 digitos significativos
    // double tem precisao entre 15 e 18 digitos significativos
    // long double tem precisao de 15, 18 ou 33 digitos dependendo de quantos
    // bytes ocupa

    // prefirir o uso de double

    // infinito e NaN
    // std::cout << 1 / 0 << "\n"; // +inf
    // std::cout << -1 / 0 << "\n"; // -inf
    // std::cout << 0.0 / 0.0 << "\n"; // indeterminado

    // boolean
    bool myBool;
    myBool = true;
    myBool = !false; // true
    // true e false são avaliados para 1 e 0 respectivamente
    std::cout << "Booleans\n";
    std::cout << "Valor de true eh: " << true << "\n";
    std::cout << "Valor de false eh: " << false << "\n";
    // alterar saida para formato true e false
    std::cout << std::boolalpha;
    std::cout << "Valor de true eh: " << true << "\n";
    std::cout << "Valor de false eh: " << false << "\n";
    // desativar o formato escolhido
    std::cout << std::noboolalpha;

    // intro to if statements
    if (true)
    {
        std::cout << "The condition is true\n";
    }
    else
    {
        std::cout << "The condition is false\n";
    }

    myBool = false;

    if (myBool)
    {
        std::cout << "myBool is true\n";
    }
    else
    {
        std::cout << "myBool is false\n";
    }

    if (isEqual(2, 3))
    {
        std::cout << "The numbers are equal\n";
    }
    else
    {
        std::cout << "The numbers are different\n";
    }

    // char

    // inicializações possíveis
    char ch1{97};  // ASCII = 'a'
    char ch2{'a'}; // mesmo que acima

    std::cout << "char1 - " << ch1 << "\n";
    std::cout << "char2 - " << ch2 << "\n";

    // type cast / static cas
    std::cout << "char1 - " << ch1 << "\n";
    std::cout << "codigo ASCII char1 - " << static_cast<int>(ch1) << "\n";
}

void logicalOperations()
{
#ifdef ENABLE_DEBUG
    std::cerr << "logicalOperations chamada\n";
#endif

    bool bool1{true};
    bool bool2{false};
    int valor1{1};
    int valor2{5};

    int resultado{valor1 < valor2 ? valor1 : valor2};

    std::cout << "O maior entre valor1 e valor2 eh: " << resultado << "\n";

    if (valor1 > valor2)
    {
        std::cout << "Valor1 eh maior que valor2\n";
    }
    else
    {
        std::cout << "Valor2 eh maior que valor1\n";
    }

    if (valor1 > 0 && valor2 > 0)
    {
        std::cout << "Valor1 e Valor2 são positivos\n";
    }
    else
    {
        std::cout << "Valor1 ou valor2 tem valor nulo ou negativo\n";
    }

    if (valor1 >= 1 || valor2 < 2)
    {
        std::cout << "valor1 é maior ou igual a 1 ou valor2 é menor que 2\n";
    }
    else
    {
        std::cout << "valor1 é menor que 1 e valor2 é maior ou igual a 2\n";
    }

    // operadores binarios

    // mais seguro utilizar unsigned
    unsigned int valor3{15};
    unsigned int valor4{1};

    //  shifts
    std::cout << "Valores originais: " << valor3 << " e " << valor4 << "\n";
    valor3 = valor3 << 2;
    valor4 = valor4 << 2;
    std::cout << "Valores deslocados 2 bits para a esquerda: " << valor3 << " e " << valor4 << "\n";

    valor3 = 15; // redefinição para evitar perda de bits pelo shift anterior
    valor4 = 1;
    valor3 = valor3 >> 2;
    valor4 = valor4 >> 2; // há perda de bits nos 2 valores quando se faz algum shift para a direita
    std::cout << "Valores deslocados 2 bits para a direita: " << valor3 << " e " << valor4 << "\n";

    // not
    valor3 = 15;
    valor4 = 1;
    std::cout << "Not bit a bit de " << valor3 << " eh " << ~valor3 << "\n";

    // and
    std::cout << "valor3 and valor4 eh " << (valor3 & valor4) << "\n";

    // or
    std::cout << "valor3 or valor4 eh " << (valor3 | valor4) << "\n";

    // xor
    std::cout << "valor3 xor valor4 eh " << (valor3 ^ valor4) << "\n";

    // atribuicoes
    // assim como é possível fazer as contrações x += 1, -=, /=, %=
    // também é possível fazer x <<= 1, >>=, &=, |=, ^=
}

// definição  de variaveis globais devem estar logo abaixo dos includes

int globalVar{4};

// usar prefixo g_ em variaveis globais

// para tornar uma variável global acessível por outros arquivos
extern int reallyGlobalVar{5};

// para tornar uma variável global acessível apenas por este arquivo
static int reallyNotGlobalVar{5};

void globalVars()
{
    // é possível usar variavel local e global com o mesmo nome
    // a local será priorizada, porém, é possível acessar a variável global também
    int globalVar{10}; // variavel local, oculta a global

    std::cout << "Valor variavel local " << globalVar << '\n';
    std::cout << "Valor variavel global " << ::globalVar << '\n';
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

// var global que está em global.cpp
extern int varGlobal1;

// apenas este arquivo poderá chamar essa função
static void funcaoEstatica()
{
    std::cout << "essa é uma funcao estatica, apenas main.cpp pode usar ela.\n";
}

int main()
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "main chamada\n";
#endif

    // var externa - forward declaration
    //extern int varGlobal2;
    //std::cout << "varGlobal2 : " << varGlobal2 << '\n';
    // deve ter impresso 50, que foi o valor definido em global.cpp

    // constantes

    const double gravity{9.8};

    // definicao de constante por entrada

    std::cout << "Digite sua idade:";
    int idade;
    std::cin >> idade;

    const int idadeUsuario{idade};

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

    std::cout << "5^3 = " << std::pow(5.0, 3.0) << "\n";
    // parametros e retorno são double
    // para inteiros é melhor fazer uma função própria

    // pre-decremento e pre-incremento tem melhor performance que pós
    printTypeSizes();

    readCharInput();

    literals();

    logicalOperations();

    globalVars();

    std::getchar();

    return 0;
}