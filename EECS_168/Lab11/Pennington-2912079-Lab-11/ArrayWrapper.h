#ifndef ARRAYWRAPPER_H
#define ARRAYWRAPPER_H
#include <string>

class ArrayWrapper
{
	private:
		double* m_arr;
		int m_size;

	public:
		ArrayWrapper(int size); //throw(std::runtime_error); 
		ArrayWrapper(const ArrayWrapper& original);
		ArrayWrapper& operator= (const ArrayWrapper& original);
		~ArrayWrapper();
		int getSize() const;
		void setEntry(int index, double value); //throw(std::runtime_error);
		double getEntry(int index); //throw(std::runtime_error);

};
#endif
	
