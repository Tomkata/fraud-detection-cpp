#include "parser.h"
#include <string>
#include <iostream>
#include <cctype>
#include <time.h>
using namespace std;

Transaction Parser::parseLine(char* line) {
	Transaction t;
	t.id = 0;
	char nullTerminator = '\0';
	char delimiter = ',';
	char temp[20];
	int j = 0;
	int field = 0;
	for (int i = 0; line[i] != nullTerminator; i++) {
		if (line[i] == delimiter) {
			temp[j] = nullTerminator;
			if (field == 0) {
				t.id = atoi(temp);
			}
			else if (field == 1) {
				t.amount = atof(temp);
			}
			j = 0;
			field++;	
		}
		else
		{
			temp[j] = line[i];
			j++;
		}
	}
	temp[j] = nullTerminator;
	for (int i = 0; temp[i] != nullTerminator; i++){
		t.type[i] = temp[i];
	}
	t.type[j] = nullTerminator;


	time_t now = time(NULL);
	struct tm time_info;
	localtime_s(&time_info,&now);
	t.createdAt = time_info;
	return t;
}
