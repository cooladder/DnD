#pragma once
#include <iostream>
#include <fstream>
#include <string>
class File
{
private:
    std::ifstream in;
public:
    File(const char* filepath);
    std::string getContext();
    std::ifstream& getStream();
};