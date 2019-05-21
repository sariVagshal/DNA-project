#ifndef __PAIR_H__
#define __PAIR_H__
#include <string>
#include "iDna.h"
#include "factory.h"
#include "../model/data.h"
#include "nucleotid.h"

class Pair: public IDna
{
public:
	Pair(SharedPtr<IDna> dna);
	~Pair();
	
	size_t getLen() const;
	Nucleotid& operator[](const size_t index) const;
	//std::string get_as_seq();// const;
private:
	SharedPtr<IDna> m_dna;
};


inline Pair::Pair(SharedPtr<IDna> dna):m_dna(dna)
{}

inline Pair::~Pair()
{}

inline size_t Pair::getLen() const 
{
	return m_dna->getLen();
}

inline Nucleotid& Pair::operator[](const size_t index) const
{
	Nucleotid& n = m_dna->operator[](index).paired();
	return n;
}
/*
inline std::string Pair::get_as_seq()// const
{
	
	return m_dna->get_as_seq();////////////////////pair of it!!!!!!
}*/

#endif //__PAIR_H__
