
#pragma once

#ifndef __xe_sg_camera_hpp__
#define __xe_sg_camera_hpp__

#include <xe/math/Vector.hpp>
#include <xe/math/Matrix.hpp>
#include <xe/sg/Renderable.hpp>
#include <xe/gfx/GraphicsDevice.hpp>

namespace xe { 
    class PhongPipeline;
    class Camera : public Renderable {
    public:
        Camera(PhongPipeline *pipeline);

        virtual ~Camera();

        virtual xe::Matrix4f getProjMatrix() const = 0;

        virtual xe::Matrix4f getViewMatrix() const = 0;

        virtual void render() override;

    private:
        PhongPipeline *m_pipeline;
    };

    template<typename ProjectionPolicy, typename ViewPolicy>
    class AnyCamera : public Camera, public ProjectionPolicy, public ViewPolicy {
    public:
        AnyCamera(PhongPipeline *pipeline) : Camera(pipeline) {}

        virtual ~AnyCamera() {}

        virtual xe::Matrix4f getProjMatrix() const {
            return ProjectionPolicy::getProjMatrix();
        }

        virtual xe::Matrix4f getViewMatrix() const {
            return ViewPolicy::getViewMatrix();
        }
    };

    struct LookAtViewPolicy {
        xe::Vector3f position = {0.0f, 0.0f, 1.0f};
        xe::Vector3f lookAt = {0.0f, 0.0f, 0.0f};
        xe::Vector3f up = {0.0f, 1.0f, 0.0f};

        xe::Matrix4f getViewMatrix() const {
            return xe::Matrix4f::makeLookat(position, lookAt, up);
        }
    };

    struct PerspectiveProjPolicy {
        float fov = 60.0f * 3.1415926535f / 180.0f;
        float aspect = 1.333333f;
        float znear = 0.1f;
        float zfar = 100.0f;

        xe::Matrix4f getProjMatrix() const {
            return xe::Matrix4f::makePerspective(fov, aspect, znear, zfar);
        }
    };

    typedef AnyCamera<PerspectiveProjPolicy, LookAtViewPolicy> LookAtPerspectiveCamera;
}

#endif
