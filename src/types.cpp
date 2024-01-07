#include <memory>
#include <iostream>
#include <functional>

#include "bind.hpp"

#define IGRAPH_VECTOR_EMCC(name) \
    val get_##name(const ig::igGraph& graph) { \
        const auto* g{static_cast<const igraph_t*>(graph)}; \
        const auto& vector{g->name}; \
        const auto size{(vector.stor_end - vector.stor_begin)}; \
        return val{typed_memory_view(size, vector.stor_begin)}; \
    }

bool get_directed(const ig::igGraph& graph) {
    const auto* g{static_cast<const igraph_t*>(graph)};
    return g->directed;
}

igraph_integer_t get_n(const ig::igGraph& graph) {
    const auto* g{static_cast<const igraph_t*>(graph)};
    return g->n;
}

var get_vector(const ig::igIntVec& v) {
    return var{typed_memory_view(v.size(), v.begin())};
}

ig::igIntVec create_vector(var arr) {
    ig::igIntVec v{};
    const auto data{convertJSArrayToNumberVector<igraph_integer_t>(arr)};

    v.resize(data.size());
    for (size_t i{0}; i < data.size(); ++i) v[i] = data[i];

    return v;
}

IGRAPH_VECTOR_EMCC(from)
IGRAPH_VECTOR_EMCC(to)

EMSCRIPTEN_BINDINGS(IGraphTypes)
{
  class_<ig::igGraph>("graph").
    constructor().
    property("n", &get_n).
    property("directed", &get_directed).
    property("from", &get_from).
    property("to", &get_to);

  class_<ig::igIntVec>("vector_int").
    constructor().
    constructor(&create_vector, allow_raw_pointers()).
    property("data", &get_vector);

  enum_<igraph_error_type_t>("error");

  enum_<igraph_neimode_t>("neimode").
    value("OUT", IGRAPH_OUT).
    value("IN", IGRAPH_IN).
    value("ALL", IGRAPH_ALL);

  enum_<igraph_star_mode_t>("starmode").
    value("OUT", IGRAPH_STAR_OUT).
    value("IN", IGRAPH_STAR_IN).
    value("UNDIRECTED", IGRAPH_STAR_UNDIRECTED).
    value("MUTUAL", IGRAPH_STAR_MUTUAL);
}
