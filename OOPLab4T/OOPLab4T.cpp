 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

 /*
#include <iostream>
#include <stdexcept>

class VectorFloat {
private:
    float* data;
    int size;
    int codeError;

public:
    // Конструктор без параметрів
    VectorFloat() : size(1), codeError(0) {
        data = new float[size];
        if (data == nullptr)
            codeError = 1;
        else
            data[0] = 0.0f;
    }

    // Конструктор з одним параметром - розміром вектора
    VectorFloat(int s) : size(s), codeError(0) {
        data = new float[size];
        if (data == nullptr)
            codeError = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = 0.0f;
        }
    }

    // Конструктор із двома параметрами - розміром вектора та значенням ініціалізації
    VectorFloat(int s, float init_value) : size(s), codeError(0) {
        data = new float[size];
        if (data == nullptr)
            codeError = 1;
        else {
            for (int i = 0; i < size; ++i)
                data[i] = init_value;
        }
    }

    // Деструктор
    ~VectorFloat() {
        delete[] data;
    }

    // Функція для друку елементів вектора
    void print() const {
        std::cout << "Vector elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Перевантаження операції унарного префіксного ++
    VectorFloat& operator++() {
        for (int i = 0; i < size; ++i)
            ++data[i];
        return *this;
    }

    // Перевантаження операції присвоєння =
    VectorFloat& operator=(const VectorFloat& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            codeError = other.codeError;
            data = new float[size];
            if (data == nullptr)
                codeError = 1;
            else {
                for (int i = 0; i < size; ++i)
                    data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Перевантаження операції присвоєння з
    VectorFloat& operator=(float value) {
        for (int i = 0; i < size; ++i)
            data[i] = value;
        return *this;
    }
};

void main() {
    int size;
    float value;

    // Підказка для користувача щодо введення розміру вектора
    std::cout << "Enter the size of the vector: ";
    std::cin >> size;

    // Підказка для користувача щодо введення значення для ініціалізації вектора
    std::cout << "Enter the value to initialize the vector: ";
    std::cin >> value;

    // Створення вектора з заданими користувачем параметрами
    VectorFloat v(size, value);

    // Друк елементів вектора
    v.print();

   */
}



#include <iostream>
#include <vector>
#include <string>

struct CountryCapitalPair {
    std::string country;
    std::string capital;
};

class CountryCapitalMap {
private:
    std::vector<CountryCapitalPair> pairs;

public:
    int codeError; // 0 - ok, 1 - key not found

    CountryCapitalMap() : codeError(0) {}

    void addPair(const std::string& country, const std::string& capital) {
        pairs.push_back({ country, capital });
    }

    std::string& operator[](const std::string& country) {
        for (auto& pair : pairs) {
            if (pair.country == country) {
                codeError = 0;
                return pair.capital;
            }
        }
        codeError = 1;
        static std::string empty;
        return empty;
    }

    std::string& operator()(const std::string& country) {
        return (*this)[country];
    }

    friend std::ostream& operator<<(std::ostream& os, const CountryCapitalMap& map) {
        for (const auto& pair : map.pairs) {
            os << pair.country << " - " << pair.capital << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, CountryCapitalMap& map) {
        std::string country, capital;
        std::cout << "Enter country-capital pairs (Enter 'end' to finish):\n";
        while (true) {
            std::cout << "Country: ";
            std::getline(is, country);
            if (country == "end") break;
            std::cout << "Capital: ";
            std::getline(is, capital);
            map.addPair(country, capital);
        }
        return is;
    }
};

int main() {
    CountryCapitalMap countries;
    std::cin >> countries;

    std::cout << "\nCountry-Capital Pairs:\n";
    std::cout << countries;

    std::cout << "\nCapital of Ukraine: " << countries["Ukraine"] << std::endl;

    if (countries.codeError == 1) {
        std::cout << "Error: Country not found!\n";
    }

    return 0;
}
