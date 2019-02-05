#include "dog.h"
#include <iostream>


int main(int, char *[])
{
    Dog dog;

    if (dog.numberOfBarks() == 0)
    {
        std::cout << "Dog hasn't barked before." << std::endl;
    }

    dog.bark();
    dog.bark();
    std::cout << "Dog has barked " << dog.numberOfBarks() << " times." << std::endl;

    return 0;
}
