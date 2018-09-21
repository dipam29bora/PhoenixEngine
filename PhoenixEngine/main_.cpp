#include <iostream>
#define DEBUG 1

#if DEBUG
	#define LOG(x) std::cout<<"============"<<std::endl<<x<<std::endl
#else
	#define LOG(x)
#endif

int Add(const int a, const int b)
{
	//DON'T DO THIS HACK
	//int& best = const_cast<int&>(a);
	//best++;
	return a + b; 
}

class ClassExample
{
public:
	int X, Y;
public:
	ClassExample()
	{

	}

	ClassExample(int x, int y)
	{
		this->X = x;
		this->Y = y;
	}

	int GetX() const { return X; }
	int GetY() const { return Y; }


};

//the way string works, stores the character array on heap than counts the last 0\ element
int count(int* array)
{
	int result = 0;
	for (; array[result] != -1; result++)
		;
	return result;
}

int main_()
{
	int a = 10;
	int b = 9;
	int n = Add(a , b);

	LOG(n);
	LOG(a);

	//storing at the stack memory and will be deleted at the end of the main return automatically
	ClassExample example_stack(2, 4);

	//The 'new' will store the object in heap memory
	//and i it won't delete the object automatically 
	//we use delete onj_name to delete manually
	ClassExample* example_heap = new ClassExample(5, 6);

	//Array storing on Stack memory 
	//and it will delete automatically
	int stack_array[4];

	//Array storing on heap memory 
	// we have to use delete[] to delete manually
	//same as char* string = "hello"
	int* heap_array = new int[4]; //size is always variable size-here 4byte.
	//we can't find the size of the array. To do that call the function count defined above
	heap_array[4] = -1;
	LOG(count(heap_array));
	//so there is no ArrayIndexOutOfBound exception in c++


	delete[] heap_array;
	delete example_heap;
	system("PAUSE");
	//std::cin.get();
} 