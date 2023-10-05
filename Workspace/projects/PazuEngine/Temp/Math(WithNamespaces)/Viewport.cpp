// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

//-------------------------------------------------------------------------------------
// SimpleMath.inl -- Simplified C++ Math wrapper for DirectXMath
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
// http://go.microsoft.com/fwlink/?LinkID=615561
//-------------------------------------------------------------------------------------

#include <functional>
#include <XMath/DirectXMath.h>
#include "Vector3.h"
#include "Matrix.h"
#include "Viewport.h"

namespace Pazu::Math
{
	bool Viewport::operator==(const Viewport &vp) const noexcept
	{
		return (x == vp.x && y == vp.y && width == vp.width && height == vp.height && minDepth == vp.minDepth && maxDepth == vp.maxDepth);
	}

	bool Viewport::operator!=(const Viewport &vp) const noexcept
	{
		return (x != vp.x || y != vp.y || width != vp.width || height != vp.height || minDepth != vp.minDepth || maxDepth != vp.maxDepth);
	}

	float Viewport::AspectRatio() const noexcept
	{
		if (width == 0.f || height == 0.f)
			return 0.f;

		return (width / height);
	}

	Vector3 Viewport::Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v = XMLoadFloat3(&p);
		XMMATRIX projection = XMLoadFloat4x4(&proj);
		v = XMVector3Project(v, x, y, width, height, minDepth, maxDepth, projection, view, world);
		Vector3 result;
		XMStoreFloat3(&result, v);
		return result;
	}

	void Viewport::Project(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v = XMLoadFloat3(&p);
		XMMATRIX projection = XMLoadFloat4x4(&proj);
		v = XMVector3Project(v, x, y, width, height, minDepth, maxDepth, projection, view, world);
		XMStoreFloat3(&result, v);
	}

	Vector3 Viewport::Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v = XMLoadFloat3(&p);
		XMMATRIX projection = XMLoadFloat4x4(&proj);
		v = XMVector3Unproject(v, x, y, width, height, minDepth, maxDepth, projection, view, world);
		Vector3 result;
		XMStoreFloat3(&result, v);
		return result;
	}

	void Viewport::Unproject(const Vector3 &p, const Matrix &proj, const Matrix &view, const Matrix &world, Vector3 &result) const noexcept
	{
		using namespace DirectX;
		XMVECTOR v = XMLoadFloat3(&p);
		XMMATRIX projection = XMLoadFloat4x4(&proj);
		v = XMVector3Unproject(v, x, y, width, height, minDepth, maxDepth, projection, view, world);
		XMStoreFloat3(&result, v);
	}
} // namespace Pazu

namespace std
{
	bool less<Pazu::Math::Viewport>::operator()(const Pazu::Math::Viewport &vp1, const Pazu::Math::Viewport &vp2) const noexcept
	{
		if (vp1.x != vp2.x)
			return (vp1.x < vp2.x);
		if (vp1.y != vp2.y)
			return (vp1.y < vp2.y);

		if (vp1.width != vp2.width)
			return (vp1.width < vp2.width);
		if (vp1.height != vp2.height)
			return (vp1.height < vp2.height);

		if (vp1.minDepth != vp2.minDepth)
			return (vp1.minDepth < vp2.minDepth);
		if (vp1.maxDepth != vp2.maxDepth)
			return (vp1.maxDepth < vp2.maxDepth);
		return false;
	}
} // namespace std
