//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#pragma once

#define FORCE_VULKAN_VALIDATION 0
#define ENABLE_VULKAN_VALIDATION (_DEBUG || FORCE_VULKAN_VALIDATION)

#define FORCE_VULKAN_DEBUG_MARKUP 0
#define ENABLE_VULKAN_DEBUG_MARKUP (_DEBUG || _PROFILE || FORCE_VULKAN_DEBUG_MARKUP)

#define FORCE_VALIDATE_FUNCTION_POINTERS 0
#define VALIDATE_FUNCTION_POINTERS (_DEBUG || FORCE_VALIDATE_FUNCTION_POINTERS)

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan.h>

#pragma comment(lib, "vulkan-1.lib")

#include "Extern\VulkanMemoryAllocator\vk_mem_alloc.h"

#include "RefCountVk.h"
#include "StructuresVk.h"

// Custom define for better code readability
#define VK_FLAGS_NONE 0
// Default fence timeout in nanoseconds
#define DEFAULT_FENCE_TIMEOUT 100000000000

const std::string s_apiName = "Vulkan";
const std::string s_apiPrefixString = "[Vulkan]";
const std::string s_defaultShaderPath = "Shaders\\SPIR-V";

inline void ThrowIfFailed(VkResult res)
{
	if (res != VK_SUCCESS)
	{
		throw;
	}
}

#if VALIDATE_FUNCTION_POINTERS
#define VALIDATE_FUNCTION_POINTER(FPTR) assert(FPTR != nullptr)
#else
#define VALIDATE_FUNCTION_POINTER(FPTR) 
#endif