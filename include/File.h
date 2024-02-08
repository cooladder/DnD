#include <iostream>
#include <fstream>
#include <string>
#ifndef MYFILE
#define MYFILE
class File
{
private:
    std::ifstream in;
public:
    File(const char* filepath);
    std::string getContext();
};
#endif