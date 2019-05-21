#ifndef DNA_2_READFILE_H
#define DNA_2_READFILE_H

#include <fstream>
#include <iostream>
#include <string>
#include "../controller/DnaSequence.h"
using std::string;
using std::ifstream;

class ReadFile
{
private:
    string m_file_name;
public:
    ReadFile(const char * path);
    ReadFile(ReadFile const & other);
    ~ReadFile();
    DnaSequence read();
};
ReadFile::ReadFile(const char * path)
{
    ifstream myfile(path);
    if (!myfile.is_open())
        throw ("unable to open file");
    while(!myfile.eof())
    {
        myfile >> m_file_name;
    }
    myfile.close();
}
ReadFile::ReadFile(ReadFile const & other):m_file_name(other.m_file_name){}
ReadFile::~ReadFile(){}
DnaSequence ReadFile:: read()
{
    DnaSequence DNA(m_file_name);
    return DNA;
}

#endif //DNA_2_READFILE_H
