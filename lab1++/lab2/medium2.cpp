#include <iostream>
#include <iomanip> 

int main() {

// Добавляем переменные
    double price;
    int skidkaProcent;
    double finalPrice;

    std::cout << "Введите исходную цену товара: ";
    std::cin >> price;

    std::cout << "Введите скидку в процентах (целое число): ";
    std::cin >> skidkaProcent;

// переводим проценты в дробь. используем static_cast, чтобы показать явное приведение
    double skidkaDrob = static_cast<double>(skidkaProcent) / 100.0;

// считаем итоговую стоимость
    finalPrice = price - (price * skidkaDrob);

// выводим цену с двумя знаками после запятой
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Итоговая цена товара со скидкой: " << finalPrice << " руб." << std::endl;

    return 0;
}
