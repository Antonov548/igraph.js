#pragma once

#include <igraph.h>
#include <igraph.hpp>
#include <stdexcept>

#define IGRAPH_JS_CHECK(func) \
    do { \
        ig::igCheck(func); \
    } while (0)

#ifdef __EMSCRIPTEN__
    #include <emscripten/bind.h>
    using var = emscripten::val;
    using namespace emscripten;
#else
    #error "Emscripten defien not found: emcc compiler should be used"
#endif
