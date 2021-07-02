#pragma once
#include <memory>
class MyMatrix
{
public:
	union
	{
		struct
		{
			float MatrixField[4][4];
		};

		struct
		{
			float MatrixArr[16];
		};
	};


public:
	MyMatrix() { Identity(); }
	~MyMatrix() {}

	MyMatrix(const MyMatrix& _Other) : MatrixField{ 0, }
	{
		memcpy_s(this, sizeof(MyMatrix), &_Other, sizeof(MyMatrix));
	}


public:
	//행렬을 항등행렬로 만드는 함수
	void Identity()
	{
		memset(this, 0, sizeof(MyMatrix));
		for (int i = 0; i < 4; i++)
		{
			MatrixField[i][i] = 1;
		}
	}
	//행렬을 역행렬로 만드는 함수
	void Reverse()
	{
		float det = (MatrixField[0][0] * MatrixField[1][1] * MatrixField[2][2] * MatrixField[3][3]) + (MatrixField[0][0] * MatrixField[1][2] * MatrixField[2][3] * MatrixField[3][1]) + (MatrixField[0][0] * MatrixField[1][3] * MatrixField[2][1] * MatrixField[3][2])
			+ (MatrixField[0][1] * MatrixField[1][0] * MatrixField[2][3] * MatrixField[3][2]) + (MatrixField[0][1] * MatrixField[1][2] * MatrixField[2][0] * MatrixField[3][3]) + (MatrixField[0][1] * MatrixField[1][3] * MatrixField[2][2] * MatrixField[3][0])
			+ (MatrixField[0][2] * MatrixField[1][0] * MatrixField[2][1] * MatrixField[3][3]) + (MatrixField[0][2] * MatrixField[1][1] * MatrixField[2][3] * MatrixField[3][0]) + (MatrixField[0][2] * MatrixField[1][3] * MatrixField[2][0] * MatrixField[3][1])
			+ (MatrixField[0][3] * MatrixField[1][0] * MatrixField[2][2] * MatrixField[3][1]) + (MatrixField[0][3] * MatrixField[1][1] * MatrixField[2][0] * MatrixField[3][2]) + (MatrixField[0][3] * MatrixField[1][2] * MatrixField[2][1] * MatrixField[3][0])
			- (MatrixField[0][0] * MatrixField[1][1] * MatrixField[2][3] * MatrixField[3][2]) - (MatrixField[0][0] * MatrixField[1][2] * MatrixField[2][1] * MatrixField[3][3]) - (MatrixField[0][0] * MatrixField[1][3] * MatrixField[2][2] * MatrixField[3][1])
			- (MatrixField[0][1] * MatrixField[1][0] * MatrixField[2][2] * MatrixField[3][3]) - (MatrixField[0][1] * MatrixField[1][2] * MatrixField[2][3] * MatrixField[3][0]) - (MatrixField[0][1] * MatrixField[1][3] * MatrixField[2][0] * MatrixField[3][2])
			- (MatrixField[0][2] * MatrixField[1][0] * MatrixField[2][3] * MatrixField[3][1]) - (MatrixField[0][2] * MatrixField[1][1] * MatrixField[2][0] * MatrixField[3][3]) - (MatrixField[0][2] * MatrixField[1][3] * MatrixField[2][1] * MatrixField[3][0])
			- (MatrixField[0][3] * MatrixField[1][0] * MatrixField[2][1] * MatrixField[3][2]) - (MatrixField[0][3] * MatrixField[1][1] * MatrixField[2][2] * MatrixField[3][0]) - (MatrixField[0][3] * MatrixField[1][2] * MatrixField[2][0] * MatrixField[3][1]);

		if (det == 0.0)
		{
			return;
		}
		MyMatrix RMat;

		RMat.MatrixField[0][0] = (MatrixField[1][1] * MatrixField[2][2] * MatrixField[3][3]) + (MatrixField[1][2] * MatrixField[2][3] * MatrixField[3][1]) + (MatrixField[1][3] * MatrixField[2][1] * MatrixField[3][2]) - (MatrixField[1][1] * MatrixField[2][3] * MatrixField[3][2]) - (MatrixField[1][2] * MatrixField[2][1] * MatrixField[3][3]) - (MatrixField[1][3] * MatrixField[2][2] * MatrixField[3][1]);

		RMat.MatrixField[0][1] = (MatrixField[0][1] * MatrixField[2][3] * MatrixField[3][2]) + (MatrixField[0][2] * MatrixField[2][1] * MatrixField[3][3]) + (MatrixField[0][3] * MatrixField[2][2] * MatrixField[3][1]) - (MatrixField[0][1] * MatrixField[2][2] * MatrixField[3][3]) - (MatrixField[0][2] * MatrixField[2][3] * MatrixField[3][1]) - (MatrixField[0][3] * MatrixField[2][1] * MatrixField[3][2]);

		RMat.MatrixField[0][2] = (MatrixField[0][1] * MatrixField[1][2] * MatrixField[3][3]) + (MatrixField[0][2] * MatrixField[1][3] * MatrixField[3][1]) + (MatrixField[0][3] * MatrixField[1][1] * MatrixField[3][2]) - (MatrixField[0][1] * MatrixField[1][3] * MatrixField[3][2]) - (MatrixField[0][2] * MatrixField[1][1] * MatrixField[3][3]) - (MatrixField[0][3] * MatrixField[1][2] * MatrixField[3][1]);

		RMat.MatrixField[0][3] = (MatrixField[0][1] * MatrixField[1][3] * MatrixField[2][2]) + (MatrixField[0][2] * MatrixField[1][1] * MatrixField[2][3]) + (MatrixField[0][3] * MatrixField[1][2] * MatrixField[2][1]) - (MatrixField[0][1] * MatrixField[1][2] * MatrixField[2][3]) - (MatrixField[0][2] * MatrixField[1][3] * MatrixField[2][1]) - (MatrixField[0][3] * MatrixField[1][1] * MatrixField[2][2]);

		RMat.MatrixField[1][0] = (MatrixField[1][0] * MatrixField[2][3] * MatrixField[3][2]) + (MatrixField[1][2] * MatrixField[2][0] * MatrixField[3][3]) + (MatrixField[1][3] * MatrixField[2][2] * MatrixField[3][0]) - (MatrixField[1][0] * MatrixField[2][2] * MatrixField[3][3]) - (MatrixField[1][2] * MatrixField[2][3] * MatrixField[3][0]) - (MatrixField[1][3] * MatrixField[2][0] * MatrixField[3][2]);

		RMat.MatrixField[1][1] = (MatrixField[0][0] * MatrixField[2][2] * MatrixField[3][3]) + (MatrixField[0][2] * MatrixField[2][3] * MatrixField[3][0]) + (MatrixField[0][3] * MatrixField[2][0] * MatrixField[3][2]) - (MatrixField[0][0] * MatrixField[2][3] * MatrixField[3][2]) - (MatrixField[0][2] * MatrixField[2][0] * MatrixField[3][3]) - (MatrixField[0][3] * MatrixField[2][2] * MatrixField[3][0]);

		RMat.MatrixField[1][2] = (MatrixField[0][0] * MatrixField[1][3] * MatrixField[3][2]) + (MatrixField[0][2] * MatrixField[1][0] * MatrixField[3][3]) + (MatrixField[0][3] * MatrixField[1][2] * MatrixField[3][0]) - (MatrixField[0][0] * MatrixField[1][2] * MatrixField[3][3]) - (MatrixField[0][2] * MatrixField[1][3] * MatrixField[3][0]) - (MatrixField[0][3] * MatrixField[1][0] * MatrixField[3][2]);

		RMat.MatrixField[1][3] = (MatrixField[0][0] * MatrixField[1][2] * MatrixField[2][3]) + (MatrixField[0][2] * MatrixField[1][3] * MatrixField[2][0]) + (MatrixField[0][3] * MatrixField[1][0] * MatrixField[2][2]) - (MatrixField[0][0] * MatrixField[1][3] * MatrixField[2][2]) - (MatrixField[0][2] * MatrixField[1][0] * MatrixField[2][3]) - (MatrixField[0][3] * MatrixField[1][2] * MatrixField[2][0]);

		RMat.MatrixField[2][0] = (MatrixField[1][0] * MatrixField[2][1] * MatrixField[3][3]) + (MatrixField[1][1] * MatrixField[2][3] * MatrixField[3][0]) + (MatrixField[1][3] * MatrixField[2][0] * MatrixField[3][1]) - (MatrixField[1][0] * MatrixField[2][3] * MatrixField[3][1]) - (MatrixField[1][1] * MatrixField[2][0] * MatrixField[3][3]) - (MatrixField[2][3] * MatrixField[2][1] * MatrixField[3][0]);

		RMat.MatrixField[2][1] = (MatrixField[0][0] * MatrixField[2][3] * MatrixField[3][1]) + (MatrixField[0][1] * MatrixField[2][0] * MatrixField[3][3]) + (MatrixField[0][3] * MatrixField[2][1] * MatrixField[3][0]) - (MatrixField[0][0] * MatrixField[2][1] * MatrixField[3][3]) - (MatrixField[0][1] * MatrixField[2][3] * MatrixField[3][0]) - (MatrixField[0][3] * MatrixField[2][0] * MatrixField[3][1]);

		RMat.MatrixField[2][2] = (MatrixField[0][0] * MatrixField[1][1] * MatrixField[3][3]) + (MatrixField[0][1] * MatrixField[1][3] * MatrixField[3][0]) + (MatrixField[0][3] * MatrixField[1][0] * MatrixField[3][1]) - (MatrixField[0][0] * MatrixField[1][3] * MatrixField[3][1]) - (MatrixField[0][1] * MatrixField[1][0] * MatrixField[3][3]) - (MatrixField[0][3] * MatrixField[1][1] * MatrixField[3][0]);

		RMat.MatrixField[2][3] = (MatrixField[0][0] * MatrixField[1][3] * MatrixField[2][1]) + (MatrixField[0][1] * MatrixField[1][0] * MatrixField[2][3]) + (MatrixField[0][3] * MatrixField[1][1] * MatrixField[2][0]) - (MatrixField[0][0] * MatrixField[1][1] * MatrixField[2][3]) - (MatrixField[0][1] * MatrixField[1][3] * MatrixField[2][0]) - (MatrixField[0][3] * MatrixField[1][0] * MatrixField[2][1]);

		RMat.MatrixField[3][0] = (MatrixField[1][0] * MatrixField[2][2] * MatrixField[3][0]) + (MatrixField[1][1] * MatrixField[2][0] * MatrixField[3][2]) + (MatrixField[1][2] * MatrixField[2][1] * MatrixField[3][0]) - (MatrixField[1][0] * MatrixField[2][1] * MatrixField[3][2]) - (MatrixField[1][1] * MatrixField[2][2] * MatrixField[3][0]) - (MatrixField[1][2] * MatrixField[2][0] * MatrixField[3][1]);

		RMat.MatrixField[3][1] = (MatrixField[0][0] * MatrixField[2][1] * MatrixField[3][2]) + (MatrixField[0][1] * MatrixField[2][2] * MatrixField[3][0]) + (MatrixField[0][2] * MatrixField[2][0] * MatrixField[3][1]) - (MatrixField[0][0] * MatrixField[2][2] * MatrixField[3][1]) - (MatrixField[0][1] * MatrixField[2][0] * MatrixField[3][2]) - (MatrixField[0][2] * MatrixField[2][1] * MatrixField[3][0]);

		RMat.MatrixField[3][2] = (MatrixField[0][0] * MatrixField[1][2] * MatrixField[3][1]) + (MatrixField[0][1] * MatrixField[1][0] * MatrixField[3][2]) + (MatrixField[0][2] * MatrixField[1][1] * MatrixField[3][0]) - (MatrixField[0][0] * MatrixField[1][1] * MatrixField[3][2]) - (MatrixField[0][1] * MatrixField[1][2] * MatrixField[3][0]) - (MatrixField[0][2] * MatrixField[1][0] * MatrixField[3][1]);

		RMat.MatrixField[3][3] = (MatrixField[0][0] * MatrixField[1][1] * MatrixField[2][2]) + (MatrixField[0][1] * MatrixField[1][2] * MatrixField[2][0]) + (MatrixField[0][2] * MatrixField[1][0] * MatrixField[2][1]) - (MatrixField[0][0] * MatrixField[1][2] * MatrixField[3][2]) - (MatrixField[0][1] * MatrixField[1][0] * MatrixField[2][2]) - (MatrixField[0][2] * MatrixField[1][1] * MatrixField[2][0]);

		RMat *= (1.0f / det);
		*this = RMat;
	}

public:
	//행렬의 덧셈
	MyMatrix operator+(const MyMatrix& _Value) const
	{
		MyMatrix ReturnMat;


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ReturnMat.MatrixField[i][j] = MatrixField[i][j] + _Value.MatrixField[i][j];
			}

		}

		return ReturnMat;
	}


	MyMatrix operator+=(const MyMatrix& _Value)
	{

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				MatrixField[i][j] += _Value.MatrixField[i][j];
			}

		}

		return *this;
	}
	//행렬의 뺄셈
	MyMatrix operator-(const MyMatrix& _Value) const
	{
		MyMatrix ReturnMat;


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ReturnMat.MatrixField[i][j] = MatrixField[i][j] - _Value.MatrixField[i][j];
			}

		}

		return ReturnMat;
	}

	MyMatrix operator-=(const MyMatrix& _Value)
	{

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				MatrixField[i][j] -= _Value.MatrixField[i][j];
			}

		}

		return *this;
	}

	//행렬의 스칼라 곱
	MyMatrix operator*(const float& _Value) const
	{
		MyMatrix ReturnMat;


		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ReturnMat.MatrixField[i][j] = MatrixField[i][j] * _Value;
			}

		}

		return ReturnMat;
	}

	MyMatrix operator*=(const float& _Value)
	{

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				MatrixField[i][j] *= _Value;
			}

		}

		return *this;
	}

	//행렬의 곱셈
	MyMatrix operator*(const MyMatrix& _Value) const
	{
		MyMatrix ReturnMat;

		unsigned int row, column, row_offset;

		for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
			for (column = 0; column < 4; ++column)
				ReturnMat.MatrixArr[row_offset + column] =
				(MatrixArr[row_offset + 0] * _Value.MatrixArr[column + 0]) +
				(MatrixArr[row_offset + 1] * _Value.MatrixArr[column + 4]) +
				(MatrixArr[row_offset + 2] * _Value.MatrixArr[column + 8]) +
				(MatrixArr[row_offset + 3] * _Value.MatrixArr[column + 12]);

		return ReturnMat;
	}

	MyMatrix operator*=(const MyMatrix& _Value)
	{
		MyMatrix ReturnMat;
		unsigned int row, column, row_offset;

		for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
			for (column = 0; column < 4; ++column)
				ReturnMat.MatrixArr[row_offset + column] =
				(MatrixArr[row_offset + 0] * _Value.MatrixArr[column + 0]) +
				(MatrixArr[row_offset + 1] * _Value.MatrixArr[column + 4]) +
				(MatrixArr[row_offset + 2] * _Value.MatrixArr[column + 8]) +
				(MatrixArr[row_offset + 3] * _Value.MatrixArr[column + 12]);

		*this = ReturnMat;
		return *this;
	}


};