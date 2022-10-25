#include "Data.hpp"

Data::Data() : _value(0)
{

}

Data::~Data()
{

}

Data::Data(const Data &obj)
{
    *this = obj;
}

Data &Data::operator=(const Data &obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

Data::Data(uintptr_t value) : _value(value)
{

}

uintptr_t serialize(Data* ptr)
{
    uintptr_t p;

    p = reinterpret_cast<uintptr_t>(ptr);
    return (p);
}

Data* deserialize(uintptr_t raw)
{
    Data *p;

    p = reinterpret_cast<Data*>(raw);
    return (p);
}

uintptr_t Data::getValue()
{
    return (this->_value);
}

void Data::setValue(uintptr_t value)
{
    this->_value = value;
}
