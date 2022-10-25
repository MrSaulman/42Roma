#include <iostream>
#include <string>
#include <cmath>
#include <limits>

void convChar(double value)
{
    if (value >= 32 && value <= 126)
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    else if (value < 0 || value > 127 || std::isnan(value))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else
    {
        std::cout << "char: Non diplayable" << std::endl;
    }
}

void convInt(double value)
{
    if (!std::isinf(value) && value > std::numeric_limits<int>::min() && value < std::numeric_limits<int>::max() && !std::isnan(value))
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void convFloat(double value)
{
    if (value == std::floor(value) || std::isinf(value))
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void convDouble(double value)
{
    if (value == std::floor(value) || std::isinf(value))
        std::cout << "float: " << static_cast<double>(value) << ".0" << std::endl;
    else
        std::cout << "float: " << static_cast<double>(value) << std::endl;
}


void convertion(double value)
{
    convChar(value);
    convInt(value);
    convFloat(value);
    convDouble(value);
}

int main(int argc, char **argv)
{
    std::string value;
    double double_val;
    if (argv[1] == NULL || argc != 2)
    {
        std::cerr << "Errore" << std::endl;
        return (0);
    }
    value = argv[1];
    if(value.length() == 1 && !std::isdigit(value[0]))
    {
        double_val = static_cast<double>(value[0]);
    }
	else
    {
        double_val = atof(argv[1]);
    }
    convertion(double_val);
    return (0);
}
