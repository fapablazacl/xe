
/**
 * @file Image.hpp
 * @brief Image abstract class declaration
 */


/*
 * Copyright (c) 2013 Felipe Apablaza.
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution.
 */

#pragma once

#ifndef __xe_gfx_image_hpp__
#define __xe_gfx_image_hpp__

#include <memory>
#include <xe/Buffer.hpp>
#include <xe/PreDef.hpp>
#include <xe/math/Vector.hpp>
#include <xe/gfx/PixelFormat.hpp>

namespace xe {

    enum class ImageType {
        Unknown,
        Img1D,
        Img2D,
        Img3D
    };
    
    struct ImageDesc {
        ImageType type = ImageType::Unknown;
        PixelFormat format = PixelFormat::Unknown;
        std::size_t width = 0;
        std::size_t height = 0;
        std::size_t depth = 0;
    };

    class XE_API Image {
    public:
        virtual ~Image();

        virtual ImageDesc getDesc() const = 0;

        virtual void* getPointer() = 0;
        virtual const void* getPointer() const = 0;
    };

    typedef std::unique_ptr<Image> ImagePtr;
}

#endif 
