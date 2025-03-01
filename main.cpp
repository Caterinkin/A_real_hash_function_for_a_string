#include <iostream>
#include <string>

// Функция для вычисления хэша строки по заданному алгоритму
int real_string_hash(const std::string& s, int p, int n)
{
    int hash = 0;  // Инициализируем переменную для хранения хэша
    int  p_pow = 1; // Переменная для хранения p в степени индекса символа

    // Проходим по каждому символу строки
    for (size_t i = 0; i < s.length(); ++i)
    {
        // Добавляем к хэшу произведение кода символа на p в степени индекса
        hash = (hash + static_cast<int>(s[i]) * p_pow) % n;
        p_pow = (p_pow * p) % n;  // Обновляем p_pow для следующего символа
    }

    return hash;  // Возвращаем вычисленный хэш
}

int main()
{
    setlocale(LC_ALL, "rus"); 

    int p, n;  
    
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cin.ignore();  // Игнорируем оставшийся символ новой строки после ввода чисел

    std::string input;  // Переменная для хранения ввода пользователя

    do
    {
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);  

        // Вычисляем хэш введенной строки и выводим его
        int hash = real_string_hash(input, p, n);
        std::cout << "Хэш строки " << input << " = " << hash << std::endl;

    } while (input != "exit");  // Продолжаем цикл, пока пользователь не введет "exit"

    return EXIT_SUCCESS; 
}