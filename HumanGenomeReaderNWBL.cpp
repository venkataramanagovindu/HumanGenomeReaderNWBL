// HumanGenomeReaderNWBL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queries_NW.h"

int main()
{
    std::cout << "Hello World!\n";

    Queries_NW* NW = new Queries_NW();

    NW->readHumanGenomes("");
    NW->readFragments("");

}
