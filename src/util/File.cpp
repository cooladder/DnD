#include "File.h"

File::File(const char* filepath){
    in.open(filepath);
    if(in.fail()){
        std::cout << "Failed to open file " << filepath;
    }
}

std::string File::getContext(){
    std::string line;
    std::string context;
    while(std::getline(in, line)){
        context += line + '\n';
    }
    return context;
}