
#pragma once 

#ifndef __xe_sg_scenenode_hpp__
#define __xe_sg_scenenode_hpp__

#include <xe/PreDef.hpp>
#include <cstddef>

namespace xe {
    
    class Renderable;

    /** 
     * @brief Scene Node abstract class.
     */
    class XE_API SceneNode {
    public:
        virtual ~SceneNode();

        virtual Renderable* getRenderable() const = 0;

        virtual void setRenderable(Renderable *data) = 0;

        virtual std::size_t getChildCount() const = 0;

        virtual SceneNode* getChild(const std::size_t index) const = 0;

        virtual SceneNode* getParent() const = 0;

        virtual void setParent(SceneNode *parent) = 0;
    };
}

#endif 
