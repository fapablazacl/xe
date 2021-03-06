/*
 * Copyright (c) 2016, 2017 Felipe Apablaza.
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution.
 */

#include "Core.hpp"

#include <cassert>
#include <vector>
#include <memory>
#include <xe/PluginManagerImpl.hpp>

#if !defined(XE_PLUGIN_DYNAMIC_LINKING)
#if defined(XE_GFX_ENABLE_GL3)
#include "xe/gfx/gl3/PluginGL.hpp"
#endif
#if defined(XE_GFX_ENABLE_GLES2)
#include "xe/gfx/es2/PluginES2.hpp"
#endif
#if defined(XE_GFX_ENABLE_FREEIMAGE)
#include "xe/gfx/fi/PluginFI.hpp"
#endif
#if defined(XE_GFX_ENABLE_PNG)
#include "xe/gfx/png/PluginPNG.hpp"
#endif
#if defined(XE_SFX_ENABLE_AL)
#include "xe/gfx/al/PluginAL.hpp"
#endif

#endif

namespace xe {
    struct Core::Private {
        std::vector<std::unique_ptr<Plugin>> m_staticPlugins;

        GraphicsManager graphicsManager;
        PluginManagerImpl pluginManager;

        Version version = {XE_VERSION_MAJOR, XE_VERSION_MINOR};

        std::string license = "The XE Low Level Engine. \n"
            "Copyright (c) 2016, 2017 Felipe Apablaza\n\n"
            "The license and distribution terms for this library may be\n"
            "found in the file LICENSE in this distribution.\n";

        Private(Core *core) : pluginManager(core) {
#if !defined(XE_PLUGIN_DYNAMIC_LINKING)
#if defined(XE_GFX_ENABLE_GL3)
            m_staticPlugins.emplace_back(new PluginGL());
#endif
#if defined(XE_GFX_ENABLE_GLES2)
            m_staticPlugins.emplace_back(new PluginES2());
#endif
#if defined(XE_GFX_ENABLE_FREEIMAGE)
            m_staticPlugins.emplace_back(new PluginFI());
#endif
#if defined(XE_GFX_ENABLE_PNG)
            m_staticPlugins.emplace_back(new PluginPNG());
#endif
#if defined(XE_SFX_ENABLE_AL)
            m_staticPlugins.emplace_back(new PluginAL());
#endif
#endif
        }

        ~Private() {}
    };

    Core::Core() : m_impl(new Core::Private(this)) {
        std::cout << m_impl->license << std::endl;

        for (auto &plugin : m_impl->m_staticPlugins) {
            plugin->start(this);
        }
    }

    Core::~Core() {
        for (auto &plugin : m_impl->m_staticPlugins) {
            plugin->stop(this);
        }

        delete m_impl;
    }

    Version Core::getVersion() const {
        assert(m_impl);

        return m_impl->version;
    }

    GraphicsManager* Core::getGraphicsManager() {
        assert(m_impl);

        return &m_impl->graphicsManager;
    }    

    PluginManager* Core::getPluginManager() {
        assert(m_impl);

        return &m_impl->pluginManager;
    }
}
