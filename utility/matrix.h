#pragma once
/*************************************************************************
* Project:Open Frameworks for Evolutionary Computation (OFEC)
*************************************************************************
* Author: Changhe Li
* Email: changhe.lw@gmail.com
* Language: C++
*************************************************************************
*  This file is part of OFEC. This library is free software;
*  you can redistribute it and/or modify it under the terms of the
*  GNU General Public License as published by the Free Software
*  Foundation; either version 2, or (at your option) any later version.
*************************************************************************/

#ifndef OFEC_matrix_H
#define OFEC_matrix_H

#include "myVector.h"


namespace OFEC {


	class matrix {								// *****************Orthogonal rotation matrix***********************
	private:
		int m_col, m_row;									// matrix size
		vector<myVector> m_vec;
	public:
		matrix(int dim = 0);
		matrix(const int c, const int r);
		~matrix();

		matrix & operator*=(const matrix & m);
		matrix & operator*=(const double x);
		matrix & operator=(const matrix & m);
		bool identity();
		bool isIdentity();
		int getRow();
		int getCol();
		void setRotationAngle(const int r, const int c, const double angle);
		void generateRotationmatrix(const double CondiNum, caller rMode);
		void randomize(caller rMode);
		void orthonormalize();
		void orthonormalizeClassical();
		void setToZero();
		void setDataRow(const double *d, const int c, const int r = 1);
		void setDataCol(const double *d, const int r, const int c = 1);
		void setData(const double * const * d);
		void diagonalize(const double CondiNum);
		void transpose();
		void inverse();
		bool isOrthogonal();
		myVector & operator[](const int idx);
		const myVector & operator[](const int idx)const;
		void Read_Data(ifstream &in) {
			for (int i = 0; i < m_row; i++) {
				in >> m_vec[i];
			}
		};
		// used for debug
		void Print(ofstream & out) {
			for (int i = 0; i < m_row; i++) {
				for (int j = 0; j < m_col; j++)
					out << m_vec[i][j] << " ";
				out << endl;
			}
			//out<<endl;
		};
		void print();
		void resize(const int row, const int col);

		void dalgonalize(double alpha);
	private:
		void freeMemory();
		void allocateMemory(const int r, const int c);
	};
}
#endif // !OFEC_matrix_H