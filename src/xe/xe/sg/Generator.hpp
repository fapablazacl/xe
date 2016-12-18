
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


}}

#endif
