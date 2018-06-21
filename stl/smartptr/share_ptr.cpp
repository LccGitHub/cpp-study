#include<stdio.h>
#include<stdlib.h>


template<class T>
class Share_ptr
{
public:
	Share_ptr(T *p)
		: mPtr(p)
		, mCount(NULL)
	{
		mCount = new int(1);

		printf("Shart_ptr Construct is called, mCount = %d \n", *mCount);
	}
	~Share_ptr()
	{
		if (--(*mCount) == 0) {
			delete mPtr;
			mPtr = NULL;
			printf("~Share_ptr Desconstruct is call mCount = %d !!! \n", *mCount);
			mCount = NULL;
		}
		else {
			printf("~Share_ptr Desconstruct is call mCount = %d \n", *mCount);
		}
	}
	Share_ptr(const Share_ptr<T> & other)
		: mPtr(other.mPtr)
		, mCount(other.mCount)
	{
		++(*mCount);
		printf("Copy Construct is called, mCount = %d \n", *mCount);
	}
	Share_ptr<T>& operator=(const Share_ptr<T> &rhs)
	{
		++(*rhs.mCount);

		if (--(*mCount) == 0) {
			printf("Left sid object is delete! mCount = %d \n", *mCount);
			delete mPtr;
			delete mCount;
			mCount = NULL;
		}

		mPtr = rhs.mPtr;
		mCount = rhs.mCount;

		printf("Assignment operator overloaded is called!, mCount = %d\n", *mCount);
		return *this;
	}

private:
	T *mPtr;
	int* mCount;

};


int main()
{
	printf("create Share_ptr p1 \n");
	Share_ptr<int> p1(new int(0));
	printf("operator   p1 = p1 \n");
	p1 = p1;

	printf("copy construct  p2(p1) \n");
	Share_ptr<int> p2(p1);


	printf("copy construct  p4(p1) \n");
	Share_ptr<int> p4(p1);

	printf("create Share_ptr p3 \n");
	Share_ptr<int> p3(new int(1));
	printf("operator   p3 = p1 \n");
	p3 = p1;


	return 0;
}

