#include <iostream>
#include "vector.h"
#include "matrix.h"

using namespace std;

int main() {

	TVector<int> v1(3);
	TVector<int> v2{3, 3, 3};
	TVector<int> v3{2, 2, 2};

	TMatrix<int> m1(3, 3, 3);
	TMatrix<int> m2(2, 2, 2);
	TMatrix<int> m3(3, 3, 5);

	TMatrix<int> m4;

	cin >> v1;
	cout << v1 << endl;
	cout << v2 << endl;

	cin >> m4;
	cout << m1 << endl;

	v3 = v3 + v2;
	cout << v3 << endl;

	v3 = v3 - v2;
	cout << v3 << endl;

	v3 = v3 * v2;
	cout << v3 << endl;

	v3 = v3 / v2;
	cout << v3 << endl;


	m3 = m3 + m1;
	cout << m3 << endl;

	m3 = m3 - m1;
	cout << m3 << endl;

	m3 = m3 * m1;
	cout << m3 << endl;
}