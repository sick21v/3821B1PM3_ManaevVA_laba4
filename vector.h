#pragma once
#include<iostream>

using namespace std;

template <class T>
class TVector 
{
protected:

	T* data;
	int len = 2;

public:

	T GetData(int i) 
	{
		return data[i];
	}

	int GetLen() 
	{
		return len;
	}

	TVector() 
	{
		data = new T[len];

		for (int i = 0; i < len; i++) 
		{
			data[i] = 0;
		}
	}

	TVector(int _len) 
	{
		len = _len;
		data = new T[len];

		for (int i = 0; i < len; i++)
		{
			data[i] = 0;
		}
	}

	TVector(const initializer_list<T>& list) :TVector(list.size()) 
	{
		int count = 0;

		for (auto& element : list)
		{
			data[count] = element;
			++count;
		}
	}

	TVector(const TVector<T>& p) 
	{
		len = p.len;
		data = new  T[len];

		for (int i = 0; i < len; i++) {
			data[i] = p.data[i];
		}
	}

	~TVector() 
	{
		delete[] data;
		data = 0;
	}

	int& operator[](const int i)
	{
		return data[i];
	};

	TVector operator=(TVector<T> p) 
	{
		if (len == p.len) 
		{
			for (int i = 0; i < len; i++) 
			{
				data[i] = p.data[i];
			}
			return *this;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TVector operator+(TVector<T> p) 
	{
		if (len == p.len) 
		{
			TVector<T> tmp(len);

			for (int i = 0; i < len; i++) 
			{
				tmp.data[i] = data[i] + p.data[i];
			}
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TVector operator-(TVector<T> p) 
	{
		if (len == p.len) 
		{
			TVector<T> tmp(len);

			for (int i = 0; i < len; i++) 
			{
				tmp.data[i] = data[i] - p.data[i];
			}
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TVector operator*(TVector<T> p) 
	{
		if (len == p.len) 
		{
			TVector<T> tmp(len);

			for (int i = 0; i < len; i++) 
			{
				tmp.data[i] = data[i] * p.data[i];
			}
			return tmp;
		}
		else {
			cout << "Error." << endl;
			abort();
		}
	};

	TVector operator/(TVector<T> p)
	{
		if (len == p.len) 
		{
			TVector<T> tmp(len);

			for (int i = 0; i < len; i++) 
			{
				tmp.data[i] = (data[i]) / (p.data[i]);
			}
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	friend ostream& operator<< (ostream& os, TVector<T>& p)
	{
		for (int i = 0; i < p.len; i++) 
		{
			os << p.data[i] << endl;
		}
		return os;
	};

	friend istream& operator>>(istream& in, TVector<T>& p)
	{
		for (int i = 0; i < p.len; i++)
		{
			in >> p.data[i];
		}
		return in;
	};

	template <class T>
	bool operator==(TVector<T> &Second) 
	{
		if (this->len != Second.len)
		{
			return false;
		}
		for (int i = 0; i < this->len; i++)
		{
			if (this->data[i] != Second.data[i])
			{
				return false;
			}
		}
		return true;
	}
};
