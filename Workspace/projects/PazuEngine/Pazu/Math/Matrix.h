//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------
#pragma once
#include <XMath/DirectXMath.h>

namespace Pazu
{
	struct Plane;
	struct Quaternion;
	struct Vector3;
	struct Vector4;

	struct Matrix : public DirectX::XMFLOAT4X4
	{
		Matrix();
		constexpr Matrix(float m00, float m01, float m02, float m03,
										 float m10, float m11, float m12, float m13,
										 float m20, float m21, float m22, float m23,
										 float m30, float m31, float m32, float m33);
		explicit Matrix(const Vector3 &r0, const Vector3 &r1, const Vector3 &r2);
		explicit Matrix(const Vector4 &r0, const Vector4 &r1, const Vector4 &r2, const Vector4 &r3);
		Matrix(const XMFLOAT4X4 &M);
		Matrix(const DirectX::XMFLOAT3X3 &M);
		Matrix(const DirectX::XMFLOAT4X3 &M);
		explicit Matrix(_In_reads_(16) const float *pArray);
		Matrix(DirectX::CXMMATRIX M);
		Matrix(const Matrix &) = default;
		Matrix &operator=(const Matrix &) = default;
		Matrix(Matrix &&) = default;
		Matrix &operator=(Matrix &&) = default;
		operator DirectX::XMMATRIX() const;
		bool operator==(const Matrix &M) const;
		bool operator!=(const Matrix &M) const;
		Matrix &operator=(const DirectX::XMFLOAT3X3 &M);
		Matrix &operator=(const DirectX::XMFLOAT4X3 &M);
		Matrix &operator+=(const Matrix &M);
		Matrix &operator-=(const Matrix &M);
		Matrix &operator*=(const Matrix &M);
		Matrix &operator*=(float S);
		Matrix &operator/=(float S);
		Matrix &operator/=(const Matrix &M);
		Matrix operator+() const;
		Matrix operator-() const;
		Vector3 Up() const;
		void Up(const Vector3 &v);
		Vector3 Down() const;
		void Down(const Vector3 &v);
		Vector3 Right() const;
		void Right(const Vector3 &v);
		Vector3 Left() const;
		void Left(const Vector3 &v);
		Vector3 Forward() const;
		void Forward(const Vector3 &v);
		Vector3 Backward() const;
		void Backward(const Vector3 &v);
		Vector3 Translation() const;
		void Translation(const Vector3 &v);
		bool Decompose(Vector3 &scale, Quaternion &rotation, Vector3 &translation);
		Matrix Transpose() const;
		void Transpose(Matrix &result) const;
		Matrix Invert() const;
		void Invert(Matrix &result) const;
		float Determinant() const;
		static Matrix CreateBillboard(
				const Vector3 &object, const Vector3 &cameraPosition, const Vector3 &cameraUp, _In_opt_ const Vector3 *cameraForward = nullptr);
		static Matrix CreateConstrainedBillboard(
				const Vector3 &object, const Vector3 &cameraPosition, const Vector3 &rotateAxis,
				_In_opt_ const Vector3 *cameraForward = nullptr, _In_opt_ const Vector3 *objectForward = nullptr);
		static Matrix CreateTranslation(const Vector3 &position);
		static Matrix CreateTranslation(float x, float y, float z);
		static Matrix CreateScale(const Vector3 &scales);
		static Matrix CreateScale(float xs, float ys, float zs);
		static Matrix CreateScale(float scale);
		static Matrix CreateRotationX(float radians);
		static Matrix CreateRotationY(float radians);
		static Matrix CreateRotationZ(float radians);
		static Matrix CreateFromAxisAngle(const Vector3 &axis, float angle);
		static Matrix CreatePerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane);
		static Matrix CreatePerspective(float width, float height, float nearPlane, float farPlane);
		static Matrix CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane);
		static Matrix CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane);
		static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNearPlane, float zFarPlane);
		static Matrix CreateLookAt(const Vector3 &position, const Vector3 &target, const Vector3 &up);
		static Matrix CreateWorld(const Vector3 &position, const Vector3 &forward, const Vector3 &up);
		static Matrix CreateFromQuaternion(const Quaternion &quat);
		static Matrix CreateFromYawPitchRoll(float yaw, float pitch, float roll);
		static Matrix CreateShadow(const Vector3 &lightDir, const Plane &plane);
		static Matrix CreateReflection(const Plane &plane);
		static void Lerp(const Matrix &M1, const Matrix &M2, float t, Matrix &result);
		static Matrix Lerp(const Matrix &M1, const Matrix &M2, float t);
		static void Transform(const Matrix &M, const Quaternion &rotation, Matrix &result);
		static Matrix Transform(const Matrix &M, const Quaternion &rotation);

		static const Matrix
				Identity;
	};

	Matrix operator+(const Matrix &M1, const Matrix &M2);
	Matrix operator-(const Matrix &M1, const Matrix &M2);
	Matrix operator*(const Matrix &M1, const Matrix &M2);
	Matrix operator*(const Matrix &M, float S);
	Matrix operator/(const Matrix &M, float S);
	Matrix operator/(const Matrix &M1, const Matrix &M2);
	Matrix operator*(float S, const Matrix &M);

} // namespace Pazu
#include "Matrix.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Matrix>
	{
		bool operator()(const Pazu::Matrix &M1, const Pazu::Matrix &M2) const;
	};
} // namespace std
