#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <locale>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int getValue()
{
    while (true)
    {
        std::cout << "введите число от 1 до 100\n";
        int value;
        std::cin >> value;

        if ((std::cin.fail())||(value>100) || (value<=0))
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "будтк внимательнее выв ошиблись!\n";
        }
        else
            return value;
    }
}
char getAnser()
{
    while (true)
    {
        std::cout << "введите  ваш ответ (y или n): ";
        char anser;
        std::cin >> anser;

        if (std::cin.fail() || ((anser!='y') && (anser!='n')))
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

        } 
        else
            return anser;
    }
}

int anser()
{
    std::cout << "хотите сыграть еще раз ? \n";
    std::cout << "yes or no \n";
    char anser;
    anser = getAnser();
    if (anser == 'y')
        return 1;
    if (anser == 'n')
        return 0;

}


int main()
{
    setlocale(LC_ALL, "ru");
    int otvet;
    do {
        srand(static_cast<unsigned int>(time(0)));
        rand();
        int random = getRandomNumber(1, 100);
        
        for (int count = 1; count <= 8; ++count)
        {
            if (count == 8)
            {
                std::cout << "ВЫ проиграли " << "Я загадал число " << random << '\n';
                break;
            } 

            std::cout << "попытка номер " << count << ": \n";
            
            int value = getValue();
            
            if (value == random)
            {
                std::cout << "вы угадали\n";
                break;
            }
            if (value < random)
                std::cout << "ваше значание маленькое\n";
            if (value > random)
                std::cout << "ваше значание большое\n";

        }
         otvet = anser();
        
    } while (otvet);
    std::cout << "Спасибо за игру!\n";

        return 0;
}