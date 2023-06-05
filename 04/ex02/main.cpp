#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    delete j;
    delete i;

    const WrongAnimal* test1 = new WrongAnimal();
    const WrongAnimal* test2 = new WrongCat();

    std::cout << test1->getType() << " " << std::endl;
    std::cout << test2->getType() << " " << std::endl;
    test1->makeSound();
    test2->makeSound();
    delete test1;
    delete test2;

    Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Cat();
    for (int i = 5; i < 10; i++)
        animals[i] = new Dog();
    for (int i = 0; i < 10; i++)
        animals[i]->makeSound();
    for (int i = 0; i < 100; i++)
        std::cout << ((Cat*) animals[0])->getBrain()->getIdea(i) << "; ";
    std::cout << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << ((Cat*) animals[1])->getBrain()->getIdea(i) << "; ";
    std::cout << std::endl;
    ((Cat*) animals[0])->getBrain()->setIdea("test", 2);
    *((Cat*) animals[1]) = *((Cat*) animals[0]);
    ((Cat*) animals[0])->getBrain()->setIdea("test2", 3);
    for (int i = 0; i < 100; i++)
        std::cout << ((Cat*) animals[0])->getBrain()->getIdea(i) << "; ";
    std::cout << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << ((Cat*) animals[1])->getBrain()->getIdea(i) << "; ";
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        delete animals[i];

    return 0;
}