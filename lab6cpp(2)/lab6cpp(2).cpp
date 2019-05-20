#include"pch.h"
#include <iostream>
#include <fstream>
#include<istream>
#include<string>

using namespace std;

struct book
{
	string avtor;
	string name;
	string chname;
	int price;
	int count;
	int day, month, year;

};

int main()
{
	book tmp;
	const int size = 20;
	book books[size] = {};

	book bookName1;
	bookName1.avtor = "avtor1";
	bookName1.count = 45665;
	bookName1.price = 400;
	bookName1.name = "price of";
	bookName1.chname = "life";


	book bookName2;
	bookName2.avtor = "avtor2";
	bookName2.count = 500000;
	bookName2.price = 200;
	bookName2.name = "test";
	bookName2.chname = "murder";

	ofstream fout("data.txt", ios::binary);
	fout << "Avtor: " << bookName2.avtor << "\n" << "Name: " << bookName2.name << " " << bookName2.chname << "\n" << "count: " << bookName2.count << "\n" << "price:" << bookName2.price << endl;
	fout << "Avtor: " << bookName1.avtor << "\n" << "Name: " << bookName1.name << " " << bookName1.chname << "\n" << "count: " << bookName1.count << "\n" << "price:" << bookName1.price << endl;
	fout.close();
	ifstream fin("data.txt", ios::binary);
	fin.seekg(3 * sizeof(tmp), ios::end);
	fin.read(reinterpret_cast<char*>(&tmp), sizeof(book));
	if ((bookName1.chname == "murder")&& (bookName2.chname == "kill")) {
		cout << "Avtor: " << bookName2.avtor << "\n" << "Name: " << bookName2.name << " " << bookName2.chname << "\n" << "count: " << bookName2.count << "\n" << "price:" << bookName2.price << endl;
		cout << "Avtor: " << bookName1.avtor << "\n" << "Name: " << bookName1.name << " " << bookName1.chname << "\n" << "count: " << bookName1.count << "\n" << "price:" << bookName1.price << endl;
	}
	else if (bookName2.chname == "murder") {
		cout << "Avtor: " << bookName2.avtor << "\n" << "Name: " << bookName2.name << " " << bookName2.chname << "\n" << "count: " << bookName2.count << "\n" << "price:" << bookName2.price << endl;
	}
	else if (bookName1.chname == "murder") {
		cout << "Avtor: " << bookName1.avtor << "\n" << "Name: " << bookName1.name << " " << bookName1.chname << "\n" << "count: " << bookName1.count << "\n" << "price:" << bookName1.price << endl;
	}
	else {
		cout << "book doesnt exist";
	}
	fin.close();

	return 0;
}
