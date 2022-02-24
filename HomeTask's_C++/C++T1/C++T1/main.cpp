// Бахтияров А.В. Вариант 2 (создание класса с трехмерным вектором).

#include <iostream>
#include <string>
using namespace std;

class Vector3D
{
	private:
		int x, y, z;

	public:
		//friend std::ostream& operator << (std::ostream& out, const Vector3D &vector);

		Vector3D(int _x = 0, int _y = 0, int _z = 0)
		{
			x = _x;
			y = _y;
			z = _z;
		};
		void set_coord(int a, int b, int c) 
		{
			x = a;
			y = b;
			z = c;
		};

		void get_coord() 
		{
			cout << " Coord x - " << x << " Coord y - " << y << " Coord z - " << z << endl;
		};
	
	int getx() const { return x; }
	int gety() const { return y; }
	int getz() const { return z; }

	Vector3D operator =(const Vector3D& other)
	{
		Vector3D equal;
		equal.x = this->x = other.x;
		equal.y = this->y = other.y;
		equal.z = this->z = other.z;
		return equal;
	};

	Vector3D operator +(const Vector3D& other)
	{
		Vector3D sum;
		sum.x = this->x + other.x;
		sum.y = this->y + other.y;
		sum.z = this->z + other.z;
		return sum;
	};

	Vector3D operator -(const Vector3D& other)
	{
		Vector3D dif;
		dif.x = this->x - other.x;
		dif.y = this->y - other.y;
		dif.z = this->z - other.z;
		return dif;
	};
	
};

//std::ostream& operator << (std::ostream& out, const Vector3D &vector);

int main(int argc, const char * argv[]) {

	setlocale(LC_ALL, "Russian");

	int p1, p2, p3, p4, p5, p6;
	cout << "Enter a first vector coord's:" << endl;
	cin >> p1 >> p2 >> p3;
	cout << "Enter a second vector coord's:" << endl;
	cin >> p4 >> p5 >> p6;
	Vector3D vector1;
	vector1.set_coord(p1, p2, p3);
	vector1.get_coord();
	Vector3D vector2;
	vector2.set_coord(p4, p5, p6);
	vector2.get_coord();

	Vector3D vectorsum = vector1.operator+(vector2);
	std::cout << "Vector sum is = " << vectorsum.getx() << "  " << vectorsum.gety() << "  " << vectorsum.getz() << endl;
	
	Vector3D vectordif = vector1.operator-(vector2);
	std::cout << "Vector diff is = " << vectordif.getx() << "  " << vectordif.gety() << "  " << vectordif.getz() << endl;

	Vector3D vectoreq = vector1.operator=(vector2);
	std::cout << "Vector equal is = " << vectoreq.getx() << "  " << vectoreq.gety() << "  " << vectoreq.getz() << endl;

	system("pause");
	return 0;
}