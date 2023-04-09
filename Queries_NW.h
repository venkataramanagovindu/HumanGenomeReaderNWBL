#pragma once
#include <string>
using namespace std;

class Queries_NW
{
	private:
		char* genomeArray;
		long long int totalGenomeLength = 0;
		long long int queriesLineCount = 0;
		int cols;
	public:
		long long int rows;
		char** genomeQueries;
		Queries_NW();
		~Queries_NW();
		void readFragments(string fragmentFilePath);
		void readHumanGenomes(string genomeFilePath);
};

