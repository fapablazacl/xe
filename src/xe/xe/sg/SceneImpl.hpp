
#pragma once 

#ifndef __xe_sg_sceneimpl_hpp__
#define __xe_sg_sceneimpl_hpp__

#include "Scene.hpp"
#include "SceneNodeImpl.hpp"

#include <memory>
#include <vector>

namespace xe {
    class SceneImpl : public Scene {
    public:
        SceneImpl() {
            m_root = this->createNode(nullptr);
        }

        virtual ~SceneImpl() {}

        virtual SceneNodeImpl* getRoot() override {
            return m_root;
        }

        virtual SceneNodeImpl* createNode() override {
            return this->createNode("", m_root);
        }

        virtual SceneNodeImpl* createNode(const std::string &name) override {
            auto node = new SceneNodeImpl(name);

            node->setParent(m_root);

            m_nodes.emplace_back(node);
        
            return node;
        }

        virtual SceneNodeImpl* createNode(const std::string &name, SceneNode *parent) override {
            auto node = new SceneNodeImpl(name);

            node->setParent(parent);

            m_nodes.emplace_back(node);
        
            return node;
        }

    private:
        std::vector<std::unique_ptr<SceneNodeImpl>> m_nodes;
        SceneNodeImpl *m_root = nullptr;
    };
}

#endif 
