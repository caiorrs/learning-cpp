#include <iostream>

struct Rectangle
{
    int length;
    int width;
}

// enum para facilitar leitura de indices

enum StudentNames {
    KENNY,       // 0
    KYLE,        // 1
    STAN,        // 2
    BUTTERS,     // 3
    CARTMAN,     // 4
    MAX_STUDENTS // 5
};

enum class StudentNames2
{
    KENNY,       // 0
    KYLE,        // 1
    STAN,        // 2
    BUTTERS,     // 3
    CARTMAN,     // 4
    WENDY,       // 5
    MAX_STUDENTS // 6
};

namespace StudentNames3
{
enum StudentNames2
{
    KENNY,       // 0
    KYLE,        // 1
    STAN,        // 2
    BUTTERS,     // 3
    CARTMAN,     // 4
    WENDY,       // 5
    MAX_STUDENTS // 6
};
} // namespace StudentNames3

void passValue(int value)
{
    value = 99;
}

void passArray(int prime[5])
{
    prime[0] = 11;
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

int main()
{
    Rectangle rects[5];

    rects[0].length = 10;
    rects[0].width = 10;

    int arr[5] = {1, 2, 3}; // ultimos dois indices inicializados com 0
    //C++11
    //int arr[5] {1, 2, 3}; // ultimos dois indices inicializados com 0
    int arr2[5] = {}; // inicializa todos os elementos com 0
    // omitted length
    int arr3[] = {1, 2, 3}; // inicializa com tamanho 3

    int testScores[MAX_STUDENTS]; // allocate 5 integers
    testScores[STAN] = 76;

    int testScores[static_cast<int>(StudentNames2::MAX_STUDENTS)]; // allocate 6 integers
    testScores[static_cast<int>(StudentNames2::STAN)] = 76;

    int testScores[StudentNames3::MAX_STUDENTS];
    testScores[StudentNames3::STAN] = 76;

    int value = 1;
    std::cout << "before passValue: " << value << "\n";
    passValue(value);
    std::cout << "after passValue: " << value << "\n";

    int prime[5]{2, 3, 5, 7, 11};
    std::cout << "before passArray: " << prime[0] << "\n";
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << "\n";

    std::size(prime); // tamanho do vetor - numero de elementos C++17

    // tip - cuidar limites do vetor, pois C não faz checagem

    return 0;
}