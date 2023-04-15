#include <iostream>
#include <fstream>
#include "config.hpp"
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        std::cerr<<"[ERROR] ccuw.exe : Invalid argument.\n"<<std::endl;
        return 1;
    }
    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open(argv[1],std::ios::in);
    if(!ifs.is_open())
    {
        std::cerr<<"[ERROR] ccuw.exe : Cannot open input file: \""<<argv[1]<<"\""<<std::endl;
    }
    ofs.open(argv[2],std::ios::out);
    if(!ofs.is_open())
    {
        std::cerr<<"[ERROR] ccuw.exe : Cannot open output file: \""<<argv[2]<<"\""<<std::endl;
        return 1;
    }
    ifs.close();
    ofs.close();
    return 0;
}