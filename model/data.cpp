#include "data.h"
#include <string>
#include <cstring> // strcpy
#include <sstream> //convert size_t to string
#include "readFile.h"
#include "writeFile.h"
#include "../controller/DnaSequence.h"


class DnaSequence;

size_t Data::serialId = 1;
size_t Data::serialName = 1;


string Data::insertNewDna(char * str, string name)
{
	if (name == "")
	{
		name = "seq" + toStrNum(serialName);
		++serialName;
	}
	
	SharedPtr<MetaData> sp(new MetaData(serialId, name, SharedPtr<IDna>(new DnaSequence(str))));
	
	m_mapById[serialId] = sp;
	m_mapByName[name] = sp;
	
	return "[" + toStrNum(serialId++) + "] " + name + ": " + str + "\n";
}

string Data::getById(size_t id)
{ 
	SharedPtr<MetaData> temp = getDataById(id);
	if (!temp)
		return "Not found";
	
	return temp->m_seq->get_as_seq();
}

string Data::getByName(string name)//!!!!!!!!!!!!!!!!!!!!!
{
	SharedPtr<MetaData> search = m_mapByName[name];
	
	if (search)// != NULL)
		return search->m_seq->get_as_seq();
	
	return "Not found";
}

string Data::showData(size_t count = 99)
{	
	string str = "";

	std::map<size_t, SharedPtr<MetaData> >::iterator itId = m_mapById.begin();
	
	for (size_t i = 0; i < count && itId != m_mapById.end(); itId++, ++i)
		str += "[" + toStrNum(itId->second->m_id) + "] " + itId->second->m_name + ": " + itId->second->m_seq->get_as_seq() + "\n";
	
	return str;
}

string Data::loadData(const char * filePath, string name)
{
	string str = "";
	try
	{
		ReadFile rf(filePath);
		
		string temp = rf.read().get_as_seq();
		char * help = new char[temp.size()+1];
		std::strcpy(help, temp.c_str());

		str = insertNewDna(help, name);

		delete[] help;
	} 
	catch(char const * err)
	{
		str = "" + std::string(err);
	}
	return str;
}

void Data::saveDataById(size_t seqId, string fileName)
{
	DnaSequence ds(getById(seqId));
	
	if (fileName == "")
		fileName = getNameById(seqId);
		
	if (fileName.find(".rawdna") == std::string::npos)
		fileName += ".rawdna";
	
	WriteFile wf(fileName.c_str());

	wf.write(ds);
}

void Data::saveDataByName(string seqName, string fileName)
{
	DnaSequence ds(getByName(seqName));
	
	if (fileName == "")
		fileName = seqName;
	
	if (fileName.find(".rawdna") == std::string::npos)
		fileName += ".rawdna";
			
	WriteFile wf(fileName.c_str());
	wf.write(ds);
}

string Data::LenOf(size_t id)
{
	return toStrNum(getById(id).length());
}

string Data::LenOf(string name)
{
	return toStrNum(getByName(name).length());
}
	
SharedPtr<MetaData> Data::getDataById(size_t id)
{
	std::map<size_t, SharedPtr<MetaData> >::iterator search = m_mapById.find(id);
	
	if (search != m_mapById.end())
		return search->second;
	
	return m_mapById.find(1)->second;
	//return SharedPtr<new DnaSequence>;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
SharedPtr<MetaData> Data::getDataByName(string name) const
{
	return m_mapByName.find("seq1")->second;
	//return SharedPtr<new DnaSequence>;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
	
	
	
	
	



string Data::toStrNum(size_t num)
{
	//convert serialId to string
	string strId;
	std::ostringstream convert0;
	convert0 << num;
	strId = convert0.str();
	return strId;
}

string Data::getNameById(size_t id)
{
	SharedPtr<MetaData> sp;
	
	std::map<size_t, SharedPtr<MetaData> >::iterator itId = m_mapById.begin();
	
	for (; itId != m_mapById.end(); itId++)
		if (itId->first == id)
			return itId->second->m_name;
		
	return "";
}



