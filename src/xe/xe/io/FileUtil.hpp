
#pragma once

#ifndef __xe_fileutil_hpp__
#define __xe_fileutil_hpp__

#include <string>
#include <xe/PreDef.hpp>

namespace xe {
    class XE_API FileUtil {
    public:
        FileUtil() = delete;
        FileUtil(const FileUtil &) = delete;

        static std::string load(const std::string &file);

        static void save(const std::string &file, const std::string &content);
    };
}

#endif
