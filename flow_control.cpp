#include <iostream>
#include <cstdlib>
#include <cmath>

void cleanup()
{
    //  some cleanup here
}

void printSqrt(double value)
{
    if (value > 0.0)
        std::cout << "The square of " << value << " is " << sqrt(value) << "\n";
    else
        std::cout << "Error: " << value << " is negative\n";
}

enum class ErrorCode
{
    SUCCESS = 0,
    NEGATIVE_NUMBER = -1
};

ErrorCode doSomething(int value)
{
    // if value is a negative number
    if (value < 0)
        // early return an error code
        return ErrorCode::NEGATIVE_NUMBER;

    // Do whatever here

    return ErrorCode::SUCCESS;
}

int main()
{

    bool sair = false;

    //std::cout << 1;
    //cleanup();

    // sair do programa / halt
    if (sair)
        exit(0);

    //std::cout << 2;

    std::cout << "Digite um numero: ";
    int x;
    std::cin >> x;

    std::cout << "Voce inseriu o numero " << x << "\n";

    if (x > 10)
    {
        std::cout << "O numero entrado eh maior que 10\n";
    }
    else
    {
        std::cout << "O numero digitado eh menor ou igual a 10\n";
    }

    printSqrt(10);
    printSqrt(-10);

    std::cout << "Enter a positive number: ";
    int y;
    std::cin >> y;

    if (doSomething(y) == ErrorCode::NEGATIVE_NUMBER)
    {
        std::cout << "You entered a negative number.\n";
    }
    else
    {
        std::cout << "It worked!\n";
    }

    // null statement
    if (y > 10)
    {
        ; // não faz nada // nop
    }
    else
    {
        std::cout << "This is not a null statement\n";
    }

    // switch statement
    switch (y)
    {
    case 1:
        std::cout << "You entered the number 1\n";
        break;
    case 2:
        std::cout << "You entered the number 2\n";
        break;
    case 3:
        std::cout << "You entered the number 3\n";
        break;
    default:
        std::cout << "You did not entered 1, 2 or 3\n";
        break;
    }

    // while statement
    int count{0};
    while (count < 10)
    {
        std::cout << count << " ";
        ++count;
    }
    std::cout << "Done!";

    // do while statement
    int selection;
    do
    {
        std::cout << "\n--Menu--\n";
        std::cout << "Opcao 1\n";
        std::cout << "Opcao 2\n";
        std::cout << "Opcao 3\n\n";
        std::cout << "Digite sua opcao";
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3);

    // for statement
    for (int count = 0; count < 10; ++count)
    {
        std::cout << count << " ";
    }

    // for loop multiple vars
    int iii, jjj;
    for (iii = 0, jjj = 9; iii < 10; ++iii, --jjj)
    {
        std::cout << iii << " " << jjj << '\n';
    }

    return 0;
}