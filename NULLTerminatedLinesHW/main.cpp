#include<iostream>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void Input(char str[], const int n);
int StringLength(char str[]);      //������� ���������� ��������
void to_upper(char str[]);         //��������� ������ � ������� �������
void to_lower(char str[]);         //��������� ������ � ������ �������
void capitalize(char str[]);       //������ ����� ������� ����� � ����������� ������ ���������
void shrink(char str[]);           //������� �� ������ ������ �������, ��������:
								   //������      �����   ��  �����   �����   ���
bool is_palindrome(char str[]);    //����������, �������� �� ������ �����������
bool is_int_number(char str[]);    //����������, �������� �� ������ ����� ������
								   //������ �������� ����� ������, ����� ��� ������� ������ �� ����.
int to_int_number(char str[]);     //���� ������ - ����� �����, ������� ������ ��� �������� ��������.

bool is_bin_number(char str[]);    //���������, �������� �� ������ �������� ������
//int bin_to_dec(char str[]);      //���� ������ - �������� �����, ������� ������ ��� ���������� ��������.
//??? dec_to_bin(int decimal);     //������� ��������� ���������� �����, � ���������� ��� �������� ��������.

//bool is_hex_number(char str[]);  //���������, �������� �� ������� ����������������� ������
//int hex_to_dec(char str[]);      //���� ������ - ����������������� �����, ������� ������ ��� ���������� ��������.
//??? dec_to_hex(int decimal);     //������� ��������� ���������� �����, � ���������� ��� ����������������� ��������.

//bool is_mac_address(char str[]); //���������, �������� �� ������ MAC-�������
//bool is_ip_address(char str[]);  //���������, �������� �� ������ IP-�������

//Hardcore:
//���� ������ - ����� �����, ������� ������ ��� ���������� �������� ����������.

/* *** ������ ***
* ������ � ����� � ������������ ����� ������ ��������� ���� char.
* ��������� ��������� ����� ������� ������ �������� ASCII - ������ � ����� 0 '\0'
* ���� ���� �������� �������������, �.�. �� ���������� ����� ������.
* ������ � ����� � �������� NULL Terminated Lines ��� ������ ��������������� �����.
*/

void main()
{
	setlocale(LC_ALL, "ru");
	const int n = 150;
	char str[n] = {};
	cout << "...������� ������: ";

	Input(str, n);

	cout << "......Line Length: " << StringLength(str) << " characters" << endl;

	to_upper(str);
	cout << ".........to_upper: " << str << endl;

	cout << "...........shrink: " << str << endl;

	capitalize(str);
	cout << ".......capitalize: " << str << endl;

	cout << ".......palindrome: ";
	cout << (is_palindrome(str) == 0 ? "������ �� �������� �����������" : "������ �������� �����������") << endl;
	//cout << "������ " << (is_palindrome(str) ? "" : "�� ") << "�������� �����������" << endl;

	cout << "....is_int_number: ";
	cout << (is_int_number(str) == 0 ? "������ �� �������� ������" : "������ �������� ������") << endl;

	cout << "....to_int_number: " << to_int_number(str) << endl;

	cout << "....is_bin_number: ";
	cout << (is_bin_number(str) == 0 ? "������ �� �������� �������� ������" : "������ �������� �������� ������") << endl;
}

void Input(char str[], const int n)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline - ��������� ��� ��������� - ��� ������ � ������ �������, ������ �������� �����������.
	cin.getline(str, n);
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ( //���� ������
			str[i] >= 'a' && str[i] <= 'z' || //��������� ���������� ����� ���
			str[i] >= '�' && str[i] <= '�'    //��������� ������� �����
			)//����� ��������� � ������� �������
			str[i] -= ' ';
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		{
			if (
				str[i] >= 'A' && str[i] <= 'Z' ||
				str[i] >= '�' && str[i] <= '�')
				str[i] += 32;
		}
	}
}

void capitalize(char str[])
{
	to_lower(str); //��������� ������� ��� ����� � ������ �������
	//������ ����� ������� ����� � ����������� ������ ���������
	if ( //��������� ������� ������ ���������
		str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= '�' && str[0] <= '�')
		str[0] -= 32;
	for (int i = 1; str[i]; i++) //��������� ��������� ������ ��� ���������, �� ����� �������� � ������� int i = 1.
	{
		if (str[i - 1] == ' ') //���� ���������� ����� ������.
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�')
				str[i] -= 32; //����� �������� 32.
		}
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//���� ������� ����� ����� ������� � ��������� ������� ����� ������� ��� 0
		while ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0)) || str[0] == ' ')
		{
			//�� �������� � ���� ������
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{
	//������ ������ ������
	int size = StringLength(str);
	to_lower(str); //��������� ������� ��� ����� � ������ �������
	for (int i = 0; i < size; i++)
	{
		//���� ������ ������ �� ����� ���������� ��� ������ �� ����� �������������� � �.�.
		if (str[i] != str[size - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return false;
	}
	return true;
}

int to_int_number(char str[])
{
	if (!is_int_number(str)) return 0;
	int num = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			num *= 10;
			num += str[i] - 48;
		}
	}
	return num;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
	}
	return true;
}