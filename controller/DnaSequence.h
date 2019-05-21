#ifndef __DNASEQUENCE_H__
#define __DNASEQUENCE_H__

#include <string>
#include <iostream>
#include "iDna.h"
#include "nucleotid.h"

using std::string;
int get_seq_len(const char * c);

class DnaSequence: public IDna
{
public:
    explicit DnaSequence(const char *);
    explicit DnaSequence(string);
    DnaSequence(const DnaSequence &);
    ~DnaSequence();
    DnaSequence & operator=(const DnaSequence &);
    DnaSequence & operator=(const string &);
    DnaSequence & operator=(const char * &);
    friend std::ostream &operator<<( std::ostream &, const DnaSequence &);
    bool operator==(const DnaSequence &);
    bool operator!=(const DnaSequence &);
    char operator[] (int i);
    string get_as_seq() const;
    void slicing(DnaSequence & dna, unsigned int from, unsigned int to);
    void get_pairing_dna(DnaSequence & dna);
    
    
    Nucleotid * m_seq;
    unsigned int m_len;
};


inline char DnaSequence::operator[] (int i)
{
    return m_seq[i].get_m_c();
}

inline bool DnaSequence::operator==(const DnaSequence & other)
{
    return get_as_seq() == other.get_as_seq();
}
inline bool DnaSequence::operator!=(const DnaSequence & other)
{
    return !(*this==other);
}

#endif //__DNASEQUENCE_H__
