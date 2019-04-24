#include <iostream>

int main()
{
    struct Person
    {
        int age;
        double weight;
    };
    Person person;

    // Member selection using actual struct variable
    person.age = 5;
    // Member selection using reference to struct
    Person &ref = person;
    ref.age = 5;

    // Member selection using pointer to struct
    Person *ptr = &person;
    (*ptr).age = 5;
    // ou
    ptr->age = 5;

    return 0;
}