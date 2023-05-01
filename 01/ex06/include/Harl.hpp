#ifndef HARL_H
#define HARL_H

#include <string>
#include <map>

class Harl {
    
    public:
        Harl(void);
        ~Harl(void);
        void    complain( std::string level );

    private:
        std::map<std::string, void (Harl::*)(void)>    functs;

        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
};

#endif