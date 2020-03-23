#ifndef ArrayWrapperDriver_H
#define ArrayWrapperDriver_H
#include "ArrayWrapper.h"

class ArrayWrapperDriver
{
	private:
		int totalRecords;
		ArrayWrapper aw;

	public:
		ArrayWrapperDriver(std::string FileName);
		void run();
		void testCopyConstructor(ArrayWrapper aw) const;
		void testAssignment();
		void setValue(int index, double value);
		void testCopyConstructor();
		void print();
};
#endif

