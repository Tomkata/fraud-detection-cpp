// fraud_detection_v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "parser.h"
#include "transaction.h"
#include "detector.h"

using namespace std;

int main()
{
	int size;
	cin >> size;
	Transaction* transactions = new Transaction[size];

	Parser p;
	for (int i = 0; i < size; i++) {
		transactions[i].amount = 1000;

		if (i < 5)
			strcpy_s(transactions[i].type,16, "withdraw");
		else
			strcpy_s(transactions[i].type,16, "deposit");
	}
		
	Detector d;
	bool result = d.detectFraud(transactions, size);
	delete[] transactions;
	cout << result << endl;

	
}

