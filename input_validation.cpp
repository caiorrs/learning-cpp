#include <iostream>

double getDouble()
{

    while (true)
    {
        std::cout << "Enter a double value: ";
        double x;
        std::cin >> x;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n'); // após a extração do primeiro caractere
            //o buffer é limpo
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op;
        std::cin >> op;
        std::cin.ignore(32767, '\n');
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            return op;
        }
        else
        {
            std::cout << "Oops, that input is invalid. Try again.\n";
        }
    }
}

void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
    else
        std::cout << "Something went wrong: printResult() got an invalid operator.";
}

int main()
{
    double x = getDouble();
    char op = getOperator();
    double y = getDouble();

    printResult(x, op, y);

    return 0;
}