#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void) {
    Zombie* zombie = newZombie("test1");
    zombie->announce();
    delete(zombie);
    randomChump("test2");
    Zombie* zombie2 = newZombie("test3");
    delete(zombie2);
}