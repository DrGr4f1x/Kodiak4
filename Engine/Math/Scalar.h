//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Developed by Minigraph
//
// Author:  James Stanard 
//

#pragma once

namespace Math
{
class Scalar
{
public:
	__forceinline Scalar() {}
	__forceinline Scalar(const Scalar& s) { m_vec = s; }
	__forceinline Scalar(float f) { m_vec = XMVectorReplicate(f); }
	__forceinline explicit Scalar(FXMVECTOR vec) { m_vec = vec; }
	__forceinline explicit Scalar(EZeroTag) { m_vec = SplatZero(); }
	__forceinline explicit Scalar(EIdentityTag) { m_vec = SplatOne(); }

	__forceinline operator XMVECTOR() const { return m_vec; }
	__forceinline operator float() const { return XMVectorGetX(m_vec); }

private:
	XMVECTOR m_vec;
};

__forceinline Scalar operator-(Scalar s) { return Scalar(XMVectorNegate(s)); }
__forceinline Scalar operator+(Scalar s1, Scalar s2) { return Scalar(XMVectorAdd(s1, s2)); }
__forceinline Scalar operator-(Scalar s1, Scalar s2) { return Scalar(XMVectorSubtract(s1, s2)); }
__forceinline Scalar operator*(Scalar s1, Scalar s2) { return Scalar(XMVectorMultiply(s1, s2)); }
__forceinline Scalar operator/(Scalar s1, Scalar s2) { return Scalar(XMVectorDivide(s1, s2)); }
__forceinline Scalar operator+(Scalar s1, float s2) { return s1 + Scalar(s2); }
__forceinline Scalar operator-(Scalar s1, float s2) { return s1 - Scalar(s2); }
__forceinline Scalar operator*(Scalar s1, float s2) { return s1 * Scalar(s2); }
__forceinline Scalar operator/(Scalar s1, float s2) { return s1 / Scalar(s2); }
__forceinline Scalar operator+(float s1, Scalar s2) { return Scalar(s1) + s2; }
__forceinline Scalar operator-(float s1, Scalar s2) { return Scalar(s1) - s2; }
__forceinline Scalar operator*(float s1, Scalar s2) { return Scalar(s1) * s2; }
__forceinline Scalar operator/(float s1, Scalar s2) { return Scalar(s1) / s2; }

} // namespace Math