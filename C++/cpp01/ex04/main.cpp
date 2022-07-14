#include "string_utils.hpp"

int main(int argc, char **argv) 
{
    StringManip strManip;

    if(argc != 4)
        return (0);

    strManip.getPath(argv[1]);
    strManip.setSub(argv[2]);
    strManip.setToSub(argv[3]);
    strManip.searchStr();
    strManip.CfileAndW();
    return(0);
}