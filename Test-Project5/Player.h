#pragma once
#include "Algoritms.h"

const string PATH_OF_FILE = "Player.dat";

class Player
{
public:
	string fio;
	int number;
	int age;
	int height;
	int weight;
	//public:
	Player();
	~Player() {};

	string get_fio();											//методы инкапсул€ции
	void set_fio(string fio);
	void change_fio();

	int get_number();
	void set_number(int number);
	void change_number();

	int get_age();
	void set_age(int age);
	void change_age();

	int get_height();
	void set_height(int height);
	void change_height();

	int get_weight();
	void set_weight(int weight);
	void change_weight();

	friend ostream& operator<<(ostream& os, Player& obj);            //перегрузки операторов
	friend istream& operator>>(istream& is, Player& obj);
	friend ofstream& operator<<(ofstream& ofs, Player& obj);
	friend ifstream& operator>>(ifstream& ifs, Player& obj);

	static bool cmpB_fio(Player left, Player right);
	static bool cmpB_number(Player left, Player right);
	static bool cmpB_age(Player left, Player right);
	static bool cmpB_height(Player left, Player right);
	static bool cmpB_weight(Player left, Player right);

	static bool cmpS_fio(Player left, Player right);
	static bool cmpS_number(Player left, Player right);
	static bool cmpS_age(Player left, Player right);
	static bool cmpS_height(Player left, Player right);
	static bool cmpS_weight(Player left, Player right);
};


int inputNumber(int left_range, int right_range);
int inputNumber(istream& is, int left_range, int right_range);


