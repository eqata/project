#include <iostream>

int main() {
    int month;
    int year;

    std::cout << "Введите номер месяца (1-12): ";
    std::cin >> month;

    switch (month) { // группировка для месяцев с 31 днем
        case 1:  // январь
        case 3:  // март
        case 5:  // май
        case 7:  // июль
        case 8:  // август
        case 10: // октябрь
        case 12: // оекабрь
            std::cout << "Количество дней: 31" << std::endl;
            break;

        // группировка для месяцев с 30 днями
        case 4:  // апрель
        case 6:  // июнь
        case 9:  // сентябрь
        case 11: // ноябрь
            std::cout << "Количество дней: 30" << std::endl;
            break;

        // для февраля
        case 2:
            std::cout << "Введите год: ";
            std::cin >> year;

            // для проверки високосного года if else: (как в лаб3)
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                std::cout << "Количество дней: 29 (високосный год)" << std::endl;
            } else {
                std::cout << "Количество дней: 28 (невисокосный год)" << std::endl;
            }
            break;

        // неверный месяц
        default:
            std::cout << "Ошибка: месяц должен быть от 1 до 12" << std::endl;
            break;
    }

    return 0;
}