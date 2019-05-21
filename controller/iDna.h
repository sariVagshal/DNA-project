#ifndef __IDNA_H__
#define __IDNA_H__
#include <string>
#include "nucleotid.h"

struct IDna
{
	virtual ~IDna();
	virtual size_t getLen() const = 0;
	virtual Nucleotid& operator[](const size_t index) const = 0;
	//virtual std::string get_as_seq() const = 0;
};

inline IDna::~IDna()
{}


/*
virtual ~IDna(){};
   virtual Nucleotide& operator[](const size_t index)const=0;
   //virtual  std::string get()const=0;
   virtual size_t getLength()const=0;*/
#endif //__IDNA_H__
