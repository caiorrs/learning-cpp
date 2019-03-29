#include <iostream>

struct Employee // Nome de structs começam com maiúscula
{
    short id;
    int age;
    double wage;
};

// Nesting structs
struct Company
{
    Employee CEO;
    int numberOfEmployees;
};

struct Point3d
{
    double x;
    double y;
    double z;
};

Point3d getZeroPoint()
{
    Point3d temp = {0.0, 0.0, 0.0};
    return temp;
}

void printInformation(Employee employee)
{
    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int add2and3()
{
    return 2 + 3;
}

int main()
{
    Employee joe;
    joe.id = 14;
    joe.age = 32;
    joe.wage = 24.15;

    Employee frank;
    frank.id = 15;
    frank.age = 28;
    frank.wage = 18.27;

    // outra forma de inicialização
    // Employee joe = { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
    // Employee frank = { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

    // C++11
    // Employee joe { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
    // Employee frank { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

    int totalAge = joe.age + frank.age;

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Frank makes more than Joe\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

    printInformation(joe);

    std::cout << "\n";

    printInformation(frank);

    std::cout << "\n";

    Point3d zero = getZeroPoint();

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    Company myCompany = {{1, 42, 60000.0f}, 5};

    // auto - pode ser usado apenas para variaveis com inicialização e como tipo de retorno de funcao
    // auto funcName(int p1, int p2) // evitar
    // serve para que a variavel tenha seu tipo definido pela inicialização
    // sendo desnecessário explicitar seu tipo
    auto d = 1.0; // d será do tipo double
    auto i = 21;  // d será do tipo int

    auto soma = add2and3(); // soma será do tipo int, pois a função retorna int

    return 0;
}