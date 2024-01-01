
#ifndef IGCPP_IGRAPH_HPP
#define IGCPP_IGRAPH_HPP

#include <igraph.h>
#include <stdexcept>

namespace ig {

// Error handling

struct igException : std::runtime_error {
    igraph_error_t err;

    explicit igException(igraph_error_t err) :
            std::runtime_error(igraph_strerror(err)),
            err(err) {}
};

inline void igCheck(igraph_error_t error) {
    if (error != IGRAPH_SUCCESS)
        throw igException{error};
}

// Data structures

class igGraph {
    igraph_t g;

public:
    igGraph() {}

    igGraph(igGraph&& other) {
        g = other.g;
        other.g.from.stor_begin = nullptr;
        other.g.to.stor_begin = nullptr;
        other.g.n = 0;
    }

    igGraph(const igGraph& other) {
        igraph_copy(&g, &other.g);
    }

    ~igGraph() {
        igraph_destroy(&g);
    }

    operator igraph_t*() {
        return &g;
    }

    operator const igraph_t*() const {
        return &g;
    }
};

template<typename T> class igVec;
template<typename T> class igMatrix;
template<typename T> class igVecList;

#define BASE_IGRAPH_REAL
#include "igraph_pmt.hpp"
#include "igraph_list_pmt.hpp"
#undef BASE_IGRAPH_REAL
using igRealVec = igVec<igraph_real_t>;
using igRealMatrix = igMatrix<igraph_real_t>;
using igVecRealList = igVecList<igraph_vector_t>;

#define BASE_INT
#include "igraph_pmt.hpp"
#include "igraph_list_pmt.hpp"
#undef BASE_INT
using igIntVec = igVec<igraph_integer_t>;
using igIntMatrix = igMatrix<igraph_integer_t>;
using igVecIntList = igVecList<igraph_vector_int_t>;

#define BASE_BOOL
#include "igraph_pmt.hpp"
#undef BASE_BOOL
using igBoolVec = igVec<igraph_bool_t>;
using igBoolMatrix = igMatrix<igraph_bool_t>;

} // namespace ig

#endif // IGCPP_IGRAPH_HPP
