#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

#include <cstdint>

#if _DEBUG
#include <iostream>
#endif // DEBUG

template <class T>
class SmartPtr
{
private:
	int32_t  _refCounter = 0;
	T*       _data       = nullptr;

public:
	template <class T>
	SmartPtr()
	{
		_refCounter++;
		_data = new T;
		
		#if _DEBUG
		std::cout << "Ctor was called; _refCounter : " << _refCounter  << std::endl;
		#endif
	}

	template <class T>
	SmartPtr(SmartPtr<T>& const smartPtr)
	{
		_refCounter++;
		_data = smartPtr._data;

		#if _DEBUG
		std::cout << "Copy ctor was called; _refCounter : " << _refCounter << std::endl;
		#endif
	}

	template <class T>
	SmartPtr(T* const value)
	{
		_refCounter++;
		_data = value;

		#if _DEBUG
		std::cout << "Ctor with parameters was called; _refCounter : " << _refCounter << std::endl;
		#endif
	}
		
	~SmartPtr()
	{
		if (_refCounter > 0)
		{
			_refCounter--;

			#if _DEBUG
			std::cout << "Dtor was called; _refCounter : " << _refCounter << std::endl;
			#endif
		}
		
		if (_refCounter <= 0) 
		{
			delete _data;

			#if _DEBUG
			std::cout << "Dtor was called; pointer was deleted; _refCounter : " << _refCounter << std::endl;
			#endif
		}			
	}
		
	SmartPtr operator()(T* value) 
	{
		_refCounter++;
		_data = value;

		#if _DEBUG
		std::cout << "Operator () was called; _refCounter : " << _refCounter << std::endl;
		#endif
	}
		
	SmartPtr operator=(SmartPtr& value) 
	{
		_refCounter++;
		_data = value._data;

		#if _DEBUG
		std::cout << "Operator = was called; _refCounter : " << _refCounter << std::endl;
		#endif
	}
		
	T* operator->()
	{
		return _data;
		#if _DEBUG
		std::cout << "Operator -> was called; _refCounter : " << _refCounter << std::endl;
		#endif
	}	
};
#endif // !SMART_PTR_HPP
