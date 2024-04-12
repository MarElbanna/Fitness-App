/*The idea of Project 6 is to customize the view according to users� need, which could be, e.g., 3 days or monthly data.
The new functionality (change) in Project 6 is:
instead of saving 7 most recent inputs in the program as Project 5, ask users to provide the number of most recent inputs to be saved,
which should be prompted after getting users� basic information and before showing the menu.
*/
#include<iostream>
#include<string>
using namespace std;

const int DAY = 7;

void shiftArrayToTheLeft(double Array1[], string Array2[], int Array3[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		Array1[i] = Array1[i + 1];
		Array2[i] = Array2[i + 1];
		Array3[i] = Array3[i + 1];
	}
}

int getIntegerInput()
{
	int input;
	//cout << "Enter an integer: ";
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a valid integer! Try one more time: ";
		cin >> input;
	}
	return input;
}

double getDoubleInput()
{
	double input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "It is not a valid input! Try one more time: ";
		cin >> input;
	}
	return input;
}

void getBasicInfo(string& name, string& gender, int& age, double& height)
{
	cout << "Enter Name: ";
	getline(cin, name);

	cout << "Enter Gender: ";
	cin >> gender;

	cout << "Enter age: ";
	age = getIntegerInput();

	cout << "Enter height: ";
	height = getDoubleInput();
}

void printMenu()
{
	string Option1 = "add data, ";
	string Option2 = "print data, ";
	string Option3 = "exit the program, ";
	string option4 = "Print History Data.\n";
	cout << "You can " << Option1 << Option2 << Option3 << option4;
}

void inputData(double weights[], string extypes[], int extimes[], int& day, int days)
{
	cout << "\nDay " << day + 1 << ": " << endl;
	if (day < days)
	{
		cout << "Enter weight: ";
		weights[day] = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, extypes[day]);

		cout << "Enter Exercise time: ";
		extimes[day] = getIntegerInput();

		cout << endl;
	}
	else
	{
		shiftArrayToTheLeft(weights, extypes, extimes, days);

		cout << "Enter weight: ";
		weights[days-1] = getDoubleInput();

		cout << "Enter Exercise Type: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, extypes[days-1]);

		cout << "Enter Exercise time: ";
		extimes[days-1] = getIntegerInput();


		cout << endl;
	}
	day++;
}

void printHistory(double weights[], string extypes[], int extimes[], int AmountOfDays) {
	for (int i = AmountOfDays - 1; i >= 0; i--)
	{
		cout << "\nDay " << i + 1<< ": " << endl;

		cout << "Weight: " << weights[i] << "kg" << endl
			<< "Exercise: " << extypes[i] << " (" << extimes[i] << " mins)" << endl
			<< endl;
	}
}

void printData(string name, string gender, int age, double height, double weights[], string extypes[], int extimes[], int& LastDayDataWasEntered, int days)
{

	cout << '\n';
	if (LastDayDataWasEntered < days)
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << weights[LastDayDataWasEntered - 1];
		cout << "kg" << endl << "Exercise: " << extypes[LastDayDataWasEntered - 1] << " (" << extimes[LastDayDataWasEntered - 1] << " mins)" << endl;
	}
	else
	{
		cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl
			<< "Weight: " << weights[days-1];
		cout << "kg" << endl << "Exercise: " << extypes[days-1] << " (" << extimes[days-1] << " mins)" << endl;
	}
}

string selectMenu()
{
	cout << "What would you like to do? ";

	string x;
	getline(cin, x);

	while (x != "add data" && x != "print data" && x != "exit the program" && x != "Print History Data")
	{
		cout << "The selected option is invalid. ";
		cout << "enter correct input: ";
		cin.clear();
		getline(cin, x);
	}
	return x;
}


int main()
{
	string x;
	bool option1 = false;

	string name;
	string gender;
	int age = 0;
	double height = 0;

	getBasicInfo(name, gender, age, height);
	cin.ignore(1000, '\n');

	int day = 0;
	int* days = new int;

	cout << "How many days would you like to keep track of? ";
	cin >> *days;
	cin.ignore(1000, '\n');

	double* weights = new double[*days];
	string* extypes = new string[*days];
	int* extimes = new int[*days];

	printMenu();

	while (x != "exit the program")
	{
		x = selectMenu();

		if (x == "add data")
		{
			option1 = true;

			inputData(weights, extypes, extimes, day, *days);
			cin.ignore(1000, '\n');
		}
		else if (x == "print data")
		{
			cout << day << endl;
			if (option1 == true)
			{
				printData(name, gender, age, height, weights, extypes, extimes, day, *days);
			}
			else
			{
				cout << "There is no fitness data to print. \n";
			}
		}
		else if (x == "Print History Data")
		{
			if (option1 == true)
			{

				cout << name << endl << gender << ", " << age << ", " << height << 'm' << endl;

				if (day < *days)
				{
					cout << endl;
					printHistory(weights, extypes, extimes, day);
				}
				else
				{
					cout << endl;
					printHistory(weights, extypes, extimes, *days);
				}

			}
			else
				cout << "no fitness data to print. \n";
		}
	}
	cout << "You have exited the app";

	delete[] weights;
	delete[] extypes;
	delete[] extimes;
	delete days;
	return 0;
}