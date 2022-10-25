#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <string>
#include <stdint.h>

class Data {
    private:
        uintptr_t _value;
    public:
        Data();
        ~Data();
        Data(const Data &obj);
        Data &operator=(const Data &obj);
        Data(uintptr_t value);

        uintptr_t getValue();
        void setValue(uintptr_t value);
};
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

#endif