
#pragma once

#ifndef __xe_sg_generator_hpp__
#define __xe_sg_generator_hpp__

#include <xe/PreDef.hpp>
#include <xe/Math.hpp>
#include <xe/Vector.hpp>
#include <xe/sg/Plane.hpp>
#include <vector>

namespace xe { namespace sg {

    struct XE_API Generator {
        std::vector<xe::Vector3f> genNormals(const std::vector<xe::Vector3f> &coords) const;

        std::vector<xe::Vector3f> genNormals(const std::vector<xe::Vector3f> &coords, const std::vector<std::uint32_t> &indices) const;

        //std::vector<xe::Vector3f> genSmoothNormals(const std::vector<xe::Vector3f> &coords, const std::vector<std::uint32_t> &indices) const;
    };

    struct XE_API SphereGenerator {
        std::size_t slices = 4;
        std::size_t stacks = 5;

        SphereGenerator() {}

        SphereGenerator(const std::size_t slices_, const std::size_t stacks_)
            : slices(slices_), stacks(stacks_) {}


        std::size_t getCoordCount() const;

        std::vector<xe::Vector3f> genCoords(const float radius) const;

        std::vector<std::uint32_t> genIndices() const;

        /**
         * @brief Generate the normal for any ellipsoid object (including spheres)
         */
        std::vector<xe::Vector3f> genNormals(const std::vector<xe::Vector3f> &coords) const;
    };

    struct XE_API PlaneGenerator {
        std::size_t slices = 1;
        std::size_t stacks = 1;

        PlaneGenerator() {}

        PlaneGenerator(const std::size_t slices_, const std::size_t stacks_)
            : slices(slices_), stacks(stacks_) {}

        std::vector<xe::Vector3f> genCoords(const Plane &plane) const;

        std::size_t getCoordCount() const;

        std::vector<std::uint32_t> genIndices() const;

        std::vector<xe::Vector3f> genNormals(const Plane &plane) const;
        
        std::vector<xe::Vector2f> genTexCoords() const;
    };
}}

#endif
