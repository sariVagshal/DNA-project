#include "DnaSequence.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
using std::string;
using std::cout;
using std::endl;
int get_seq_len(const char * c)
{
    int j = 0;
    while (c[j++] != '\0');
    return j - 1;
}


DnaSequence::DnaSequence(const char * c)
{
    //try 
    //{
        m_len = get_seq_len(c);
        m_seq = new Nucleotid[m_len]();
        for (unsigned int i = 0; i < m_len; ++i)
        {
        	Nucleotid::checkNotOK(c[i]);
            m_seq[i] = (c[i]);
        }
    /*}
    catch (const char * e)
    {
    	cout << e << endl;
    	delete [] m_seq;
    }*/
}
DnaSequence::DnaSequence(string str)
{
    //try
    //{
        const char *c = str.c_str();
        m_len = get_seq_len(c);
        m_seq = new Nucleotid[m_len]();
        for (unsigned int i = 0; i < m_len; ++i)
            m_seq[i] = (c[i]);
    /*}
	catch (const char * e)
	{
		cout << e << endl;
		delete [] m_seq;
	}*/
}
DnaSequence::DnaSequence(const DnaSequence & other)
{
    m_len = other.m_len;
    m_seq = new Nucleotid[m_len]();
    for(unsigned int i = 0; i < m_len ;++i)
        m_seq[i] = (other.m_seq[i]);

}
DnaSequence::~DnaSequence()
{
    delete[] m_seq;
}
DnaSequence & DnaSequence::operator=(const DnaSequence & other)
{
    if(this == &other)
        return *this;
    delete [] m_seq;
    m_len = other.m_len;
    m_seq = new Nucleotid[m_len]();
    for(unsigned int i = 0; i < m_len ;++i)
        m_seq[i] = (other.m_seq[i]);

    return *this;
}
DnaSequence & DnaSequence::operator=(const string & str)
{
    //try
    //{
		const char * c = str.c_str();
		delete [] m_seq;
		m_len = get_seq_len(c);
		m_seq = new Nucleotid[m_len]();
		for(unsigned int i = 0; i < m_len ;++i)
			{
				Nucleotid::checkNotOK(c[i]);
				m_seq[i] = (c[i]);
			}
		return *this;
    /*}
    catch (const char * e)
    {
        cout << e << endl;
        delete [] m_seq;
    }
    return *this;*/
}
DnaSequence & DnaSequence::operator=(const char * &c)
{
    //try
    //{
        delete[] m_seq;
        m_len = get_seq_len(c);
        m_seq = new Nucleotid[m_len]();
        for (unsigned int i = 0; i < m_len; ++i)
        {
        	Nucleotid::checkNotOK(c[i]);
            m_seq[i] = (c[i]);
        }

        return *this;
    /*}
    catch (const char * e)
    {
        cout << e << endl;
        delete [] m_seq;
    }
    return *this;*/
}
std::ostream &operator<<( std::ostream & out, const DnaSequence & other)
{
    out << other.get_as_seq() << std::endl;
    return out;
}

string DnaSequence::get_as_seq() const
{
    string s = "";
    for(unsigned int i = 0; i< m_len; ++i)
        s += m_seq[i].get_m_c();
    return s;
}
void DnaSequence::slicing(DnaSequence & dna, unsigned int from, unsigned int to)
{
    if(to < from)
    {
        int temp = to;
        to = from;
        from = temp;
    }
    if(to >= m_len || from >= m_len)
        throw "not a valid index\n";
    string s = "";
    for(; from < to ;++from)
        s += m_seq[from];
    dna = s;
}
void DnaSequence::get_pairing_dna(DnaSequence & dna)
{
    dna = *this;
    int n = get_seq_len(get_as_seq().c_str()) - 1;
    for(int i = 0; i <= n; ++i)
        dna.m_seq[i] = m_seq[n - i].paired();
}


