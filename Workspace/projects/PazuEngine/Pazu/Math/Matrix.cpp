//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
#include <functional>
#include <memory.h>
#include "Plane.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix.h"

namespace Pazu
{
	Matrix::Matrix()
			: XMFLOAT4X4(1.f, 0, 0, 0,
									 0, 1.f, 0, 0,
									 0, 0, 1.f, 0,
									 0, 0, 0, 1.f) {}

	Matrix::Matrix(const Vector3 &r0, const Vector3 &r1, const Vector3 &r2)
			: XMFLOAT4X4(r0.x, r0.y, r0.z, 0,
									 r1.x, r1.y, r1.z, 0,
									 r2.x, r2.y, r2.z, 0,
									 0, 0, 0, 1.f) {}

	Matrix::Matrix(const Vector4 &r0, const Vector4 &r1, const Vector4 &r2, const Vector4 &r3)
			: XMFLOAT4X4(r0.x, r0.y, r0.z, r0.w,
									 r1.x, r1.y, r1.z, r1.w,
									 r2.x, r2.y, r2.z, r2.w,
									 r3.x, r3.y, r3.z, r3.w) {}

	Matrix::Matrix(const XMFLOAT4X4 &M)
	{
		memcpy_s(this, sizeof(float) * 16, &M, sizeof(XMFLOAT4X4));
	}

	Matrix::Matrix(const DirectX::XMFLOAT3X3 &M)
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = 0.f;
		_42 = 0.f;
		_43 = 0.f;
		_44 = 1.f;
	}

	Matrix::Matrix(const DirectX::XMFLOAT4X3 &M)
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = M._41;
		_42 = M._42;
		_43 = M._43;
		_44 = 1.f;
	}

	Matrix::Matrix(_In_reads_(16) const float *pArray)
			: XMFLOAT4X4(pArray) {}

	Matrix::Matrix(DirectX::CXMMATRIX M)
	{
		XMStoreFloat4x4(this, M);
	}

	Matrix::operator DirectX::XMMATRIX() const
	{
		return XMLoadFloat4x4(this);
	}

	bool Matrix::operator==(const Matrix &M) const
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		return (XMVector4Equal(x1, y1) && XMVector4Equal(x2, y2) && XMVector4Equal(x3, y3) && XMVector4Equal(x4, y4)) != 0;
	}

	bool Matrix::operator!=(const Matrix &M) const
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		return (XMVector4NotEqual(x1, y1) || XMVector4NotEqual(x2, y2) || XMVector4NotEqual(x3, y3) || XMVector4NotEqual(x4, y4)) != 0;
	}

	Matrix &Matrix::operator=(const DirectX::XMFLOAT3X3 &M)
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = 0.f;
		_42 = 0.f;
		_43 = 0.f;
		_44 = 1.f;
		return *this;
	}

	Matrix &Matrix::operator=(const DirectX::XMFLOAT4X3 &M)
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = M._41;
		_42 = M._42;
		_43 = M._43;
		_44 = 1.f;
		return *this;
	}

	Matrix &Matrix::operator+=(const Matrix &M)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		x1 = XMVectorAdd(x1, y1);
		x2 = XMVectorAdd(x2, y2);
		x3 = XMVectorAdd(x3, y3);
		x4 = XMVectorAdd(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_41), x4);
		return *this;
	}

	Matrix &Matrix::operator-=(const Matrix &M)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		x1 = XMVectorSubtract(x1, y1);
		x2 = XMVectorSubtract(x2, y2);
		x3 = XMVectorSubtract(x3, y3);
		x4 = XMVectorSubtract(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_41), x4);
		return *this;
	}

	Matrix &Matrix::operator*=(const Matrix &M)
	{
		using namespace DirectX;
		XMMATRIX M1 = XMLoadFloat4x4(this);
		XMMATRIX M2 = XMLoadFloat4x4(&M);
		XMMATRIX X = XMMatrixMultiply(M1, M2);
		XMStoreFloat4x4(this, X);
		return *this;
	}

	Matrix &Matrix::operator*=(float S)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_41), x4);
		return *this;
	}

	Matrix &Matrix::operator/=(float S)
	{
		using namespace DirectX;
		assert(S != 0.f);
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		float rs = 1.f / S;

		x1 = XMVectorScale(x1, rs);
		x2 = XMVectorScale(x2, rs);
		x3 = XMVectorScale(x3, rs);
		x4 = XMVectorScale(x4, rs);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_41), x4);
		return *this;
	}

	Matrix &Matrix::operator/=(const Matrix &M)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		x1 = XMVectorDivide(x1, y1);
		x2 = XMVectorDivide(x2, y2);
		x3 = XMVectorDivide(x3, y3);
		x4 = XMVectorDivide(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&_41), x4);
		return *this;
	}

	Matrix Matrix::operator+() const
	{
		return *this;
	}

	Matrix Matrix::operator-() const
	{
		using namespace DirectX;
		XMVECTOR v1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_11));
		XMVECTOR v2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_21));
		XMVECTOR v3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_31));
		XMVECTOR v4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&_41));

		v1 = XMVectorNegate(v1);
		v2 = XMVectorNegate(v2);
		v3 = XMVectorNegate(v3);
		v4 = XMVectorNegate(v4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), v1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), v2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), v3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), v4);
		return R;
	}

	Vector3 Matrix::Up() const
	{
		return Vector3(_21, _22, _23);
	}

	void Matrix::Up(const Vector3 &v)
	{
		_21 = v.x;
		_22 = v.y;
		_23 = v.z;
	}

	Vector3 Matrix::Down() const
	{
		return Vector3(-_21, -_22, -_23);
	}

	void Matrix::Down(const Vector3 &v)
	{
		_21 = -v.x;
		_22 = -v.y;
		_23 = -v.z;
	}

	Vector3 Matrix::Right() const
	{
		return Vector3(_11, _12, _13);
	}

	void Matrix::Right(const Vector3 &v)
	{
		_11 = v.x;
		_12 = v.y;
		_13 = v.z;
	}

	Vector3 Matrix::Left() const
	{
		return Vector3(-_11, -_12, -_13);
	}

	void Matrix::Left(const Vector3 &v)
	{
		_11 = -v.x;
		_12 = -v.y;
		_13 = -v.z;
	}

	Vector3 Matrix::Forward() const
	{
		return Vector3(-_31, -_32, -_33);
	}

	void Matrix::Forward(const Vector3 &v)
	{
		_31 = -v.x;
		_32 = -v.y;
		_33 = -v.z;
	}

	Vector3 Matrix::Backward() const
	{
		return Vector3(_31, _32, _33);
	}

	void Matrix::Backward(const Vector3 &v)
	{
		_31 = v.x;
		_32 = v.y;
		_33 = v.z;
	}

	Vector3 Matrix::Translation() const
	{
		return Vector3(_41, _42, _43);
	}

	void Matrix::Translation(const Vector3 &v)
	{
		_41 = v.x;
		_42 = v.y;
		_43 = v.z;
	}

	bool Matrix::Decompose(Vector3 &scale, Quaternion &rotation, Vector3 &translation)
	{
		using namespace DirectX;

		XMVECTOR s, r, t;

		if (!XMMatrixDecompose(&s, &r, &t, *this))
			return false;

		XMStoreFloat3(&scale, s);
		XMStoreFloat4(&rotation, r);
		XMStoreFloat3(&translation, t);

		return true;
	}

	Matrix Matrix::Transpose() const
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(this);
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranspose(M));
		return R;
	}

	void Matrix::Transpose(Matrix &result) const
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(this);
		XMStoreFloat4x4(&result, XMMatrixTranspose(M));
	}

	Matrix Matrix::Invert() const
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(this);
		Matrix R;
		XMVECTOR det;
		XMStoreFloat4x4(&R, XMMatrixInverse(&det, M));
		return R;
	}

	void Matrix::Invert(Matrix &result) const
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(this);
		XMVECTOR det;
		XMStoreFloat4x4(&result, XMMatrixInverse(&det, M));
	}

	float Matrix::Determinant() const
	{
		using namespace DirectX;
		XMMATRIX M = XMLoadFloat4x4(this);
		return XMVectorGetX(XMMatrixDeterminant(M));
	}

	_Use_decl_annotations_ Matrix Matrix::CreateBillboard(
			const Vector3 &object,
			const Vector3 &cameraPosition,
			const Vector3 &cameraUp,
			const Vector3 *cameraForward)
	{
		using namespace DirectX;
		XMVECTOR O = XMLoadFloat3(&object);
		XMVECTOR C = XMLoadFloat3(&cameraPosition);
		XMVECTOR Z = XMVectorSubtract(O, C);

		XMVECTOR N = XMVector3LengthSq(Z);
		if (XMVector3Less(N, g_XMEpsilon))
		{
			if (cameraForward)
			{
				XMVECTOR F = XMLoadFloat3(cameraForward);
				Z = XMVectorNegate(F);
			}
			else
				Z = g_XMNegIdentityR2;
		}
		else
		{
			Z = XMVector3Normalize(Z);
		}

		XMVECTOR up = XMLoadFloat3(&cameraUp);
		XMVECTOR X = XMVector3Cross(up, Z);
		X = XMVector3Normalize(X);

		XMVECTOR Y = XMVector3Cross(Z, X);

		XMMATRIX M;
		M.r[0] = X;
		M.r[1] = Y;
		M.r[2] = Z;
		M.r[3] = XMVectorSetW(O, 1.f);

		Matrix R;
		XMStoreFloat4x4(&R, M);
		return R;
	}

	_Use_decl_annotations_ Matrix Matrix::CreateConstrainedBillboard(
			const Vector3 &object,
			const Vector3 &cameraPosition,
			const Vector3 &rotateAxis,
			const Vector3 *cameraForward,
			const Vector3 *objectForward)
	{
		using namespace DirectX;

		static const XMVECTORF32 s_minAngle = {{{0.99825467075f, 0.99825467075f, 0.99825467075f, 0.99825467075f}}}; // 1.0 - XMConvertToRadians( 0.1f );

		XMVECTOR O = XMLoadFloat3(&object);
		XMVECTOR C = XMLoadFloat3(&cameraPosition);
		XMVECTOR faceDir = XMVectorSubtract(O, C);

		XMVECTOR N = XMVector3LengthSq(faceDir);
		if (XMVector3Less(N, g_XMEpsilon))
		{
			if (cameraForward)
			{
				XMVECTOR F = XMLoadFloat3(cameraForward);
				faceDir = XMVectorNegate(F);
			}
			else
				faceDir = g_XMNegIdentityR2;
		}
		else
		{
			faceDir = XMVector3Normalize(faceDir);
		}

		XMVECTOR Y = XMLoadFloat3(&rotateAxis);
		XMVECTOR X, Z;

		XMVECTOR dot = XMVectorAbs(XMVector3Dot(Y, faceDir));
		if (XMVector3Greater(dot, s_minAngle))
		{
			if (objectForward)
			{
				Z = XMLoadFloat3(objectForward);
				dot = XMVectorAbs(XMVector3Dot(Y, Z));
				if (XMVector3Greater(dot, s_minAngle))
				{
					dot = XMVectorAbs(XMVector3Dot(Y, g_XMNegIdentityR2));
					Z = (XMVector3Greater(dot, s_minAngle)) ? g_XMIdentityR0 : g_XMNegIdentityR2;
				}
			}
			else
			{
				dot = XMVectorAbs(XMVector3Dot(Y, g_XMNegIdentityR2));
				Z = (XMVector3Greater(dot, s_minAngle)) ? g_XMIdentityR0 : g_XMNegIdentityR2;
			}

			X = XMVector3Cross(Y, Z);
			X = XMVector3Normalize(X);

			Z = XMVector3Cross(X, Y);
			Z = XMVector3Normalize(Z);
		}
		else
		{
			X = XMVector3Cross(Y, faceDir);
			X = XMVector3Normalize(X);

			Z = XMVector3Cross(X, Y);
			Z = XMVector3Normalize(Z);
		}

		XMMATRIX M;
		M.r[0] = X;
		M.r[1] = Y;
		M.r[2] = Z;
		M.r[3] = XMVectorSetW(O, 1.f);

		Matrix R;
		XMStoreFloat4x4(&R, M);
		return R;
	}

	Matrix Matrix::CreateTranslation(const Vector3 &position)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranslation(position.x, position.y, position.z));
		return R;
	}

	Matrix Matrix::CreateTranslation(float x, float y, float z)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranslation(x, y, z));
		return R;
	}

	Matrix Matrix::CreateScale(const Vector3 &scales)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(scales.x, scales.y, scales.z));
		return R;
	}

	Matrix Matrix::CreateScale(float xs, float ys, float zs)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(xs, ys, zs));
		return R;
	}

	Matrix Matrix::CreateScale(float scale)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(scale, scale, scale));
		return R;
	}

	Matrix Matrix::CreateRotationX(float radians)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationX(radians));
		return R;
	}

	Matrix Matrix::CreateRotationY(float radians)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationY(radians));
		return R;
	}

	Matrix Matrix::CreateRotationZ(float radians)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationZ(radians));
		return R;
	}

	Matrix Matrix::CreateFromAxisAngle(const Vector3 &axis, float angle)
	{
		using namespace DirectX;
		Matrix R;
		XMVECTOR a = XMLoadFloat3(&axis);
		XMStoreFloat4x4(&R, XMMatrixRotationAxis(a, angle));
		return R;
	}

	Matrix Matrix::CreatePerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixPerspectiveFovRH(fov, aspectRatio, nearPlane, farPlane));
		return R;
	}

	Matrix Matrix::CreatePerspective(float width, float height, float nearPlane, float farPlane)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixPerspectiveRH(width, height, nearPlane, farPlane));
		return R;
	}

	Matrix Matrix::CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixPerspectiveOffCenterRH(left, right, bottom, top, nearPlane, farPlane));
		return R;
	}

	Matrix Matrix::CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixOrthographicRH(width, height, zNearPlane, zFarPlane));
		return R;
	}

	Matrix Matrix::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNearPlane, float zFarPlane)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixOrthographicOffCenterRH(left, right, bottom, top, zNearPlane, zFarPlane));
		return R;
	}

	Matrix Matrix::CreateLookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up)
	{
		using namespace DirectX;
		Matrix R;
		XMVECTOR eyev = XMLoadFloat3(&eye);
		XMVECTOR targetv = XMLoadFloat3(&target);
		XMVECTOR upv = XMLoadFloat3(&up);
		XMStoreFloat4x4(&R, XMMatrixLookAtRH(eyev, targetv, upv));
		return R;
	}

	Matrix Matrix::CreateWorld(const Vector3 &position, const Vector3 &forward, const Vector3 &up)
	{
		using namespace DirectX;
		XMVECTOR zaxis = XMVector3Normalize(XMVectorNegate(XMLoadFloat3(&forward)));
		XMVECTOR yaxis = XMLoadFloat3(&up);
		XMVECTOR xaxis = XMVector3Normalize(XMVector3Cross(yaxis, zaxis));
		yaxis = XMVector3Cross(zaxis, xaxis);

		Matrix R;
		XMStoreFloat3(reinterpret_cast<XMFLOAT3 *>(&R._11), xaxis);
		XMStoreFloat3(reinterpret_cast<XMFLOAT3 *>(&R._21), yaxis);
		XMStoreFloat3(reinterpret_cast<XMFLOAT3 *>(&R._31), zaxis);
		R._14 = R._24 = R._34 = 0.f;
		R._41 = position.x;
		R._42 = position.y;
		R._43 = position.z;
		R._44 = 1.f;
		return R;
	}

	Matrix Matrix::CreateFromQuaternion(const Quaternion &rotation)
	{
		using namespace DirectX;
		Matrix R;
		XMVECTOR quatv = XMLoadFloat4(&rotation);
		XMStoreFloat4x4(&R, XMMatrixRotationQuaternion(quatv));
		return R;
	}

	Matrix Matrix::CreateFromYawPitchRoll(float yaw, float pitch, float roll)
	{
		using namespace DirectX;
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationRollPitchYaw(pitch, yaw, roll));
		return R;
	}

	Matrix Matrix::CreateShadow(const Vector3 &lightDir, const Plane &plane)
	{
		using namespace DirectX;
		Matrix R;
		XMVECTOR light = XMLoadFloat3(&lightDir);
		XMVECTOR planev = XMLoadFloat4(&plane);
		XMStoreFloat4x4(&R, XMMatrixShadow(planev, light));
		return R;
	}

	Matrix Matrix::CreateReflection(const Plane &plane)
	{
		using namespace DirectX;
		Matrix R;
		XMVECTOR planev = XMLoadFloat4(&plane);
		XMStoreFloat4x4(&R, XMMatrixReflect(planev));
		return R;
	}

	void Matrix::Lerp(const Matrix &M1, const Matrix &M2, float t, Matrix &result)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._41));

		x1 = XMVectorLerp(x1, y1, t);
		x2 = XMVectorLerp(x2, y2, t);
		x3 = XMVectorLerp(x3, y3, t);
		x4 = XMVectorLerp(x4, y4, t);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._41), x4);
	}

	Matrix Matrix::Lerp(const Matrix &M1, const Matrix &M2, float t)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._41));

		x1 = XMVectorLerp(x1, y1, t);
		x2 = XMVectorLerp(x2, y2, t);
		x3 = XMVectorLerp(x3, y3, t);
		x4 = XMVectorLerp(x4, y4, t);

		Matrix result;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&result._41), x4);
		return result;
	}

	void Matrix::Transform(const Matrix &M, const Quaternion &rotation, Matrix &result)
	{
		using namespace DirectX;
		XMVECTOR quatv = XMLoadFloat4(&rotation);

		XMMATRIX M0 = XMLoadFloat4x4(&M);
		XMMATRIX M1 = XMMatrixRotationQuaternion(quatv);

		XMStoreFloat4x4(&result, XMMatrixMultiply(M0, M1));
	}

	Matrix Matrix::Transform(const Matrix &M, const Quaternion &rotation)
	{
		using namespace DirectX;
		XMVECTOR quatv = XMLoadFloat4(&rotation);

		XMMATRIX M0 = XMLoadFloat4x4(&M);
		XMMATRIX M1 = XMMatrixRotationQuaternion(quatv);

		Matrix result;
		XMStoreFloat4x4(&result, XMMatrixMultiply(M0, M1));
		return result;
	}

	const Matrix
			Matrix::Identity(1.f, 0.f, 0.f, 0.f,
											 0.f, 1.f, 0.f, 0.f,
											 0.f, 0.f, 1.f, 0.f,
											 0.f, 0.f, 0.f, 1.f);

	Matrix operator+(const Matrix &M1, const Matrix &M2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._41));

		x1 = XMVectorAdd(x1, y1);
		x2 = XMVectorAdd(x2, y2);
		x3 = XMVectorAdd(x3, y3);
		x4 = XMVectorAdd(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}

	Matrix operator-(const Matrix &M1, const Matrix &M2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._41));

		x1 = XMVectorSubtract(x1, y1);
		x2 = XMVectorSubtract(x2, y2);
		x3 = XMVectorSubtract(x3, y3);
		x4 = XMVectorSubtract(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}

	Matrix operator*(const Matrix &M1, const Matrix &M2)
	{
		using namespace DirectX;
		XMMATRIX m1 = XMLoadFloat4x4(&M1);
		XMMATRIX m2 = XMLoadFloat4x4(&M2);
		XMMATRIX X = XMMatrixMultiply(m1, m2);

		Matrix R;
		XMStoreFloat4x4(&R, X);
		return R;
	}

	Matrix operator*(const Matrix &M, float S)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}

	Matrix operator/(const Matrix &M, float S)
	{
		using namespace DirectX;
		assert(S != 0.f);

		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		float rs = 1.f / S;

		x1 = XMVectorScale(x1, rs);
		x2 = XMVectorScale(x2, rs);
		x3 = XMVectorScale(x3, rs);
		x4 = XMVectorScale(x4, rs);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}

	Matrix operator/(const Matrix &M1, const Matrix &M2)
	{
		using namespace DirectX;
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M1._41));

		XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._11));
		XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._21));
		XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._31));
		XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M2._41));

		x1 = XMVectorDivide(x1, y1);
		x2 = XMVectorDivide(x2, y2);
		x3 = XMVectorDivide(x3, y3);
		x4 = XMVectorDivide(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}

	Matrix operator*(float S, const Matrix &M)
	{
		using namespace DirectX;

		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4 *>(&M._41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4 *>(&R._41), x4);
		return R;
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Matrix>::operator()(const Pazu::Matrix &M1, const Pazu::Matrix &M2) const
	{
		if (M1._11 != M2._11)
			return M1._11 < M2._11;
		if (M1._12 != M2._12)
			return M1._12 < M2._12;
		if (M1._13 != M2._13)
			return M1._13 < M2._13;
		if (M1._14 != M2._14)
			return M1._14 < M2._14;
		if (M1._21 != M2._21)
			return M1._21 < M2._21;
		if (M1._22 != M2._22)
			return M1._22 < M2._22;
		if (M1._23 != M2._23)
			return M1._23 < M2._23;
		if (M1._24 != M2._24)
			return M1._24 < M2._24;
		if (M1._31 != M2._31)
			return M1._31 < M2._31;
		if (M1._32 != M2._32)
			return M1._32 < M2._32;
		if (M1._33 != M2._33)
			return M1._33 < M2._33;
		if (M1._34 != M2._34)
			return M1._34 < M2._34;
		if (M1._41 != M2._41)
			return M1._41 < M2._41;
		if (M1._42 != M2._42)
			return M1._42 < M2._42;
		if (M1._43 != M2._43)
			return M1._43 < M2._43;
		if (M1._44 != M2._44)
			return M1._44 < M2._44;
		return false;
	}
} // namespace std
