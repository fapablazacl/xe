
#pragma once 

#ifndef __demo_application_hpp__
#define __demo_application_hpp__

#include <xe/Core.hpp>

#include <iostream>
#include <map>
#include <xe/Core.hpp>
#include <xe/Matrix.hpp>
#include <xe/PluginManager.hpp>
#include <xe/gfx/Manager.hpp>
#include <xe/gfx/Device.hpp>
#include <xe/gfx/Material.hpp>
#include <xe/gfx/DeviceInfo.hpp>
#include <xe/sg/SceneNode.hpp>
#include <xe/sg/Scene.hpp>

#include "Renderable.hpp"
#include "SceneRenderer.hpp"
#include "Pipeline.hpp"

namespace demo {
    class Application : public xe::Core {
    public:
        Application();

        ~Application();

        int run();

    private:
        xe::gfx::DevicePtr createDevice();

        xe::gfx::MeshFormatPtr createMeshFormat();

        xe::sg::ScenePtr createScene();
        
        std::map<std::string, xe::gfx::MaterialPtr> createMaterials();

        std::map<std::string, xe::sg::RenderablePtr> createRenderables();
        
        xe::gfx::TexturePtr createTexture(const std::string &file);
        
        std::map<std::string, xe::gfx::TexturePtr> createTextures();
        

    private:
        xe::sg::RenderablePtr createSphereRenderable();

        xe::sg::RenderablePtr createPlaneRenderable();

        xe::sg::RenderablePtr createLightRenderable();

    private:
        xe::gfx::DevicePtr m_device;
        xe::gfx::MeshFormatPtr m_meshFormat;
        xe::sg::ScenePtr m_scene;

        xe::sg::SceneNode *m_meshNode = nullptr;
        //float m_angle = 0.0f;

        std::map<std::string, xe::sg::RenderablePtr> m_renderables;
        std::map<std::string, xe::gfx::MaterialPtr> m_materials;
        std::map<std::string, xe::gfx::TexturePtr> m_textures;

        std::unique_ptr<xe::sg::Pipeline> m_pipeline;
        std::unique_ptr<xe::sg::SceneRenderer> m_sceneRenderer;
    };
}

#endif
