#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    ICharacter* test = new Character("test");
    AMateria* ice = new Ice();
    test->equip(ice);
    test->use(0, *test);
    AMateria* ice2 = new Ice((*(Ice*)ice));
    test->equip(ice2);
    test->use(0, *test);
    test->use(1, *test);

    delete test;

    return 0;
}