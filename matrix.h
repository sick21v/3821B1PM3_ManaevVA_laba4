#pragma once
#include "vector.h"
#include<iostream>

using namespace std;

template <class T>
class TMatrix : public TVector<T> 
{
protected:

	T** dataM;
	int len = 2;
	int weidth = 2;

public:

	TMatrix() 
	{
		dataM = new T * [len];

		for (int i = 0; i < len; i++) 
		{
			dataM[i] = new T[weidth];
		}

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < weidth; j++)
			{
				dataM[i][j] = 0;
			}
		}
	}

	TMatrix(int x, int y, T v) 
	{
		len = x;
		weidth = y;
		dataM = new T * [len];

		for (int i = 0; i < len; i++) 
		{
			dataM[i] = new T[weidth];
		}

		for (int i = 0; i < len; i++) 
		{
			for (int j = 0; j < weidth; j++)
			{
				dataM[i][j] = v;
			}
		}
	}

	TMatrix(const TMatrix<T>& p) 
	{
		dataM = new  T * [p.len];

		for (int i = 0; i < p.len; i++) 
		{
			dataM[i] = new T[p.weidth];
		}

		for (int i = 0; i < p.len; i++) 
		{
			for (int j = 0; j < p.weidth; j++)
			{
				dataM[i][j] = p.dataM[i][j];
			}
		}
	}

	~TMatrix() {
		for (int i = 0; i < len; i++) 
		{
			delete[] dataM[i];
		}

		delete[] dataM;
	}

	auto operator[](const int i) 
	{
		return dataM[i];
	};

	TMatrix& operator = (TMatrix<T> p) 
	{
		for (int i = 0; i < len; i++) 
		{
			for (int j = 0; j < weidth; j++) 
			{
				dataM[i][j] = p.dataM[i][j];
			}
		}
		return *this;
	};

	TMatrix operator+(TMatrix<T>& p) 
	{
		if ((len == p.len) && (weidth == p.weidth))
		{
			TMatrix<T> tmp(len, weidth, 0);

			for (int i = 0; i < len; i++) 
			{
				for (int j = 0; j < weidth; j++) 
				{
					tmp.dataM[i][j] = dataM[i][j] + p.dataM[i][j];
				}
			}
			return tmp;
		}
		else
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TMatrix operator-(TMatrix<T>& p) 
	{
		if ((len == p.len) && (weidth == p.weidth)) 
		{
			TMatrix<T> tmp(len, weidth, 0);

			for (int i = 0; i < len; i++) 
			{
				for (int j = 0; j < weidth; j++) 
				{
					tmp.dataM[i][j] = dataM[i][j] - p.dataM[i][j];
				}
			}
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TMatrix operator*(TMatrix<T>& p) 
	{
		if (weidth == p.len) 
		{
			TMatrix<T> tmp(len, p.weidth, 0);
			for (int i = 0; i < len; i++) 
			{
				for (int j = 0; j < p.len; j++) 
				{
					for (int k = 0; k < weidth; k++) 
					{
						tmp.dataM[i][j] += dataM[i][k] * p.dataM[k][j];
					}
				}
			}
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	TMatrix operator*(TVector<T>& p) 
	{
		if (weidth == p.GetLen()) 
		{
			TMatrix<T> tmp(p.GetLen(), 1, 0);

			for (int i = 0; i < tmp.len; i++) 
			{
				for (int j = 0; j < 1; j++) 
				{
					for (int k = 0; k < p.GetLen(); k++) 
					{
						tmp.dataM[i][j] += dataM[i][k] * p.GetData(k);
					}
				}
			}
			cout << tmp << endl;
			return tmp;
		}
		else 
		{
			cout << "Error." << endl;
			abort();
		}
	};

	friend ostream& operator<< (ostream& os, TMatrix<T>& p) 
	{
		for (int i = 0; i < p.len; i++) 
		{
			for (int j = 0; j < p.weidth; j++) 
			{
				os << p.dataM[i][j] << " ";
			}
			os << endl;
		}
		return os;
	};

	friend istream& operator>>(istream& in, TMatrix<T>& p)
	{
		for (int i = 0; i < p.len; i++) 
		{
			for (int j = 0; j < p.weidth; j++) 
			{
				in >> p.dataM[i][j];
			}
		}
		return in;
	};

	template <class T>
	bool operator==(TMatrix<T>& Second)
	{
		if ((this->len != Second.len) || (this->weidth != Second.weidth))
		{
			return false;
		}

		for (int i = 0; i < this->len; i++)
		{
			for (int j = 0; j < this->weidth; j++) 
			{
				if (this->dataM[i][j] != Second.dataM[i][j]) 
				{
					return false;
				}
			}
		}
		return true;
	}
};

