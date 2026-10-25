#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

// вводим константы для чисел
    const int MIN_MONTH = 1;
    const int MAX_MONTH = 12;
    const int MIN_DAY = 1;
    const int MAX_DAY_31 = 31;
    const int MAX_DAY_30 = 30;
    const int MAX_DAY_FEB = 29;

    int day, month;

    std::cout << "Введите день рождения (число): ";
    std::cin >> day;
    std::cout << "Введите месяц рождения (1-12): ";
    std::cin >> month;

// ввел ли пользователь числа, а не буквы
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно вводить только числа" << std::endl;
    }
// существует ли такой месяц
    else if (month < MIN_MONTH || month > MAX_MONTH) {
        std::cout << "Ошибка: месяц должен быть от 1 до 12" << std::endl;
    }
// день не может быть меньше 1 или больше 31 вообще никогда
    else if (day < MIN_DAY || day > MAX_DAY_31) {
        std::cout << "Ошибка: день должен быть от 1 до 31" << std::endl;
    }
// для февраля максимум 29 дней
    else if (month == 2 && day > MAX_DAY_FEB) {
        std::cout << "Ошибка: в феврале не может быть больше 29 дней" << std::endl;
    }
// для месяцев, в которых всего 30 дней (апрель, июнь, сентябрь, ноябрь)
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > MAX_DAY_30) {
        std::cout << "Ошибка: в этом месяце только 30 дней" << std::endl;
    }

        // определение знака зодиака
    else {
        if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
            std::cout << "овен - упрямый и энергичный" << std::endl;
        }
        else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
            std::cout << "телец - спокойный и надежный" << std::endl;
        }
        else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
            std::cout << "близнецы - общительный и веселый" << std::endl;
        }
        else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
            std::cout << "рак - добрый и заботливый" << std::endl;
        }
        else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
            std::cout << "лев - смелый и уверенный" << std::endl;
        }
        else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
            std::cout << "дева - умный и аккуратный" << std::endl;
        }
        else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
            std::cout << "весы - честный и дружелюбный" << std::endl;
        }
        else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
            std::cout << "скорпион - решительный и сильный" << std::endl;
        }
        else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
            std::cout << "стрелец - активный и оптимистичный" << std::endl;
        }
        else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
            std::cout << "козерог - терпеливый и серьезный" << std::endl;
        }
        else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
            std::cout << "водолей - творческий и независимый" << std::endl;
        }
        else {
            std::cout << "рыбы - мечтательный и спокойный" << std::endl;
        }
    }

    return 0;
}