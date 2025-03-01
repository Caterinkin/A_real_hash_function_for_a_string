#include <iostream>
#include <string>

// ������� ��� ���������� ���� ������ �� ��������� ���������
int real_string_hash(const std::string& s, int p, int n)
{
    int hash = 0;  // �������������� ���������� ��� �������� ����
    int  p_pow = 1; // ���������� ��� �������� p � ������� ������� �������

    // �������� �� ������� ������� ������
    for (size_t i = 0; i < s.length(); ++i)
    {
        // ��������� � ���� ������������ ���� ������� �� p � ������� �������
        hash = (hash + static_cast<int>(s[i]) * p_pow) % n;
        p_pow = (p_pow * p) % n;  // ��������� p_pow ��� ���������� �������
    }

    return hash;  // ���������� ����������� ���
}

int main()
{
    setlocale(LC_ALL, "rus"); 

    int p, n;  
    
    std::cout << "������� p: ";
    std::cin >> p;
    std::cout << "������� n: ";
    std::cin >> n;
    std::cin.ignore();  // ���������� ���������� ������ ����� ������ ����� ����� �����

    std::string input;  // ���������� ��� �������� ����� ������������

    do
    {
        std::cout << "������� ������: ";
        std::getline(std::cin, input);  

        // ��������� ��� ��������� ������ � ������� ���
        int hash = real_string_hash(input, p, n);
        std::cout << "��� ������ " << input << " = " << hash << std::endl;

    } while (input != "exit");  // ���������� ����, ���� ������������ �� ������ "exit"

    return EXIT_SUCCESS; 
}