#include <iostream>

int c_to_up(int c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
    return (c);
}

int main(int argc, char **argv)
{
    int i = 1, j = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char)c_to_up(argv[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}