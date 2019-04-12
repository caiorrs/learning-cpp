#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "random.hpp" // Effolkronium
//https://github.com/effolkronium/random/blob/master/include/effolkronium/random.hpp

using Random = effolkronium::random_static;

namespace MyRandom
{
std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
}

int getRandomNumberMT(int min, int max)
{
    std::uniform_int_distribution<> die(min, max);
    return die(MyRandom::mersenne);
}

// exemplo de PRNG
unsigned int PRNG()
{
    static unsigned seed = 5323;

    seed = 8253729 * seed + 2396403;

    return seed % 32768;
}

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0); // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{

    std::cout << "Random with seed function\n";
    for (int i = 1; i <= 100; ++i)
    {
        std::cout << PRNG() << "\t";

        if (i % 5 == 0)
        {
            std::cout << "\n";
        }
    }

    std::cout << "Random using c libs\n";

    std::srand(5323);

    for (int i = 1; i <= 100; ++i)
    {
        std::cout << std::rand() << "\t";

        if (i % 5 == 0)
        {
            std::cout << "\n";
        }
    }

    std::cout << "Random using c libs and time\n";

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 1; i <= 100; ++i)
    {
        std::cout << std::rand() << "\t";

        if (i % 5 == 0)
        {
            std::cout << "\n";
        }
    }

    std::cout << "Mersenne Twister random\n";

    std::mt19937 mersenne(static_cast<std::mt19937::result_type>(std::time(nullptr)));
    std::uniform_int_distribution<> die(1, 6);

    for (int count = 1; count <= 48; ++count)
    {
        std::cout << die(mersenne) << "\t";

        if (count % 6 == 0)
        {
            std::cout << '\n';
        }
    }

    // random number MT
    std::cout << "MT\n";
    std::cout << getRandomNumberMT(1, 6) << '\n';
    std::cout << getRandomNumberMT(1, 10) << '\n';
    std::cout << getRandomNumberMT(1, 20) << '\n';

    //effolkronium
    std::cout << "effolkronium\n";
    std::cout << Random::get(1, 6) << '\n';
    std::cout << Random::get(1, 10) << '\n';
    std::cout << Random::get(1, 20) << '\n';

    return 0;
}