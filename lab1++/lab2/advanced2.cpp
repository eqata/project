#include <iostream>
#include <cmath>    // для std::abs и std::round
#include <iomanip>  // для std::fixed и std::setprecision

int main() {

// объявляем переменные типа double, так как координаты могут быть дробными
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double squareDouble;

    std::cout << "Введите x1 и y1 через пробел: ";
    std::cin >> x1 >> y1;

    std::cout << "Введите x2 и y2 через пробел: ";
    std::cin >> x2 >> y2;

    std::cout << "Введите x3 и y3 через пробел: ";
    std::cin >> x3 >> y3;

// проверка на ошибку ввода
    if (std::cin.fail()) {
        std::cout << "Ошибка! Вы ввели не числа." << std::endl;
        return 1; 
    }

// считаем площадь по формуле через определитель
// double выбран, так как этот тип точнее и вмещает очень большие числа
    double det = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    squareDouble = 0.5 * std::abs(det); // std::abs нужен, чтобы площадь не стала отрицательной

// выводим результат
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Площадь треугольника: " << squareDouble << std::endl;

// считаем ту же самую площадь, но принудительно переводим все во float
    float fX1 = static_cast<float>(x1);
    float fY1 = static_cast<float>(y1);
    float fX2 = static_cast<float>(x2); 
    float fY2 = static_cast<float>(y2);
    float fX3 = static_cast<float>(x3); 
    float fY3 = static_cast<float>(y3);

    float detFloat = fX1 * (fY2 - fY3) + fX2 * (fY3 - fY1) + fX3 * (fY1 - fY2);
    float squareFloat = 0.5f * std::abs(detFloat);

// показываем накопление погрешности: сложим 0.1 много раз в цикле
    float sumFloat = 0.0f;
    double sumDouble = 0.0;
    for (int i = 0; i < 1000; i++) {
        sumFloat += 0.1f;
        sumDouble += 0.1;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Площадь во float: " << squareFloat << std::endl;
    std::cout << "Результат 1000 сложений 0.1 во float : " << sumFloat << std::endl;
    std::cout << "Результат 1000 сложений 0.1 в double: " << sumDouble << std::endl;


// static_cast<int> просто отбрасывает дробную часть
// std::round делает математическое округление к ближнему целому
    int truncated = static_cast<int>(squareDouble);
    int rounded = static_cast<int>(std::round(squareDouble));

    std::cout << "Исходная площадь: " << squareDouble << std::endl;
    std::cout << "Усечение: " << truncated << std::endl;
    std::cout << "Округление: " << rounded << std::endl;

    return 0;
}

