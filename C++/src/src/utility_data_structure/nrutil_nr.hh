/*
 * The MIT License

   Conograph (powder auto-indexing program)

Copyright (c) <2012> <Ryoko Oishi-Tomiyasu, KEK>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 *
 */
#ifndef _NR_UTIL_H_
#define _NR_UTIL_H_

#include <assert.h>
#include <cstdlib>
#include <algorithm>
#include "../zerror_type/error_out.hh"

using namespace std;

template <class T>
class NRVec {
private:
	int nn;	// size of array. upper index is nn-1
	T *v;
public:
	NRVec();
	explicit NRVec(int n);		// Zero-based array
	NRVec(int n, const T &a);	//initialize to constant value
	NRVec(const NRVec &rhs);	// Copy constructor
	NRVec & operator=(const NRVec &rhs);	//assignment
	NRVec & operator=(const T &a);	//assign a to every element
	inline T & operator[](const int i);	//i'th element
	inline const T & operator[](const int i) const;
	inline int size() const;
	~NRVec();

	NRVec& operator+=(const NRVec& rhs);
	NRVec& operator-=(const NRVec& rhs);
	NRVec& operator*=(const T&);
};

template <class T>
NRVec<T>::NRVec() : nn(0), v(0) {}

template <class T>
NRVec<T>::NRVec(int n) : nn(n), v(0)
{
	assert( n >= 0 );
	if( n > 0 ) v = new T[n];
}

template <class T>
NRVec<T>::NRVec(int n, const T& a) : nn(n), v(0)
{
	assert( n >= 0 );
	if( n > 0 ) v = new T[n];
	for(int i=0; i<n; i++) v[i] = a;
}

template <class T>
NRVec<T>::NRVec(const NRVec<T> &rhs) : nn(rhs.nn), v(0)
{
	if( rhs.nn > 0 ) v = new T[nn];
	for(int i=0; i<nn; i++)
		v[i] = rhs[i];
}

template <class T>
NRVec<T> & NRVec<T>::operator=(const NRVec<T> &rhs)
// postcondition: normal assignment via copying has been performed;
//		if vector and rhs were different sizes, vector
//		has been resized to match the size of rhs
{
	if (this != &rhs)
	{
		if (nn != rhs.nn) {
			delete [] (v);
			v = 0;
			nn=rhs.nn;
			if( nn > 0 ) v= new T[nn];
		}
		for (int i=0; i<nn; i++)
			v[i]=rhs[i];
	}
	return *this;
}


template <class T>
NRVec<T> & NRVec<T>::operator=(const T &a)	//assign a to every element
{
	for (int i=0; i<nn; i++)
		v[i]=a;
	return *this;
}


template <class T>
inline T & NRVec<T>::operator[](const int i)	//subscripting
{
	assert( 0 <= i && i < nn );
	return v[i];
}

template <class T>
inline const T & NRVec<T>::operator[](const int i) const	//subscripting
{
	assert( 0 <= i && i < nn );
	return v[i];
}

template <class T>
inline int NRVec<T>::size() const
{
	return nn;
}

template <class T>
NRVec<T>::~NRVec()
{
	if (v != 0)
		delete[] (v);
}

template <class T>
NRVec<T>& NRVec<T>::operator+=(const NRVec<T>& rhs)
{
	assert(nn==(Int4)rhs.size());
	
	for(int k=0; k<nn; k++) v[k]+=rhs[k];
	return *this;
}

template <class T>
NRVec<T> operator+(const NRVec<T>& lhs, const NRVec<T>& rhs)
{
	NRVec<T> ans(lhs);
	ans+=rhs;
	return ans;
}

template <class T>
NRVec<T>& NRVec<T>::operator-=(const NRVec<T>& rhs)
{
	assert(nn==(Int4)rhs.size());
	
	for(int k=0; k<nn; k++) v[k]-=rhs[k];
	return *this;
}

template <class T>
NRVec<T> operator-(const NRVec<T>& lhs, const NRVec<T>& rhs)
{
	NRVec<T> ans(lhs);
	ans-=rhs;
	return ans;
}

template <class T>
NRVec<T>& NRVec<T>::operator*=(const T& rhs)
{
	for(int k=0; k<nn; k++) v[k]*=rhs;
	return *this;
}

template <class T>
NRVec<T> operator*(const NRVec<T>& lhs, const T& rhs)
{
	NRVec<T> ans(lhs);
	ans*=rhs;
	return ans;
}

template <class T>
T inner_product(const NRVec<T>& lhs, const NRVec<T>& rhs)
{
	const Int4 isize = lhs.size();
	assert( isize == (Int4)rhs.size() );
	
	T ans = 0;
	for(int k=0; k<isize; k++) ans += lhs[k]*rhs[k];
	return ans;
}

template <class T>
NRVec<T> product_each_element(const NRVec<T>& lhs, const NRVec<T>& rhs)
{
	const Int4 isize = lhs.size();
	assert( isize == (Int4)rhs.size() );
	
	NRVec<T> ans(isize);
	for(int k=0; k<isize; k++) ans[k] = lhs[k]*rhs[k];
	return ans;
}




template <class T>
class NRMat {
private:
	int nn;
	int mm;
	T **v;
public:
	NRMat();
	NRMat(int n, int m);			// Zero-based array
	NRMat(int n, int m, const T& a);	//Initialize to constant
	NRMat(const NRMat &rhs);		// Copy constructor
	NRMat& operator=(const NRMat& rhs);	//assignment
	NRMat& operator=(const T& a);		//assign a to every element
	inline T* operator[](const int i);	//subscripting: pointer to row i
	inline const T* operator[](const int i) const;
	inline int nrows() const;
	inline int ncols() const;
	~NRMat();

	NRMat& operator+=(const NRMat&);
	NRMat& operator-=(const NRMat&);
	NRMat& operator*=(const T&);
//	NRMat& operator/=(const T&);
};

template <class T>
NRMat<T>::NRMat() : nn(0), mm(0), v(0) {}

template <class T>
NRMat<T>::NRMat(int n, int m) : nn(n), mm(m), v(0)
{
	assert( n >= 0 );
	assert( m >= 0 );
	if(n > 0)
	{
		v = new T*[n];
		if(m > 0)
		{
			v[0] = new T[m*n];
			for (int i=1; i< n; i++)
				v[i] = v[i-1] + m;
		}
		else for (int i=0; i< n; i++) v[i] = 0;
	}
}

template <class T>
NRMat<T>::NRMat(int n, int m, const T &a) : nn(n), mm(m), v(0)
{
	assert( n >= 0 );
	assert( m >= 0 );

	int i,j;
	if(n > 0)
	{
		v = new T*[n];
		if(m > 0)
		{
			v[0] = new T[m*n];
			for (i=1; i< n; i++)
				v[i] = v[i-1] + m;
			for (i=0; i< n; i++)
				for (j=0; j<m; j++)
					v[i][j] = a;
		}
		else for (int i=0; i< n; i++) v[i] = 0;
	}
}

template <class T>
NRMat<T>::NRMat(const NRMat &rhs) : nn(rhs.nn), mm(rhs.mm), v(0)
{
	int i,j;
	if(nn > 0)
	{
		v = new T*[nn];
		if(mm > 0)
		{
			v[0] = new T[mm*nn];
			for (i=1; i< nn; i++)
				v[i] = v[i-1] + mm;
			for (i=0; i< nn; i++)
				for (j=0; j<mm; j++)
					v[i][j] = rhs[i][j];
		}
		else for (int i=0; i<nn; i++) v[i] = 0;
	}
}

template <class T>
NRMat<T> & NRMat<T>::operator=(const NRMat<T> &rhs)
// postcondition: normal assignment via copying has been performed;
//		if matrix and rhs were different sizes, matrix
//		has been resized to match the size of rhs
{
	if (this != &rhs) {
		int i,j;
		if (nn != rhs.nn || mm != rhs.mm) {
			if(nn > 0) delete[] (v[0]);
			delete[] (v);
			v = 0;
			nn=rhs.nn;
			mm=rhs.mm;
			if( nn > 0 )
			{
				v = new T*[nn];
				if( mm > 0 )
				{
					v[0] = new T[mm*nn];
					for (i=1; i<nn; i++)
						v[i] = v[i-1] + mm;
				}
				else for (i=0; i< nn; i++) v[i] = 0;
			}
		}
		for (i=0; i<nn; i++)
			for (j=0; j<mm; j++)
				v[i][j] = rhs[i][j];
	}
	return *this;
}


template <class T>
NRMat<T> & NRMat<T>::operator=(const T &a)	//assign a to every element
{
	for (int i=0; i<nn; i++)
		for (int j=0; j<mm; j++)
			v[i][j] = a;
	return *this;
}

template <class T>
inline T* NRMat<T>::operator[](const int i)	//subscripting: pointer to row i
{
	assert( 0 <= i && i < nn );
	return v[i];
}

template <class T>
inline const T* NRMat<T>::operator[](const int i) const
{
	assert( 0 <= i && i < nn );
	return v[i];
}



template <class T>
inline int NRMat<T>::nrows() const
{
	return nn;
}

template <class T>
inline int NRMat<T>::ncols() const
{
	return mm;
}

template <class T>
NRMat<T>::~NRMat()
{
	if(nn > 0) delete[] (v[0]);
	delete[] (v);
}

template <class T>
NRMat<T>& NRMat<T>::operator+=(const NRMat<T>& rhs)
{
	assert(nn==rhs.nrows());
	assert(mm==rhs.ncols());

	for(Int4 k=0; k<nn; k++)
		for(Int4 j=0; j<mm; j++) v[k][j] += rhs[k][j];
	return *this;
}

template <class T>
NRMat<T>& NRMat<T>::operator-=(const NRMat<T>& rhs)
{
	assert(nn==rhs.nrows());
	assert(mm==rhs.ncols());

	for(Int4 k=0; k<nn; k++)
		for(Int4 j=0; j<mm; j++) v[k][j] -= rhs[k][j];
	return *this;
}

/*
template <class T>
NRMat<T> operator-(const NRMat<T>& rhs)
{
	const Int4 nn =rhs.nrows();
	const Int4 mm =rhs.ncols();

	NRMat<T> ans(nn, mm);
	for(Int4 k=0; k<nn; k++)
		for(Int4 j=0; j<mm; j++) ans[k][j] = -rhs[k][j];
	return ans;
}
*/

template <class T>
NRMat<T>& NRMat<T>::operator*=(const T& rhs)
{
	for(Int4 k=0; k<nn; k++)
		for(Int4 j=0; j<mm; j++) v[k][j] *= rhs;
	return *this;
}


//template <class T>
//NRMat<T>& NRMat<T>::operator/=(const T& rhs)
//{
//	for(Int4 k=0; k<nn; k++)
//		for(Int4 j=0; j<mm; j++) v[k][j] /= rhs;
//	return *this;
//}


template <class T>
NRMat<T> operator*(const NRMat<T>& lhs, const T& rhs)
{
	NRMat<T> ans = lhs;
	ans *= rhs;
	return ans;
}

template<class T>
NRMat<T> operator/(const NRMat<T>& lhs, const Int4& rhs)
{
	const Int4 nn = lhs.nrows();
	const Int4 mm = lhs.ncols();
	NRMat<T> ans = lhs;
	for(Int4 k=0; k<nn; k++)
		for(Int4 j=0; j<mm; j++)
		{
			assert( ans[k][j] % rhs == 0 );
			ans[k][j] /= rhs;
		}
	return ans;
}

inline NRMat<Double> int2double (const NRMat<Int4> mat)
{
	Int4 irow = mat.nrows();
	Int4 icol = mat.ncols();

	NRMat<Double> ans (irow, icol, 0.0);
	for (Int4 i=0; i<irow; i++)
	{
		for (Int4 j=0; j<icol; j++)
		{
			ans[i][j] = double (mat[i][j]);
		}
	}
	return ans;
}

template <class T>
NRMat<T> mprod(const NRMat<T>& lhs, const NRMat<T>& rhs)
{
	const Int4 isize = lhs.ncols();
	assert( isize == rhs.nrows() );

	const Int4 irow = lhs.nrows();
	const Int4 icol = rhs.ncols();
	
	NRMat<T> ans(irow, icol, 0);
	for(Int4 k=0; k<irow; k++)
		for(Int4 j=0; j<icol; j++)
			for(Int4 l=0; l<isize; l++) ans[k][j] += lhs[k][l] * rhs[l][j];
	
	return ans;
}

// ----------over load of mprod in nrutil_nr.cc-------------
// lhs     rhs        output
// int,    int    ---> int
// double, double ---> double
// int,    double ---> double
// double, int    ---> double 
// <<int @ double --> double>>

inline NRMat<Double> mprod (const NRMat<Int4>& lhs, const NRMat<Double>& rhs)
{
	NRMat<Double> lhs_ = int2double (lhs);
	NRMat<Double> ans = mprod (lhs_, rhs);
	return ans;
}

// <<double @ int --> double>>
inline NRMat<Double> mprod (const NRMat<Double>& lhs, const NRMat<Int4>& rhs)
{
	NRMat<Double> rhs_ = int2double (rhs);
	NRMat<Double> ans = mprod (lhs, rhs_);
	return ans;
}

template<class T>
NRMat<T> diagonal (const vector <T> dvec)
{
	int ndim = dvec.size();
	NRMat<T> mat (ndim, ndim, 0);
	for (Int4 i = 0; i < ndim; i++)
	{
		mat[i][i] = dvec[i];
	}
	return mat;
} 

// multiple definition error!!
inline Double trace (const NRMat<Double> mat)
{
	Double ans = 0.0;
	int ndim = mat.nrows();
	for (int i = 0; i < ndim; i++)
	{
		ans += mat[i][i];
	}
	return ans;
}

template <class T>
NRMat<T> difference (const NRMat<T>& rhs, const NRMat<T>& lhs)
{
	int irow = rhs.nrows();
	int icol = rhs.ncols();
	NRMat<T> ans (irow, icol, 0);
	for (int i = 0; i < irow; i++)
	{
		for (int j = 0; j < icol; j++)
		{
			ans[i][j] = rhs[i][j] - lhs[i][j];
		}
	}
	return ans;
}

//template <class T>
//NRMat<T> transpose(const NRMat<T>& lhs)
//{
//	const Int4 icol = lhs.nrows();
//	const Int4 irow = lhs.ncols();
//	
//	NRMat<T> ans(irow, icol);
//	for(Int4 k=0; k<irow; k++)
//		for(Int4 j=0; j<icol; j++) ans[k][j] = lhs[j][k];
//	
//	return ans;
//}

template <class T>
inline NRMat<T> transpose(const NRMat<T>& rhs)
{
	NRMat<T> ans(rhs.ncols(), rhs.nrows());
	for(Int4 i=0; i<rhs.nrows(); i++)
	{
		for(Int4 j=0; j<rhs.ncols(); j++)
		{
			ans[j][i] = rhs[i][j];
		}
	}
	return ans;
}


template <class T>
NRVec<T> left_act(const NRMat<T>& lhs, const NRVec<T>& rhs)
{
	const Int4 irow = lhs.nrows();
	const Int4 icol = lhs.ncols();
	assert(icol==(Int4)rhs.size());

	
	NRVec<T> ans( irow, 0 );
	for(Int4 k=0; k<irow; k++)
		for(Int4 j=0; j<icol; j++) ans[k] += lhs[k][j]*rhs[j];

	return ans;
}

template <class T>
NRVec<T> right_act(const NRVec<T>& lhs, const NRMat<T>& rhs)
{
	const Int4 irow = rhs.nrows();
	const Int4 icol = rhs.ncols();
	assert(irow==(Int4)lhs.size());

	
	NRVec<T> ans( icol, 0 );
	for(Int4 k=0; k<icol; k++)
		for(Int4 j=0; j<irow; j++) ans[k] += lhs[j]*rhs[j][k];

	return ans;
}

template<class T>
inline void transpose_square_matrix(NRMat<T>& rhs)
{
	const Int4 isize = rhs.nrows();
	assert( isize == rhs.ncols() );
	
	for(Int4 i=0; i<isize; i++)
		for(Int4 j=0; j<i; j++) swap(rhs[i][j], rhs[j][i]);
}


inline Int4 Determinant3(const NRMat<Int4>& rhs)
{
	assert( rhs.nrows() == 3 && rhs.ncols() == 3 );
	
	const Int4 det12 = rhs[1][1]*rhs[2][2]-rhs[1][2]*rhs[2][1];
	const Int4 det12_02 = rhs[1][0]*rhs[2][2]-rhs[1][2]*rhs[2][0];
	const Int4 det12_01 = rhs[1][0]*rhs[2][1]-rhs[1][1]*rhs[2][0];
	
	return rhs[0][0]*det12 - rhs[0][1]*det12_02 + rhs[0][2]*det12_01;
}



inline NRMat<Int4> Inverse3(const NRMat<Int4>& rhs)
{
	assert( rhs.nrows() == 3 && rhs.ncols() == 3 );
	
	const Int4 det01 = rhs[0][0]*rhs[1][1]-rhs[0][1]*rhs[1][0];
	const Int4 det02 = rhs[0][0]*rhs[2][2]-rhs[0][2]*rhs[2][0];
	const Int4 det12 = rhs[1][1]*rhs[2][2]-rhs[1][2]*rhs[2][1];
	const Int4 det01_02 = rhs[0][0]*rhs[1][2]-rhs[0][2]*rhs[1][0];
	const Int4 det02_01 = rhs[0][0]*rhs[2][1]-rhs[0][1]*rhs[2][0];
	const Int4 det01_12 = rhs[0][1]*rhs[1][2]-rhs[0][2]*rhs[1][1];
	const Int4 det02_12 = rhs[0][1]*rhs[2][2]-rhs[0][2]*rhs[2][1];
	const Int4 det12_02 = rhs[1][0]*rhs[2][2]-rhs[1][2]*rhs[2][0];
	const Int4 det12_01 = rhs[1][0]*rhs[2][1]-rhs[1][1]*rhs[2][0];
	
	const Int4 det = rhs[0][0]*det12 - rhs[0][1]*det12_02 + rhs[0][2]*det12_01;
	assert( abs(det) == 1 );
	
	NRMat<Int4> ans(3,3);
	ans[0][0] = det12;
	ans[0][1] = -det02_12;
	ans[0][2] = det01_12;
	ans[1][0] = -det12_02;
	ans[1][1] = det02;
	ans[1][2] = -det01_02;
	ans[2][0] = det12_01;
	ans[2][1] = -det02_01;
	ans[2][2] = det01;
	
	if( det == 1 )
	{
		return ans;
	}
	else
	{
		return ans * (-1);
	}
}

template<class T>
T det_2x2 (NRMat<T> mat)
{
	T a11, a22, a12, a21;
	a11 = mat[0][0]; a12 = mat[0][1];
	a21 = mat[1][0]; a22 = mat[1][1];
	return (a11 * a22) - (a12 * a21);
}

template<class T>
T det_3x3 (NRMat<T> mat)
{
	T ans = mat[0][0] * mat[1][1] * mat[2][2]; // a11*a22*a33
	ans += mat[0][1] * mat[1][2] * mat[2][0]; //+= a12*a23*a31
	ans += mat[0][2] * mat[2][1] * mat[1][0]; //+= a13*a32*a21
	ans -= mat[0][2] * mat[1][1] * mat[2][0]; //-= a13*a22*a31
	ans -= mat[0][1] * mat[1][0] * mat[2][2]; //-= a12*a21*a33
	ans -= mat[0][0] * mat[2][1] * mat[1][2]; //-= a11*a32*a23
	return ans;
}


/*
template <class T>
NRMat<T> transpose_product(const NRVec<T>& lhs, const NRVec<T>& rhs)
{
	const Int4 irow = lhs.size();
	const Int4 icol = lhs.size();
	
	NRMat<T> ans( irow, icol );
	for(Int4 k=0; k<irow; k++)
		for(Int4 j=0; j<icol; j++) ans[k][j] = lhs[k]*rhs[j];

	return ans;
}
*/

template <class T>
inline NRMat<T> identity_matrix(const Int4& isize)
{
	NRMat<T> TransMat(isize,isize,0);
	for(Int4 k=0; k<isize; k++) TransMat[k][k] = 1;

	return TransMat;
}

template <class T>
vector <Int4> argsort (const vector<T>& vec)
{
    Int4 vecSize = vec.size();
	vector <Int4> index (vec.size());
	for (Int4 i = 0; i < vecSize; i++) index[i] = i;
    sort (index.begin(), index.end(),
            [&](Int4 x, Int4 y){return vec[x] < vec[y];});
    return index;
}

template <class T>
NRMat<T> mat_delete (const NRMat<T>& mat, const Int4& idx, const Int4& axis)
{
	assert (axis == 0 || axis == 1);
	assert (0 <= idx);
	if (axis == 0) assert (idx < mat.nrows());
	else assert (idx < mat.ncols());

    vector <Int4> idxRow, idxCol;
    for (Int4 i = 0; i < mat.nrows(); i++)
    {
        if (axis != 0 || (axis == 0 && i != idx))
        idxRow.push_back (i);
    }
    for (Int4 j = 0; j < mat.ncols(); j++)
    {
        if (axis != 1 || (axis == 1 && j != idx))
        idxCol.push_back (j);
    }
    
	Int4 sizeRow = idxRow.size();
	Int4 sizeCol = idxCol.size();
	NRMat<T> ans (sizeRow, sizeCol, 0);
    for (Int4 i = 0; i < sizeRow; i++)
    {
        for (Int4 j = 0; j < sizeCol; j++)
        {
            ans[i][j] = mat[idxRow[i]][idxCol[j]];
        }
    }

	return ans;
}

template <class T>
Double cofactor (const NRMat<T>& mat, const Int4& i, const Int4& j)
{
	NRMat<T> m2x2 = mat_delete (mat_delete (mat, i, 0), j, 1);
	T ans = ((i + j)%2==0?1:-1) * det_2x2 (m2x2);
	return ans;
}

template <class T>
NRMat<T> inverse_mat_3x3 (const NRMat<T>& mat)
{
	Double det = det_3x3 (mat);
	NRMat<T> ans (3,3,0);
	for (Int4 i = 0; i < mat.nrows(); i++)
	{
		for (Int4 j = 0; j < mat.ncols(); j++)
		{
			ans[i][j] = cofactor (mat, i, j) / det;
		}
	}
	return transpose (ans);
}

template <class T>
NRMat<T> put_matrix (const vector<vector<T>>& vec)
{
	Int4 nrow = vec.size();
	Int4 ncol = vec[0].size();
	NRMat<T> ans (nrow, ncol, 0);
	for (Int4 i = 0; i < nrow; i++)
	{
		for (Int4 j = 0; j < ncol; j++)
		{
			ans[i][j] = vec[i][j];
		}
	}
	return ans;
}

#endif /* _NR_UTIL_H_ */
