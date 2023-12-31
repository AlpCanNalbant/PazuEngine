// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------

#pragma once
#include <XMath/DirectXMath.h>

namespace Pazu::Math
{
	struct Plane;
	struct Quaternion;
	struct Vector3;
	struct Vector4;

	struct Matrix : public DirectX::XMFLOAT4X4
	{
		Matrix() noexcept;
		constexpr Matrix(float m00, float m01, float m02, float m03,
						 float m10, float m11, float m12, float m13,
						 float m20, float m21, float m22, float m23,
						 float m30, float m31, float m32, float m33) noexcept;
		explicit Matrix(const Vector3 &r0, const Vector3 &r1, const Vector3 &r2) noexcept;
		explicit Matrix(const Vector4 &r0, const Vector4 &r1, const Vector4 &r2, const Vector4 &r3) noexcept;
		Matrix(const XMFLOAT4X4 &M) noexcept;
		Matrix(const DirectX::XMFLOAT3X3 &M) noexcept;
		Matrix(const DirectX::XMFLOAT4X3 &M) noexcept;
		explicit Matrix(_In_reads_(16) const float *pArray) noexcept;
		Matrix(DirectX::CXMMATRIX M) noexcept;
		Matrix(const Matrix &) = default;
		Matrix &operator=(const Matrix &) = default;
		Matrix(Matrix &&) = default;
		Matrix &operator=(Matrix &&) = default;
		operator DirectX::XMMATRIX() const noexcept;
		bool operator==(const Matrix &M) const noexcept;
		bool operator!=(const Matrix &M) const noexcept;
		Matrix &operator=(const DirectX::XMFLOAT3X3 &M) noexcept;
		Matrix &operator=(const DirectX::XMFLOAT4X3 &M) noexcept;
		Matrix &operator+=(const Matrix &M) noexcept;
		Matrix &operator-=(const Matrix &M) noexcept;
		Matrix &operator*=(const Matrix &M) noexcept;
		Matrix &operator*=(float S) noexcept;
		Matrix &operator/=(float S) noexcept;
		Matrix &operator/=(const Matrix &M) noexcept;
		Matrix operator+() const noexcept;
		Matrix operator-() const noexcept;
		Vector3 Up() const noexcept;
		void Up(const Vector3 &v) noexcept;
		Vector3 Down() const noexcept;
		void Down(const Vector3 &v) noexcept;
		Vector3 Right() const noexcept;
		void Right(const Vector3 &v) noexcept;
		Vector3 Left() const noexcept;
		void Left(const Vector3 &v) noexcept;
		Vector3 Forward() const noexcept;
		void Forward(const Vector3 &v) noexcept;
		Vector3 Backward() const noexcept;
		void Backward(const Vector3 &v) noexcept;
		Vector3 Translation() const noexcept;
		void Translation(const Vector3 &v) noexcept;
		bool Decompose(Vector3 &scale, Quaternion &rotation, Vector3 &translation) noexcept;
		Matrix Transpose() const noexcept;
		void Transpose(Matrix &result) const noexcept;
		Matrix Invert() const noexcept;
		void Invert(Matrix &result) const noexcept;
		float Determinant() const noexcept;
		static Matrix CreateBillboard(
			const Vector3 &object, const Vector3 &cameraPosition, const Vector3 &cameraUp, _In_opt_ const Vector3 *cameraForward = nullptr) noexcept;
		static Matrix CreateConstrainedBillboard(
			const Vector3 &object, const Vector3 &cameraPosition, const Vector3 &rotateAxis,
			_In_opt_ const Vector3 *cameraForward = nullptr, _In_opt_ const Vector3 *objectForward = nullptr) noexcept;
		static Matrix CreateTranslation(const Vector3 &position) noexcept;
		static Matrix CreateTranslation(float x, float y, float z) noexcept;
		static Matrix CreateScale(const Vector3 &scales) noexcept;
		static Matrix CreateScale(float xs, float ys, float zs) noexcept;
		static Matrix CreateScale(float scale) noexcept;
		static Matrix CreateRotationX(float radians) noexcept;
		static Matrix CreateRotationY(float radians) noexcept;
		static Matrix CreateRotationZ(float radians) noexcept;
		static Matrix CreateFromAxisAngle(const Vector3 &axis, float angle) noexcept;
		static Matrix CreatePerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane) noexcept;
		static Matrix CreatePerspective(float width, float height, float nearPlane, float farPlane) noexcept;
		static Matrix CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float nearPlane, float farPlane) noexcept;
		static Matrix CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane) noexcept;
		static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNearPlane, float zFarPlane) noexcept;
		static Matrix CreateLookAt(const Vector3 &position, const Vector3 &target, const Vector3 &up) noexcept;
		static Matrix CreateWorld(const Vector3 &position, const Vector3 &forward, const Vector3 &up) noexcept;
		static Matrix CreateFromQuaternion(const Quaternion &quat) noexcept;
		static Matrix CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept;
		static Matrix CreateShadow(const Vector3 &lightDir, const Plane &plane) noexcept;
		static Matrix CreateReflection(const Plane &plane) noexcept;
		static void Lerp(const Matrix &M1, const Matrix &M2, float t, Matrix &result) noexcept;
		static Matrix Lerp(const Matrix &M1, const Matrix &M2, float t) noexcept;
		static void Transform(const Matrix &M, const Quaternion &rotation, Matrix &result) noexcept;
		static Matrix Transform(const Matrix &M, const Quaternion &rotation) noexcept;

		static const Matrix
			Identity;
	};

	Matrix operator+(const Matrix &M1, const Matrix &M2) noexcept;
	Matrix operator-(const Matrix &M1, const Matrix &M2) noexcept;
	Matrix operator*(const Matrix &M1, const Matrix &M2) noexcept;
	Matrix operator*(const Matrix &M, float S) noexcept;
	Matrix operator/(const Matrix &M, float S) noexcept;
	Matrix operator/(const Matrix &M1, const Matrix &M2) noexcept;
	Matrix operator*(float S, const Matrix &M) noexcept;

} // namespace Pazu
#include "Matrix.inl"

namespace std
{
	template <typename T>
	struct less;
	template <>
	struct less<Pazu::Math::Matrix>
	{
		bool operator()(const Pazu::Math::Matrix &M1, const Pazu::Math::Matrix &M2) const noexcept;
	};
} // namespace std
