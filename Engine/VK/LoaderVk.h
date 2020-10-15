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

namespace Kodiak
{

// Core functions (these can be loaded without a live VkInstance object)
void LoadBaseFunctionPointers();

// Instance functions for various Vulkan versions
void LoadInstanceFunctionPointers(VkInstance instance, uint32_t apiVersion);

// Device functions for various Vulkan versions
void LoadDeviceFunctionPointers(VkDevice device, uint32_t apiVersion);


// Extension functions

} // namespace Kodiak