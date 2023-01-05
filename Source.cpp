#include <iostream>
#include <string>

bool IsKPeriodic(int K, const std::string& txt)
{
    if ((K < 1) || (txt.empty()) || (K > txt.size()))
    {
        std::cout << "Ошибка ввода!" << std::endl;
        return false;
    }
    else
    {
        for (int i = 0; i < K; ++i)
        {
            for (int j = i + K; j < txt.size(); j += K)
            {
                if (txt[j] != txt[i])
                {
                    std::cout << "строка " << txt << " не кратна " << K << std::endl;
                    return false;
                }
                std::cout << "строка " << txt << " кратна " << K << std::endl;
                return true;
            }
        }
        std::cout << "строка " << txt << " кратна " << K << std::endl;
        return true;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    std::string txt;
    int K;
    char ans;
    bool exit = false;
    do
    {
        std::cout << "Введите строку: " << std::endl;
        std::getline(std::cin, txt);
        std::cout << "Введите число периодичности (K): " << std::endl;
        std::cin >> K;
        IsKPeriodic(K, txt);
        std::cout << "\nTry again (Y/N)?" << std::endl;
        std::cin >> ans;
        std::cin.ignore(32767, '\n');
        if (ans == 'N' || ans == 'n')
            exit = true;
    } while (!exit);
    return 0;
}