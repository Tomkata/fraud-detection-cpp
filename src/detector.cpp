#include <iostream>
#include <cmath>

#include "detector.h"
const double LARGE_TRANSACTION_THRESHOLD = 10000;
const short WITHDRAWS_THRESHOLD = 5;

bool Detector::hasFrequentTransactions(const Transaction* arr, int size) {

	if (size == 0 || size == 1) return false;

	int j = 0;
	int i = 0;
	while (j < size) {

		if ((arr[j].createdAt.tm_hour * 60 + arr[j].createdAt.tm_min) -
			(arr[i].createdAt.tm_hour * 60 + arr[i].createdAt.tm_min) < 5) {
			j++;
		}
		else {
			while ((arr[j].createdAt.tm_hour * 60 + arr[j].createdAt.tm_min) -
				(arr[i].createdAt.tm_hour * 60 + arr[i].createdAt.tm_min) >= 5)
			{
				i++;
			}
		}


		if (j - i + 1 >= 10) return true;
	}

	return false;
}

bool Detector::hasLargeTransaction(const Transaction* arr, int size) {

	if (size <= 0) return false;


	for (int i = 0; i < size; i++) {
		if (hasLargeTransaction(arr[i])) {
			return true;
		}
	}

	return false;
}

bool Detector::hasConsecutiveWithdraws(const Transaction* arr, int size) {
	
	if (size < 5) return false;

	int count = 0;

	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i].type, "withdraw") == 0) {
			count++;
		}
		else count = 0;
		if (count >= WITHDRAWS_THRESHOLD) return true;
	}

	return false;
}

bool Detector::hasLargeTransaction(const Transaction& t) const {
	return t.amount > LARGE_TRANSACTION_THRESHOLD;
}

bool Detector::detectFraud(const Transaction* arr, int size) {
	return hasFrequentTransactions(arr, size) ||
		hasConsecutiveWithdraws(arr, size) ||
		hasLargeTransaction(arr,size);
}