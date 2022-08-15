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
#include <omni/graph/core/IGraphRegistry.h>

const struct carb::PluginImplDesc pluginImplDesc = { "omni.example.cpp.graph_node.plugin",
                                                     "An example C++ extension.", "NVIDIA",
                                                     carb::PluginHotReload::eEnabled, "dev" };

CARB_PLUGIN_IMPL_DEPS(omni::graph::core::IGraphRegistry)

namespace omni
{
namespace example
{
namespace cpp
{
namespace graph_node
{

class ExampleGraphNodeExtension : public omni::ext::IExt
{
public:
    void onStartup(const char* extId) override
    {
        printf("ExampleGraphNodeExtension starting up (ext_id: %s).\n", extId);
    }

    void onShutdown() override
    {
        printf("ExampleGraphNodeExtension shutting down.\n");
    }

private:
};

}
}
}
}

CARB_PLUGIN_IMPL(pluginImplDesc, omni::example::cpp::graph_node::ExampleGraphNodeExtension)

void fillInterface(omni::example::cpp::graph_node::ExampleGraphNodeExtension& iface)
{
}
