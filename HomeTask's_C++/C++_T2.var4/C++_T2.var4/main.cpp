// ��������� �.�. ������� �2. ������� 4.

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

	// ~Octal() {};  //����������;

	unsigned int getNum() //�. ������������ �����(��� �� ������������� � �������);
	{
		return number;
	};

	Octal() //�����������,� ������� ��� ����������� �� ����� ����� ���������� ������;
	{
		str = new unsigned char[1000 - 7];
	};

	// 1 �������, ���������. ����� ����������� � ������� char:
	void char_arr(unsigned int number) //������������� ����� � ������� unsigned char;
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

	//����������:

	// 1: +  -:

	Octal operator +(const Octal& oct)
	{
		Octal POresult;
		POresult.number = this->number + oct.number;
		POresult.char_arr(POresult.number); //����� char_arr � �������� � ��� POres.num;
		cout << POresult.number << endl;
		return POresult;
	};

	Octal operator -(const Octal& oct)
	{
		Octal MOresult;
		MOresult.number = this->number - oct.number;
		MOresult.char_arr(MOresult.number); //����� char_arr � �������� � ��� MOres.num;
		cout << MOresult.number << endl;
		return MOresult;
	};

	// 2: ���������:

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

	// 3: ���������:
	Octal operator *(Octal& oct)
	{
		Octal PR_result;
		PR_result.number = this->number * oct.number;
		PR_result.char_arr(PR_result.number);
		cout << PR_result.number << endl;
		return PR_result;
	};

	// 4: ������������:

	Octal operator =(Octal& oct)
	{
		this->number = oct.number;
		int temp = this->number;
		cout << temp << endl;
	};

	// 5: �������� ������ �� ������� �������:

	unsigned char operator [](int i)
	{
		if (i >= size) {
			cout << "����� �� ������� �������" << endl;
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

	void char_input() //�����, ����������� ������ � int;
	{
		string temp = "";
		for (int i = 0; i < Octal::size; i++) {
			temp += Octal::str[i];
		}
		Octal::number = stoi(temp);
	};
};

// 6: ���������� ���������� ifstream + ofstream:

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
		cout << "�� ������� ������� ����" << endl;
	}
	else
	{
		cout << "���� ������" << endl;
	}

	cout << "������� ������ ��� ������ � ����:" << endl;
	SetConsoleCP(1251);  //����� ���������,��� ������������� �������� ����� (�� ����� ��� ���� ������);
	cin >> chislo1 >> chislo2;
	FILEin << chislo1 << "\n" << chislo2 << "\n";
	SetConsoleCP(866); //�������� ����� ���������,��� ����������� ������ ����� ������ ���������;

	Octal out_chislo1(chislo1);
	Octal out_chislo2(chislo2);

	FILEout << out_chislo1 << out_chislo2;


	FILEin.close();
	FILEout.close();
	return 0;
}


