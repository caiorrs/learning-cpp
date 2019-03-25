#include "add.h"
#include "constants.h"
#include "sub.h"

#include <cmath> // para potenciacao por exemplo
#include <cstdio>
#include <iomanip> // for std::setprecision()
#include <string>
#include <limits>
#include <iostream>

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

// typedef - apenas um alias - ajuda na documentacao, por exemplo esclarece o que uma função retorna, não apenas o tipo
// dependendo do nome dado
// tambem ajuda na manutenabilidade - se diversas funções e/ou variáveis tiverem que mudar de short para int, é muito mais fácil
// desde que tenha usado o alias nestes lugares, só é necessário alterar a linha de definição do alias - cuidar int>float por questões de comparações ==

typedef double distance_t;
// em c++11
//using distance_t = double;
// usar sufixo _t para mostrar que é typedef

// cross-platform - "renomear" tipos de variaveis
// #ifdef INT_2_BYTES
// typedef char int8_t;
// typedef int int16_t;
// typedef long int32_t;
// #else
// typedef char int8_t;
// typedef short int16_t;
// typedef int int32_t;
// #endif

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

// static duration variables
void addAndPrint()
{
    static int s_value{1}; // s_ -> prefixo para static
    // por ter sido declarada como static ela é declarada e inicializada apenas
    // uma vez depois da primeira execução da função, ela vai continuar com o
    // valor dela
    ++s_value;
    std::cout << "The static value is " << s_value << '\n';
} // a variável nao é destruida após o término da função, mas é acessível
  // apenas por ela

int counter()
{
    static int s_counter{0};
    return s_counter++;
}

void literals()
{
#ifdef ENABLE_DEBUG
    std::cerr << "literals chamada\n"
#endif
        int radius{5};

    double circumference = 2 * radius * Constants::pi;
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
    // int	ull, uLL, Ull, ULL, llu, llU, LLu, or LLU	unsigned long
    // long double	f or F	float double	l or L	long double
}

void readCharInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "readCharInput chamada";
#endif

    std::cout << "Digite um caractere para saber seu correspondente em asc: ";
    char chInput;
    std::cin >> chInput;

    std::cout << "O valor de " << chInput << " em ASCII eh "
              << static_cast<int>(chInput) << "\n";
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
// void imprimeTela();

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
    // preferencialmente usar int16, para ter certeza que será tratado como
    // inteiro

    // tipos de int mais rápidos com pelo menos x bits
    // int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t
    // uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t

    // menores int com no minimo x bits
    // int_least8_t, int_least16_t, int_least32_t, int_least64_t
    // uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t

    // boas práticas
    int x(5);      // 5 means integer
    double y(5.0); // 5.0 is a floating point literal (no suffix means double
                   // type by default)
    float z(5.0f); // 5.0 is a floating point literal, f suffix means float type

    // exibição de ponto flutuante
    std::cout << 5.0 << "\n";
    std::cout << 5.1f << "\n";
    std::cout << 9876543.21 << "\n"; // deve exibir em formato cientifico
    // por padrão cout trunca em 6 digitos significativos
    std::cout << std::setprecision(
        16); // altera a precisão de cout para 16 digitos significativos
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
    std::cout << "Valores deslocados 2 bits para a esquerda: " << valor3 << " e "
              << valor4 << "\n";

    valor3 = 15; // redefinição para evitar perda de bits pelo shift anterior
    valor4 = 1;
    valor3 = valor3 >> 2;
    valor4 = valor4 >> 2; // há perda de bits nos 2 valores quando se faz algum
                          // shift para a direita
    std::cout << "Valores deslocados 2 bits para a direita: " << valor3 << " e "
              << valor4 << "\n";

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

enum Color
{
    COLOR_BLACK, // atribuido à 0
    COLOR_BLUE,  // atribuido à 1
    COLOR_RED,   // atribuido à 2
    COLOR_GREEN, // atribuido à 3

    // valores enum são avaliados para numeros inteiros

    // ANIMAL_CAT = -3,
    //ANIMAL_DOG, // assigned -2
    //ANIMAL_PIG, // assigned -1
    //ANIMAL_HORSE = 5,
    //ANIMAL_GIRAFFE = 5, // shares same value as ANIMAL_HORSE // evitar enum com dois valores iguais
    //ANIMAL_CHICKEN // assigned 6

    // enum conta para cima. Se algo for definido, contará a partir dele
    // melhor nao atribuir numeros aos enum

    // enum pode ser usado para documentacao
    // algo como codigos de erro
    // exemplo abaixo

};

// enum ParseResult
// {
//     SUCCESS = 0,
//     ERROR_OPENING_FILE = -1,
//     ERROR_READING_FILE = -2,
//     ERROR_PARSING_FILE = -3
// };

// ParseResult readFileContents()
// {
//     if (!openFile())
//         return ERROR_OPENING_FILE;
//     if (!readFile())
//         return ERROR_READING_FILE;
//     if (!parsefile())
//         return ERROR_PARSING_FILE;

//     return SUCCESS;
// }

void enumClass()
{
    enum class Color // "enum class" defines this as a scoped enumeration instead of a standard enumeration
    {
        RED, // RED is inside the scope of Color
        BLUE
    };

    enum class Fruit
    {
        BANANA, // BANANA is inside the scope of Fruit
        APPLE
    };

    Color color = Color::RED;    // note: RED is not directly accessible any more, we have to use Color::RED
    Fruit fruit = Fruit::BANANA; // note: BANANA is not directly accessible any more, we have to use Fruit::BANANA

    if (color == fruit) // compile error here, as the compiler doesn't know how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";
}

int main()
{
#ifdef ENABLE_DEBUG
    // imprimir erros sem atraso
    std::cerr << "main chamada\n";
#endif

    // tipo de dado definido pelo usuario
    Color fontColor = COLOR_BLACK;
    Color borderColor(COLOR_BLUE);
    Color paintColor{COLOR_RED};

    std::cout << "FontColor: " << fontColor << '\n';

    // var externa - forward declaration
    // extern int varGlobal2;
    // std::cout << "varGlobal2 : " << varGlobal2 << '\n';
    // deve ter impresso 50, que foi o valor definido em global.cpp

    // constantes

    const double gravity{9.8};

    // definicao de constante por entrada

    std::cout << "Digite sua idade:";
    int idade;
    std::cin >> idade;

    const int idadeUsuario{idade};

    // Inicialização direta - melhor performance
    // int variavel(10);

    // Copy initialization
    // int variavel2 = 10;

    // Brace initialization (Uniform initialization) - aoo tentar atribuir um
    // valor incompativel com o tipo é gerado um warning
    // int variavel3{5};
    // int variavel4{}; // Inicializa com 0 ou vazio, dependendo do tipo de
    // variavel

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

    std::cout << "Soma = " << soma
              << '\n'; // \n é melhor pois não faz flush. cout já faz flush, e
                       // endl tambem, sendo desnecessario
    std::cout << "Subtracao = " << subtracao << '\n';
    std::cout << "Multiplicacao = " << multiplicacao << std::endl;
    std::cout << "Divisao = " << divisao << std::endl;

    int variavel5;

    std::cout << "O valor de variavel5 eh: " << variavel5 << '\n';

    // int x{ 2 };             // initialize variable x with value 2
    // int y{ 2 + 3 };         // initialize variable y with value 5
    // int z{ (2 * 3) + 4 };   // initialize variable z with value 10
    // int w{ y };             // initialize variable w with value 5 (the current
    // value of variable y)

    imprimeTela();

    int num{getValueFromUser()};
    printDouble(num);
    // ou
    //
    // printDouble(getValueFromUser());

    int x{getValueFromUser()};
    int y{getValueFromUser()};

    printAdd(x, y);

    // someFunction(a(), b()); // a() or b() may be called first

    // forma de forçar ordem de execução
    // int a{ a() }; // a() will always be called first
    // int b{ b() }; // b() will always be called second
    // someFunction(a, b); // it doesn't matter whether a or b are copied first
    // because they are just values

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

    addAndPrint();
    addAndPrint();
    addAndPrint();

    std::cout << "O contador esta em " << counter() << '\n';
    std::cout << "O contador esta em " << counter() << '\n';
    std::cout << "O contador esta em " << counter() << '\n';
    std::cout << "O contador esta em " << counter() << '\n';
    std::cout << "O contador esta em " << counter() << '\n';

    std::cout << "Subtracao namespace Sub: " << Sub::sub(5, 3) << '\n';
    // é possível aninhar namespaces, para usar ns1::ns2::ns...::funcao()/constante
    // por essa razao, tambem é possivel criar apelidos da forma
    // namespace ns = ns1::ns2;

    // using statements // seguem as regras de escopo // não é recomendado usar "using"
    // se estiver utilizando muito um objeto de um namespace
    // se encontrar outro objeto com mesma identificação, irá preferir o que está em using
    // é possível fazer por exemplo
    // using std::cout; // using declaration
    // cout << "It's working\n";
    // ou usar um namespace inteiro
    // se encontrar outro objeto com mesma identificação, irá gerar erro de ambiguidade
    // using namespace std; // using directive
    // cout << "This works as well\n";

    //type casting

    int i{10};
    int j{4};
    float f = (float)i / j;
    // outra forma
    // float f = float(i) / j;
    // evitar o uso das duas formas acima

    // static cast
    // mais usado quando um tipo é fundamentalmente diferente do outro
    // como char <-> int
    // float f = static_cast<float>(i) / j
    // evitar o uso de casts

    std::cout << "Divisao = " << f << '\n';

    // std::string

    std::string myString;
    std::string myName("Caio");
    std::cout << "My name is: " << myName << '\n';

    std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    // limpando buffer que o cin deixou
    // ou
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore unlimited characters until a \n is removed

    // leitura/entrada de string
    std::cout << "Enter your first and last name: ";
    std::string fullName;
    std::getline(std::cin, fullName);

    std::cout << "Enter age: ";
    std::string age;
    std::getline(std::cin, age);

    std::cout << "Full name: " << fullName << '\n';
    std::cout << "Age: " << age << '\n';

    std::cout << "Your name is " << fullName.length() << " chars long\n";

    distance_t howFar;

    //std::getchar();

    return 0;
}