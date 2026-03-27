#pragma once
#include <ctime>
struct Transaction{
	int id;
	double amount;
	char type[16];
	struct tm createdAt;
};