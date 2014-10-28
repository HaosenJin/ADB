#include "stdafx.h";
template<class T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		ref = ptr;
		ref_count = (unsigned int*)malloc(sizeof(unsigned int));
		*ref_count = 1;
	}

	SmartPointer(SmartPointer<T>& sptr)
	{
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		(*ref_count)++;
	}

	SmartPointer<T>& operator=(SmartPointer<T>& sptr)
	{
		if (this == &sptr)
			return *this;
		if (ref_count != NULL&&*ref_count > 0)
			remove();
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return *this;
	}

	~SmartPointer()
	{
		remove();
	}

	T getValue()
	{
		return *ref;
	}

private:
protected:
	T* ref;
	unsigned int* ref_count;
	void remove()
	{
		(*ref_count)--;
		if (*ref_count == 0)
		{
			delete ref;
			free(ref_count);
			ref = NULL;
			ref_count = NULL;
		}
	}

};

