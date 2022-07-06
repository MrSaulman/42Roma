#ifndef KAREN_H
# define KAREN_H

#include <string>
#include <iostream>

class Karen
{
    public:
        Karen();
        ~Karen();
        void    complain(std::string level);

    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void ); 
        void    (Karen::*_level[4])(void);
};

#endif