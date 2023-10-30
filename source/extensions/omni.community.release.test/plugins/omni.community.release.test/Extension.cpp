// Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto.  Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.
//

#define CARB_EXPORTS

#include <carb/PluginUtils.h>

#include <omni/ext/IExt.h>
#include <omni/kit/IApp.h>

const struct carb::PluginImplDesc pluginImplDesc = { "omni.community.release.test.plugin",
                                                     "An example C++ extension.", "NVIDIA",
                                                     carb::PluginHotReload::eEnabled, "dev" };

CARB_PLUGIN_IMPL_DEPS(omni::kit::IApp)

namespace omni
{
namespace community
{
namespace release
{
namespace test
{

// When this extension is enabled, any class that derives from omni.ext.IExt
// will be instantiated and 'onStartup(extId)' called. When the extension is
// later disabled, a matching 'onShutdown()' call will be made on the object.
class CommunityReleaseTestExtension : public omni::ext::IExt
{
public:
    void onStartup(const char* extId) override
    {
        printf("CommunityReleaseTestExtension starting up (ext_id: %s).\n", extId);
    }

    void onShutdown() override
    {
        printf("CommunityReleaseTestExtension shutting down.\n");
    }
};

}
}
}
}

CARB_PLUGIN_IMPL(pluginImplDesc, omni::community::release::test::CommunityReleaseTestExtension)

void fillInterface(omni::community::release::test::CommunityReleaseTestExtension& iface)
{
}
