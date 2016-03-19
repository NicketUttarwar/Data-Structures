#include <iostream>
#include <string>

using namespace std;

//Global Variables
int *A = new int[16];
string *B = new string[16];
int *C = new int[16];
int newsize = 16;

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(string);
	DynamicArray(int);
	int strcheck(string c);
	int getsize(int x);
	void resize(int y);
	int main();




private:

};

DynamicArray::DynamicArray()
{

}

DynamicArray::~DynamicArray()
{
	delete[] A;//deallocating memory
	delete[] B;
	delete[] C;
}

DynamicArray::DynamicArray(string s)
{
	int temp = strcheck(s);
	A[temp] = temp;
}

DynamicArray::DynamicArray(int w)
{
	if (w > newsize)
	{
		if (w>65536)
		{
			cout << "Exceed Max Array" << endl;
		}
		else
		{
			resize(w);
			A[w] = w;
		}
		}
	else if (w>=0 && w<=newsize)
	{
		A[w] = 100 + w;							//Adding 100 to the number to differentiate numbers
	}
	else if (w<0)
	{
		cout << "Invalid Index" << endl;
	}

}

	

int DynamicArray::strcheck(string c)
	{
		return atoi(c.c_str());
	}

int DynamicArray::getsize(int x)
	{
		if (x>0 && x <= 16)
		{
			return 16;
		}
		else if (x>16 && x <= 32)
		{
			return 32;
		}
		else if (x > 32 && x <= 64)
		{
			return 64;
		}
		else if (x > 64 && x <= 128)
		{
			return 128;
		}
		else if (x > 128 && x <= 256)
		{
			return 256;
		}
		else if (x > 256 && x <= 512)
		{
			return 512;
		}
		else if (x > 512 && x <= 1024)
		{
			return 1024;
		}
		else if (x > 1024 && x <= 2048)
		{
			return 2048;
		}
		else if (x > 2048 && x <= 4096)
		{
			return 4096;
		}
		else if (x > 4096 && x <= 8192)
		{
			return 8192;
		}
		else if (x > 8192 && x <= 16384)
		{
			return 16384;
		}
		else if (x > 16384 && x <= 32768)
		{
			return 32768;
		}
		else if (x > 32768 && x <= 65536)
		{
			return 65536;
		}
		else
		{
			cout << "ERROR";
		}


}

void DynamicArray::resize(int y)
	{
		int *arr1 = new int[y];
		
		for (int i = 0; i < y; i++)
		{
			arr1[i] = A[i];
		}
		A = arr1;

	}

	int main()
	{

		A[0] = 666;//accessing the dynamic array element directly
		A[1] = 777;//accessing the dynamic array element directly

		DynamicArray DynamicArray(13);	//Replace the number inside the braces with any number
		cout << A[13] << endl;

		


		cin.get();
		return 0;

	}		
