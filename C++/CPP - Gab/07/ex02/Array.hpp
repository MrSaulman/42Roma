#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <stdexcept>

template<typename T>
class Array {
	public:
	Array(void) {
		this->_n = 0;
		this->_arr = NULL;
	}
	~Array(){}
	Array(unsigned int n) {
		this->_n = n;
		this->_arr = new T[n]();
	}
	Array(const Array& obj) {
		this->_n = obj._n;
		this->_arr = new T[this->_n];
		for (unsigned int i = 0; i < this->_n; i++) {
			this->_arr[i] = obj._arr[i];
		}
	}
	Array& operator=(const Array& obj) {
		if (this != &obj) {
			delete[] this->_arr;
			this->_n = obj._n;
			this->_arr = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; i++)
				this->_arr[i] = obj._arr[i];
		}
		return *this;
	}
	T&		operator[](unsigned int idx) {
		if (idx >= this->_n)
			throw std::out_of_range("index out of range");
		return this->_arr[idx];
	}
	unsigned int	size() const {
		return this->_n;
	}

	private:
	unsigned int	_n;
	T*	_arr;
};



#endif