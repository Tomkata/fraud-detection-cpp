#pragma once
#include "transaction.h"

class Detector {
public:
	bool detectFraud(const Transaction* arr, int size);

	private:
	bool hasLargeTransaction(const Transaction* arr,int size);
	bool hasFrequentTransactions(const Transaction* arr,int size);
	bool hasConsecutiveWithdraws(const Transaction* arr, int size);
	bool hasLargeTransaction(const Transaction& t) const;
};