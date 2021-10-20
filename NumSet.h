#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <Windows.h>

using namespace std; 

class NumSet
{
	int _hand[5] = { 0 };
	string _playername; 
	
public:
	NumSet();
	void setName(string name) { this->_playername = name; }
	string getName() const { return this->_playername; }
	int maximum(); 
	int minimum();
	int minIndex();
	void insert(int num);
	int freecells() const;
	void replace(int index , int number);
	float average();
	int biggerThan(int num);
	int smallerThan(int num);
	const NumSet& operator++();
	const NumSet& operator--();
	int operator==(const NumSet& n) const;
	const NumSet& operator+=(int num);
	const NumSet& operator+=(const NumSet& n);
	const NumSet& operator=(int* arr);
	const NumSet& operator=(const NumSet& n);
	const NumSet& operator*=(const NumSet& n);
	void Del(int index);
	void sortHand();
	int getcart1(int b, int c2);
	int getcart2();
	int getindex(int c1);
	void removeone(int c2);

	friend ostream& operator<<(ostream& out, const NumSet& n);
};

