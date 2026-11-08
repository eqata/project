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

    int mainChoice = -1; // выбор в главном меню
    int subChoice = -1;  // выбор во вложенном подменю
    int day = 0;         // день (1-31)
    int month = 0;       // месяц (1-12)

    // цикл главного меню (работает, пока пользователь не введет 0)
    while (mainChoice != 0) {
        std::cout << "\nГЛАВНОЕ МЕНЮ" << std::endl;
        std::cout << "1. Ввести дату" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> mainChoice;

        // защита от ввода букв вместо цифр
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); // очищаем буфер ввода от неправильных символов
            std::cout << "Ошибка: нужно вводить число, а не буквы" << std::endl;
            mainChoice = -1;
            continue; // возвращаемся в начало цикла
        }

        // внешний
        switch (mainChoice) {
            case 1: {
                std::cout << "Введите день рождения (число): ";
                std::cin >> day;
                std::cout << "Введите месяц рождения (1-12): ";
                std::cin >> month;

                // проверка ввел ли пользователь числа, а не буквы
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
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
                else {
                    // цикл подменю
                    subChoice = -1;
                    while (subChoice != 0) {
                        std::cout << "\nПОДМЕНЮ ДЛЯ ДАТЫ " << day << "." << month << " ---" << std::endl;
                        std::cout << "1. Узнать время года" << std::endl;
                        std::cout << "2. Узнать знак зодиака" << std::endl;
                        std::cout << "3. Узнать количество дней до конца года" << std::endl;
                        std::cout << "0. Вернуться в главное меню" << std::endl;
                        std::cout << "Ваш выбор: ";
                        std::cin >> subChoice;

                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            std::cout << "Ошибка: введите цифру пункта меню" << std::endl;
                            subChoice = -1;
                            continue;
                        }

                        // вложенный switch
                        switch (subChoice) {
                            case 1: // время года и группировка case
                                switch (month) {
                                    case 12: case 1: case 2:
                                        std::cout << "Время года: зима" << std::endl;
                                        break;
                                    case 3: case 4: case 5:
                                        std::cout << "Время года: весна" << std::endl;
                                        break;
                                    case 6: case 7: case 8:
                                        std::cout << "Время года: лето" << std::endl;
                                        break;
                                    case 9: case 10: case 11:
                                        std::cout << "Время года: осень" << std::endl;
                                        break;
                                    default:
                                        std::cout << "Ошибка" << std::endl;
                                        break;
                                }
                                break;

                            case 2: // определение знака зодиака
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
                                break;

                            case 3: { // количество дней до конца года (из 365)
                                int passedDays = 0; // сколько дней прошло в предыдущих месяцах
                                switch (month) {
                                    case 1:  passedDays = 0;   break;
                                    case 2:  passedDays = 31;  break;
                                    case 3:  passedDays = 59;  break;
                                    case 4:  passedDays = 90;  break;
                                    case 5:  passedDays = 120; break;
                                    case 6:  passedDays = 151; break;
                                    case 7:  passedDays = 181; break;
                                    case 8:  passedDays = 212; break;
                                    case 9:  passedDays = 243; break;
                                    case 10: passedDays = 273; break;
                                    case 11: passedDays = 304; break;
                                    case 12: passedDays = 334; break;
                                    default: passedDays = 0;   break;
                                }
                                int dayOfYear = passedDays + day;   // номер дня в году
                                int daysLeft = 365 - dayOfYear;     // осталось до конца года
                                std::cout << "До конца года осталось дней: " << daysLeft << std::endl;
                                break;
                            }

                            case 0:
                                std::cout << "Возврат в главное меню" << std::endl;
                                break;

                            default: // для вложенного switch
                                std::cout << "Ошибка: неверный пункт подменю" << std::endl;
                                break;
                        }
                    }
                }
                break;
            }

            case 0:
                std::cout << "Выход из программы" << std::endl;
                break;

            default:
                std::cout << "Ошибка: выберите 1 или 0" << std::endl;
                break;
        }
    }

    return 0;
}