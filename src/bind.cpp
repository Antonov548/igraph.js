#include "bind.hpp"
#include <string>
#include <memory>

namespace {

  auto js_empty(igraph_integer_t n, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_empty(static_cast<igraph_t*>(*graph), n, directed));
    return graph;
  }

  auto js_add_edges(ig::igGraph* graph, ig::igIntVec* edges, uintptr_t attr) {
    
    
    IGRAPH_JS_CHECK(igraph_add_edges(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*edges), reinterpret_cast<void*>(attr)));
    return graph;
  }

  auto js_add_vertices(ig::igGraph* graph, igraph_integer_t nv, uintptr_t attr) {
    
    
    IGRAPH_JS_CHECK(igraph_add_vertices(static_cast<igraph_t*>(*graph), nv, reinterpret_cast<void*>(attr)));
    return graph;
  }

  auto js_copy(ig::igGraph* from) {
    std::unique_ptr<ig::igGraph> to;

    to = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_copy(static_cast<igraph_t*>(*to), static_cast<igraph_t*>(*from)));
    return to;
  }

  auto js_delete_edges(ig::igGraph* graph, igraph_es_t edges) {
    
    
    IGRAPH_JS_CHECK(igraph_delete_edges(static_cast<igraph_t*>(*graph), edges));
    return graph;
  }

  auto js_delete_vertices(ig::igGraph* graph, igraph_vs_t vertices) {
    
    
    IGRAPH_JS_CHECK(igraph_delete_vertices(static_cast<igraph_t*>(*graph), vertices));
    return graph;
  }

  auto js_delete_vertices_idx(ig::igGraph* graph, igraph_vs_t vertices) {
    std::unique_ptr<ig::igIntVec> idx;
    std::unique_ptr<ig::igIntVec> invidx;

    idx = std::make_unique<ig::igIntVec>();
    invidx = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_delete_vertices_idx(static_cast<igraph_t*>(*graph), vertices, static_cast<igraph_vector_int_t*>(*idx), static_cast<igraph_vector_int_t*>(*invidx)));
  }

  igraph_integer_t js_vcount(ig::igGraph* graph) {
    
    
    return igraph_vcount(static_cast<igraph_t*>(*graph));
  }

  igraph_integer_t js_ecount(ig::igGraph* graph) {
    
    
    return igraph_ecount(static_cast<igraph_t*>(*graph));
  }

  auto js_neighbors(ig::igGraph* graph, igraph_integer_t vid, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> neis;

    neis = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_neighbors(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*neis), vid, mode));
    return neis;
  }

  igraph_bool_t js_is_directed(ig::igGraph* graph) {
    
    
    return igraph_is_directed(static_cast<igraph_t*>(*graph));
  }

  auto js_degree(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_bool_t loops) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_degree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), vids, mode, loops));
    return res;
  }

  auto js_edge(ig::igGraph* graph, igraph_integer_t eid) {
    igraph_integer_t from;
    igraph_integer_t to;

    
    IGRAPH_JS_CHECK(igraph_edge(static_cast<igraph_t*>(*graph), eid, &from, &to));
  }

  auto js_edges(ig::igGraph* graph, igraph_es_t eids) {
    std::unique_ptr<ig::igIntVec> edges;

    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_edges(static_cast<igraph_t*>(*graph), eids, static_cast<igraph_vector_int_t*>(*edges)));
    return edges;
  }

  auto js_empty_attrs(igraph_integer_t n, igraph_bool_t directed, uintptr_t attr) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_empty_attrs(static_cast<igraph_t*>(*graph), n, directed, reinterpret_cast<void*>(attr)));
    return graph;
  }

  auto js_get_eid(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, igraph_bool_t directed, igraph_bool_t error) {
    igraph_integer_t eid;

    
    IGRAPH_JS_CHECK(igraph_get_eid(static_cast<igraph_t*>(*graph), &eid, from, to, directed, error));
    return eid;
  }

  auto js_get_eids(ig::igGraph* graph, ig::igIntVec* pairs, igraph_bool_t directed, igraph_bool_t error) {
    std::unique_ptr<ig::igIntVec> eids;

    eids = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_eids(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*eids), static_cast<igraph_vector_int_t*>(*pairs), directed, error));
    return eids;
  }

  auto js_get_all_eids_between(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, igraph_bool_t directed) {
    std::unique_ptr<ig::igIntVec> eids;

    eids = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_all_eids_between(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*eids), from, to, directed));
    return eids;
  }

  auto js_incident(ig::igGraph* graph, igraph_integer_t vid, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> eids;

    eids = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_incident(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*eids), vid, mode));
    return eids;
  }

  auto js_is_same_graph(ig::igGraph* graph1, ig::igGraph* graph2) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_same_graph(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), &res));
    return res;
  }

  auto js_create(ig::igIntVec* edges, igraph_integer_t n, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_create(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*edges), n, directed));
    return graph;
  }

  auto js_adjacency(ig::igRealMatrix adjmatrix, igraph_adjacency_t mode, igraph_loops_t loops) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_adjacency(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(adjmatrix), mode, loops));
    return graph;
  }

  auto js_weighted_adjacency(ig::igRealMatrix adjmatrix, igraph_adjacency_t mode, igraph_loops_t loops) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igRealVec> weights;

    graph = std::make_unique<ig::igGraph>();
    weights = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_weighted_adjacency(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(adjmatrix), mode, static_cast<igraph_vector_t*>(*weights), loops));
  }

  auto js_star(igraph_integer_t n, igraph_star_mode_t mode, igraph_integer_t center) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_star(static_cast<igraph_t*>(*graph), n, mode, center));
    return graph;
  }

  auto js_wheel(igraph_integer_t n, igraph_wheel_mode_t mode, igraph_integer_t center) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_wheel(static_cast<igraph_t*>(*graph), n, mode, center));
    return graph;
  }

  auto js_square_lattice(ig::igIntVec* dimvector, igraph_integer_t nei, igraph_bool_t directed, igraph_bool_t mutual, ig::igBoolVec* periodic) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_square_lattice(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*dimvector), nei, directed, mutual, static_cast<igraph_vector_bool_t*>(*periodic)));
    return graph;
  }

  auto js_triangular_lattice(ig::igIntVec* dimvector, igraph_bool_t directed, igraph_bool_t mutual) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_triangular_lattice(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*dimvector), directed, mutual));
    return graph;
  }

  auto js_ring(igraph_integer_t n, igraph_bool_t directed, igraph_bool_t mutual, igraph_bool_t circular) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_ring(static_cast<igraph_t*>(*graph), n, directed, mutual, circular));
    return graph;
  }

  auto js_kary_tree(igraph_integer_t n, igraph_integer_t children, igraph_tree_mode_t type) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_kary_tree(static_cast<igraph_t*>(*graph), n, children, type));
    return graph;
  }

  auto js_symmetric_tree(ig::igIntVec* branches, igraph_tree_mode_t type) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_symmetric_tree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*branches), type));
    return graph;
  }

  auto js_regular_tree(igraph_integer_t h, igraph_integer_t k, igraph_tree_mode_t type) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_regular_tree(static_cast<igraph_t*>(*graph), h, k, type));
    return graph;
  }

  auto js_full(igraph_integer_t n, igraph_bool_t directed, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_full(static_cast<igraph_t*>(*graph), n, directed, loops));
    return graph;
  }

  auto js_full_citation(igraph_integer_t n, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_full_citation(static_cast<igraph_t*>(*graph), n, directed));
    return graph;
  }

  auto js_atlas(igraph_integer_t number) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_atlas(static_cast<igraph_t*>(*graph), number));
    return graph;
  }

  auto js_extended_chordal_ring(igraph_integer_t nodes, ig::igIntMatrix W, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_extended_chordal_ring(static_cast<igraph_t*>(*graph), nodes, static_cast<igraph_matrix_int_t*>(W), directed));
    return graph;
  }

  auto js_connect_neighborhood(ig::igGraph* graph, igraph_integer_t order, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_connect_neighborhood(static_cast<igraph_t*>(*graph), order, mode));
    return graph;
  }

  auto js_graph_power(ig::igGraph* graph, igraph_integer_t order, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_graph_power(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), order, directed));
    return res;
  }

  auto js_linegraph(ig::igGraph* graph) {
    std::unique_ptr<ig::igGraph> linegraph;

    linegraph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_linegraph(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*linegraph)));
    return linegraph;
  }

  auto js_de_bruijn(igraph_integer_t m, igraph_integer_t n) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_de_bruijn(static_cast<igraph_t*>(*graph), m, n));
    return graph;
  }

  auto js_kautz(igraph_integer_t m, igraph_integer_t n) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_kautz(static_cast<igraph_t*>(*graph), m, n));
    return graph;
  }

  auto js_famous(std::string name) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_famous(static_cast<igraph_t*>(*graph), name.c_str()));
    return graph;
  }

  auto js_lcf_vector(igraph_integer_t n, ig::igIntVec* shifts, igraph_integer_t repeats) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_lcf_vector(static_cast<igraph_t*>(*graph), n, static_cast<igraph_vector_int_t*>(*shifts), repeats));
    return graph;
  }

  auto js_full_bipartite(igraph_integer_t n1, igraph_integer_t n2, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igBoolVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_full_bipartite(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), n1, n2, directed, mode));
  }

  auto js_full_multipartite(ig::igIntVec* n, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_full_multipartite(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*types), static_cast<igraph_vector_int_t*>(*n), directed, mode));
  }

  auto js_realize_degree_sequence(ig::igIntVec* out_deg, ig::igIntVec* in_deg, igraph_edge_type_sw_t allowed_edge_types, igraph_realize_degseq_t method) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_realize_degree_sequence(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*out_deg), static_cast<igraph_vector_int_t*>(*in_deg), allowed_edge_types, method));
    return graph;
  }

  auto js_circulant(igraph_integer_t n, ig::igIntVec* shifts, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_circulant(static_cast<igraph_t*>(*graph), n, static_cast<igraph_vector_int_t*>(*shifts), directed));
    return graph;
  }

  auto js_generalized_petersen(igraph_integer_t n, igraph_integer_t k) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_generalized_petersen(static_cast<igraph_t*>(*graph), n, k));
    return graph;
  }

  auto js_turan(igraph_integer_t n, igraph_integer_t r) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_turan(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*types), n, r));
  }

  auto js_barabasi_game(igraph_integer_t n, igraph_real_t power, igraph_integer_t m, ig::igIntVec* outseq, igraph_bool_t outpref, igraph_real_t A, igraph_bool_t directed, igraph_barabasi_algorithm_t algo, ig::igGraph* start_from) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_barabasi_game(static_cast<igraph_t*>(*graph), n, power, m, static_cast<igraph_vector_int_t*>(*outseq), outpref, A, directed, algo, static_cast<igraph_t*>(*start_from)));
    return graph;
  }

  auto js_erdos_renyi_game_gnp(igraph_integer_t n, igraph_real_t p, igraph_bool_t directed, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_erdos_renyi_game_gnp(static_cast<igraph_t*>(*graph), n, p, directed, loops));
    return graph;
  }

  auto js_erdos_renyi_game_gnm(igraph_integer_t n, igraph_integer_t m, igraph_bool_t directed, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_erdos_renyi_game_gnm(static_cast<igraph_t*>(*graph), n, m, directed, loops));
    return graph;
  }

  auto js_degree_sequence_game(ig::igIntVec* out_deg, ig::igIntVec* in_deg, igraph_degseq_t method) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_degree_sequence_game(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*out_deg), static_cast<igraph_vector_int_t*>(*in_deg), method));
    return graph;
  }

  auto js_growing_random_game(igraph_integer_t n, igraph_integer_t m, igraph_bool_t directed, igraph_bool_t citation) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_growing_random_game(static_cast<igraph_t*>(*graph), n, m, directed, citation));
    return graph;
  }

  auto js_barabasi_aging_game(igraph_integer_t nodes, igraph_integer_t m, ig::igIntVec* outseq, igraph_bool_t outpref, igraph_real_t pa_exp, igraph_real_t aging_exp, igraph_integer_t aging_bin, igraph_real_t zero_deg_appeal, igraph_real_t zero_age_appeal, igraph_real_t deg_coef, igraph_real_t age_coef, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_barabasi_aging_game(static_cast<igraph_t*>(*graph), nodes, m, static_cast<igraph_vector_int_t*>(*outseq), outpref, pa_exp, aging_exp, aging_bin, zero_deg_appeal, zero_age_appeal, deg_coef, age_coef, directed));
    return graph;
  }

  auto js_recent_degree_game(igraph_integer_t n, igraph_real_t power, igraph_integer_t window, igraph_integer_t m, ig::igIntVec* outseq, igraph_bool_t outpref, igraph_real_t zero_appeal, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_recent_degree_game(static_cast<igraph_t*>(*graph), n, power, window, m, static_cast<igraph_vector_int_t*>(*outseq), outpref, zero_appeal, directed));
    return graph;
  }

  auto js_recent_degree_aging_game(igraph_integer_t nodes, igraph_integer_t m, ig::igIntVec* outseq, igraph_bool_t outpref, igraph_real_t pa_exp, igraph_real_t aging_exp, igraph_integer_t aging_bin, igraph_integer_t window, igraph_real_t zero_appeal, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_recent_degree_aging_game(static_cast<igraph_t*>(*graph), nodes, m, static_cast<igraph_vector_int_t*>(*outseq), outpref, pa_exp, aging_exp, aging_bin, window, zero_appeal, directed));
    return graph;
  }

  auto js_callaway_traits_game(igraph_integer_t nodes, igraph_integer_t types, igraph_integer_t edges_per_step, ig::igRealVec* type_dist, ig::igRealMatrix pref_matrix, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> node_type_vec;

    graph = std::make_unique<ig::igGraph>();
    node_type_vec = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_callaway_traits_game(static_cast<igraph_t*>(*graph), nodes, types, edges_per_step, static_cast<igraph_vector_t*>(*type_dist), static_cast<igraph_matrix_t*>(pref_matrix), directed, static_cast<igraph_vector_int_t*>(*node_type_vec)));
  }

  auto js_establishment_game(igraph_integer_t nodes, igraph_integer_t types, igraph_integer_t k, ig::igRealVec* type_dist, ig::igRealMatrix pref_matrix, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> node_type_vec;

    graph = std::make_unique<ig::igGraph>();
    node_type_vec = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_establishment_game(static_cast<igraph_t*>(*graph), nodes, types, k, static_cast<igraph_vector_t*>(*type_dist), static_cast<igraph_matrix_t*>(pref_matrix), directed, static_cast<igraph_vector_int_t*>(*node_type_vec)));
  }

  auto js_grg_game(igraph_integer_t nodes, igraph_real_t radius, igraph_bool_t torus) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igRealVec> x;
    std::unique_ptr<ig::igRealVec> y;

    graph = std::make_unique<ig::igGraph>();
    x = std::make_unique<ig::igRealVec>();
    y = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_grg_game(static_cast<igraph_t*>(*graph), nodes, radius, torus, static_cast<igraph_vector_t*>(*x), static_cast<igraph_vector_t*>(*y)));
  }

  auto js_preference_game(igraph_integer_t nodes, igraph_integer_t types, ig::igRealVec* type_dist, igraph_bool_t fixed_sizes, ig::igRealMatrix pref_matrix, igraph_bool_t directed, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> node_type_vec;

    graph = std::make_unique<ig::igGraph>();
    node_type_vec = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_preference_game(static_cast<igraph_t*>(*graph), nodes, types, static_cast<igraph_vector_t*>(*type_dist), fixed_sizes, static_cast<igraph_matrix_t*>(pref_matrix), static_cast<igraph_vector_int_t*>(*node_type_vec), directed, loops));
  }

  auto js_asymmetric_preference_game(igraph_integer_t nodes, igraph_integer_t out_types, igraph_integer_t in_types, ig::igRealMatrix type_dist_matrix, ig::igRealMatrix pref_matrix, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igIntVec> node_type_out_vec;
    std::unique_ptr<ig::igIntVec> node_type_in_vec;

    graph = std::make_unique<ig::igGraph>();
    node_type_out_vec = std::make_unique<ig::igIntVec>();
    node_type_in_vec = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_asymmetric_preference_game(static_cast<igraph_t*>(*graph), nodes, out_types, in_types, static_cast<igraph_matrix_t*>(type_dist_matrix), static_cast<igraph_matrix_t*>(pref_matrix), static_cast<igraph_vector_int_t*>(*node_type_out_vec), static_cast<igraph_vector_int_t*>(*node_type_in_vec), loops));
  }

  auto js_rewire_edges(ig::igGraph* graph, igraph_real_t prob, igraph_bool_t loops, igraph_bool_t multiple) {
    
    
    IGRAPH_JS_CHECK(igraph_rewire_edges(static_cast<igraph_t*>(*graph), prob, loops, multiple));
    return graph;
  }

  auto js_rewire_directed_edges(ig::igGraph* graph, igraph_real_t prob, igraph_bool_t loops, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_rewire_directed_edges(static_cast<igraph_t*>(*graph), prob, loops, mode));
    return graph;
  }

  auto js_watts_strogatz_game(igraph_integer_t dim, igraph_integer_t size, igraph_integer_t nei, igraph_real_t p, igraph_bool_t loops, igraph_bool_t multiple) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_watts_strogatz_game(static_cast<igraph_t*>(*graph), dim, size, nei, p, loops, multiple));
    return graph;
  }

  auto js_lastcit_game(igraph_integer_t nodes, igraph_integer_t edges_per_node, igraph_integer_t agebins, ig::igRealVec* preference, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_lastcit_game(static_cast<igraph_t*>(*graph), nodes, edges_per_node, agebins, static_cast<igraph_vector_t*>(*preference), directed));
    return graph;
  }

  auto js_cited_type_game(igraph_integer_t nodes, ig::igIntVec* types, ig::igRealVec* pref, igraph_integer_t edges_per_step, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_cited_type_game(static_cast<igraph_t*>(*graph), nodes, static_cast<igraph_vector_int_t*>(*types), static_cast<igraph_vector_t*>(*pref), edges_per_step, directed));
    return graph;
  }

  auto js_citing_cited_type_game(igraph_integer_t nodes, ig::igIntVec* types, ig::igRealMatrix pref, igraph_integer_t edges_per_step, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_citing_cited_type_game(static_cast<igraph_t*>(*graph), nodes, static_cast<igraph_vector_int_t*>(*types), static_cast<igraph_matrix_t*>(pref), edges_per_step, directed));
    return graph;
  }

  auto js_forest_fire_game(igraph_integer_t nodes, igraph_real_t fw_prob, igraph_real_t bw_factor, igraph_integer_t ambs, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_forest_fire_game(static_cast<igraph_t*>(*graph), nodes, fw_prob, bw_factor, ambs, directed));
    return graph;
  }

  auto js_simple_interconnected_islands_game(igraph_integer_t islands_n, igraph_integer_t islands_size, igraph_real_t islands_pin, igraph_integer_t n_inter) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_simple_interconnected_islands_game(static_cast<igraph_t*>(*graph), islands_n, islands_size, islands_pin, n_inter));
    return graph;
  }

  auto js_static_fitness_game(igraph_integer_t no_of_edges, ig::igRealVec* fitness_out, ig::igRealVec* fitness_in, igraph_bool_t loops, igraph_bool_t multiple) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_static_fitness_game(static_cast<igraph_t*>(*graph), no_of_edges, static_cast<igraph_vector_t*>(*fitness_out), static_cast<igraph_vector_t*>(*fitness_in), loops, multiple));
    return graph;
  }

  auto js_static_power_law_game(igraph_integer_t no_of_nodes, igraph_integer_t no_of_edges, igraph_real_t exponent_out, igraph_real_t exponent_in, igraph_bool_t loops, igraph_bool_t multiple, igraph_bool_t finite_size_correction) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_static_power_law_game(static_cast<igraph_t*>(*graph), no_of_nodes, no_of_edges, exponent_out, exponent_in, loops, multiple, finite_size_correction));
    return graph;
  }

  auto js_k_regular_game(igraph_integer_t no_of_nodes, igraph_integer_t k, igraph_bool_t directed, igraph_bool_t multiple) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_k_regular_game(static_cast<igraph_t*>(*graph), no_of_nodes, k, directed, multiple));
    return graph;
  }

  auto js_sbm_game(igraph_integer_t n, ig::igRealMatrix pref_matrix, ig::igIntVec* block_sizes, igraph_bool_t directed, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_sbm_game(static_cast<igraph_t*>(*graph), n, static_cast<igraph_matrix_t*>(pref_matrix), static_cast<igraph_vector_int_t*>(*block_sizes), directed, loops));
    return graph;
  }

  auto js_hsbm_game(igraph_integer_t n, igraph_integer_t m, ig::igRealVec* rho, ig::igRealMatrix C, igraph_real_t p) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_hsbm_game(static_cast<igraph_t*>(*graph), n, m, static_cast<igraph_vector_t*>(*rho), static_cast<igraph_matrix_t*>(C), p));
    return graph;
  }

  auto js_correlated_game(ig::igGraph* old_graph, igraph_real_t corr, igraph_real_t p, ig::igIntVec* permutation) {
    std::unique_ptr<ig::igGraph> new_graph;

    new_graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_correlated_game(static_cast<igraph_t*>(*old_graph), static_cast<igraph_t*>(*new_graph), corr, p, static_cast<igraph_vector_int_t*>(*permutation)));
    return new_graph;
  }

  auto js_correlated_pair_game(igraph_integer_t n, igraph_real_t corr, igraph_real_t p, igraph_bool_t directed, ig::igIntVec* permutation) {
    std::unique_ptr<ig::igGraph> graph1;
    std::unique_ptr<ig::igGraph> graph2;

    graph1 = std::make_unique<ig::igGraph>();
    graph2 = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_correlated_pair_game(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), n, corr, p, directed, static_cast<igraph_vector_int_t*>(*permutation)));
  }

  auto js_dot_product_game(ig::igRealMatrix vecs, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_dot_product_game(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(vecs), directed));
    return graph;
  }

  auto js_sample_sphere_surface(igraph_integer_t dim, igraph_integer_t n, igraph_real_t radius, igraph_bool_t positive) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_sample_sphere_surface(dim, n, radius, positive, static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_sample_sphere_volume(igraph_integer_t dim, igraph_integer_t n, igraph_real_t radius, igraph_bool_t positive) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_sample_sphere_volume(dim, n, radius, positive, static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_sample_dirichlet(igraph_integer_t n, ig::igRealVec* alpha) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_sample_dirichlet(n, static_cast<igraph_vector_t*>(*alpha), static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_are_connected(ig::igGraph* graph, igraph_integer_t v1, igraph_integer_t v2) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_are_connected(static_cast<igraph_t*>(*graph), v1, v2, &res));
    return res;
  }

  auto js_diameter(ig::igGraph* graph, igraph_bool_t directed, igraph_bool_t unconnected) {
    igraph_real_t res;
    igraph_integer_t from;
    igraph_integer_t to;
    std::unique_ptr<ig::igIntVec> vertex_path;
    std::unique_ptr<ig::igIntVec> edge_path;

    vertex_path = std::make_unique<ig::igIntVec>();
    edge_path = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_diameter(static_cast<igraph_t*>(*graph), &res, &from, &to, static_cast<igraph_vector_int_t*>(*vertex_path), static_cast<igraph_vector_int_t*>(*edge_path), directed, unconnected));
  }

  auto js_diameter_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_bool_t directed, igraph_bool_t unconnected) {
    igraph_real_t res;
    igraph_integer_t from;
    igraph_integer_t to;
    std::unique_ptr<ig::igIntVec> vertex_path;
    std::unique_ptr<ig::igIntVec> edge_path;

    vertex_path = std::make_unique<ig::igIntVec>();
    edge_path = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_diameter_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), &res, &from, &to, static_cast<igraph_vector_int_t*>(*vertex_path), static_cast<igraph_vector_int_t*>(*edge_path), directed, unconnected));
  }

  auto js_closeness(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, ig::igRealVec* weights, igraph_bool_t normalized) {
    std::unique_ptr<ig::igRealVec> res;
    std::unique_ptr<ig::igIntVec> reachable_count;
    igraph_bool_t all_reachable;

    res = std::make_unique<ig::igRealVec>();
    reachable_count = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_closeness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_int_t*>(*reachable_count), &all_reachable, vids, mode, static_cast<igraph_vector_t*>(*weights), normalized));
  }

  auto js_closeness_cutoff(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, ig::igRealVec* weights, igraph_bool_t normalized, igraph_real_t cutoff) {
    std::unique_ptr<ig::igRealVec> res;
    std::unique_ptr<ig::igIntVec> reachable_count;
    igraph_bool_t all_reachable;

    res = std::make_unique<ig::igRealVec>();
    reachable_count = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_closeness_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_int_t*>(*reachable_count), &all_reachable, vids, mode, static_cast<igraph_vector_t*>(*weights), normalized, cutoff));
  }

  auto js_distances(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, mode));
    return res;
  }

  auto js_distances_cutoff(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, igraph_neimode_t mode, igraph_real_t cutoff) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, mode, cutoff));
    return res;
  }

  auto js_get_shortest_path(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_path(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), from, to, mode));
  }

  auto js_get_shortest_path_bellman_ford(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_path_bellman_ford(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode));
  }

  auto js_get_shortest_path_dijkstra(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_path_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode));
  }

  auto js_get_shortest_path_astar(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, ig::igRealVec* weights, igraph_neimode_t mode, igraph_astar_heuristic_func_t heuristic, void* extra) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_path_astar(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode, heuristic, 0));
  }

  auto js_get_shortest_paths(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> parents;
    std::unique_ptr<ig::igIntVec> inbound_edges;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    parents = std::make_unique<ig::igIntVec>();
    inbound_edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_paths(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), from, to, mode, static_cast<igraph_vector_int_t*>(*parents), static_cast<igraph_vector_int_t*>(*inbound_edges)));
  }

  auto js_get_all_shortest_paths(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> nrgeo;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    nrgeo = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_all_shortest_paths(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), static_cast<igraph_vector_int_t*>(*nrgeo), from, to, mode));
  }

  auto js_distances_dijkstra(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_distances_dijkstra_cutoff(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode, igraph_real_t cutoff) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_dijkstra_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode, cutoff));
    return res;
  }

  auto js_get_shortest_paths_dijkstra(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> parents;
    std::unique_ptr<ig::igIntVec> inbound_edges;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    parents = std::make_unique<ig::igIntVec>();
    inbound_edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_paths_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode, static_cast<igraph_vector_int_t*>(*parents), static_cast<igraph_vector_int_t*>(*inbound_edges)));
  }

  auto js_get_shortest_paths_bellman_ford(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> parents;
    std::unique_ptr<ig::igIntVec> inbound_edges;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    parents = std::make_unique<ig::igIntVec>();
    inbound_edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_shortest_paths_bellman_ford(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode, static_cast<igraph_vector_int_t*>(*parents), static_cast<igraph_vector_int_t*>(*inbound_edges)));
  }

  auto js_get_all_shortest_paths_dijkstra(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> nrgeo;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    nrgeo = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_all_shortest_paths_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), static_cast<igraph_vector_int_t*>(*nrgeo), from, to, static_cast<igraph_vector_t*>(*weights), mode));
  }

  auto js_distances_bellman_ford(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_bellman_ford(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_distances_johnson(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_johnson(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_distances_floyd_warshall(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode, igraph_floyd_warshall_algorithm_t method) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_distances_floyd_warshall(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode, method));
    return res;
  }

  auto js_voronoi(ig::igGraph* graph, ig::igIntVec* generators, ig::igRealVec* weights, igraph_neimode_t mode, igraph_voronoi_tiebreaker_t tiebreaker) {
    std::unique_ptr<ig::igIntVec> membership;
    std::unique_ptr<ig::igRealVec> distances;

    membership = std::make_unique<ig::igIntVec>();
    distances = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_voronoi(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_t*>(*distances), static_cast<igraph_vector_int_t*>(*generators), static_cast<igraph_vector_t*>(*weights), mode, tiebreaker));
  }

  auto js_get_all_simple_paths(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, igraph_integer_t cutoff, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_all_simple_paths(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), from, to, cutoff, mode));
    return res;
  }

  auto js_get_k_shortest_paths(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t k, igraph_integer_t from, igraph_integer_t to, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertex_paths;
    std::unique_ptr<ig::igVecIntList> edge_paths;

    vertex_paths = std::make_unique<ig::igVecIntList>();
    edge_paths = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_get_k_shortest_paths(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*vertex_paths), static_cast<igraph_vector_int_list_t*>(*edge_paths), k, from, to, mode));
  }

  auto js_get_widest_path(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_widest_path(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode));
  }

  auto js_get_widest_paths(ig::igGraph* graph, igraph_integer_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igVecIntList> vertices;
    std::unique_ptr<ig::igVecIntList> edges;
    std::unique_ptr<ig::igIntVec> parents;
    std::unique_ptr<ig::igIntVec> inbound_edges;

    vertices = std::make_unique<ig::igVecIntList>();
    edges = std::make_unique<ig::igVecIntList>();
    parents = std::make_unique<ig::igIntVec>();
    inbound_edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_widest_paths(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*vertices), static_cast<igraph_vector_int_list_t*>(*edges), from, to, static_cast<igraph_vector_t*>(*weights), mode, static_cast<igraph_vector_int_t*>(*parents), static_cast<igraph_vector_int_t*>(*inbound_edges)));
  }

  auto js_widest_path_widths_dijkstra(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_widest_path_widths_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_widest_path_widths_floyd_warshall(ig::igGraph* graph, igraph_vs_t from, igraph_vs_t to, ig::igRealVec* weights, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_widest_path_widths_floyd_warshall(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), from, to, static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_spanner(ig::igGraph* graph, igraph_real_t stretch, ig::igRealVec* weights) {
    std::unique_ptr<ig::igIntVec> spanner;

    spanner = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_spanner(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*spanner), stretch, static_cast<igraph_vector_t*>(*weights)));
    return spanner;
  }

  auto js_subcomponent(ig::igGraph* graph, igraph_integer_t vid, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_subcomponent(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), vid, mode));
    return res;
  }

  auto js_betweenness(ig::igGraph* graph, igraph_vs_t vids, igraph_bool_t directed, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_betweenness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, directed, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_betweenness_cutoff(ig::igGraph* graph, igraph_vs_t vids, igraph_bool_t directed, ig::igRealVec* weights, igraph_real_t cutoff) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_betweenness_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, directed, static_cast<igraph_vector_t*>(*weights), cutoff));
    return res;
  }

  auto js_betweenness_subset(ig::igGraph* graph, igraph_vs_t vids, igraph_bool_t directed, igraph_vs_t sources, igraph_vs_t targets, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_betweenness_subset(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, directed, sources, targets, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_edge_betweenness(ig::igGraph* graph, igraph_bool_t directed, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_edge_betweenness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), directed, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_edge_betweenness_cutoff(ig::igGraph* graph, igraph_bool_t directed, ig::igRealVec* weights, igraph_real_t cutoff) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_edge_betweenness_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), directed, static_cast<igraph_vector_t*>(*weights), cutoff));
    return res;
  }

  auto js_edge_betweenness_subset(ig::igGraph* graph, igraph_es_t eids, igraph_bool_t directed, igraph_vs_t sources, igraph_vs_t targets, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_edge_betweenness_subset(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), eids, directed, sources, targets, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_harmonic_centrality(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, ig::igRealVec* weights, igraph_bool_t normalized) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_harmonic_centrality(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, mode, static_cast<igraph_vector_t*>(*weights), normalized));
    return res;
  }

  auto js_harmonic_centrality_cutoff(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, ig::igRealVec* weights, igraph_bool_t normalized, igraph_real_t cutoff) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_harmonic_centrality_cutoff(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, mode, static_cast<igraph_vector_t*>(*weights), normalized, cutoff));
    return res;
  }

  auto js_rewire(ig::igGraph* rewire, igraph_integer_t n, igraph_rewiring_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_rewire(static_cast<igraph_t*>(*rewire), n, mode));
    return rewire;
  }

  auto js_induced_subgraph(ig::igGraph* graph, igraph_vs_t vids, igraph_subgraph_implementation_t impl) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_induced_subgraph(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), vids, impl));
    return res;
  }

  auto js_subgraph_from_edges(ig::igGraph* graph, igraph_es_t eids, igraph_bool_t delete_vertices) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_subgraph_from_edges(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), eids, delete_vertices));
    return res;
  }

  auto js_reverse_edges(ig::igGraph* graph, igraph_es_t eids) {
    
    
    IGRAPH_JS_CHECK(igraph_reverse_edges(static_cast<igraph_t*>(*graph), eids));
    return graph;
  }

  auto js_average_path_length(ig::igGraph* graph, igraph_bool_t directed, igraph_bool_t unconn) {
    igraph_real_t res;
    igraph_real_t unconn_pairs;

    
    IGRAPH_JS_CHECK(igraph_average_path_length(static_cast<igraph_t*>(*graph), &res, &unconn_pairs, directed, unconn));
  }

  auto js_average_path_length_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_bool_t directed, igraph_bool_t unconn) {
    igraph_real_t res;
    igraph_real_t unconn_pairs;

    
    IGRAPH_JS_CHECK(igraph_average_path_length_dijkstra(static_cast<igraph_t*>(*graph), &res, &unconn_pairs, static_cast<igraph_vector_t*>(*weights), directed, unconn));
  }

  auto js_path_length_hist(ig::igGraph* graph, igraph_bool_t directed) {
    std::unique_ptr<ig::igRealVec> res;
    igraph_real_t unconnected;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_path_length_hist(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), &unconnected, directed));
  }

  auto js_transitivity_undirected(ig::igGraph* graph, igraph_transitivity_mode_t mode) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_transitivity_undirected(static_cast<igraph_t*>(*graph), &res, mode));
    return res;
  }

  auto js_transitivity_local_undirected(ig::igGraph* graph, igraph_vs_t vids, igraph_transitivity_mode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_transitivity_local_undirected(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, mode));
    return res;
  }

  auto js_transitivity_avglocal_undirected(ig::igGraph* graph, igraph_transitivity_mode_t mode) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_transitivity_avglocal_undirected(static_cast<igraph_t*>(*graph), &res, mode));
    return res;
  }

  auto js_transitivity_barrat(ig::igGraph* graph, igraph_vs_t vids, ig::igRealVec* weights, igraph_transitivity_mode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_transitivity_barrat(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_ecc(ig::igGraph* graph, igraph_es_t eids, igraph_integer_t k, igraph_bool_t offset, igraph_bool_t normalize) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_ecc(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), eids, k, offset, normalize));
    return res;
  }

  auto js_reciprocity(ig::igGraph* graph, igraph_bool_t ignore_loops, igraph_reciprocity_t mode) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_reciprocity(static_cast<igraph_t*>(*graph), &res, ignore_loops, mode));
    return res;
  }

  auto js_constraint(ig::igGraph* graph, igraph_vs_t vids, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_constraint(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_maxdegree(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_bool_t loops) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_maxdegree(static_cast<igraph_t*>(*graph), &res, vids, mode, loops));
    return res;
  }

  auto js_density(ig::igGraph* graph, igraph_bool_t loops) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_density(static_cast<igraph_t*>(*graph), &res, loops));
    return res;
  }

  auto js_neighborhood_size(ig::igGraph* graph, igraph_vs_t vids, igraph_integer_t order, igraph_neimode_t mode, igraph_integer_t mindist) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_neighborhood_size(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), vids, order, mode, mindist));
    return res;
  }

  auto js_neighborhood(ig::igGraph* graph, igraph_vs_t vids, igraph_integer_t order, igraph_neimode_t mode, igraph_integer_t mindist) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_neighborhood(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res), vids, order, mode, mindist));
    return res;
  }

  auto js_topological_sorting(ig::igGraph* graph, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_topological_sorting(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), mode));
    return res;
  }

  auto js_feedback_arc_set(ig::igGraph* graph, ig::igRealVec* weights, igraph_fas_algorithm_t algo) {
    std::unique_ptr<ig::igIntVec> result;

    result = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_feedback_arc_set(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*result), static_cast<igraph_vector_t*>(*weights), algo));
    return result;
  }

  auto js_is_loop(ig::igGraph* graph, igraph_es_t es) {
    std::unique_ptr<ig::igBoolVec> res;

    res = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_is_loop(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*res), es));
    return res;
  }

  auto js_is_dag(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_dag(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_is_acyclic(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_acyclic(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_is_simple(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_simple(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_is_multiple(ig::igGraph* graph, igraph_es_t es) {
    std::unique_ptr<ig::igBoolVec> res;

    res = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_is_multiple(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*res), es));
    return res;
  }

  auto js_has_loop(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_has_loop(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_has_multiple(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_has_multiple(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_count_multiple(ig::igGraph* graph, igraph_es_t es) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_count_multiple(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), es));
    return res;
  }

  auto js_girth(ig::igGraph* graph) {
    igraph_real_t girth;
    std::unique_ptr<ig::igIntVec> circle;

    circle = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_girth(static_cast<igraph_t*>(*graph), &girth, static_cast<igraph_vector_int_t*>(*circle)));
  }

  auto js_is_perfect(ig::igGraph* graph) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_perfect(static_cast<igraph_t*>(*graph), &res));
    return res;
  }

  auto js_add_edge(ig::igGraph* graph, igraph_integer_t from, igraph_integer_t to) {
    
    
    IGRAPH_JS_CHECK(igraph_add_edge(static_cast<igraph_t*>(*graph), from, to));
    return graph;
  }

  auto js_unfold_tree(ig::igGraph* graph, igraph_neimode_t mode, ig::igIntVec* roots) {
    std::unique_ptr<ig::igGraph> tree;
    std::unique_ptr<ig::igIntVec> vertex_index;

    tree = std::make_unique<ig::igGraph>();
    vertex_index = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_unfold_tree(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*tree), mode, static_cast<igraph_vector_int_t*>(*roots), static_cast<igraph_vector_int_t*>(*vertex_index)));
  }

  auto js_is_mutual(ig::igGraph* graph, igraph_es_t es, igraph_bool_t loops) {
    std::unique_ptr<ig::igBoolVec> res;

    res = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_is_mutual(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*res), es, loops));
    return res;
  }

  auto js_has_mutual(ig::igGraph* graph, igraph_bool_t loops) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_has_mutual(static_cast<igraph_t*>(*graph), &res, loops));
    return res;
  }

  auto js_maximum_cardinality_search(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> alpha;
    std::unique_ptr<ig::igIntVec> alpham1;

    alpha = std::make_unique<ig::igIntVec>();
    alpham1 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_maximum_cardinality_search(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*alpha), static_cast<igraph_vector_int_t*>(*alpham1)));
  }

  auto js_is_chordal(ig::igGraph* graph, ig::igIntVec* alpha, ig::igIntVec* alpham1) {
    igraph_bool_t chordal;
    std::unique_ptr<ig::igIntVec> fillin;
    std::unique_ptr<ig::igGraph> newgraph;

    fillin = std::make_unique<ig::igIntVec>();
    newgraph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_is_chordal(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*alpha), static_cast<igraph_vector_int_t*>(*alpham1), &chordal, static_cast<igraph_vector_int_t*>(*fillin), static_cast<igraph_t*>(*newgraph)));
  }

  auto js_avg_nearest_neighbor_degree(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_neimode_t neighbor_degree_mode, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> knn;
    std::unique_ptr<ig::igRealVec> knnk;

    knn = std::make_unique<ig::igRealVec>();
    knnk = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_avg_nearest_neighbor_degree(static_cast<igraph_t*>(*graph), vids, mode, neighbor_degree_mode, static_cast<igraph_vector_t*>(*knn), static_cast<igraph_vector_t*>(*knnk), static_cast<igraph_vector_t*>(*weights)));
  }

  auto js_degree_correlation_vector(ig::igGraph* graph, ig::igRealVec* weights, igraph_neimode_t from_mode, igraph_neimode_t to_mode, igraph_bool_t directed_neighbors) {
    std::unique_ptr<ig::igRealVec> knnk;

    knnk = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_degree_correlation_vector(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*knnk), static_cast<igraph_vector_t*>(*weights), from_mode, to_mode, directed_neighbors));
    return knnk;
  }

  auto js_strength(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_bool_t loops, ig::igRealVec* weights) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_strength(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, mode, loops, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  igraph_real_t js_centralization(ig::igRealVec* scores, igraph_real_t theoretical_max, igraph_bool_t normalized) {
    
    
    return igraph_centralization(static_cast<igraph_vector_t*>(*scores), theoretical_max, normalized);
  }

  auto js_centralization_degree(ig::igGraph* graph, igraph_neimode_t mode, igraph_bool_t loops, igraph_bool_t normalized) {
    std::unique_ptr<ig::igRealVec> res;
    igraph_real_t centralization;
    igraph_real_t theoretical_max;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_centralization_degree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), mode, loops, &centralization, &theoretical_max, normalized));
  }

  auto js_centralization_degree_tmax(ig::igGraph* graph, igraph_integer_t nodes, igraph_neimode_t mode, igraph_bool_t loops) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_centralization_degree_tmax(static_cast<igraph_t*>(*graph), nodes, mode, loops, &res));
    return res;
  }

  auto js_centralization_betweenness(ig::igGraph* graph, igraph_bool_t directed, igraph_bool_t normalized) {
    std::unique_ptr<ig::igRealVec> res;
    igraph_real_t centralization;
    igraph_real_t theoretical_max;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_centralization_betweenness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), directed, &centralization, &theoretical_max, normalized));
  }

  auto js_centralization_betweenness_tmax(ig::igGraph* graph, igraph_integer_t nodes, igraph_bool_t directed) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_centralization_betweenness_tmax(static_cast<igraph_t*>(*graph), nodes, directed, &res));
    return res;
  }

  auto js_centralization_closeness(ig::igGraph* graph, igraph_neimode_t mode, igraph_bool_t normalized) {
    std::unique_ptr<ig::igRealVec> res;
    igraph_real_t centralization;
    igraph_real_t theoretical_max;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_centralization_closeness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), mode, &centralization, &theoretical_max, normalized));
  }

  auto js_centralization_closeness_tmax(ig::igGraph* graph, igraph_integer_t nodes, igraph_neimode_t mode) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_centralization_closeness_tmax(static_cast<igraph_t*>(*graph), nodes, mode, &res));
    return res;
  }

  auto js_centralization_eigenvector_centrality_tmax(ig::igGraph* graph, igraph_integer_t nodes, igraph_bool_t directed, igraph_bool_t scale) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_centralization_eigenvector_centrality_tmax(static_cast<igraph_t*>(*graph), nodes, directed, scale, &res));
    return res;
  }

  auto js_assortativity_nominal(ig::igGraph* graph, ig::igIntVec* types, igraph_bool_t directed, igraph_bool_t normalized) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_assortativity_nominal(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*types), &res, directed, normalized));
    return res;
  }

  auto js_assortativity(ig::igGraph* graph, ig::igRealVec* values, ig::igRealVec* values_in, igraph_bool_t directed, igraph_bool_t normalized) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_assortativity(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*values), static_cast<igraph_vector_t*>(*values_in), &res, directed, normalized));
    return res;
  }

  auto js_assortativity_degree(ig::igGraph* graph, igraph_bool_t directed) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_assortativity_degree(static_cast<igraph_t*>(*graph), &res, directed));
    return res;
  }

  auto js_joint_degree_matrix(ig::igGraph* graph, igraph_integer_t max_out_degree, igraph_integer_t max_in_degree, ig::igRealVec* weights) {
    ig::igRealMatrix jdm;

    
    IGRAPH_JS_CHECK(igraph_joint_degree_matrix(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(jdm), max_out_degree, max_in_degree, static_cast<igraph_vector_t*>(*weights)));
    return jdm;
  }

  auto js_eccentricity(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_eccentricity(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, mode));
    return res;
  }

  auto js_eccentricity_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_vs_t vids, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_eccentricity_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*res), vids, mode));
    return res;
  }

  auto js_graph_center(ig::igGraph* graph, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_graph_center(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), mode));
    return res;
  }

  auto js_graph_center_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_graph_center_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_t*>(*res), mode));
    return res;
  }

  auto js_radius(ig::igGraph* graph, igraph_neimode_t mode) {
    igraph_real_t radius;

    
    IGRAPH_JS_CHECK(igraph_radius(static_cast<igraph_t*>(*graph), &radius, mode));
    return radius;
  }

  auto js_radius_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_neimode_t mode) {
    igraph_real_t radius;

    
    IGRAPH_JS_CHECK(igraph_radius_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), &radius, mode));
    return radius;
  }

  auto js_pseudo_diameter(ig::igGraph* graph, igraph_integer_t start_vid, igraph_bool_t directed, igraph_bool_t unconnected) {
    igraph_real_t diameter;
    igraph_integer_t from;
    igraph_integer_t to;

    
    IGRAPH_JS_CHECK(igraph_pseudo_diameter(static_cast<igraph_t*>(*graph), &diameter, start_vid, &from, &to, directed, unconnected));
  }

  auto js_pseudo_diameter_dijkstra(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t start_vid, igraph_bool_t directed, igraph_bool_t unconnected) {
    igraph_real_t diameter;
    igraph_integer_t from;
    igraph_integer_t to;

    
    IGRAPH_JS_CHECK(igraph_pseudo_diameter_dijkstra(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), &diameter, start_vid, &from, &to, directed, unconnected));
  }

  auto js_diversity(ig::igGraph* graph, ig::igRealVec* weights, igraph_vs_t vids) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_diversity(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*res), vids));
    return res;
  }

  auto js_random_walk(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t start, igraph_neimode_t mode, igraph_integer_t steps, igraph_random_walk_stuck_t stuck) {
    std::unique_ptr<ig::igIntVec> vertices;
    std::unique_ptr<ig::igIntVec> edges;

    vertices = std::make_unique<ig::igIntVec>();
    edges = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_random_walk(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_t*>(*vertices), static_cast<igraph_vector_int_t*>(*edges), start, mode, steps, stuck));
  }

  auto js_random_edge_walk(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t start, igraph_neimode_t mode, igraph_integer_t steps, igraph_random_walk_stuck_t stuck) {
    std::unique_ptr<ig::igIntVec> edgewalk;

    edgewalk = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_random_edge_walk(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_t*>(*edgewalk), start, mode, steps, stuck));
    return edgewalk;
  }

  auto js_global_efficiency(ig::igGraph* graph, ig::igRealVec* weights, igraph_bool_t directed) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_global_efficiency(static_cast<igraph_t*>(*graph), &res, static_cast<igraph_vector_t*>(*weights), directed));
    return res;
  }

  auto js_local_efficiency(ig::igGraph* graph, igraph_vs_t vids, ig::igRealVec* weights, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_efficiency(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids, static_cast<igraph_vector_t*>(*weights), directed, mode));
    return res;
  }

  auto js_average_local_efficiency(ig::igGraph* graph, ig::igRealVec* weights, igraph_bool_t directed, igraph_neimode_t mode) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_average_local_efficiency(static_cast<igraph_t*>(*graph), &res, static_cast<igraph_vector_t*>(*weights), directed, mode));
    return res;
  }

  auto js_transitive_closure_dag(ig::igGraph* graph) {
    std::unique_ptr<ig::igGraph> closure;

    closure = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_transitive_closure_dag(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*closure)));
    return closure;
  }

  auto js_trussness(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> trussness;

    trussness = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_trussness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*trussness)));
    return trussness;
  }

  auto js_is_bigraphical(ig::igIntVec* degrees1, ig::igIntVec* degrees2, igraph_edge_type_sw_t allowed_edge_types) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_bigraphical(static_cast<igraph_vector_int_t*>(*degrees1), static_cast<igraph_vector_int_t*>(*degrees2), allowed_edge_types, &res));
    return res;
  }

  auto js_is_graphical(ig::igIntVec* out_deg, ig::igIntVec* in_deg, igraph_edge_type_sw_t allowed_edge_types) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_graphical(static_cast<igraph_vector_int_t*>(*out_deg), static_cast<igraph_vector_int_t*>(*in_deg), allowed_edge_types, &res));
    return res;
  }

  auto js_bfs(ig::igGraph* graph, igraph_integer_t root, ig::igIntVec* roots, igraph_neimode_t mode, igraph_bool_t unreachable, ig::igIntVec* restricted, igraph_bfshandler_t callback, void* extra) {
    std::unique_ptr<ig::igIntVec> order;
    std::unique_ptr<ig::igIntVec> rank;
    std::unique_ptr<ig::igIntVec> parents;
    std::unique_ptr<ig::igIntVec> pred;
    std::unique_ptr<ig::igIntVec> succ;
    std::unique_ptr<ig::igIntVec> dist;

    order = std::make_unique<ig::igIntVec>();
    rank = std::make_unique<ig::igIntVec>();
    parents = std::make_unique<ig::igIntVec>();
    pred = std::make_unique<ig::igIntVec>();
    succ = std::make_unique<ig::igIntVec>();
    dist = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_bfs(static_cast<igraph_t*>(*graph), root, static_cast<igraph_vector_int_t*>(*roots), mode, unreachable, static_cast<igraph_vector_int_t*>(*restricted), static_cast<igraph_vector_int_t*>(*order), static_cast<igraph_vector_int_t*>(*rank), static_cast<igraph_vector_int_t*>(*parents), static_cast<igraph_vector_int_t*>(*pred), static_cast<igraph_vector_int_t*>(*succ), static_cast<igraph_vector_int_t*>(*dist), callback, 0));
  }

  auto js_bfs_simple(ig::igGraph* graph, igraph_integer_t root, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> order;
    std::unique_ptr<ig::igIntVec> layers;
    std::unique_ptr<ig::igIntVec> parents;

    order = std::make_unique<ig::igIntVec>();
    layers = std::make_unique<ig::igIntVec>();
    parents = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_bfs_simple(static_cast<igraph_t*>(*graph), root, mode, static_cast<igraph_vector_int_t*>(*order), static_cast<igraph_vector_int_t*>(*layers), static_cast<igraph_vector_int_t*>(*parents)));
  }

  auto js_dfs(ig::igGraph* graph, igraph_integer_t root, igraph_neimode_t mode, igraph_bool_t unreachable, igraph_dfshandler_t in_callback, igraph_dfshandler_t out_callback, void* extra) {
    std::unique_ptr<ig::igIntVec> order;
    std::unique_ptr<ig::igIntVec> order_out;
    std::unique_ptr<ig::igIntVec> father;
    std::unique_ptr<ig::igIntVec> dist;

    order = std::make_unique<ig::igIntVec>();
    order_out = std::make_unique<ig::igIntVec>();
    father = std::make_unique<ig::igIntVec>();
    dist = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_dfs(static_cast<igraph_t*>(*graph), root, mode, unreachable, static_cast<igraph_vector_int_t*>(*order), static_cast<igraph_vector_int_t*>(*order_out), static_cast<igraph_vector_int_t*>(*father), static_cast<igraph_vector_int_t*>(*dist), in_callback, out_callback, 0));
  }

  auto js_bipartite_projection_size(ig::igGraph* graph, ig::igBoolVec* types) {
    igraph_integer_t vcount1;
    igraph_integer_t ecount1;
    igraph_integer_t vcount2;
    igraph_integer_t ecount2;

    
    IGRAPH_JS_CHECK(igraph_bipartite_projection_size(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), &vcount1, &ecount1, &vcount2, &ecount2));
  }

  auto js_bipartite_projection(ig::igGraph* graph, ig::igBoolVec* types, igraph_integer_t probe1) {
    std::unique_ptr<ig::igGraph> proj1;
    std::unique_ptr<ig::igGraph> proj2;
    std::unique_ptr<ig::igIntVec> multiplicity1;
    std::unique_ptr<ig::igIntVec> multiplicity2;

    proj1 = std::make_unique<ig::igGraph>();
    proj2 = std::make_unique<ig::igGraph>();
    multiplicity1 = std::make_unique<ig::igIntVec>();
    multiplicity2 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_bipartite_projection(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_t*>(*proj1), static_cast<igraph_t*>(*proj2), static_cast<igraph_vector_int_t*>(*multiplicity1), static_cast<igraph_vector_int_t*>(*multiplicity2), probe1));
  }

  auto js_create_bipartite(ig::igBoolVec* types, ig::igIntVec* edges, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_create_bipartite(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_vector_int_t*>(*edges), directed));
    return graph;
  }

  auto js_biadjacency(ig::igRealMatrix incidence, igraph_bool_t directed, igraph_neimode_t mode, igraph_bool_t multiple) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igBoolVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_biadjacency(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_matrix_t*>(incidence), directed, mode, multiple));
  }

  auto js_get_biadjacency(ig::igGraph* graph, ig::igBoolVec* types) {
    ig::igRealMatrix res;
    std::unique_ptr<ig::igIntVec> row_ids;
    std::unique_ptr<ig::igIntVec> col_ids;

    row_ids = std::make_unique<ig::igIntVec>();
    col_ids = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_biadjacency(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_matrix_t*>(res), static_cast<igraph_vector_int_t*>(*row_ids), static_cast<igraph_vector_int_t*>(*col_ids)));
  }

  auto js_is_bipartite(ig::igGraph* graph) {
    igraph_bool_t res;
    std::unique_ptr<ig::igBoolVec> type;

    type = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_is_bipartite(static_cast<igraph_t*>(*graph), &res, static_cast<igraph_vector_bool_t*>(*type)));
  }

  auto js_bipartite_game_gnp(igraph_integer_t n1, igraph_integer_t n2, igraph_real_t p, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igBoolVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_bipartite_game_gnp(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), n1, n2, p, directed, mode));
  }

  auto js_bipartite_game_gnm(igraph_integer_t n1, igraph_integer_t n2, igraph_integer_t m, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igBoolVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_bipartite_game_gnm(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), n1, n2, m, directed, mode));
  }

  auto js_bipartite_game(igraph_erdos_renyi_t type, igraph_integer_t n1, igraph_integer_t n2, igraph_real_t p, igraph_integer_t m, igraph_bool_t directed, igraph_neimode_t mode) {
    std::unique_ptr<ig::igGraph> graph;
    std::unique_ptr<ig::igBoolVec> types;

    graph = std::make_unique<ig::igGraph>();
    types = std::make_unique<ig::igBoolVec>();

    IGRAPH_JS_CHECK(igraph_bipartite_game(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), type, n1, n2, p, m, directed, mode));
  }

  auto js_get_laplacian(ig::igGraph* graph, igraph_neimode_t mode, igraph_laplacian_normalization_t normalization, ig::igRealVec* weights) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_get_laplacian(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), mode, normalization, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_connected_components(ig::igGraph* graph, igraph_connectedness_t mode) {
    std::unique_ptr<ig::igIntVec> membership;
    std::unique_ptr<ig::igIntVec> csize;
    igraph_integer_t no;

    membership = std::make_unique<ig::igIntVec>();
    csize = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_connected_components(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*csize), &no, mode));
  }

  auto js_is_connected(ig::igGraph* graph, igraph_connectedness_t mode) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_connected(static_cast<igraph_t*>(*graph), &res, mode));
    return res;
  }

  auto js_articulation_points(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_articulation_points(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res)));
    return res;
  }

  auto js_biconnected_components(ig::igGraph* graph) {
    igraph_integer_t no;
    std::unique_ptr<ig::igVecIntList> tree_edges;
    std::unique_ptr<ig::igVecIntList> component_edges;
    std::unique_ptr<ig::igVecIntList> components;
    std::unique_ptr<ig::igIntVec> articulation_points;

    tree_edges = std::make_unique<ig::igVecIntList>();
    component_edges = std::make_unique<ig::igVecIntList>();
    components = std::make_unique<ig::igVecIntList>();
    articulation_points = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_biconnected_components(static_cast<igraph_t*>(*graph), &no, static_cast<igraph_vector_int_list_t*>(*tree_edges), static_cast<igraph_vector_int_list_t*>(*component_edges), static_cast<igraph_vector_int_list_t*>(*components), static_cast<igraph_vector_int_t*>(*articulation_points)));
  }

  auto js_bridges(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_bridges(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res)));
    return res;
  }

  auto js_cliques(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_cliques(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res), min_size, max_size));
    return res;
  }

  auto js_clique_size_hist(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igRealVec> hist;

    hist = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_clique_size_hist(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*hist), min_size, max_size));
    return hist;
  }

  auto js_largest_cliques(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_largest_cliques(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res)));
    return res;
  }

  auto js_maximal_cliques(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_maximal_cliques(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res), min_size, max_size));
    return res;
  }

  auto js_maximal_cliques_subset(ig::igGraph* graph, ig::igIntVec* subset, FILE* outfile, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igVecIntList> res;
    igraph_integer_t no;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_maximal_cliques_subset(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*subset), static_cast<igraph_vector_int_list_t*>(*res), &no, outfile, min_size, max_size));
  }

  auto js_maximal_cliques_count(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    igraph_integer_t no;

    
    IGRAPH_JS_CHECK(igraph_maximal_cliques_count(static_cast<igraph_t*>(*graph), &no, min_size, max_size));
    return no;
  }

  auto js_maximal_cliques_hist(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igRealVec> hist;

    hist = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_maximal_cliques_hist(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*hist), min_size, max_size));
    return hist;
  }

  auto js_clique_number(ig::igGraph* graph) {
    igraph_integer_t no;

    
    IGRAPH_JS_CHECK(igraph_clique_number(static_cast<igraph_t*>(*graph), &no));
    return no;
  }

  auto js_weighted_cliques(ig::igGraph* graph, ig::igRealVec* vertex_weights, igraph_real_t min_weight, igraph_real_t max_weight, igraph_bool_t maximal) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_weighted_cliques(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*vertex_weights), static_cast<igraph_vector_int_list_t*>(*res), min_weight, max_weight, maximal));
    return res;
  }

  auto js_largest_weighted_cliques(ig::igGraph* graph, ig::igRealVec* vertex_weights) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_largest_weighted_cliques(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*vertex_weights), static_cast<igraph_vector_int_list_t*>(*res)));
    return res;
  }

  auto js_weighted_clique_number(ig::igGraph* graph, ig::igRealVec* vertex_weights) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_weighted_clique_number(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*vertex_weights), &res));
    return res;
  }

  auto js_independent_vertex_sets(ig::igGraph* graph, igraph_integer_t min_size, igraph_integer_t max_size) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_independent_vertex_sets(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res), min_size, max_size));
    return res;
  }

  auto js_largest_independent_vertex_sets(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_largest_independent_vertex_sets(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res)));
    return res;
  }

  auto js_maximal_independent_vertex_sets(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> res;

    res = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_maximal_independent_vertex_sets(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*res)));
    return res;
  }

  auto js_independence_number(ig::igGraph* graph) {
    igraph_integer_t no;

    
    IGRAPH_JS_CHECK(igraph_independence_number(static_cast<igraph_t*>(*graph), &no));
    return no;
  }

  auto js_layout_random(ig::igGraph* graph) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_random(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_layout_circle(ig::igGraph* graph, igraph_vs_t order) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_circle(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), order));
    return res;
  }

  auto js_layout_star(ig::igGraph* graph, igraph_integer_t center, ig::igIntVec* order) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_star(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), center, static_cast<igraph_vector_int_t*>(*order)));
    return res;
  }

  auto js_layout_grid(ig::igGraph* graph, igraph_integer_t width) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_grid(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), width));
    return res;
  }

  auto js_layout_grid_3d(ig::igGraph* graph, igraph_integer_t width, igraph_integer_t height) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_grid_3d(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), width, height));
    return res;
  }

  auto js_layout_kamada_kawai(ig::igGraph* graph, ig::igRealMatrix coords, igraph_bool_t use_seed, igraph_integer_t maxiter, igraph_real_t epsilon, igraph_real_t kkconst, ig::igRealVec* weights, ig::igRealVec* minx, ig::igRealVec* maxx, ig::igRealVec* miny, ig::igRealVec* maxy) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_kamada_kawai(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(coords), use_seed, maxiter, epsilon, kkconst, static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*minx), static_cast<igraph_vector_t*>(*maxx), static_cast<igraph_vector_t*>(*miny), static_cast<igraph_vector_t*>(*maxy)));
    return coords;
  }

  auto js_layout_lgl(ig::igGraph* graph, igraph_integer_t maxiter, igraph_real_t maxdelta, igraph_real_t area, igraph_real_t coolexp, igraph_real_t repulserad, igraph_real_t cellsize, igraph_integer_t root) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_lgl(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), maxiter, maxdelta, area, coolexp, repulserad, cellsize, root));
    return res;
  }

  auto js_layout_reingold_tilford(ig::igGraph* graph, igraph_neimode_t mode, ig::igIntVec* roots, ig::igIntVec* rootlevel) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_reingold_tilford(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), mode, static_cast<igraph_vector_int_t*>(*roots), static_cast<igraph_vector_int_t*>(*rootlevel)));
    return res;
  }

  auto js_layout_reingold_tilford_circular(ig::igGraph* graph, igraph_neimode_t mode, ig::igIntVec* roots, ig::igIntVec* rootlevel) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_reingold_tilford_circular(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), mode, static_cast<igraph_vector_int_t*>(*roots), static_cast<igraph_vector_int_t*>(*rootlevel)));
    return res;
  }

  auto js_roots_for_tree_layout(ig::igGraph* graph, igraph_neimode_t mode, igraph_root_choice_t heuristic) {
    std::unique_ptr<ig::igIntVec> roots;

    roots = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_roots_for_tree_layout(static_cast<igraph_t*>(*graph), mode, static_cast<igraph_vector_int_t*>(*roots), heuristic));
    return roots;
  }

  auto js_layout_random_3d(ig::igGraph* graph) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_random_3d(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_layout_sphere(ig::igGraph* graph) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_sphere(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res)));
    return res;
  }

  auto js_layout_kamada_kawai_3d(ig::igGraph* graph, ig::igRealMatrix coords, igraph_bool_t use_seed, igraph_integer_t maxiter, igraph_real_t epsilon, igraph_real_t kkconst, ig::igRealVec* weights, ig::igRealVec* minx, ig::igRealVec* maxx, ig::igRealVec* miny, ig::igRealVec* maxy, ig::igRealVec* minz, ig::igRealVec* maxz) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_kamada_kawai_3d(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(coords), use_seed, maxiter, epsilon, kkconst, static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*minx), static_cast<igraph_vector_t*>(*maxx), static_cast<igraph_vector_t*>(*miny), static_cast<igraph_vector_t*>(*maxy), static_cast<igraph_vector_t*>(*minz), static_cast<igraph_vector_t*>(*maxz)));
    return coords;
  }

  auto js_layout_graphopt(ig::igGraph* graph, ig::igRealMatrix res, igraph_integer_t niter, igraph_real_t node_charge, igraph_real_t node_mass, igraph_real_t spring_length, igraph_real_t spring_constant, igraph_real_t max_sa_movement, igraph_bool_t use_seed) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_graphopt(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), niter, node_charge, node_mass, spring_length, spring_constant, max_sa_movement, use_seed));
    return res;
  }

  auto js_layout_sugiyama(ig::igGraph* graph, ig::igIntVec* layers, igraph_real_t hgap, igraph_real_t vgap, igraph_integer_t maxiter, ig::igRealVec* weights) {
    ig::igRealMatrix res;
    std::unique_ptr<ig::igGraph> extd_graph;
    std::unique_ptr<ig::igIntVec> extd_to_orig_eids;

    extd_graph = std::make_unique<ig::igGraph>();
    extd_to_orig_eids = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_layout_sugiyama(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), static_cast<igraph_t*>(*extd_graph), static_cast<igraph_vector_int_t*>(*extd_to_orig_eids), static_cast<igraph_vector_int_t*>(*layers), hgap, vgap, maxiter, static_cast<igraph_vector_t*>(*weights)));
  }

  auto js_layout_mds(ig::igGraph* graph, ig::igRealMatrix dist, igraph_integer_t dim) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_mds(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), static_cast<igraph_matrix_t*>(dist), dim));
    return res;
  }

  auto js_layout_bipartite(ig::igGraph* graph, ig::igBoolVec* types, igraph_real_t hgap, igraph_real_t vgap, igraph_integer_t maxiter) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_layout_bipartite(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_matrix_t*>(res), hgap, vgap, maxiter));
    return res;
  }

  auto js_layout_gem(ig::igGraph* graph, ig::igRealMatrix res, igraph_bool_t use_seed, igraph_integer_t maxiter, igraph_real_t temp_max, igraph_real_t temp_min, igraph_real_t temp_init) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_gem(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), use_seed, maxiter, temp_max, temp_min, temp_init));
    return res;
  }

  auto js_layout_davidson_harel(ig::igGraph* graph, ig::igRealMatrix res, igraph_bool_t use_seed, igraph_integer_t maxiter, igraph_integer_t fineiter, igraph_real_t cool_fact, igraph_real_t weight_node_dist, igraph_real_t weight_border, igraph_real_t weight_edge_lengths, igraph_real_t weight_edge_crossings, igraph_real_t weight_node_edge_dist) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_davidson_harel(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), use_seed, maxiter, fineiter, cool_fact, weight_node_dist, weight_border, weight_edge_lengths, weight_edge_crossings, weight_node_edge_dist));
    return res;
  }

  auto js_layout_umap(ig::igGraph* graph, ig::igRealMatrix res, igraph_bool_t use_seed, ig::igRealVec* distances, igraph_real_t min_dist, igraph_integer_t epochs, igraph_bool_t distances_are_weights) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_umap(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), use_seed, static_cast<igraph_vector_t*>(*distances), min_dist, epochs, distances_are_weights));
    return res;
  }

  auto js_layout_umap_3d(ig::igGraph* graph, ig::igRealMatrix res, igraph_bool_t use_seed, ig::igRealVec* distances, igraph_real_t min_dist, igraph_integer_t epochs, igraph_bool_t distances_are_weights) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_umap_3d(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), use_seed, static_cast<igraph_vector_t*>(*distances), min_dist, epochs, distances_are_weights));
    return res;
  }

  auto js_layout_umap_compute_weights(ig::igGraph* graph, ig::igRealVec* distances, ig::igRealVec* weights) {
    
    
    IGRAPH_JS_CHECK(igraph_layout_umap_compute_weights(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*distances), static_cast<igraph_vector_t*>(*weights)));
    return weights;
  }

  auto js_cocitation(ig::igGraph* graph, igraph_vs_t vids) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_cocitation(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), vids));
    return res;
  }

  auto js_bibcoupling(ig::igGraph* graph, igraph_vs_t vids) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_bibcoupling(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), vids));
    return res;
  }

  auto js_similarity_dice(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_bool_t loops) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_similarity_dice(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), vids, mode, loops));
    return res;
  }

  auto js_similarity_dice_es(ig::igGraph* graph, igraph_es_t es, igraph_neimode_t mode, igraph_bool_t loops) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_similarity_dice_es(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), es, mode, loops));
    return res;
  }

  auto js_similarity_dice_pairs(ig::igGraph* graph, ig::igIntVec* pairs, igraph_neimode_t mode, igraph_bool_t loops) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_similarity_dice_pairs(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_int_t*>(*pairs), mode, loops));
    return res;
  }

  auto js_similarity_inverse_log_weighted(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_similarity_inverse_log_weighted(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), vids, mode));
    return res;
  }

  auto js_similarity_jaccard(ig::igGraph* graph, igraph_vs_t vids, igraph_neimode_t mode, igraph_bool_t loops) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_similarity_jaccard(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), vids, mode, loops));
    return res;
  }

  auto js_similarity_jaccard_es(ig::igGraph* graph, igraph_es_t es, igraph_neimode_t mode, igraph_bool_t loops) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_similarity_jaccard_es(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), es, mode, loops));
    return res;
  }

  auto js_similarity_jaccard_pairs(ig::igGraph* graph, ig::igIntVec* pairs, igraph_neimode_t mode, igraph_bool_t loops) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_similarity_jaccard_pairs(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_int_t*>(*pairs), mode, loops));
    return res;
  }

  auto js_compare_communities(ig::igIntVec* comm1, ig::igIntVec* comm2, igraph_community_comparison_t method) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_compare_communities(static_cast<igraph_vector_int_t*>(*comm1), static_cast<igraph_vector_int_t*>(*comm2), &res, method));
    return res;
  }

  auto js_community_spinglass(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t spins, igraph_bool_t parupdate, igraph_real_t starttemp, igraph_real_t stoptemp, igraph_real_t coolfact, igraph_spincomm_update_t update_rule, igraph_real_t gamma, igraph_spinglass_implementation_t implementation, igraph_real_t lambda) {
    igraph_real_t modularity;
    igraph_real_t temperature;
    std::unique_ptr<ig::igIntVec> membership;
    std::unique_ptr<ig::igIntVec> csize;

    membership = std::make_unique<ig::igIntVec>();
    csize = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_spinglass(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), &modularity, &temperature, static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*csize), spins, parupdate, starttemp, stoptemp, coolfact, update_rule, gamma, implementation, lambda));
  }

  auto js_community_spinglass_single(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t vertex, igraph_integer_t spins, igraph_spincomm_update_t update_rule, igraph_real_t gamma) {
    std::unique_ptr<ig::igIntVec> community;
    igraph_real_t cohesion;
    igraph_real_t adhesion;
    igraph_integer_t inner_links;
    igraph_integer_t outer_links;

    community = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_spinglass_single(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), vertex, static_cast<igraph_vector_int_t*>(*community), &cohesion, &adhesion, &inner_links, &outer_links, spins, update_rule, gamma));
  }

  auto js_community_walktrap(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t steps) {
    ig::igIntMatrix merges;
    std::unique_ptr<ig::igRealVec> modularity;
    std::unique_ptr<ig::igIntVec> membership;

    modularity = std::make_unique<ig::igRealVec>();
    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_walktrap(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), steps, static_cast<igraph_matrix_int_t*>(merges), static_cast<igraph_vector_t*>(*modularity), static_cast<igraph_vector_int_t*>(*membership)));
  }

  auto js_community_edge_betweenness(ig::igGraph* graph, igraph_bool_t directed, ig::igRealVec* weights) {
    std::unique_ptr<ig::igIntVec> result;
    std::unique_ptr<ig::igRealVec> edge_betweenness;
    ig::igIntMatrix merges;
    std::unique_ptr<ig::igIntVec> bridges;
    std::unique_ptr<ig::igRealVec> modularity;
    std::unique_ptr<ig::igIntVec> membership;

    result = std::make_unique<ig::igIntVec>();
    edge_betweenness = std::make_unique<ig::igRealVec>();
    bridges = std::make_unique<ig::igIntVec>();
    modularity = std::make_unique<ig::igRealVec>();
    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_edge_betweenness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*result), static_cast<igraph_vector_t*>(*edge_betweenness), static_cast<igraph_matrix_int_t*>(merges), static_cast<igraph_vector_int_t*>(*bridges), static_cast<igraph_vector_t*>(*modularity), static_cast<igraph_vector_int_t*>(*membership), directed, static_cast<igraph_vector_t*>(*weights)));
  }

  auto js_community_eb_get_merges(ig::igGraph* graph, igraph_bool_t directed, ig::igIntVec* edges, ig::igRealVec* weights) {
    ig::igIntMatrix merges;
    std::unique_ptr<ig::igIntVec> bridges;
    std::unique_ptr<ig::igRealVec> modularity;
    std::unique_ptr<ig::igIntVec> membership;

    bridges = std::make_unique<ig::igIntVec>();
    modularity = std::make_unique<ig::igRealVec>();
    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_eb_get_merges(static_cast<igraph_t*>(*graph), directed, static_cast<igraph_vector_int_t*>(*edges), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_matrix_int_t*>(merges), static_cast<igraph_vector_int_t*>(*bridges), static_cast<igraph_vector_t*>(*modularity), static_cast<igraph_vector_int_t*>(*membership)));
  }

  auto js_community_fastgreedy(ig::igGraph* graph, ig::igRealVec* weights) {
    ig::igIntMatrix merges;
    std::unique_ptr<ig::igRealVec> modularity;
    std::unique_ptr<ig::igIntVec> membership;

    modularity = std::make_unique<ig::igRealVec>();
    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_fastgreedy(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_matrix_int_t*>(merges), static_cast<igraph_vector_t*>(*modularity), static_cast<igraph_vector_int_t*>(*membership)));
  }

  auto js_community_to_membership(ig::igIntMatrix merges, igraph_integer_t nodes, igraph_integer_t steps) {
    std::unique_ptr<ig::igIntVec> membership;
    std::unique_ptr<ig::igIntVec> csize;

    membership = std::make_unique<ig::igIntVec>();
    csize = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_to_membership(static_cast<igraph_matrix_int_t*>(merges), nodes, steps, static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*csize)));
  }

  auto js_le_community_to_membership(ig::igIntMatrix merges, igraph_integer_t steps, ig::igIntVec* membership) {
    std::unique_ptr<ig::igIntVec> csize;

    csize = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_le_community_to_membership(static_cast<igraph_matrix_int_t*>(merges), steps, static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*csize)));
  }

  auto js_modularity(ig::igGraph* graph, ig::igIntVec* membership, ig::igRealVec* weights, igraph_real_t resolution, igraph_bool_t directed) {
    igraph_real_t modularity;

    
    IGRAPH_JS_CHECK(igraph_modularity(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_t*>(*weights), resolution, directed, &modularity));
    return modularity;
  }

  auto js_modularity_matrix(ig::igGraph* graph, ig::igRealVec* weights, igraph_real_t resolution, igraph_bool_t directed) {
    ig::igRealMatrix modmat;

    
    IGRAPH_JS_CHECK(igraph_modularity_matrix(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), resolution, static_cast<igraph_matrix_t*>(modmat), directed));
    return modmat;
  }

  auto js_reindex_membership(ig::igIntVec* membership) {
    std::unique_ptr<ig::igIntVec> new_to_old;
    igraph_integer_t nb_clusters;

    new_to_old = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_reindex_membership(static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*new_to_old), &nb_clusters));
  }

  auto js_community_fluid_communities(ig::igGraph* graph, igraph_integer_t no_of_communities) {
    std::unique_ptr<ig::igIntVec> membership;

    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_fluid_communities(static_cast<igraph_t*>(*graph), no_of_communities, static_cast<igraph_vector_int_t*>(*membership)));
    return membership;
  }

  auto js_community_label_propagation(ig::igGraph* graph, igraph_neimode_t mode, ig::igRealVec* weights, ig::igIntVec* initial, ig::igBoolVec* fixed) {
    std::unique_ptr<ig::igIntVec> membership;

    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_label_propagation(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*membership), mode, static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_t*>(*initial), static_cast<igraph_vector_bool_t*>(*fixed)));
    return membership;
  }

  auto js_community_multilevel(ig::igGraph* graph, ig::igRealVec* weights, igraph_real_t resolution) {
    std::unique_ptr<ig::igIntVec> membership;
    ig::igIntMatrix memberships;
    std::unique_ptr<ig::igRealVec> modularity;

    membership = std::make_unique<ig::igIntVec>();
    modularity = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_community_multilevel(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), resolution, static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_matrix_int_t*>(memberships), static_cast<igraph_vector_t*>(*modularity)));
  }

  auto js_community_optimal_modularity(ig::igGraph* graph, ig::igRealVec* weights) {
    igraph_real_t modularity;
    std::unique_ptr<ig::igIntVec> membership;

    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_optimal_modularity(static_cast<igraph_t*>(*graph), &modularity, static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_t*>(*weights)));
  }

  auto js_community_leiden(ig::igGraph* graph, ig::igRealVec* weights, ig::igRealVec* vertex_weights, igraph_real_t resolution, igraph_real_t beta, igraph_bool_t start, igraph_integer_t n_iterations, ig::igIntVec* membership) {
    igraph_integer_t nb_clusters;
    igraph_real_t quality;

    
    IGRAPH_JS_CHECK(igraph_community_leiden(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*vertex_weights), resolution, beta, start, n_iterations, static_cast<igraph_vector_int_t*>(*membership), &nb_clusters, &quality));
  }

  auto js_split_join_distance(ig::igIntVec* comm1, ig::igIntVec* comm2) {
    igraph_integer_t distance12;
    igraph_integer_t distance21;

    
    IGRAPH_JS_CHECK(igraph_split_join_distance(static_cast<igraph_vector_int_t*>(*comm1), static_cast<igraph_vector_int_t*>(*comm2), &distance12, &distance21));
  }

  auto js_community_infomap(ig::igGraph* graph, ig::igRealVec* e_weights, ig::igRealVec* v_weights, igraph_integer_t nb_trials) {
    std::unique_ptr<ig::igIntVec> membership;
    igraph_real_t codelength;

    membership = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_infomap(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*e_weights), static_cast<igraph_vector_t*>(*v_weights), nb_trials, static_cast<igraph_vector_int_t*>(*membership), &codelength));
  }

  auto js_community_voronoi(ig::igGraph* graph, ig::igRealVec* lengths, ig::igRealVec* weights, igraph_neimode_t mode, igraph_real_t radius) {
    std::unique_ptr<ig::igIntVec> membership;
    std::unique_ptr<ig::igIntVec> generators;
    igraph_real_t modularity;

    membership = std::make_unique<ig::igIntVec>();
    generators = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_community_voronoi(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*membership), static_cast<igraph_vector_int_t*>(*generators), &modularity, static_cast<igraph_vector_t*>(*lengths), static_cast<igraph_vector_t*>(*weights), mode, radius));
  }

  auto js_graphlets(ig::igGraph* graph, ig::igRealVec* weights, igraph_integer_t niter) {
    std::unique_ptr<ig::igVecIntList> cliques;
    std::unique_ptr<ig::igRealVec> Mu;

    cliques = std::make_unique<ig::igVecIntList>();
    Mu = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_graphlets(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*cliques), static_cast<igraph_vector_t*>(*Mu), niter));
  }

  auto js_graphlets_candidate_basis(ig::igGraph* graph, ig::igRealVec* weights) {
    std::unique_ptr<ig::igVecIntList> cliques;
    std::unique_ptr<ig::igRealVec> thresholds;

    cliques = std::make_unique<ig::igVecIntList>();
    thresholds = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_graphlets_candidate_basis(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*cliques), static_cast<igraph_vector_t*>(*thresholds)));
  }

  auto js_graphlets_project(ig::igGraph* graph, ig::igRealVec* weights, ig::igVecIntList* cliques, ig::igRealVec* Muc, igraph_bool_t startMu, igraph_integer_t niter) {
    
    
    IGRAPH_JS_CHECK(igraph_graphlets_project(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*cliques), static_cast<igraph_vector_t*>(*Muc), startMu, niter));
    return Muc;
  }

  auto js_get_adjacency(ig::igGraph* graph, igraph_get_adjacency_t type, ig::igRealVec* weights, igraph_loops_t loops) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_get_adjacency(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), type, static_cast<igraph_vector_t*>(*weights), loops));
    return res;
  }

  auto js_get_edgelist(ig::igGraph* graph, igraph_bool_t bycol) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_get_edgelist(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), bycol));
    return res;
  }

  auto js_get_stochastic(ig::igGraph* graph, igraph_bool_t column_wise, ig::igRealVec* weights) {
    ig::igRealMatrix res;

    
    IGRAPH_JS_CHECK(igraph_get_stochastic(static_cast<igraph_t*>(*graph), static_cast<igraph_matrix_t*>(res), column_wise, static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_to_directed(ig::igGraph* graph, igraph_to_directed_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_to_directed(static_cast<igraph_t*>(*graph), mode));
    return graph;
  }

  auto js_read_graph_edgelist(FILE* instream, igraph_integer_t n, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_edgelist(static_cast<igraph_t*>(*graph), instream, n, directed));
    return graph;
  }

  auto js_read_graph_lgl(FILE* instream, igraph_bool_t names, igraph_add_weights_t weights, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_lgl(static_cast<igraph_t*>(*graph), instream, names, weights, directed));
    return graph;
  }

  auto js_read_graph_pajek(FILE* instream) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_pajek(static_cast<igraph_t*>(*graph), instream));
    return graph;
  }

  auto js_read_graph_graphml(FILE* instream, igraph_integer_t index) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_graphml(static_cast<igraph_t*>(*graph), instream, index));
    return graph;
  }

  auto js_read_graph_graphdb(FILE* instream, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_graphdb(static_cast<igraph_t*>(*graph), instream, directed));
    return graph;
  }

  auto js_read_graph_gml(FILE* instream) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_gml(static_cast<igraph_t*>(*graph), instream));
    return graph;
  }

  auto js_read_graph_dl(FILE* instream, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_read_graph_dl(static_cast<igraph_t*>(*graph), instream, directed));
    return graph;
  }

  auto js_motifs_randesu(ig::igGraph* graph, igraph_integer_t size, ig::igRealVec* cut_prob) {
    std::unique_ptr<ig::igRealVec> hist;

    hist = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_motifs_randesu(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*hist), size, static_cast<igraph_vector_t*>(*cut_prob)));
    return hist;
  }

  auto js_motifs_randesu_estimate(ig::igGraph* graph, igraph_integer_t size, ig::igRealVec* cut_prob, igraph_integer_t sample_size, ig::igIntVec* sample) {
    igraph_integer_t est;

    
    IGRAPH_JS_CHECK(igraph_motifs_randesu_estimate(static_cast<igraph_t*>(*graph), &est, size, static_cast<igraph_vector_t*>(*cut_prob), sample_size, static_cast<igraph_vector_int_t*>(*sample)));
    return est;
  }

  auto js_motifs_randesu_no(ig::igGraph* graph, igraph_integer_t size, ig::igRealVec* cut_prob) {
    igraph_integer_t no;

    
    IGRAPH_JS_CHECK(igraph_motifs_randesu_no(static_cast<igraph_t*>(*graph), &no, size, static_cast<igraph_vector_t*>(*cut_prob)));
    return no;
  }

  auto js_dyad_census(ig::igGraph* graph) {
    igraph_real_t mut;
    igraph_real_t asym;
    igraph_real_t null;

    
    IGRAPH_JS_CHECK(igraph_dyad_census(static_cast<igraph_t*>(*graph), &mut, &asym, &null));
  }

  auto js_triad_census(ig::igGraph* graph) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_triad_census(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res)));
    return res;
  }

  auto js_adjacent_triangles(ig::igGraph* graph, igraph_vs_t vids) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_adjacent_triangles(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), vids));
    return res;
  }

  auto js_local_scan_0(ig::igGraph* graph, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_0(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_local_scan_0_them(ig::igGraph* us, ig::igGraph* them, ig::igRealVec* weights_them, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_0_them(static_cast<igraph_t*>(*us), static_cast<igraph_t*>(*them), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights_them), mode));
    return res;
  }

  auto js_local_scan_1_ecount(ig::igGraph* graph, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_1_ecount(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_local_scan_1_ecount_them(ig::igGraph* us, ig::igGraph* them, ig::igRealVec* weights_them, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_1_ecount_them(static_cast<igraph_t*>(*us), static_cast<igraph_t*>(*them), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights_them), mode));
    return res;
  }

  auto js_local_scan_k_ecount(ig::igGraph* graph, igraph_integer_t k, ig::igRealVec* weights, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_k_ecount(static_cast<igraph_t*>(*graph), k, static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights), mode));
    return res;
  }

  auto js_local_scan_k_ecount_them(ig::igGraph* us, ig::igGraph* them, igraph_integer_t k, ig::igRealVec* weights_them, igraph_neimode_t mode) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_k_ecount_them(static_cast<igraph_t*>(*us), static_cast<igraph_t*>(*them), k, static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights_them), mode));
    return res;
  }

  auto js_local_scan_neighborhood_ecount(ig::igGraph* graph, ig::igRealVec* weights, ig::igVecIntList* neighborhoods) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_neighborhood_ecount(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*neighborhoods)));
    return res;
  }

  auto js_local_scan_subset_ecount(ig::igGraph* graph, ig::igRealVec* weights, ig::igVecIntList* subsets) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_local_scan_subset_ecount(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*res), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_int_list_t*>(*subsets)));
    return res;
  }

  auto js_list_triangles(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_list_triangles(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res)));
    return res;
  }

  auto js_disjoint_union(ig::igGraph* left, ig::igGraph* right) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_disjoint_union(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*left), static_cast<igraph_t*>(*right)));
    return res;
  }

  auto js_union(ig::igGraph* left, ig::igGraph* right) {
    std::unique_ptr<ig::igGraph> res;
    std::unique_ptr<ig::igIntVec> edge_map_left;
    std::unique_ptr<ig::igIntVec> edge_map_right;

    res = std::make_unique<ig::igGraph>();
    edge_map_left = std::make_unique<ig::igIntVec>();
    edge_map_right = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_union(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*left), static_cast<igraph_t*>(*right), static_cast<igraph_vector_int_t*>(*edge_map_left), static_cast<igraph_vector_int_t*>(*edge_map_right)));
  }

  auto js_intersection(ig::igGraph* left, ig::igGraph* right) {
    std::unique_ptr<ig::igGraph> res;
    std::unique_ptr<ig::igIntVec> edge_map_left;
    std::unique_ptr<ig::igIntVec> edge_map_right;

    res = std::make_unique<ig::igGraph>();
    edge_map_left = std::make_unique<ig::igIntVec>();
    edge_map_right = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_intersection(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*left), static_cast<igraph_t*>(*right), static_cast<igraph_vector_int_t*>(*edge_map_left), static_cast<igraph_vector_int_t*>(*edge_map_right)));
  }

  auto js_difference(ig::igGraph* orig, ig::igGraph* sub) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_difference(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*orig), static_cast<igraph_t*>(*sub)));
    return res;
  }

  auto js_complementer(ig::igGraph* graph, igraph_bool_t loops) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_complementer(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*graph), loops));
    return res;
  }

  auto js_compose(ig::igGraph* g1, ig::igGraph* g2) {
    std::unique_ptr<ig::igGraph> res;
    std::unique_ptr<ig::igIntVec> edge_map1;
    std::unique_ptr<ig::igIntVec> edge_map2;

    res = std::make_unique<ig::igGraph>();
    edge_map1 = std::make_unique<ig::igIntVec>();
    edge_map2 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_compose(static_cast<igraph_t*>(*res), static_cast<igraph_t*>(*g1), static_cast<igraph_t*>(*g2), static_cast<igraph_vector_int_t*>(*edge_map1), static_cast<igraph_vector_int_t*>(*edge_map2)));
  }

  auto js_induced_subgraph_map(ig::igGraph* graph, igraph_vs_t vids, igraph_subgraph_implementation_t impl) {
    std::unique_ptr<ig::igGraph> res;
    std::unique_ptr<ig::igIntVec> map;
    std::unique_ptr<ig::igIntVec> invmap;

    res = std::make_unique<ig::igGraph>();
    map = std::make_unique<ig::igIntVec>();
    invmap = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_induced_subgraph_map(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), vids, impl, static_cast<igraph_vector_int_t*>(*map), static_cast<igraph_vector_int_t*>(*invmap)));
  }

  auto js_gomory_hu_tree(ig::igGraph* graph, ig::igRealVec* capacity) {
    std::unique_ptr<ig::igGraph> tree;
    std::unique_ptr<ig::igRealVec> flows;

    tree = std::make_unique<ig::igGraph>();
    flows = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_gomory_hu_tree(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*tree), static_cast<igraph_vector_t*>(*flows), static_cast<igraph_vector_t*>(*capacity)));
  }

  auto js_mincut(ig::igGraph* graph, ig::igRealVec* capacity) {
    igraph_real_t value;
    std::unique_ptr<ig::igIntVec> partition1;
    std::unique_ptr<ig::igIntVec> partition2;
    std::unique_ptr<ig::igIntVec> cut;

    partition1 = std::make_unique<ig::igIntVec>();
    partition2 = std::make_unique<ig::igIntVec>();
    cut = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_mincut(static_cast<igraph_t*>(*graph), &value, static_cast<igraph_vector_int_t*>(*partition1), static_cast<igraph_vector_int_t*>(*partition2), static_cast<igraph_vector_int_t*>(*cut), static_cast<igraph_vector_t*>(*capacity)));
  }

  auto js_mincut_value(ig::igGraph* graph, ig::igRealVec* capacity) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_mincut_value(static_cast<igraph_t*>(*graph), &res, static_cast<igraph_vector_t*>(*capacity)));
    return res;
  }

  auto js_residual_graph(ig::igGraph* graph, ig::igRealVec* capacity, ig::igRealVec* flow) {
    std::unique_ptr<ig::igGraph> residual;
    std::unique_ptr<ig::igRealVec> residual_capacity;

    residual = std::make_unique<ig::igGraph>();
    residual_capacity = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_residual_graph(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*capacity), static_cast<igraph_t*>(*residual), static_cast<igraph_vector_t*>(*residual_capacity), static_cast<igraph_vector_t*>(*flow)));
  }

  auto js_reverse_residual_graph(ig::igGraph* graph, ig::igRealVec* capacity, ig::igRealVec* flow) {
    std::unique_ptr<ig::igGraph> residual;

    residual = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_reverse_residual_graph(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*capacity), static_cast<igraph_t*>(*residual), static_cast<igraph_vector_t*>(*flow)));
    return residual;
  }

  auto js_st_mincut(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target, ig::igRealVec* capacity) {
    igraph_real_t value;
    std::unique_ptr<ig::igIntVec> cut;
    std::unique_ptr<ig::igIntVec> partition1;
    std::unique_ptr<ig::igIntVec> partition2;

    cut = std::make_unique<ig::igIntVec>();
    partition1 = std::make_unique<ig::igIntVec>();
    partition2 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_st_mincut(static_cast<igraph_t*>(*graph), &value, static_cast<igraph_vector_int_t*>(*cut), static_cast<igraph_vector_int_t*>(*partition1), static_cast<igraph_vector_int_t*>(*partition2), source, target, static_cast<igraph_vector_t*>(*capacity)));
  }

  auto js_st_mincut_value(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target, ig::igRealVec* capacity) {
    igraph_real_t res;

    
    IGRAPH_JS_CHECK(igraph_st_mincut_value(static_cast<igraph_t*>(*graph), &res, source, target, static_cast<igraph_vector_t*>(*capacity)));
    return res;
  }

  auto js_st_vertex_connectivity(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target, igraph_vconn_nei_t neighbors) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_st_vertex_connectivity(static_cast<igraph_t*>(*graph), &res, source, target, neighbors));
    return res;
  }

  auto js_vertex_connectivity(ig::igGraph* graph, igraph_bool_t checks) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_vertex_connectivity(static_cast<igraph_t*>(*graph), &res, checks));
    return res;
  }

  auto js_st_edge_connectivity(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_st_edge_connectivity(static_cast<igraph_t*>(*graph), &res, source, target));
    return res;
  }

  auto js_edge_connectivity(ig::igGraph* graph, igraph_bool_t checks) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_edge_connectivity(static_cast<igraph_t*>(*graph), &res, checks));
    return res;
  }

  auto js_edge_disjoint_paths(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_edge_disjoint_paths(static_cast<igraph_t*>(*graph), &res, source, target));
    return res;
  }

  auto js_vertex_disjoint_paths(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_vertex_disjoint_paths(static_cast<igraph_t*>(*graph), &res, source, target));
    return res;
  }

  auto js_adhesion(ig::igGraph* graph, igraph_bool_t checks) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_adhesion(static_cast<igraph_t*>(*graph), &res, checks));
    return res;
  }

  auto js_cohesion(ig::igGraph* graph, igraph_bool_t checks) {
    igraph_integer_t res;

    
    IGRAPH_JS_CHECK(igraph_cohesion(static_cast<igraph_t*>(*graph), &res, checks));
    return res;
  }

  auto js_dominator_tree(ig::igGraph* graph, igraph_integer_t root, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> dom;
    std::unique_ptr<ig::igGraph> domtree;
    std::unique_ptr<ig::igIntVec> leftout;

    dom = std::make_unique<ig::igIntVec>();
    domtree = std::make_unique<ig::igGraph>();
    leftout = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_dominator_tree(static_cast<igraph_t*>(*graph), root, static_cast<igraph_vector_int_t*>(*dom), static_cast<igraph_t*>(*domtree), static_cast<igraph_vector_int_t*>(*leftout), mode));
  }

  auto js_all_st_cuts(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target) {
    std::unique_ptr<ig::igVecIntList> cuts;
    std::unique_ptr<ig::igVecIntList> partition1s;

    cuts = std::make_unique<ig::igVecIntList>();
    partition1s = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_all_st_cuts(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*cuts), static_cast<igraph_vector_int_list_t*>(*partition1s), source, target));
  }

  auto js_all_st_mincuts(ig::igGraph* graph, igraph_integer_t source, igraph_integer_t target, ig::igRealVec* capacity) {
    igraph_real_t value;
    std::unique_ptr<ig::igVecIntList> cuts;
    std::unique_ptr<ig::igVecIntList> partition1s;

    cuts = std::make_unique<ig::igVecIntList>();
    partition1s = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_all_st_mincuts(static_cast<igraph_t*>(*graph), &value, static_cast<igraph_vector_int_list_t*>(*cuts), static_cast<igraph_vector_int_list_t*>(*partition1s), source, target, static_cast<igraph_vector_t*>(*capacity)));
  }

  auto js_even_tarjan_reduction(ig::igGraph* graph) {
    std::unique_ptr<ig::igGraph> graphbar;
    std::unique_ptr<ig::igRealVec> capacity;

    graphbar = std::make_unique<ig::igGraph>();
    capacity = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_even_tarjan_reduction(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*graphbar), static_cast<igraph_vector_t*>(*capacity)));
  }

  auto js_is_separator(ig::igGraph* graph, igraph_vs_t candidate) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_separator(static_cast<igraph_t*>(*graph), candidate, &res));
    return res;
  }

  auto js_is_minimal_separator(ig::igGraph* graph, igraph_vs_t candidate) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_minimal_separator(static_cast<igraph_t*>(*graph), candidate, &res));
    return res;
  }

  auto js_all_minimal_st_separators(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> separators;

    separators = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_all_minimal_st_separators(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*separators)));
    return separators;
  }

  auto js_minimum_size_separators(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> separators;

    separators = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_minimum_size_separators(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*separators)));
    return separators;
  }

  auto js_cohesive_blocks(ig::igGraph* graph) {
    std::unique_ptr<ig::igVecIntList> blocks;
    std::unique_ptr<ig::igIntVec> cohesion;
    std::unique_ptr<ig::igIntVec> parent;
    std::unique_ptr<ig::igGraph> blockTree;

    blocks = std::make_unique<ig::igVecIntList>();
    cohesion = std::make_unique<ig::igIntVec>();
    parent = std::make_unique<ig::igIntVec>();
    blockTree = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_cohesive_blocks(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*blocks), static_cast<igraph_vector_int_t*>(*cohesion), static_cast<igraph_vector_int_t*>(*parent), static_cast<igraph_t*>(*blockTree)));
  }

  auto js_coreness(ig::igGraph* graph, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> cores;

    cores = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_coreness(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*cores), mode));
    return cores;
  }

  auto js_isoclass(ig::igGraph* graph) {
    igraph_integer_t isoclass;

    
    IGRAPH_JS_CHECK(igraph_isoclass(static_cast<igraph_t*>(*graph), &isoclass));
    return isoclass;
  }

  auto js_isomorphic(ig::igGraph* graph1, ig::igGraph* graph2) {
    igraph_bool_t iso;

    
    IGRAPH_JS_CHECK(igraph_isomorphic(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), &iso));
    return iso;
  }

  auto js_isoclass_subgraph(ig::igGraph* graph, ig::igIntVec* vids) {
    igraph_integer_t isoclass;

    
    IGRAPH_JS_CHECK(igraph_isoclass_subgraph(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*vids), &isoclass));
    return isoclass;
  }

  auto js_isoclass_create(igraph_integer_t size, igraph_integer_t number, igraph_bool_t directed) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_isoclass_create(static_cast<igraph_t*>(*graph), size, number, directed));
    return graph;
  }

  auto js_isomorphic_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    igraph_bool_t iso;
    std::unique_ptr<ig::igIntVec> map12;
    std::unique_ptr<ig::igIntVec> map21;

    map12 = std::make_unique<ig::igIntVec>();
    map21 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_isomorphic_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), &iso, static_cast<igraph_vector_int_t*>(*map12), static_cast<igraph_vector_int_t*>(*map21), node_compat_fn, edge_compat_fn, 0));
  }

  auto js_count_isomorphisms_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    igraph_integer_t count;

    
    IGRAPH_JS_CHECK(igraph_count_isomorphisms_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), &count, node_compat_fn, edge_compat_fn, 0));
    return count;
  }

  auto js_get_isomorphisms_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    std::unique_ptr<ig::igVecIntList> maps;

    maps = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_get_isomorphisms_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), static_cast<igraph_vector_int_list_t*>(*maps), node_compat_fn, edge_compat_fn, 0));
    return maps;
  }

  auto js_subisomorphic(ig::igGraph* graph1, ig::igGraph* graph2) {
    igraph_bool_t iso;

    
    IGRAPH_JS_CHECK(igraph_subisomorphic(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), &iso));
    return iso;
  }

  auto js_subisomorphic_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    igraph_bool_t iso;
    std::unique_ptr<ig::igIntVec> map12;
    std::unique_ptr<ig::igIntVec> map21;

    map12 = std::make_unique<ig::igIntVec>();
    map21 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_subisomorphic_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), &iso, static_cast<igraph_vector_int_t*>(*map12), static_cast<igraph_vector_int_t*>(*map21), node_compat_fn, edge_compat_fn, 0));
  }

  auto js_subisomorphic_function_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isohandler_t ishohandler_fn, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* arg) {
    std::unique_ptr<ig::igIntVec> map12;
    std::unique_ptr<ig::igIntVec> map21;

    map12 = std::make_unique<ig::igIntVec>();
    map21 = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_subisomorphic_function_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), static_cast<igraph_vector_int_t*>(*map12), static_cast<igraph_vector_int_t*>(*map21), ishohandler_fn, node_compat_fn, edge_compat_fn, 0));
  }

  auto js_count_subisomorphisms_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    igraph_integer_t count;

    
    IGRAPH_JS_CHECK(igraph_count_subisomorphisms_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), &count, node_compat_fn, edge_compat_fn, 0));
    return count;
  }

  auto js_get_subisomorphisms_vf2(ig::igGraph* graph1, ig::igGraph* graph2, ig::igIntVec* vertex_color1, ig::igIntVec* vertex_color2, ig::igIntVec* edge_color1, ig::igIntVec* edge_color2, igraph_isocompat_t node_compat_fn, igraph_isocompat_t edge_compat_fn, void* extra) {
    std::unique_ptr<ig::igVecIntList> maps;

    maps = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_get_subisomorphisms_vf2(static_cast<igraph_t*>(*graph1), static_cast<igraph_t*>(*graph2), static_cast<igraph_vector_int_t*>(*vertex_color1), static_cast<igraph_vector_int_t*>(*vertex_color2), static_cast<igraph_vector_int_t*>(*edge_color1), static_cast<igraph_vector_int_t*>(*edge_color2), static_cast<igraph_vector_int_list_t*>(*maps), node_compat_fn, edge_compat_fn, 0));
    return maps;
  }

  auto js_permute_vertices(ig::igGraph* graph, ig::igIntVec* permutation) {
    std::unique_ptr<ig::igGraph> res;

    res = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_permute_vertices(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), static_cast<igraph_vector_int_t*>(*permutation)));
    return res;
  }

  auto js_subisomorphic_lad(ig::igGraph* pattern, ig::igGraph* target, ig::igVecIntList* domains, igraph_bool_t induced, igraph_integer_t time_limit) {
    igraph_bool_t iso;
    std::unique_ptr<ig::igIntVec> map;
    std::unique_ptr<ig::igVecIntList> maps;

    map = std::make_unique<ig::igIntVec>();
    maps = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_subisomorphic_lad(static_cast<igraph_t*>(*pattern), static_cast<igraph_t*>(*target), static_cast<igraph_vector_int_list_t*>(*domains), &iso, static_cast<igraph_vector_int_t*>(*map), static_cast<igraph_vector_int_list_t*>(*maps), induced, time_limit));
  }

  auto js_simplify_and_colorize(ig::igGraph* graph) {
    std::unique_ptr<ig::igGraph> res;
    std::unique_ptr<ig::igIntVec> vertex_color;
    std::unique_ptr<ig::igIntVec> edge_color;

    res = std::make_unique<ig::igGraph>();
    vertex_color = std::make_unique<ig::igIntVec>();
    edge_color = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_simplify_and_colorize(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*res), static_cast<igraph_vector_int_t*>(*vertex_color), static_cast<igraph_vector_int_t*>(*edge_color)));
  }

  auto js_graph_count(igraph_integer_t n, igraph_bool_t directed) {
    igraph_integer_t count;

    
    IGRAPH_JS_CHECK(igraph_graph_count(n, directed, &count));
    return count;
  }

  auto js_is_matching(ig::igGraph* graph, ig::igBoolVec* types, ig::igIntVec* matching) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_matching(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_vector_int_t*>(*matching), &res));
    return res;
  }

  auto js_is_maximal_matching(ig::igGraph* graph, ig::igBoolVec* types, ig::igIntVec* matching) {
    igraph_bool_t res;

    
    IGRAPH_JS_CHECK(igraph_is_maximal_matching(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), static_cast<igraph_vector_int_t*>(*matching), &res));
    return res;
  }

  auto js_maximum_bipartite_matching(ig::igGraph* graph, ig::igBoolVec* types, ig::igRealVec* weights, igraph_real_t eps) {
    igraph_integer_t matching_size;
    igraph_real_t matching_weight;
    std::unique_ptr<ig::igIntVec> matching;

    matching = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_maximum_bipartite_matching(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_bool_t*>(*types), &matching_size, &matching_weight, static_cast<igraph_vector_int_t*>(*matching), static_cast<igraph_vector_t*>(*weights), eps));
  }

  auto js_running_mean(ig::igRealVec* data, igraph_integer_t binwidth) {
    std::unique_ptr<ig::igRealVec> res;

    res = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_running_mean(static_cast<igraph_vector_t*>(*data), static_cast<igraph_vector_t*>(*res), binwidth));
    return res;
  }

  auto js_random_sample(igraph_integer_t l, igraph_integer_t h, igraph_integer_t length) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_random_sample(static_cast<igraph_vector_int_t*>(*res), l, h, length));
    return res;
  }

  auto js_convex_hull(ig::igRealMatrix data) {
    std::unique_ptr<ig::igIntVec> resverts;
    ig::igRealMatrix rescoords;

    resverts = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_convex_hull(static_cast<igraph_matrix_t*>(data), static_cast<igraph_vector_int_t*>(*resverts), static_cast<igraph_matrix_t*>(rescoords)));
  }

  auto js_dim_select(ig::igRealVec* sv) {
    igraph_integer_t dim;

    
    IGRAPH_JS_CHECK(igraph_dim_select(static_cast<igraph_vector_t*>(*sv), &dim));
    return dim;
  }

  igraph_bool_t js_almost_equals(double a, double b, double eps) {
    
    
    return igraph_almost_equals(a, b, eps);
  }

  int js_cmp_epsilon(double a, double b, double eps) {
    
    
    return igraph_cmp_epsilon(a, b, eps);
  }

  auto js_solve_lsap(ig::igRealMatrix c, igraph_integer_t n) {
    std::unique_ptr<ig::igIntVec> p;

    p = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_solve_lsap(static_cast<igraph_matrix_t*>(c), n, static_cast<igraph_vector_int_t*>(*p)));
    return p;
  }

  auto js_is_eulerian(ig::igGraph* graph) {
    igraph_bool_t has_path;
    igraph_bool_t has_cycle;

    
    IGRAPH_JS_CHECK(igraph_is_eulerian(static_cast<igraph_t*>(*graph), &has_path, &has_cycle));
  }

  auto js_eulerian_path(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> edge_res;
    std::unique_ptr<ig::igIntVec> vertex_res;

    edge_res = std::make_unique<ig::igIntVec>();
    vertex_res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_eulerian_path(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*edge_res), static_cast<igraph_vector_int_t*>(*vertex_res)));
  }

  auto js_eulerian_cycle(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> edge_res;
    std::unique_ptr<ig::igIntVec> vertex_res;

    edge_res = std::make_unique<ig::igIntVec>();
    vertex_res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_eulerian_cycle(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*edge_res), static_cast<igraph_vector_int_t*>(*vertex_res)));
  }

  auto js_fundamental_cycles(ig::igGraph* graph, igraph_integer_t start, igraph_integer_t bfs_cutoff, ig::igRealVec* weights) {
    std::unique_ptr<ig::igVecIntList> basis;

    basis = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_fundamental_cycles(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*basis), start, bfs_cutoff, static_cast<igraph_vector_t*>(*weights)));
    return basis;
  }

  auto js_minimum_cycle_basis(ig::igGraph* graph, igraph_integer_t bfs_cutoff, igraph_bool_t complete, igraph_bool_t use_cycle_order, ig::igRealVec* weights) {
    std::unique_ptr<ig::igVecIntList> basis;

    basis = std::make_unique<ig::igVecIntList>();

    IGRAPH_JS_CHECK(igraph_minimum_cycle_basis(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_list_t*>(*basis), bfs_cutoff, complete, use_cycle_order, static_cast<igraph_vector_t*>(*weights)));
    return basis;
  }

  auto js_is_tree(ig::igGraph* graph, igraph_neimode_t mode) {
    igraph_bool_t res;
    igraph_integer_t root;

    
    IGRAPH_JS_CHECK(igraph_is_tree(static_cast<igraph_t*>(*graph), &res, &root, mode));
  }

  auto js_is_forest(ig::igGraph* graph, igraph_neimode_t mode) {
    igraph_bool_t res;
    std::unique_ptr<ig::igIntVec> roots;

    roots = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_is_forest(static_cast<igraph_t*>(*graph), &res, static_cast<igraph_vector_int_t*>(*roots), mode));
  }

  auto js_from_prufer(ig::igIntVec* prufer) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_from_prufer(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*prufer)));
    return graph;
  }

  auto js_to_prufer(ig::igGraph* graph) {
    std::unique_ptr<ig::igIntVec> prufer;

    prufer = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_to_prufer(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*prufer)));
    return prufer;
  }

  auto js_tree_from_parent_vector(ig::igIntVec* parents, igraph_tree_mode_t type) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_tree_from_parent_vector(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*parents), type));
    return graph;
  }

  auto js_minimum_spanning_tree(ig::igGraph* graph, ig::igRealVec* weights) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_minimum_spanning_tree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), static_cast<igraph_vector_t*>(*weights)));
    return res;
  }

  auto js_minimum_spanning_tree_unweighted(ig::igGraph* graph) {
    std::unique_ptr<ig::igGraph> mst;

    mst = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_minimum_spanning_tree_unweighted(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*mst)));
    return mst;
  }

  auto js_minimum_spanning_tree_prim(ig::igGraph* graph, ig::igRealVec* weights) {
    std::unique_ptr<ig::igGraph> mst;

    mst = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_minimum_spanning_tree_prim(static_cast<igraph_t*>(*graph), static_cast<igraph_t*>(*mst), static_cast<igraph_vector_t*>(*weights)));
    return mst;
  }

  auto js_random_spanning_tree(ig::igGraph* graph, igraph_integer_t vid) {
    std::unique_ptr<ig::igIntVec> res;

    res = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_random_spanning_tree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*res), vid));
    return res;
  }

  auto js_tree_game(igraph_integer_t n, igraph_bool_t directed, igraph_random_tree_t method) {
    std::unique_ptr<ig::igGraph> graph;

    graph = std::make_unique<ig::igGraph>();

    IGRAPH_JS_CHECK(igraph_tree_game(static_cast<igraph_t*>(*graph), n, directed, method));
    return graph;
  }

  auto js_vertex_coloring_greedy(ig::igGraph* graph, igraph_coloring_greedy_t heuristic) {
    std::unique_ptr<ig::igIntVec> colors;

    colors = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_vertex_coloring_greedy(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_int_t*>(*colors), heuristic));
    return colors;
  }

  auto js_deterministic_optimal_imitation(ig::igGraph* graph, igraph_integer_t vid, igraph_optimal_t optimality, ig::igRealVec* quantities, ig::igIntVec* strategies, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_deterministic_optimal_imitation(static_cast<igraph_t*>(*graph), vid, optimality, static_cast<igraph_vector_t*>(*quantities), static_cast<igraph_vector_int_t*>(*strategies), mode));
    return strategies;
  }

  auto js_moran_process(ig::igGraph* graph, ig::igRealVec* weights, ig::igRealVec* quantities, ig::igIntVec* strategies, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_moran_process(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*weights), static_cast<igraph_vector_t*>(*quantities), static_cast<igraph_vector_int_t*>(*strategies), mode));
  }

  auto js_roulette_wheel_imitation(ig::igGraph* graph, igraph_integer_t vid, igraph_bool_t is_local, ig::igRealVec* quantities, ig::igIntVec* strategies, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_roulette_wheel_imitation(static_cast<igraph_t*>(*graph), vid, is_local, static_cast<igraph_vector_t*>(*quantities), static_cast<igraph_vector_int_t*>(*strategies), mode));
    return strategies;
  }

  auto js_stochastic_imitation(ig::igGraph* graph, igraph_integer_t vid, igraph_imitate_algorithm_t algo, ig::igRealVec* quantities, ig::igIntVec* strategies, igraph_neimode_t mode) {
    
    
    IGRAPH_JS_CHECK(igraph_stochastic_imitation(static_cast<igraph_t*>(*graph), vid, algo, static_cast<igraph_vector_t*>(*quantities), static_cast<igraph_vector_int_t*>(*strategies), mode));
    return strategies;
  }

  auto js_convergence_degree(ig::igGraph* graph) {
    std::unique_ptr<ig::igRealVec> result;
    std::unique_ptr<ig::igRealVec> in;
    std::unique_ptr<ig::igRealVec> out;

    result = std::make_unique<ig::igRealVec>();
    in = std::make_unique<ig::igRealVec>();
    out = std::make_unique<ig::igRealVec>();

    IGRAPH_JS_CHECK(igraph_convergence_degree(static_cast<igraph_t*>(*graph), static_cast<igraph_vector_t*>(*result), static_cast<igraph_vector_t*>(*in), static_cast<igraph_vector_t*>(*out)));
  }

  igraph_bool_t js_has_attribute_table() {
    
    
    return igraph_has_attribute_table();
  }

  std::string js_strerror(igraph_error_t igraph_errno) {
    
    
    return igraph_strerror(igraph_errno);
  }

  auto js_expand_path_to_pairs(ig::igIntVec* path) {
    
    
    IGRAPH_JS_CHECK(igraph_expand_path_to_pairs(static_cast<igraph_vector_int_t*>(*path)));
    return path;
  }

  void js_invalidate_cache(ig::igGraph* graph) {
    
    
    return igraph_invalidate_cache(static_cast<igraph_t*>(*graph));
  }

  auto js_vertex_path_from_edge_path(ig::igGraph* graph, igraph_integer_t start, ig::igIntVec* edge_path, igraph_neimode_t mode) {
    std::unique_ptr<ig::igIntVec> vertex_path;

    vertex_path = std::make_unique<ig::igIntVec>();

    IGRAPH_JS_CHECK(igraph_vertex_path_from_edge_path(static_cast<igraph_t*>(*graph), start, static_cast<igraph_vector_int_t*>(*edge_path), static_cast<igraph_vector_int_t*>(*vertex_path), mode));
    return vertex_path;
  }
}

#ifdef __EMSCRIPTEN__

#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(IGraphBind) {
  function("empty", &js_empty, allow_raw_pointers());
  function("add_edges", &js_add_edges, allow_raw_pointers());
  function("add_vertices", &js_add_vertices, allow_raw_pointers());
  function("copy", &js_copy, allow_raw_pointers());
  function("delete_edges", &js_delete_edges, allow_raw_pointers());
  function("delete_vertices", &js_delete_vertices, allow_raw_pointers());
  function("delete_vertices_idx", &js_delete_vertices_idx, allow_raw_pointers());
  function("vcount", &js_vcount, allow_raw_pointers());
  function("ecount", &js_ecount, allow_raw_pointers());
  function("neighbors", &js_neighbors, allow_raw_pointers());
  function("is_directed", &js_is_directed, allow_raw_pointers());
  function("degree", &js_degree, allow_raw_pointers());
  function("edge", &js_edge, allow_raw_pointers());
  function("edges", &js_edges, allow_raw_pointers());
  function("empty_attrs", &js_empty_attrs, allow_raw_pointers());
  function("get_eid", &js_get_eid, allow_raw_pointers());
  function("get_eids", &js_get_eids, allow_raw_pointers());
  function("get_all_eids_between", &js_get_all_eids_between, allow_raw_pointers());
  function("incident", &js_incident, allow_raw_pointers());
  function("is_same_graph", &js_is_same_graph, allow_raw_pointers());
  function("create", &js_create, allow_raw_pointers());
  function("adjacency", &js_adjacency, allow_raw_pointers());
  function("weighted_adjacency", &js_weighted_adjacency, allow_raw_pointers());
  function("star", &js_star, allow_raw_pointers());
  function("wheel", &js_wheel, allow_raw_pointers());
  function("square_lattice", &js_square_lattice, allow_raw_pointers());
  function("triangular_lattice", &js_triangular_lattice, allow_raw_pointers());
  function("ring", &js_ring, allow_raw_pointers());
  function("kary_tree", &js_kary_tree, allow_raw_pointers());
  function("symmetric_tree", &js_symmetric_tree, allow_raw_pointers());
  function("regular_tree", &js_regular_tree, allow_raw_pointers());
  function("full", &js_full, allow_raw_pointers());
  function("full_citation", &js_full_citation, allow_raw_pointers());
  function("atlas", &js_atlas, allow_raw_pointers());
  function("extended_chordal_ring", &js_extended_chordal_ring, allow_raw_pointers());
  function("connect_neighborhood", &js_connect_neighborhood, allow_raw_pointers());
  function("graph_power", &js_graph_power, allow_raw_pointers());
  function("linegraph", &js_linegraph, allow_raw_pointers());
  function("de_bruijn", &js_de_bruijn, allow_raw_pointers());
  function("kautz", &js_kautz, allow_raw_pointers());
  function("famous", &js_famous, allow_raw_pointers());
  function("lcf_vector", &js_lcf_vector, allow_raw_pointers());
  function("full_bipartite", &js_full_bipartite, allow_raw_pointers());
  function("full_multipartite", &js_full_multipartite, allow_raw_pointers());
  function("realize_degree_sequence", &js_realize_degree_sequence, allow_raw_pointers());
  function("circulant", &js_circulant, allow_raw_pointers());
  function("generalized_petersen", &js_generalized_petersen, allow_raw_pointers());
  function("turan", &js_turan, allow_raw_pointers());
  function("barabasi_game", &js_barabasi_game, allow_raw_pointers());
  function("erdos_renyi_game_gnp", &js_erdos_renyi_game_gnp, allow_raw_pointers());
  function("erdos_renyi_game_gnm", &js_erdos_renyi_game_gnm, allow_raw_pointers());
  function("degree_sequence_game", &js_degree_sequence_game, allow_raw_pointers());
  function("growing_random_game", &js_growing_random_game, allow_raw_pointers());
  function("barabasi_aging_game", &js_barabasi_aging_game, allow_raw_pointers());
  function("recent_degree_game", &js_recent_degree_game, allow_raw_pointers());
  function("recent_degree_aging_game", &js_recent_degree_aging_game, allow_raw_pointers());
  function("callaway_traits_game", &js_callaway_traits_game, allow_raw_pointers());
  function("establishment_game", &js_establishment_game, allow_raw_pointers());
  function("grg_game", &js_grg_game, allow_raw_pointers());
  function("preference_game", &js_preference_game, allow_raw_pointers());
  function("asymmetric_preference_game", &js_asymmetric_preference_game, allow_raw_pointers());
  function("rewire_edges", &js_rewire_edges, allow_raw_pointers());
  function("rewire_directed_edges", &js_rewire_directed_edges, allow_raw_pointers());
  function("watts_strogatz_game", &js_watts_strogatz_game, allow_raw_pointers());
  function("lastcit_game", &js_lastcit_game, allow_raw_pointers());
  function("cited_type_game", &js_cited_type_game, allow_raw_pointers());
  function("citing_cited_type_game", &js_citing_cited_type_game, allow_raw_pointers());
  function("forest_fire_game", &js_forest_fire_game, allow_raw_pointers());
  function("simple_interconnected_islands_game", &js_simple_interconnected_islands_game, allow_raw_pointers());
  function("static_fitness_game", &js_static_fitness_game, allow_raw_pointers());
  function("static_power_law_game", &js_static_power_law_game, allow_raw_pointers());
  function("k_regular_game", &js_k_regular_game, allow_raw_pointers());
  function("sbm_game", &js_sbm_game, allow_raw_pointers());
  function("hsbm_game", &js_hsbm_game, allow_raw_pointers());
  function("correlated_game", &js_correlated_game, allow_raw_pointers());
  function("correlated_pair_game", &js_correlated_pair_game, allow_raw_pointers());
  function("dot_product_game", &js_dot_product_game, allow_raw_pointers());
  function("sample_sphere_surface", &js_sample_sphere_surface, allow_raw_pointers());
  function("sample_sphere_volume", &js_sample_sphere_volume, allow_raw_pointers());
  function("sample_dirichlet", &js_sample_dirichlet, allow_raw_pointers());
  function("are_connected", &js_are_connected, allow_raw_pointers());
  function("diameter", &js_diameter, allow_raw_pointers());
  function("diameter_dijkstra", &js_diameter_dijkstra, allow_raw_pointers());
  function("closeness", &js_closeness, allow_raw_pointers());
  function("closeness_cutoff", &js_closeness_cutoff, allow_raw_pointers());
  function("distances", &js_distances, allow_raw_pointers());
  function("distances_cutoff", &js_distances_cutoff, allow_raw_pointers());
  function("get_shortest_path", &js_get_shortest_path, allow_raw_pointers());
  function("get_shortest_path_bellman_ford", &js_get_shortest_path_bellman_ford, allow_raw_pointers());
  function("get_shortest_path_dijkstra", &js_get_shortest_path_dijkstra, allow_raw_pointers());
  function("get_shortest_path_astar", &js_get_shortest_path_astar, allow_raw_pointers());
  function("get_shortest_paths", &js_get_shortest_paths, allow_raw_pointers());
  function("get_all_shortest_paths", &js_get_all_shortest_paths, allow_raw_pointers());
  function("distances_dijkstra", &js_distances_dijkstra, allow_raw_pointers());
  function("distances_dijkstra_cutoff", &js_distances_dijkstra_cutoff, allow_raw_pointers());
  function("get_shortest_paths_dijkstra", &js_get_shortest_paths_dijkstra, allow_raw_pointers());
  function("get_shortest_paths_bellman_ford", &js_get_shortest_paths_bellman_ford, allow_raw_pointers());
  function("get_all_shortest_paths_dijkstra", &js_get_all_shortest_paths_dijkstra, allow_raw_pointers());
  function("distances_bellman_ford", &js_distances_bellman_ford, allow_raw_pointers());
  function("distances_johnson", &js_distances_johnson, allow_raw_pointers());
  function("distances_floyd_warshall", &js_distances_floyd_warshall, allow_raw_pointers());
  function("voronoi", &js_voronoi, allow_raw_pointers());
  function("get_all_simple_paths", &js_get_all_simple_paths, allow_raw_pointers());
  function("get_k_shortest_paths", &js_get_k_shortest_paths, allow_raw_pointers());
  function("get_widest_path", &js_get_widest_path, allow_raw_pointers());
  function("get_widest_paths", &js_get_widest_paths, allow_raw_pointers());
  function("widest_path_widths_dijkstra", &js_widest_path_widths_dijkstra, allow_raw_pointers());
  function("widest_path_widths_floyd_warshall", &js_widest_path_widths_floyd_warshall, allow_raw_pointers());
  function("spanner", &js_spanner, allow_raw_pointers());
  function("subcomponent", &js_subcomponent, allow_raw_pointers());
  function("betweenness", &js_betweenness, allow_raw_pointers());
  function("betweenness_cutoff", &js_betweenness_cutoff, allow_raw_pointers());
  function("betweenness_subset", &js_betweenness_subset, allow_raw_pointers());
  function("edge_betweenness", &js_edge_betweenness, allow_raw_pointers());
  function("edge_betweenness_cutoff", &js_edge_betweenness_cutoff, allow_raw_pointers());
  function("edge_betweenness_subset", &js_edge_betweenness_subset, allow_raw_pointers());
  function("harmonic_centrality", &js_harmonic_centrality, allow_raw_pointers());
  function("harmonic_centrality_cutoff", &js_harmonic_centrality_cutoff, allow_raw_pointers());
  function("rewire", &js_rewire, allow_raw_pointers());
  function("induced_subgraph", &js_induced_subgraph, allow_raw_pointers());
  function("subgraph_from_edges", &js_subgraph_from_edges, allow_raw_pointers());
  function("reverse_edges", &js_reverse_edges, allow_raw_pointers());
  function("average_path_length", &js_average_path_length, allow_raw_pointers());
  function("average_path_length_dijkstra", &js_average_path_length_dijkstra, allow_raw_pointers());
  function("path_length_hist", &js_path_length_hist, allow_raw_pointers());
  function("transitivity_undirected", &js_transitivity_undirected, allow_raw_pointers());
  function("transitivity_local_undirected", &js_transitivity_local_undirected, allow_raw_pointers());
  function("transitivity_avglocal_undirected", &js_transitivity_avglocal_undirected, allow_raw_pointers());
  function("transitivity_barrat", &js_transitivity_barrat, allow_raw_pointers());
  function("ecc", &js_ecc, allow_raw_pointers());
  function("reciprocity", &js_reciprocity, allow_raw_pointers());
  function("constraint", &js_constraint, allow_raw_pointers());
  function("maxdegree", &js_maxdegree, allow_raw_pointers());
  function("density", &js_density, allow_raw_pointers());
  function("neighborhood_size", &js_neighborhood_size, allow_raw_pointers());
  function("neighborhood", &js_neighborhood, allow_raw_pointers());
  function("topological_sorting", &js_topological_sorting, allow_raw_pointers());
  function("feedback_arc_set", &js_feedback_arc_set, allow_raw_pointers());
  function("is_loop", &js_is_loop, allow_raw_pointers());
  function("is_dag", &js_is_dag, allow_raw_pointers());
  function("is_acyclic", &js_is_acyclic, allow_raw_pointers());
  function("is_simple", &js_is_simple, allow_raw_pointers());
  function("is_multiple", &js_is_multiple, allow_raw_pointers());
  function("has_loop", &js_has_loop, allow_raw_pointers());
  function("has_multiple", &js_has_multiple, allow_raw_pointers());
  function("count_multiple", &js_count_multiple, allow_raw_pointers());
  function("girth", &js_girth, allow_raw_pointers());
  function("is_perfect", &js_is_perfect, allow_raw_pointers());
  function("add_edge", &js_add_edge, allow_raw_pointers());
  function("unfold_tree", &js_unfold_tree, allow_raw_pointers());
  function("is_mutual", &js_is_mutual, allow_raw_pointers());
  function("has_mutual", &js_has_mutual, allow_raw_pointers());
  function("maximum_cardinality_search", &js_maximum_cardinality_search, allow_raw_pointers());
  function("is_chordal", &js_is_chordal, allow_raw_pointers());
  function("avg_nearest_neighbor_degree", &js_avg_nearest_neighbor_degree, allow_raw_pointers());
  function("degree_correlation_vector", &js_degree_correlation_vector, allow_raw_pointers());
  function("strength", &js_strength, allow_raw_pointers());
  function("centralization", &js_centralization, allow_raw_pointers());
  function("centralization_degree", &js_centralization_degree, allow_raw_pointers());
  function("centralization_degree_tmax", &js_centralization_degree_tmax, allow_raw_pointers());
  function("centralization_betweenness", &js_centralization_betweenness, allow_raw_pointers());
  function("centralization_betweenness_tmax", &js_centralization_betweenness_tmax, allow_raw_pointers());
  function("centralization_closeness", &js_centralization_closeness, allow_raw_pointers());
  function("centralization_closeness_tmax", &js_centralization_closeness_tmax, allow_raw_pointers());
  function("centralization_eigenvector_centrality_tmax", &js_centralization_eigenvector_centrality_tmax, allow_raw_pointers());
  function("assortativity_nominal", &js_assortativity_nominal, allow_raw_pointers());
  function("assortativity", &js_assortativity, allow_raw_pointers());
  function("assortativity_degree", &js_assortativity_degree, allow_raw_pointers());
  function("joint_degree_matrix", &js_joint_degree_matrix, allow_raw_pointers());
  function("eccentricity", &js_eccentricity, allow_raw_pointers());
  function("eccentricity_dijkstra", &js_eccentricity_dijkstra, allow_raw_pointers());
  function("graph_center", &js_graph_center, allow_raw_pointers());
  function("graph_center_dijkstra", &js_graph_center_dijkstra, allow_raw_pointers());
  function("radius", &js_radius, allow_raw_pointers());
  function("radius_dijkstra", &js_radius_dijkstra, allow_raw_pointers());
  function("pseudo_diameter", &js_pseudo_diameter, allow_raw_pointers());
  function("pseudo_diameter_dijkstra", &js_pseudo_diameter_dijkstra, allow_raw_pointers());
  function("diversity", &js_diversity, allow_raw_pointers());
  function("random_walk", &js_random_walk, allow_raw_pointers());
  function("random_edge_walk", &js_random_edge_walk, allow_raw_pointers());
  function("global_efficiency", &js_global_efficiency, allow_raw_pointers());
  function("local_efficiency", &js_local_efficiency, allow_raw_pointers());
  function("average_local_efficiency", &js_average_local_efficiency, allow_raw_pointers());
  function("transitive_closure_dag", &js_transitive_closure_dag, allow_raw_pointers());
  function("trussness", &js_trussness, allow_raw_pointers());
  function("is_bigraphical", &js_is_bigraphical, allow_raw_pointers());
  function("is_graphical", &js_is_graphical, allow_raw_pointers());
  function("bfs", &js_bfs, allow_raw_pointers());
  function("bfs_simple", &js_bfs_simple, allow_raw_pointers());
  function("dfs", &js_dfs, allow_raw_pointers());
  function("bipartite_projection_size", &js_bipartite_projection_size, allow_raw_pointers());
  function("bipartite_projection", &js_bipartite_projection, allow_raw_pointers());
  function("create_bipartite", &js_create_bipartite, allow_raw_pointers());
  function("biadjacency", &js_biadjacency, allow_raw_pointers());
  function("get_biadjacency", &js_get_biadjacency, allow_raw_pointers());
  function("is_bipartite", &js_is_bipartite, allow_raw_pointers());
  function("bipartite_game_gnp", &js_bipartite_game_gnp, allow_raw_pointers());
  function("bipartite_game_gnm", &js_bipartite_game_gnm, allow_raw_pointers());
  function("bipartite_game", &js_bipartite_game, allow_raw_pointers());
  function("get_laplacian", &js_get_laplacian, allow_raw_pointers());
  function("connected_components", &js_connected_components, allow_raw_pointers());
  function("is_connected", &js_is_connected, allow_raw_pointers());
  function("articulation_points", &js_articulation_points, allow_raw_pointers());
  function("biconnected_components", &js_biconnected_components, allow_raw_pointers());
  function("bridges", &js_bridges, allow_raw_pointers());
  function("cliques", &js_cliques, allow_raw_pointers());
  function("clique_size_hist", &js_clique_size_hist, allow_raw_pointers());
  function("largest_cliques", &js_largest_cliques, allow_raw_pointers());
  function("maximal_cliques", &js_maximal_cliques, allow_raw_pointers());
  function("maximal_cliques_subset", &js_maximal_cliques_subset, allow_raw_pointers());
  function("maximal_cliques_count", &js_maximal_cliques_count, allow_raw_pointers());
  function("maximal_cliques_hist", &js_maximal_cliques_hist, allow_raw_pointers());
  function("clique_number", &js_clique_number, allow_raw_pointers());
  function("weighted_cliques", &js_weighted_cliques, allow_raw_pointers());
  function("largest_weighted_cliques", &js_largest_weighted_cliques, allow_raw_pointers());
  function("weighted_clique_number", &js_weighted_clique_number, allow_raw_pointers());
  function("independent_vertex_sets", &js_independent_vertex_sets, allow_raw_pointers());
  function("largest_independent_vertex_sets", &js_largest_independent_vertex_sets, allow_raw_pointers());
  function("maximal_independent_vertex_sets", &js_maximal_independent_vertex_sets, allow_raw_pointers());
  function("independence_number", &js_independence_number, allow_raw_pointers());
  function("layout_random", &js_layout_random, allow_raw_pointers());
  function("layout_circle", &js_layout_circle, allow_raw_pointers());
  function("layout_star", &js_layout_star, allow_raw_pointers());
  function("layout_grid", &js_layout_grid, allow_raw_pointers());
  function("layout_grid_3d", &js_layout_grid_3d, allow_raw_pointers());
  function("layout_kamada_kawai", &js_layout_kamada_kawai, allow_raw_pointers());
  function("layout_lgl", &js_layout_lgl, allow_raw_pointers());
  function("layout_reingold_tilford", &js_layout_reingold_tilford, allow_raw_pointers());
  function("layout_reingold_tilford_circular", &js_layout_reingold_tilford_circular, allow_raw_pointers());
  function("roots_for_tree_layout", &js_roots_for_tree_layout, allow_raw_pointers());
  function("layout_random_3d", &js_layout_random_3d, allow_raw_pointers());
  function("layout_sphere", &js_layout_sphere, allow_raw_pointers());
  function("layout_kamada_kawai_3d", &js_layout_kamada_kawai_3d, allow_raw_pointers());
  function("layout_graphopt", &js_layout_graphopt, allow_raw_pointers());
  function("layout_sugiyama", &js_layout_sugiyama, allow_raw_pointers());
  function("layout_mds", &js_layout_mds, allow_raw_pointers());
  function("layout_bipartite", &js_layout_bipartite, allow_raw_pointers());
  function("layout_gem", &js_layout_gem, allow_raw_pointers());
  function("layout_davidson_harel", &js_layout_davidson_harel, allow_raw_pointers());
  function("layout_umap", &js_layout_umap, allow_raw_pointers());
  function("layout_umap_3d", &js_layout_umap_3d, allow_raw_pointers());
  function("layout_umap_compute_weights", &js_layout_umap_compute_weights, allow_raw_pointers());
  function("cocitation", &js_cocitation, allow_raw_pointers());
  function("bibcoupling", &js_bibcoupling, allow_raw_pointers());
  function("similarity_dice", &js_similarity_dice, allow_raw_pointers());
  function("similarity_dice_es", &js_similarity_dice_es, allow_raw_pointers());
  function("similarity_dice_pairs", &js_similarity_dice_pairs, allow_raw_pointers());
  function("similarity_inverse_log_weighted", &js_similarity_inverse_log_weighted, allow_raw_pointers());
  function("similarity_jaccard", &js_similarity_jaccard, allow_raw_pointers());
  function("similarity_jaccard_es", &js_similarity_jaccard_es, allow_raw_pointers());
  function("similarity_jaccard_pairs", &js_similarity_jaccard_pairs, allow_raw_pointers());
  function("compare_communities", &js_compare_communities, allow_raw_pointers());
  function("community_spinglass", &js_community_spinglass, allow_raw_pointers());
  function("community_spinglass_single", &js_community_spinglass_single, allow_raw_pointers());
  function("community_walktrap", &js_community_walktrap, allow_raw_pointers());
  function("community_edge_betweenness", &js_community_edge_betweenness, allow_raw_pointers());
  function("community_eb_get_merges", &js_community_eb_get_merges, allow_raw_pointers());
  function("community_fastgreedy", &js_community_fastgreedy, allow_raw_pointers());
  function("community_to_membership", &js_community_to_membership, allow_raw_pointers());
  function("le_community_to_membership", &js_le_community_to_membership, allow_raw_pointers());
  function("modularity", &js_modularity, allow_raw_pointers());
  function("modularity_matrix", &js_modularity_matrix, allow_raw_pointers());
  function("reindex_membership", &js_reindex_membership, allow_raw_pointers());
  function("community_fluid_communities", &js_community_fluid_communities, allow_raw_pointers());
  function("community_label_propagation", &js_community_label_propagation, allow_raw_pointers());
  function("community_multilevel", &js_community_multilevel, allow_raw_pointers());
  function("community_optimal_modularity", &js_community_optimal_modularity, allow_raw_pointers());
  function("community_leiden", &js_community_leiden, allow_raw_pointers());
  function("split_join_distance", &js_split_join_distance, allow_raw_pointers());
  function("community_infomap", &js_community_infomap, allow_raw_pointers());
  function("community_voronoi", &js_community_voronoi, allow_raw_pointers());
  function("graphlets", &js_graphlets, allow_raw_pointers());
  function("graphlets_candidate_basis", &js_graphlets_candidate_basis, allow_raw_pointers());
  function("graphlets_project", &js_graphlets_project, allow_raw_pointers());
  function("get_adjacency", &js_get_adjacency, allow_raw_pointers());
  function("get_edgelist", &js_get_edgelist, allow_raw_pointers());
  function("get_stochastic", &js_get_stochastic, allow_raw_pointers());
  function("to_directed", &js_to_directed, allow_raw_pointers());
  function("read_graph_edgelist", &js_read_graph_edgelist, allow_raw_pointers());
  function("read_graph_lgl", &js_read_graph_lgl, allow_raw_pointers());
  function("read_graph_pajek", &js_read_graph_pajek, allow_raw_pointers());
  function("read_graph_graphml", &js_read_graph_graphml, allow_raw_pointers());
  function("read_graph_graphdb", &js_read_graph_graphdb, allow_raw_pointers());
  function("read_graph_gml", &js_read_graph_gml, allow_raw_pointers());
  function("read_graph_dl", &js_read_graph_dl, allow_raw_pointers());
  function("motifs_randesu", &js_motifs_randesu, allow_raw_pointers());
  function("motifs_randesu_estimate", &js_motifs_randesu_estimate, allow_raw_pointers());
  function("motifs_randesu_no", &js_motifs_randesu_no, allow_raw_pointers());
  function("dyad_census", &js_dyad_census, allow_raw_pointers());
  function("triad_census", &js_triad_census, allow_raw_pointers());
  function("adjacent_triangles", &js_adjacent_triangles, allow_raw_pointers());
  function("local_scan_0", &js_local_scan_0, allow_raw_pointers());
  function("local_scan_0_them", &js_local_scan_0_them, allow_raw_pointers());
  function("local_scan_1_ecount", &js_local_scan_1_ecount, allow_raw_pointers());
  function("local_scan_1_ecount_them", &js_local_scan_1_ecount_them, allow_raw_pointers());
  function("local_scan_k_ecount", &js_local_scan_k_ecount, allow_raw_pointers());
  function("local_scan_k_ecount_them", &js_local_scan_k_ecount_them, allow_raw_pointers());
  function("local_scan_neighborhood_ecount", &js_local_scan_neighborhood_ecount, allow_raw_pointers());
  function("local_scan_subset_ecount", &js_local_scan_subset_ecount, allow_raw_pointers());
  function("list_triangles", &js_list_triangles, allow_raw_pointers());
  function("disjoint_union", &js_disjoint_union, allow_raw_pointers());
  function("union", &js_union, allow_raw_pointers());
  function("intersection", &js_intersection, allow_raw_pointers());
  function("difference", &js_difference, allow_raw_pointers());
  function("complementer", &js_complementer, allow_raw_pointers());
  function("compose", &js_compose, allow_raw_pointers());
  function("induced_subgraph_map", &js_induced_subgraph_map, allow_raw_pointers());
  function("gomory_hu_tree", &js_gomory_hu_tree, allow_raw_pointers());
  function("mincut", &js_mincut, allow_raw_pointers());
  function("mincut_value", &js_mincut_value, allow_raw_pointers());
  function("residual_graph", &js_residual_graph, allow_raw_pointers());
  function("reverse_residual_graph", &js_reverse_residual_graph, allow_raw_pointers());
  function("st_mincut", &js_st_mincut, allow_raw_pointers());
  function("st_mincut_value", &js_st_mincut_value, allow_raw_pointers());
  function("st_vertex_connectivity", &js_st_vertex_connectivity, allow_raw_pointers());
  function("vertex_connectivity", &js_vertex_connectivity, allow_raw_pointers());
  function("st_edge_connectivity", &js_st_edge_connectivity, allow_raw_pointers());
  function("edge_connectivity", &js_edge_connectivity, allow_raw_pointers());
  function("edge_disjoint_paths", &js_edge_disjoint_paths, allow_raw_pointers());
  function("vertex_disjoint_paths", &js_vertex_disjoint_paths, allow_raw_pointers());
  function("adhesion", &js_adhesion, allow_raw_pointers());
  function("cohesion", &js_cohesion, allow_raw_pointers());
  function("dominator_tree", &js_dominator_tree, allow_raw_pointers());
  function("all_st_cuts", &js_all_st_cuts, allow_raw_pointers());
  function("all_st_mincuts", &js_all_st_mincuts, allow_raw_pointers());
  function("even_tarjan_reduction", &js_even_tarjan_reduction, allow_raw_pointers());
  function("is_separator", &js_is_separator, allow_raw_pointers());
  function("is_minimal_separator", &js_is_minimal_separator, allow_raw_pointers());
  function("all_minimal_st_separators", &js_all_minimal_st_separators, allow_raw_pointers());
  function("minimum_size_separators", &js_minimum_size_separators, allow_raw_pointers());
  function("cohesive_blocks", &js_cohesive_blocks, allow_raw_pointers());
  function("coreness", &js_coreness, allow_raw_pointers());
  function("isoclass", &js_isoclass, allow_raw_pointers());
  function("isomorphic", &js_isomorphic, allow_raw_pointers());
  function("isoclass_subgraph", &js_isoclass_subgraph, allow_raw_pointers());
  function("isoclass_create", &js_isoclass_create, allow_raw_pointers());
  function("isomorphic_vf2", &js_isomorphic_vf2, allow_raw_pointers());
  function("count_isomorphisms_vf2", &js_count_isomorphisms_vf2, allow_raw_pointers());
  function("get_isomorphisms_vf2", &js_get_isomorphisms_vf2, allow_raw_pointers());
  function("subisomorphic", &js_subisomorphic, allow_raw_pointers());
  function("subisomorphic_vf2", &js_subisomorphic_vf2, allow_raw_pointers());
  function("subisomorphic_function_vf2", &js_subisomorphic_function_vf2, allow_raw_pointers());
  function("count_subisomorphisms_vf2", &js_count_subisomorphisms_vf2, allow_raw_pointers());
  function("get_subisomorphisms_vf2", &js_get_subisomorphisms_vf2, allow_raw_pointers());
  function("permute_vertices", &js_permute_vertices, allow_raw_pointers());
  function("subisomorphic_lad", &js_subisomorphic_lad, allow_raw_pointers());
  function("simplify_and_colorize", &js_simplify_and_colorize, allow_raw_pointers());
  function("graph_count", &js_graph_count, allow_raw_pointers());
  function("is_matching", &js_is_matching, allow_raw_pointers());
  function("is_maximal_matching", &js_is_maximal_matching, allow_raw_pointers());
  function("maximum_bipartite_matching", &js_maximum_bipartite_matching, allow_raw_pointers());
  function("running_mean", &js_running_mean, allow_raw_pointers());
  function("random_sample", &js_random_sample, allow_raw_pointers());
  function("convex_hull", &js_convex_hull, allow_raw_pointers());
  function("dim_select", &js_dim_select, allow_raw_pointers());
  function("almost_equals", &js_almost_equals, allow_raw_pointers());
  function("cmp_epsilon", &js_cmp_epsilon, allow_raw_pointers());
  function("solve_lsap", &js_solve_lsap, allow_raw_pointers());
  function("is_eulerian", &js_is_eulerian, allow_raw_pointers());
  function("eulerian_path", &js_eulerian_path, allow_raw_pointers());
  function("eulerian_cycle", &js_eulerian_cycle, allow_raw_pointers());
  function("fundamental_cycles", &js_fundamental_cycles, allow_raw_pointers());
  function("minimum_cycle_basis", &js_minimum_cycle_basis, allow_raw_pointers());
  function("is_tree", &js_is_tree, allow_raw_pointers());
  function("is_forest", &js_is_forest, allow_raw_pointers());
  function("from_prufer", &js_from_prufer, allow_raw_pointers());
  function("to_prufer", &js_to_prufer, allow_raw_pointers());
  function("tree_from_parent_vector", &js_tree_from_parent_vector, allow_raw_pointers());
  function("minimum_spanning_tree", &js_minimum_spanning_tree, allow_raw_pointers());
  function("minimum_spanning_tree_unweighted", &js_minimum_spanning_tree_unweighted, allow_raw_pointers());
  function("minimum_spanning_tree_prim", &js_minimum_spanning_tree_prim, allow_raw_pointers());
  function("random_spanning_tree", &js_random_spanning_tree, allow_raw_pointers());
  function("tree_game", &js_tree_game, allow_raw_pointers());
  function("vertex_coloring_greedy", &js_vertex_coloring_greedy, allow_raw_pointers());
  function("deterministic_optimal_imitation", &js_deterministic_optimal_imitation, allow_raw_pointers());
  function("moran_process", &js_moran_process, allow_raw_pointers());
  function("roulette_wheel_imitation", &js_roulette_wheel_imitation, allow_raw_pointers());
  function("stochastic_imitation", &js_stochastic_imitation, allow_raw_pointers());
  function("convergence_degree", &js_convergence_degree, allow_raw_pointers());
  function("has_attribute_table", &js_has_attribute_table, allow_raw_pointers());
  function("strerror", &js_strerror, allow_raw_pointers());
  function("expand_path_to_pairs", &js_expand_path_to_pairs, allow_raw_pointers());
  function("invalidate_cache", &js_invalidate_cache, allow_raw_pointers());
  function("vertex_path_from_edge_path", &js_vertex_path_from_edge_path, allow_raw_pointers());
}

#endif