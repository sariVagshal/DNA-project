#include "nucleotid.h"

Nucleotid::Nucleotid():m_c('A')
{}
Nucleotid::Nucleotid(char c)
{
	checkNotOK(c);
	m_c = c;
}
Nucleotid::Nucleotid(Nucleotid& other):m_c(other.m_c)
{}
void Nucleotid::checkNotOK(const char c)
{
    if(!(c == 'A' || c == 'T' || c == 'G' || c == 'C'))
        throw "not a correct sequence!\n";
}
Nucleotid& Nucleotid::paired()
{
	Nucleotid* n = new Nucleotid;
    switch (m_c){
        case('T'):
            //return Nucleotid('A');
            *n = 'A'; break;
        case('A'):
            //return Nucleotid('T');
            *n = 'T'; break;
        case('C'):
            *n = 'G'; break;//return Nucleotid('G');
        case('G'):
            *n = 'C'; break;//return Nucleotid('C');
    }
    //return Nucleotid();
    return *n;
}

