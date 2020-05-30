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

template <typename T> __forceinline T AlignUpWithMask(T value, size_t mask)
{
	return (T)(((size_t)value + mask) & ~mask);
}

template <typename T> __forceinline T AlignDownWithMask(T value, size_t mask)
{
	return (T)((size_t)value & ~mask);
}

template <typename T> __forceinline T AlignUp(T value, size_t alignment)
{
	return AlignUpWithMask(value, alignment - 1);
}

template <typename T> __forceinline T AlignDown(T value, size_t alignment)
{
	return AlignDownWithMask(value, alignment - 1);
}

template <typename T> __forceinline bool IsAligned(T value, size_t alignment)
{
	return 0 == ((size_t)value & (alignment - 1));
}

template <typename T> __forceinline T DivideByMultiple(T value, size_t alignment)
{
	return (T)((value + alignment - 1) / alignment);
}

template <typename T> __forceinline bool IsPowerOfTwo(T value)
{
	return 0 == (value & (value - 1));
}

template <typename T> __forceinline bool IsDivisible(T value, T divisor)
{
	return (value / divisor) * divisor == value;
}

} // namespace Math