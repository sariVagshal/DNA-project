#ifndef __NUCLEOTID_H__
#define __NUCLEOTID_H__

class Nucleotid
{
public:
    Nucleotid();
    Nucleotid(char c);
    Nucleotid(Nucleotid& other);
    ~Nucleotid(){}
    inline operator char() const {return m_c;}
    void operator= (char c){m_c = c;}
    char get_m_c() const;
    Nucleotid& paired();
    
    static void checkNotOK(const char);
private:
    char m_c;
    
};

inline char Nucleotid::get_m_c() const
{
	return m_c;
}

#endif //__NUCLEOTID_H__
