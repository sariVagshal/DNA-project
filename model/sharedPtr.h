#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include <stdexcept>

template<typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* = NULL);
    SharedPtr(const SharedPtr &);
    ~SharedPtr();
    
    
    template<class U>
    friend class SharedPtr;
    
    template<class U>
    SharedPtr(const SharedPtr<U>& ptr);


    T* operator->() const;
    T& operator*()  const;


	SharedPtr& operator= (const SharedPtr& ptr);
	SharedPtr& operator= (T * ptr);
	
	
	void reset();
	
	
	bool operator!=(const SharedPtr&) const;
	bool operator==(const SharedPtr&) const;


	operator bool() const;
	
	
    T* get() const;	
	size_t getCounter() const;
private:
	T * m_ptr;
	size_t * refCount;
};


template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)try :m_ptr(ptr), refCount(new size_t(1))
{}
catch(std::bad_alloc& e)
{
	delete ptr;		
	throw;
}

template<typename T>    
SharedPtr<T>::SharedPtr(const SharedPtr & sp):m_ptr(sp.m_ptr), refCount(sp.refCount)
{
	++(*refCount);
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
	reset();
}

template<typename T>
template<class U>
SharedPtr<T>::SharedPtr(const SharedPtr<U>& ptr):m_ptr(ptr.m_ptr), refCount(ptr.refCount)
{
	++(*refCount);
}

template<typename T>
T* SharedPtr<T>::operator->() const
{
	if (!m_ptr)
		throw std::invalid_argument("its a NULL pointer");
	return m_ptr;
}

template<typename T>
T& SharedPtr<T>::operator*()  const
{
	if (!m_ptr)
		throw std::invalid_argument("its a NULL pointer");
	return *m_ptr;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr)
{
	reset();
		
	m_ptr = ptr.m_ptr;
	refCount = ptr.refCount;
	++(*refCount);
	
	return *this;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(T * ptr)
{
	reset();
	
	m_ptr = ptr.m_ptr;
	refCount = new size_t(1);
	
	return *this;
}

template<typename T>
void SharedPtr<T>::reset()
{
	--(*refCount);
	if(*refCount == 0)
	{
		delete m_ptr;
		delete refCount;
	}
}
	
template<typename T>
inline bool SharedPtr<T>::operator!=(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}
	
template<typename T>
inline bool SharedPtr<T>::operator==(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}

template<typename T>
inline SharedPtr<T>::operator bool() const
{
	return m_ptr;
}

template<typename T>	
inline T* SharedPtr<T>::get() const
{
	return m_ptr;
}	
	
template<typename T>	
inline size_t SharedPtr<T>::getCounter() const
{
	return *refCount;
}
	
#endif //__SHAREDPTR_H__
