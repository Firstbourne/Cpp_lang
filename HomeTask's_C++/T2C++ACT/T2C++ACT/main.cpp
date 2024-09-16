//Bakhtiarov A. V. : Group 3821B1PR2, Task #2 Variant 4.

#include <iostream>
#include <string>
#include <sstream>
#include <fstream> //Read from file's and wtite to file's
#include <Windows.h> //Console
using namespace std;

 enum MyEnum
{
	quit = 0, // exit from prog
	assignment = 1, // x1 = x2 (Prisvoit)
	plus_oct = 2, // +
	minus_oct = 3, // -
	multiply_oct = 4, // *
	index = 5, // index checker
	assimilate = 6, // Sravnenie
	equal_oct = 7, // =
	not_equal_oct = 8, // !=
	equal_larg_oct = 9, // >=
	equal_less_oct = 10, // <=
	larger_oct = 11, // >
	less_oct = 12 // <
};

class Octal {
private:
	unsigned char* octal;
	unsigned int oct;
	int arr_size;
public:
	Octal(); //Constr default

	Octal(std::string str); // Constr initialize

	Octal(const Octal& number); // Constr copy

	~Octal(); // Destruct

	void operator = (const Octal& number) {
		this->oct = number.oct;
	}
	 void operator += (Octal& number) {
		 this->oct += number.oct;
	}
	 void operator -= (Octal& number) {
		 this->oct -= number.oct;
	 }
	 void operator *= (Octal& number) {
		 this->oct *= number.oct;
	 }
	 bool operator == (Octal& number) {
		 return this->oct == number.oct;
	 }
	 bool operator != (Octal& number) {
		 return this->oct != number.oct;
	 }
	 bool operator >= (Octal& number) {
		 return this->oct >= number.oct;
	 }
	 bool operator <= (Octal& number) {
		 return this->oct <= number.oct;
	 }
	 bool operator > (Octal& number) {
		 return this->oct > number.oct;
	 }
	 bool operator < (Octal& number) {
		 return this->oct < number.oct;
	 }

	friend std::ostream& operator << (std::ostream& out, Octal& number);
	friend std::ofstream& operator << (std::ofstream& out, Octal& number);

	char operator[](int index);

	void toChar(unsigned int oct) {
		stringstream ss;
		string temp;
		ss << oct << oct;
		ss >> temp;
		arr_size = temp.size();
		octal = new unsigned char[arr_size];
		for (int i = 0; i < arr_size; i++) {
			octal[i] = temp[arr_size - 1];
		}
	}
};

std::ostream& operator << (std::ostream& out, Octal& number)
{
	out << "Octal: " << number.octal;
	return out;
}

std::ofstream& operator << (std::ofstream& out, Octal& number)
{
	out << number.octal;
	return out;
}

char Octal::operator[](int index)
{
	if (index > arr_size) { return '\0'; } 
	return octal[index];
}

Octal::Octal() // Constr default
{
	octal = 0;
}

Octal::Octal(std::string str) // Constr Initial.
{
	stringstream ss;
	ss << oct << str;
	ss >> this->oct;
	toChar(this->oct);
}

Octal::Octal(const Octal& number) // Constr copy
{
	octal = number.octal;
}

Octal::~Octal() {} //Destruct

/*_____________________________________________________________________________________________________________________________________________________*/
//Functions:
void assimilate_oct(int choose, Octal oct_first, Octal oct_second)
{
	if (choose == equal_oct) {
		if (oct_first == oct_second) { std::cout << "Operation (" << oct_first << " == " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " == " << oct_second << ") True\n"; }
	}
	if (choose == not_equal_oct) {
		if (oct_first != oct_second) { std::cout << "Operation (" << oct_first << " != " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " != " << oct_second << ") True\n"; }
	}
	if (choose == equal_larg_oct) {
		if (oct_first >= oct_second) { std::cout << "Operation (" << oct_first << " >= " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " >= " << oct_second << ") True\n"; }
	}
	if (choose == equal_less_oct) {
		if (oct_first <= oct_second) { std::cout << "Operation (" << oct_first << " <= " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " <= " << oct_second << ") True\n"; }
	}
	if (choose == larger_oct) {
		if (oct_first > oct_second) { std::cout << "Operation (" << oct_first << " > " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " > " << oct_second << ") True\n"; }
	}
	if (choose == less_oct) {
		if (oct_first < oct_second) { std::cout << "Operation (" << oct_first << " < " << oct_second << ") True\n"; }
		else { std::cout << "Operation (" << oct_first << " < " << oct_second << ") True\n"; }
	}
}

void working_operation(int operation, Octal oct_first, Octal oct_second)
{
	int choose;
	if (operation == assignment) { oct_first = oct_second; }
	else if (operation == plus_oct) { oct_first += oct_second; }
	else if (operation == minus_oct) { oct_first -= oct_second; }
	else if (operation == multiply_oct) { oct_first *= oct_second; }
	else if (operation == assimilate)
	{
		std::cout << "Choose operation: \n" << "1 - '=='\n" << "2 - '!='\n" << "3 - '>='\n" << "4 - '<='\n" << "1 - '>'\n" << "1 - '<'\n";
		std::cin >> choose;
		system("cls");
		assimilate_oct(choose, oct_first, oct_second);
	}
}


int main() {
	setlocale(LC_ALL, "russian");

	int operation, indexs;
	std::string str;

	// Number from keyboard
	std::cout << "Hello!";
	std::cout << "Enter your octal number #1: ";
	std::cin.ignore();
	getline(std::cin, str);

	// Create first Octal object:
	Octal oct_first(str);
	std::cout << "Enter operation: \n" << "1 - assignment\n" << "2 - plus octal\n" << "3 - minus octal\n" << "4 - multiply octal\n" << "5 - index\n" << "6 - assimilate\n" << "0 - exit\n";
	std::cin >> operation;

	//Enum operation's:
	if (operation == quit) {
		std::cout << "Exit";
		exit(0);
	}
	if (operation == index) {
		std::cout << "Enter index: " << std::endl;
		std::cin >> indexs;
		std::string res;
		if (oct_first[indexs] == '\0') { res = "Error, index does not exist"; }
		else { res = oct_first[indexs]; }
		std::cout << "Index[" << indexs << "] = " << res << std::endl;
	}
	else if (operation != index) {
		std::cout << "Enter your octal number #2: ";
		std::cin.ignore();
		getline(std::cin, str);
		Octal oct_second(str);
	}
}