#include <iostream>

// probar el algoritmo para normalizar los valores
struct BigInt {
    bool negative;
    int* digits;
    size_t size;
    size_t capacity;

    BigInt(int arr[], size_t n, bool neg = false) {
        this->capacity = n;
        this->size = n;
        this->negative = neg;
        this->digits = new int[this->capacity];
        for (size_t i = 0; i < n; i++) {
            this->digits[i] = arr[i];
        }
    }

    BigInt& normalize() {
        while (size > 1 && digits[size - 1] == 0) {
            --size;
        }
        if (size == 1 && digits[0] == 0) {
            negative = false;
        }
        return *this;
    }

    void toString() const {
        if (negative) std::cout << "-";
        for (size_t i = 0; i < size; i++) {
            std::cout << digits[size - 1 - i];
        }
        std::cout << std::endl;
    }

    ~BigInt() {
        delete[] this->digits;
    }
};

int main() {
    /*
    para esto se me ocurre la idea de implementar una pila, porque
    siento que un arreglo dinamico queda algo rudimentario en 
    comparacion a una pila
    */
    int arr1[] = {0, 0, 0, 1, 2, 3};
    BigInt a(arr1, 6, false);

    int arr2[] = {0, 0, 0};
    BigInt b(arr2, 3, false);

    std::cout << "Antes de normalizarse: " << std::endl;
    std::cout << "\na = "; a.toString();
    std::cout << "\nb = "; b.toString();

    std::cout << "\nDespues de normalizarse: " << std::endl;
    std::cout << "\na = "; a.normalize().toString();
    std::cout << "\nb = "; b.normalize().toString();
}