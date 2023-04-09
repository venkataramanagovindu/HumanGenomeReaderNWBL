#include "Queries_NW.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

Queries_NW::Queries_NW() {
    genomeArray = NULL;
    genomeQueries = NULL;
    cols = 16;
}

void Queries_NW::readFragments(string fragmentFilePath) {
    queriesLineCount = 0;
    string line;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    /* Creating input filestream */
    ifstream file(fragmentFilePath);
    while (getline(file, line))
        queriesLineCount++;

    file.close();

    /* Creating input filestream */
    ifstream fin(fragmentFilePath);

    this->rows = queriesLineCount / 2;

    this->genomeQueries = new char* [this->rows];
    char c;

    long long int genomeQueryIdx = 0;
    for (int i = 0; i < queriesLineCount; i++)
    {
        getline(fin, line);
        if (i % 2 == 0)
            continue;


        this->genomeQueries[genomeQueryIdx] = new char[this->cols];
        int j = 0;
        for (; j < this->cols; j++) {
            this->genomeQueries[genomeQueryIdx][j] = line[j];
        }
        this->genomeQueries[genomeQueryIdx][j] = '\0';
        genomeQueryIdx++;
    }

    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the queries file : " << fixed
        << time_taken;
    cout << " sec " << endl;

    cout << "Numbers of lines in the file : " << queriesLineCount << endl;
}

void Queries_NW::readHumanGenomes(string genomeFilePath) {
    // read file char by char
    char ch;
    fstream fin(genomeFilePath, fstream::in);
    char* headerCharArray;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    // Calculating the size of the file
    fin.seekg(0, std::ios::end);
    long long size = fin.tellg();
    fin.seekg(0, std::ios::beg);

    // Dynamically allocating memory for the array
    genomeArray = new char[size];
    bool isHeader = false;
    long long int charArridx = 0;
    long long int headerCharidx = 0;
    //long long int genomeLength = 0;

    while (fin >> noskipws >> ch) {

        // 62 = >
        if (ch == 62) {
            isHeader = true;

            /*totalGenomeLength += genomeLength;
            genomeLength = 0;*/
        }

        if (isHeader) {
            if (ch == 10) {
                isHeader = false;
            }
        }
        else if (ch != 10)
        {
            genomeArray[charArridx++] = ch;
            totalGenomeLength++;
        }
    }
    fin.close();

    genomeArray[charArridx] = '\0';

    std::ios_base::sync_with_stdio(false);
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the genome file : " << fixed
        << time_taken;
    cout << " sec " << endl;
}

Queries_NW::~Queries_NW() {

}