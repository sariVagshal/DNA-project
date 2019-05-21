//
// Created by RENT on 31/10/2018.
//

#ifndef DNA_2_1_WRITEFILE_H
#define DNA_2_1_WRITEFILE_H
#include <fstream>
#include <iostream>
#include <string>
#include "../controller/DnaSequence.h"
using std::string;
using std::ofstream;

//class DnaSequence;
class WriteFile
{
private:
    string m_file_name;
public:
    WriteFile(const char * path);
    WriteFile(WriteFile const & other);
    ~WriteFile();
    void write(const DnaSequence);
};
WriteFile::WriteFile(const char * path):m_file_name(path){}
WriteFile::WriteFile(WriteFile const & other):m_file_name(other.m_file_name){}
WriteFile::~WriteFile(){}
void WriteFile:: write(const DnaSequence dna)
{
    ofstream myfile;
    myfile.open(m_file_name.c_str());
    if (!myfile.is_open())
        throw ("unable to open file");
    myfile << dna;
    myfile.close();
}


#endif //DNA_2_1_WRITEFILE_H
