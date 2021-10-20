#include "NumSet.h"


NumSet::NumSet()
{
	for (int i = 0; i < 5; i++)
	{
		this->_hand[i] = rand() % 10 + 1;
	}

	this->_playername = "unknown";
	this->sortHand();
}

void NumSet::sortHand() {
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5 - i - 1; j++)
			if (this->_hand[j] > this->_hand[j + 1]) {
				this->_hand[j] += this->_hand[j + 1];
				this->_hand[j + 1] = this->_hand[j] - this->_hand[j + 1];
				this->_hand[j] = this->_hand[j] - this->_hand[j + 1];
			}
}

void NumSet::insert(int num) {
	for (int i = 0; i < 5; i++) {
		if (this->_hand[i] == 0) {
			this->_hand[i] = num;
			this->sortHand();
			return;
		}
	}
}

int NumSet::maximum()
{
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] > max) max = this->_hand[i];
	}

	return max;
}

int NumSet::minimum()
{
	int min = this->_hand[0];
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] != 0 && this->_hand[i] < min ) min = this->_hand[i];
	}
	return min;

}

int NumSet::minIndex()
{
	int minIndex = 0;
	int min = this->_hand[0];
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] != 0 && this->_hand[i] < min) {
			min = this->_hand[i];
			minIndex = i;
		}
	}
	return minIndex;

}

int NumSet::freecells() const
{
	int counter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] == 0) counter++; 
	}
	return counter;
}

void NumSet::replace(int index, int number)
{
	this->_hand[index - 1] = number;
	this->sortHand();
}

float NumSet::average()
{
	int sum = 0;
	int number = 0;
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] != 0)
		{
			sum += this->_hand[i];
			number++;
		}
	}
	return float(sum) / float(number);
}

int NumSet::biggerThan(int num)
{
	int counter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] >= num) counter++;
	}
	return counter;
}

int NumSet::smallerThan(int num)
{
	int counter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] <= num) counter++;
	}
	return counter;
}

/*les operateurs*/ 

const NumSet& NumSet::operator++()
{
	for (int i = 0; i < 5; i++)
	{
		this->_hand[i] += 1;
	}
	return *this;

}

const NumSet& NumSet::operator--()
{
	for (int i = 0; i < 5; i++)
	{
		this->_hand[i] -= 1;
	}
	return *this;

}

// this->_p1.insert(4);
// this->_p1 += 4;
const NumSet& NumSet::operator+=(int num) {
	this->insert(num);
	return *this;
}

// this->_p1 += this->_p2;
const NumSet& NumSet::operator+=(const NumSet& n) {
	for (int i = 0; i < 5; i++) {
		this->_hand[i] += n._hand[i];
	}
	return *this;
}

const NumSet& NumSet::operator=(int* arr) {
	for (int i = 0; i < 5; i++) {
		this->insert(arr[i]);
	}
	return *this;
}

const NumSet& NumSet::operator=(const NumSet& n) {
	for (int i = 0; i < 5; i++) {
		this->replace(i + 1, n._hand[i]);
	}
	return *this;
}

int NumSet::operator==(const NumSet& n) const {
	for (int i = 0; i < 5; i++) {
		if (this->_hand[i] != n._hand[i]) return false;
	}
	return true;
}

const NumSet& NumSet::operator*=(const NumSet& n) {
	int numCells = 5 - this->freecells() + 5 - n.freecells() <= 5;
	if (numCells <= 5) {
		for (int i = 0; i < 5; i++) {
			if (n._hand[i] != 0) {
				this->insert(n._hand[i]);
			}
		}
	}
	else {
		int k = numCells - 5;
		for (int i = 0; i < k; i++) {
			this->Del(this->minIndex());
		}
		for (int i = 0; i < 5; i++) {
			if (n._hand[i] != 0) {
				this->insert(n._hand[i]);
			}
		}
	}

	return *this;
}

void NumSet::Del(int index) {
	this->_hand[index] = 0;
	this->sortHand();
}

// NumSet n;
// cout << n;
ostream& operator<<(ostream& out, const NumSet& n) {
	for (int i = 0; i < 5; i++) {
		if (n._hand[i] != 0) {
			out << n._hand[i] << ", ";
		}
	}
	out << endl;

	return out;
}



int NumSet::getcart1(int b, int c2) {
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] < b && this->_hand[i] > c2)
			return this->_hand[i];
	}

	return this->maximum();
}

int NumSet::getcart2() {
	return this->minimum();
}


int NumSet::getindex(int c1) {
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] == c1)
			return i+1;
	}
	return -1;
}

void NumSet::removeone(int c2)
{
	for (int i = 0; i < 5; i++)
	{
		if (this->_hand[i] == c2)
		{
			this->_hand[i] = c2-1;
			return;
		}
	}
}