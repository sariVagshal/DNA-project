#ifndef __DATA_H__
#define __DATA_H__

#include "../controller/metaData.h"
#include "sharedPtr.h"
#include <map>
using std::string;

class Data
{
public:
	string insertNewDna(char *, string name = "");
	string showData(size_t count);
	string loadData(const char * filePath, string name = "");
	void saveDataById(size_t seqId, string fileName = "");
	void saveDataByName(string seqName, string fileName = "");
	string LenOf(size_t id);
	string LenOf(string name);
	string getById(size_t id);
	string getByName(string name);
	SharedPtr<MetaData> getDataById(size_t id);
	SharedPtr<MetaData> getDataByName(string name) const;
private:
	static size_t serialId;
	static size_t serialName;
	
	string toStrNum(size_t num);
	string getNameById(size_t id);
	
	std::map<size_t, SharedPtr<MetaData> > m_mapById;
	std::map<string, SharedPtr<MetaData> > m_mapByName;
};

#endif //__DATA_H__
