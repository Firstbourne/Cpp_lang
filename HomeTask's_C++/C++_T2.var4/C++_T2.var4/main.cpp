// Бахтияров А.В. Задание №2. Вариант 4.

#include <iostream>
#include <string>
#include <sstream>
#include <fstream> //Read from file's and wtite to file's
#include <Windows.h>
using namespace std;

class Octal
{
	 unsigned int number;
	 int size;
	 unsigned char* str;

public:
	friend ifstream& operator >>(ifstream& fileinput, Octal& result);
	friend ofstream& operator <<(ofstream& fileout, Octal& result);

	// ~Octal() {};  //Деструктор;

	unsigned int getNum() //Ф. возвращающая число(для ее использования в методах);
	{
		return number;
	};

	Octal() //Конструктор,в котором для полученного из файла числа выделяется память;
	{
		str = new unsigned char[1000 - 7];
	};

	// 1 задание, восьмирич. число представить в массиве char:
	void char_arr(unsigned int number) //Представление числа в массиве unsigned char;
	{
		stringstream write;
		string temp;
		write << oct << number;
		write >> temp;
		size = temp.size();
		str = new unsigned char[size];
		for (int i = 0; i < size; i++) {
			str[i] = temp[size - i];
		}
	};
	// endl;

	//Перегрузки:

	// 1: +  -:

	Octal operator +(const Octal& oct)
	{
		Octal POresult;
		POresult.number = this->number + oct.number;
		POresult.char_arr(POresult.number); //Вызов char_arr и передача в нее POres.num;
		cout << POresult.number << endl;
		return POresult;
	};

	Octal operator -(const Octal& oct)
	{
		Octal MOresult;
		MOresult.number = this->number - oct.number;
		MOresult.char_arr(MOresult.number); //Вызов char_arr и передача в нее MOres.num;
		cout << MOresult.number << endl;
		return MOresult;
	};

	// 2: Сравнение:

	bool operator ==(const Octal& oct)
	{
		bool temp = this->number = oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	bool operator!=(const Octal& oct)
	{
		bool temp = this->number != oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	bool operator>(const Octal& oct)
	{
		bool temp = this->number > oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	bool operator<(const Octal& oct)
	{
		bool temp = this->number < oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	bool operator <=(const Octal& oct)
	{
		bool temp = this->number <= oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	bool operator >=(const Octal& oct)
	{
		bool temp = this->number >= oct.number ? true : false;
		cout << temp << endl;
		return temp;
	};

	// 3: Умножение:
	Octal operator *(Octal& oct)
	{
		Octal PR_result;
		PR_result.number = this->number * oct.number;
		PR_result.char_arr(PR_result.number);
		cout << PR_result.number << endl;
		return PR_result;
	};

	// 4: Присваивание:

	Octal operator =(Octal& oct)
	{
		this->number = oct.number;
		int temp = this->number;
		cout << temp << endl;
	};

	// 5: Проверка выхода за границу массива:

	unsigned char operator [](int i)
	{
		if (i >= size) {
			cout << "Выход за границы массива" << endl;
			return '\0';
		}
		return str[i];
	};

	
	Octal(string number)
	{
		stringstream write;
		write << oct << number;
		write >> this->number;
	};

	void char_input() //Метод, переводящий строку в int;
	{
		string temp = "";
		for (int i = 0; i < Octal::size; i++) {
			temp += Octal::str[i];
		}
		Octal::number = stoi(temp);
	};
};

// 6: Перегрузка операторов ifstream + ofstream:

ofstream& operator <<(ofstream& fileout, Octal& result)
{
	 fileout << oct << result.getNum() << endl;
	 return fileout;
}

ifstream& operator >>(ifstream& fileinput, Octal& result)
{
	fileinput >> result.str;
	result.char_input();
	return fileinput;
}

int main() {
	setlocale(LC_ALL, "russian");

	string chislo1, chislo2;
	//string way = "input.txt";
	//FILE.open(way, fstream in | fstream out | fstream app);
	fstream FILEin;
	FILEin.open("input.txt");
	ofstream FILEout;
	FILEout.open("output.txt");
	if (!FILEin.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
	}
	else
	{
		cout << "Файл открыт" << endl;
	}

	cout << "Введите данные для записи в файл:" << endl;
	SetConsoleCP(1251);  //Смена кодировки,для распознования русского языка (не нужно для этой задачи);
	cin >> chislo1 >> chislo2;
	FILEin << chislo1 << "\n" << chislo2 << "\n";
	SetConsoleCP(866); //Обратная смена кодировки,для корректного вывода после работы программы;

	Octal out_chislo1(chislo1);
	Octal out_chislo2(chislo2);

	FILEout << out_chislo1 << out_chislo2;


	FILEin.close();
	FILEout.close();
	return 0;
}


