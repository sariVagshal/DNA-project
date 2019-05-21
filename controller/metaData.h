#ifndef __METADATA_H__
#define __METADATA_H__

#include "iDna.h"
#include "../model/sharedPtr.h"

class MetaData
{
public:
	MetaData(size_t, std::string, SharedPtr<IDna>);
	
	size_t m_id;
	std::string m_name;
	SharedPtr<IDna> m_seq;
};

inline MetaData::MetaData(size_t id, std::string name, SharedPtr<IDna> seq): m_id(id), m_name(name), m_seq(seq)
{}

#endif //__METADATA_H__
