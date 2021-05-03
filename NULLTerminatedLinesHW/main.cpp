#include<iostream>
#include<cctype>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void Input(char str[], const int n);
int StringLength(char str[]);      //Выводит количество символов
void to_upper(char str[]);         //Переводит строку в верхний регистр
void to_lower(char str[]);         //Переводит строку в нижний регистр
void capitalize(char str[]);       //Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);           //Удаляет из строки лишние пробелы, например:
void shrink_two(char str[]);	   //Хорошо      живет   на  свете   Винни   Пух

void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]);    //Определяет, является ли строка палиндромом
bool is_palindrome_two(char str[]);

bool is_int_number(char str[]);    //Определяет, является ли строка целым числом
								   //Строка является целым числом, когда она состоит только из цифр.
int to_int_number(char str[]);     //Если строка - целое число, функция вернет его числовое значение.

bool is_bin_number(char str[]);    //Проверяет, является ли строка двоичным числом
int bin_to_dec(char str[]);        //Если строка - двоичное число, функция вернет его десятичное значение.
int bin_to_dec_two(char str[]);
//??? dec_to_bin(int decimal);     //Функция принимает десятичное число, и возвращает его двоичное значение.

bool is_hex_number(char str[]);    //Проверяет, является ли функция шестнадцатеричным числом
int hex_to_dec(char str[]);        //Если строка - шестнадцатеричное число, функция вернет его десятичное значение.
//??? dec_to_hex(int decimal);     //Функция принимает десятичное число, и возвращает его Шестнадцатеричное значение.

//bool is_mac_address(char str[]); //Проверяет, является ли строка MAC-адресом
//bool is_ip_address(char str[]);  //Проверяет, является ли строка IP-адресом

//Hardcore:
//Если строка - целое число, функция вернет его письменное значение кириллицей.

/* *** Строки ***
* Строка в языке С представляет собой массив элементов типа char.
* Последним элементом этого массива всегда является ASCII - символ с кодом 0 '\0'
* Этот ноль называют терминирующим, т.е. он показывает конец строки.
* Строки в языке С называют NULL Terminated Lines или строки заканчивающиеся нулем.
*/

void main()
{
	setlocale(LC_ALL, "ru");
	const int n = 150;
	char str[n] = {};
	cout << "...Введите строку: ";

	Input(str, n);

	/*cout << "......Line Length: " << StringLength(str) << " characters" << endl;

	to_upper(str);
	cout << ".........to_upper: " << str << endl;

	to_lower(str);
	cout << ".........to_lower: " << str << endl;

	shrink(str);
	cout << "...........shrink: " << str << endl;
	cout << ".......shrink_two: " << str << endl;

	capitalize(str);
	cout << ".......capitalize: " << str << endl;

	cout << ".......palindrome: ";
	cout << "Строка " << (is_palindrome(str) ? "" : "не ") << "является палиндромом" << endl;

	cout << "...palindrome_two: ";
	cout << "Строка " << (is_palindrome_two(str) ? "" : "не ") << "является палиндромом" << endl;

	cout << "....is_int_number: ";
	cout << "Строка " << (is_int_number(str) ? "" : "не ") << "является числом" << endl;

	cout << "....to_int_number: " << to_int_number(str) << endl;

	cout << "....is_bin_number: ";
	cout << "Строка " << (is_bin_number(str) ? "" : "не ") << "является двоичным числом" << endl;

	cout << ".......bin_to_dec: ";
	cout << bin_to_dec(str) << endl;

	cout << "...bin_to_dec_two: ";
	cout << bin_to_dec_two(str) << endl;

	cout << "....is_hex_number: ";
	cout << "Строка " << (is_hex_number(str) ? "" : "не ") << "является шестнадцатеричным числом" << endl;*/

	cout << ".......hex_to_dec: ";
	cout << str << "(hex) = " << hex_to_dec(str) << "(dec)" << endl;
}

void Input(char str[], const int n)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline - принимает два параметра - это буффер и размер буффера, третий параметр разделитель.
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
		if ( //Если символ
			str[i] >= 'a' && str[i] <= 'z' || //маленькая английская буква ИЛИ
			str[i] >= 'а' && str[i] <= 'я'    //маленькая русская буква
			)//тогда переводим в верхний регистр
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
				str[i] >= 'А' && str[i] <= 'Я')
				str[i] += 32;
		}
	}
}

void capitalize(char str[])
{
	to_lower(str); //Перевести сначала все буквы в нижний регистр
	//Первую букву каждого слова в предложении делает заглавной
	if ( //Проверяет нулевой символ начальный
		str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я')
		str[0] -= 32;
	for (int i = 1; str[i]; i++) //Поскольку начальный символ уже проверили, то можно начинать с единицы int i = 1.
	{
		if (str[i - 1] == ' ') //Если предыдущий символ пробел.
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32; //Тогда отнимаем 32.
		}
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//Пока элемент стоки равен пробелу и следующий элемент равен пробелу или 0
		while ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0)) || str[0] == ' ')
		{
			//То сдвигаем в лево строку
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void shrink_two(char str[])
{
	//Частный случай: убирает в начале пробелы
	//for (int j = 0; str[j]; j++)
	//Общий случай:
	for (int i = 0; str[i]; i++)
	{
		//Пока элемент стоки равен пробелу и следующий элемент равен пробелу или 0
		if (
			str[i] == ' ' &&
			(
				str[i + 1] == ' ' ||
				str[i + 1] == '.' ||
				str[i + 1] == ',' ||
				str[i + 1] == '?' ||
				str[i + 1] == '!' ||
				str[i + 1] == ':' ||
				str[i + 1] == ';' ||
				str[i + 1] == '-' ||
				str[i + 1] == ')'
				)
			|| str[0] == ' '
			|| str[i - 1] == '(' && str[i] == ' '
			|| str[i - 1] == '-' && str[i] == ' '
			)
		{
			//То сдвигаем в лево строку
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

bool is_palindrome(char str[])
{
	//Узнаем размер строки
	int size = StringLength(str);
	to_lower(str); //Перевести сначала все буквы в нижний регистр
	for (int i = 0; i < size; i++)
	{
		//Если первый символ не равен последнему или второй не равен предпоследнему и т.д.
		if (str[i] != str[size - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool is_palindrome_two(char str[])
{
	//Узнаем размер строки
	int size = StringLength(str);
	char* buffer = new char[size + 1]{};
	strcpy_s(buffer, size + 1, str); //Копирует строку str в сторку buffer
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	size = StringLength(buffer);
	for (int i = 0; i < size / 2; i++)
	{
		//Если первый символ не равен последнему или второй не равен предпоследнему и т.д.
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	remove_symbol(str, ' ');
	for (int i = 0; str[i]; i++)
	{
		//Если элемент строки не цифра
		//Если элемент строки строго больше или равно 0 и элемент строки меньше или равно 9
		//и элемент строки не является пробелом
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return false;
		//Если текущий элемент - пробел и следующий пробел
		if (str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	//Если же отрицание не выполнилось, то все элементы строки являются цифрами
	return true;
}

int to_int_number(char str[])
{
	remove_symbol(str, ' ');
	if (!is_int_number(str))
		return 0;
	int num = 0; //Значение числа
	for (int i = 0; str[i]; i++)
	{
		//Если элемент строки не пробел,
		if (str[i] != ' ')
		{
			//тогда значение числа умножаем на 10.
			num *= 10; //Сдвигаем число на один разряд влево, чтобы освободить младший разряд для следующей цифры
			//После того как сдвинули число на целый разряд, к num прибавляем значение строки 
			num += str[i] - 48; //48 - ASCII-код символа '0'
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
		//Предыдущий элемент строки - пробел и текущий элемент строки - пробел и следующий элемент строки пробел
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

int bin_to_dec(char str[])      //Перевод двоичного числа в десятичную систему счисления
{
	if (!is_bin_number(str))
		return 0;
	int decimal = 0;            //Конечное десятичное число 
	int weight = 1;             //Весовой коэффициент у младшего разряда - единица.
	int n = StringLength(str);  //Разрядность числа
	for (int i = n - 1; i >= 0; i--)
	{
		//Если элемент строки не пробел,
		if (str[i] != ' ')
		{
			//тогда к десятичному значению числа прибавляем значение разряда (-48) * на весовой коэффициент weight
			decimal += (str[i] - 48) * weight;
			//После чего переходим к следующему весовому коэффициенту
			weight *= 2;
		}
	}
	return decimal;
}

int bin_to_dec_two(char str[])
{
	if (!is_bin_number(str))
		return 0;
	int decimal = 0;
	remove_symbol(str, ' ');
	int n = StringLength(str);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * pow(2, --n);
		}
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			str[i] != ' '
			)
		{
			return false;
		}
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int n = StringLength(str);
	char* buffer = new char[n + 1]{};
	strcpy_s(buffer, n + 1, str); //Копирует строку str в сторку buffer
	to_upper(buffer);
	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (buffer[i] == 'x' || buffer[i] == 'X')break;
		if (buffer[i] != ' ')
		{
			decimal += (buffer[i] - (isdigit(buffer[i]) ? 48 : 55))*weight;
			weight *= 16;
		}
	}
	return decimal;
}
