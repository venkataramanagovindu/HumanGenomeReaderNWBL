#pragma once
#include <string>
using namespace std;

class Queries_NW
{
	private:
		char* genomeArray;
		int fragmentLength = 16;
	public:
		char** genomeQueries;
		void readFragments(string fragmentFilePath);
		void readHumanGenomes(string genomeFilePath);
};

