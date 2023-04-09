// HumanGenomeReaderNWBL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queries_NW.h"

int main()
{
    std::cout << "Hello World!\n";

    Queries_NW* NW = new Queries_NW();

    //NW->readHumanGenomes("human_genome.txt");
    /*NW->readHumanGenomes("human.txt");*/
    NW->readHumanGenomes("human_medium.txt");

    //NW->readFragments("human_reads_trimmed_small.fa");
    NW->readFragments("human_reads_trimmed_medium.fa");

}
