#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <random>

// Функция для переворачивания строки задом наперед
std::string reverseString(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Функция для удаления гласных букв из строки
std::string removeVowels(const std::string& str) {
    std::string vowels = "AEIOUaeiouАЕЁИОУЫЭЮЯаеёиоуыэюя";
    std::string result = str;
    result.erase(std::remove_if(result.begin(), result.end(), [&](char c) {
        return vowels.find(c) != std::string::npos;
        }), result.end());
    return result;
}

// Функция для удаления согласных букв из строки
std::string removeConsonants(const std::string& str) {
    std::string consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyzБВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ";
    std::string result = str;
    result.erase(std::remove_if(result.begin(), result.end(), [&](char c) {
        return consonants.find(c) != std::string::npos;
        }), result.end());
    return result;
}

// Функция для перемешивания букв в слове
std::string shuffleString(const std::string& str) {
    std::string shuffled = str;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), rng);
    return shuffled;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::string word;
    int choice;

    std::cout << "Введите слово: ";
    std::cin >> word;

    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Вывести слово задом наперед" << std::endl;
    std::cout << "2. Вывести слово без гласных" << std::endl;
    std::cout << "3. Вывести слово без согласных" << std::endl;
    std::cout << "4. Рандомно раскидывать буквы заданного слова" << std::endl;
    std::cout << "Выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Результат: " << reverseString(word) << std::endl;
        break;
    case 2:
        std::cout << "Результат: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Результат: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "Результат: " << shuffleString(word) << std::endl;
        break;
    default:
        std::cout << "Неправильный выбор!" << std::endl;
        break;
    }

    return 0;
}
