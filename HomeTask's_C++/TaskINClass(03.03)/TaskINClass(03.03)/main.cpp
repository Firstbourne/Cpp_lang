#include <iostream>
#include <string>
using namespace std;

class Weight
{
	int gramm;

public:
	void set_weight(int _gramm)
	{
		gramm = _gramm;
	}
	void get_weight()
	{
		cout << "Weight is: " << gramm << " " << "gramm" << endl;
	}
	Weight operator +(const Weight& other)
	{
		Weight sum;
		sum.gramm = this->gramm + other.gramm;
		return sum;
	}
	Weight operator -(const Weight& other)
	{
		Weight min;
		if (this->gramm < other.gramm) {
			min.gramm = other.gramm - this->gramm;
			return min;
		}
		else {
			min.gramm = this->gramm - other.gramm;
			return min;
		}
	}
	Weight operator *(const Weight& other)
	{
		Weight prod;
		prod.gramm = this->gramm * other.gramm;
		return prod;
	}
	Weight operator =(const Weight& other)
	{
		Weight equal;
		equal.gramm = this->gramm = other.gramm;
		return equal;
	}
	bool operator ==(const Weight& other) 
	{
		return this->gramm == other.gramm;
	}
	bool operator !=(const Weight& other)
	{
		return this->gramm != other.gramm;
	}
	bool operator >(const Weight& other)
	{
		return this->gramm > other.gramm;
	}

	friend ostream& operator <<(ostream& output, Weight other);
};

ostream& operator <<(ostream& output, Weight other)
{
	output << other.gramm << endl;
	return output;
}

int main(int argc, const char * argv[]) 
{
	setlocale(LC_ALL, "russian");
	int wght1, wght2;
	cout << "Enter the 1st weight(in gramm's):" << endl;
	cin >> wght1;
	cout << "Enter the 2nd weight(in gramm's):" << endl;
	cin >> wght2;

	Weight weight1;
	weight1.set_weight(wght1);
	weight1.get_weight();
	Weight weight2;
	weight2.set_weight(wght2);
	weight2.get_weight();

	Weight sum = weight1 + weight2;
	std::cout << "Weight summ is: " << sum << " " << "gramm's" << endl;
	Weight min = weight1 - weight2;
	std::cout << "Weight diff is: " << min << " " << "gramm's" << endl;
	Weight prod = weight1 * weight2;
	std::cout << "Weight prod is: " << prod << " " << "gramm's" << endl;
	Weight equal = weight1 = weight2;
	std::cout << "Latest weight is: " << equal << " " << "gramm's" << endl;
	
	bool sravn_rav = wght1 == wght2;
	if (sravn_rav == 1) {
		cout << "1st Weight = 2nd weight" << endl;
	}
	else {
		cout << "1st weight != 2nd weight" << endl;
	}
	//cout << sravn_rav << endl;
	bool sravn_nerav = wght1 != wght2;
	//cout << sravn_nerav << endl;
	bool value_check = wght1 > wght2;
	if (value_check == 1) {
		cout << "1st weight > 2nd weight" << endl;
	}
	else {
		cout << "1st weight < 2nd weight" << endl;
	}

	float to_pounds(); { // 1 pound = 453,592 gramm's;
		float pound1 = 0, pound2 = 0;
		float pound_val = 453.592;
		pound1 = (wght1 / pound_val);
		pound2 = (wght2 / pound_val);

		cout << "1st weight = " << pound1 << " " << "pound's" << "\n" << "2nd weight = " << pound2 << " " << "pound's" << endl;
	}
	float to_kg(); { // 1kg = 1000gramm's;
		float kg1 = 0, kg2 = 0;
		float kg_val = 1000;
		kg1 = (wght1 / kg_val);
		kg2 = (wght2 / kg_val);

		cout << "1st weight = " << kg1 << " " << "kg's" << "\n" << "2nd weight = " << kg2 << " " << "kg's" << endl;
	}
	system("pause");
	return 0;
}