 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


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

    
}

/*

#include <iostream>
#include <map>
#include <string>

class CountryCapitalMap {
private:
    std::map<std::string, std::string> countryCapitalPairs;

public:
    int codeError; // 0 - ok, 1 - key not found

    CountryCapitalMap() : codeError(0) {}
    
    // Додати пару країна - столиця до асоціативного масиву
    void addPair(const std::string& country, const std::string& capital) {
        countryCapitalPairs[country] = capital;
    }

    // Перевантаження оператора індексації для звернення до столиці за назвою країни
    std::string& operator[](const std::string& country) {
        auto it = countryCapitalPairs.find(country);
        if (it != countryCapitalPairs.end()) {
            codeError = 0; // Знайдено
            return it->second; // Повернути столицю
        }
        else {
            codeError = 1; // Ключ не знайдено
            static std::string empty; // Повернути порожній рядок
            return empty;
        }
    }

    // Перевантаження оператора виклику функції для звернення до столиці за назвою країни
    std::string& operator()(const std::string& country) {
        return (*this)[country];
    }

    // Вивід асоціативного масиву на екран
    friend std::ostream& operator<<(std::ostream& os, const CountryCapitalMap& map) {
        for (const auto& pair : map.countryCapitalPairs) {
            os << pair.first << " - " << pair.second << std::endl;
        }
        return os;
    }

    // Введення асоціативного масиву з консолі
    friend std::istream& operator>>(std::istream& is, CountryCapitalMap& map) {
        std::string country, capital;
        std::cout << "Enter country-capital pairs (Enter 'break' to finish):\n";
        while (true) {
            std::cout << "Country: ";
            std::getline(is, country);
            if (country == "break") break;
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
    
    // Приклад використання оператора індексації []
    std::cout << "\nCapital of Ukraine: " << countries["Ukraine"] << std::endl;

    // Перевірка коду помилки
    if (countries.codeError == 1) {
        std::cout << "Error: Country not found!\n";
    }

    return 0;
}
*/