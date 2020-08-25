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

// Forward declarations
class ExtensionManager;
struct DeviceFeatures;
struct DeviceProperties;


class IExtension
{
	friend class ExtensionManager;

public:
	virtual const char* GetName() const = 0;
	
	virtual void Enable(DeviceFeatures& features, DeviceProperties& properties) = 0;

	bool IsAvailable() const { return m_isAvailable; }
	bool IsEnabled() const { return m_isEnabled; }

protected:
	bool m_isAvailable{ false };
	bool m_isEnabled{ false };
};


class BufferMarkerAMD : public IExtension
{
public:
	BufferMarkerAMD(ExtensionManager* manager);

	const char* GetName() const final { return VK_AMD_BUFFER_MARKER_EXTENSION_NAME; }

	void Enable(DeviceFeatures& features, DeviceProperties& properties) final;
};

} // namespace Kodiak