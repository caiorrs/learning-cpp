#define __STDC_WANT_LIB_EXT1__ 1 // para strcpy_s

#include <iostream>
#include <iterator>
#include <cstring>

int main()
{
    char myString[] = "string";
    // const int length = std::size(myString);
    // // onde fica a função size? vscode não está encontrando

    // std::cout << myString << " has " << length << " characters.\n";

    // for (int index = 0; index < length; ++index)
    // {
    //     std::cout << static_cast<int>(myString[index]);
    // }

    // não é possível alterar uma string após a inicialização, mas é possível
    // alterar cada posição de forma individual

    myString[1] = 'p';
    std::cout << myString << '\n';

    char name[20] = "Alex";
    std::cout << "My name is: " << name << '\n';

    char name2[255];
    std::cout << "Enter your name: ";
    std::cin.getline(name2, 255); // forma segura, restringe a 254 caracteres + \0
    std::cout << "You entered: " << name2 << '\n';

    // char source[] = "Copy this!";
    // char dest[50];

    // strcpy(source, dest);      // inseguro, não faz verificações
    // strlcpy(dest, 5, source);  // vscode nao encontra
    // strcpy_s(dest, 5, source); // vscode nao encontra

    // std::cout << dest << '\n';

    std::cout << name << " has " << strlen(name) << " letters.\n";
    std::cout << name << " has " << sizeof(name) << " chars in array.\n";

    return 0;
}