
#include <igraph_pmt.h>

template<> class igVec<BASE> {
    TYPE(igraph_vector) vec;

public:
    typedef BASE value_type;
    typedef igraph_integer_t size_type;
    typedef igraph_integer_t difference_type;

    explicit igVec<BASE>(igraph_integer_t n = 0) {
        FUNCTION(igraph_vector, init)(&vec, n);
    }

    igVec<BASE>(igVec<BASE> &&other) {
        vec = other.vec;
        other.vec.stor_begin = nullptr;
    }

    igVec<BASE>(const igVec<BASE> &other) {
        FUNCTION(igraph_vector, init_copy)(&vec, &other.vec);
    }

    igVec<BASE>(const TYPE(igraph_vector) *v) {
        FUNCTION(igraph_vector, init_copy)(&vec, v);
    }

    igVec<BASE> & operator = (const igVec<BASE> &other) {
        igCheck(FUNCTION(igraph_vector, update)(&vec, &other.vec));
        return *this;
    }

    ~igVec<BASE>() {
        FUNCTION(igraph_vector, destroy)(&vec);
    }

    operator TYPE(igraph_vector) *() { return &vec; }

    BASE *begin() { return vec.stor_begin; }
    BASE *end() { return vec.end; }

    const BASE *begin() const { return vec.stor_begin; }
    const BASE *end() const { return vec.end; }

    BASE *data() { return begin(); }

    size_type size() const { return vec.end - vec.stor_begin; }
    size_type capacity() const { return vec.stor_end - vec.stor_begin; }

    BASE & operator [] (size_type i) { return begin()[i]; }
    const BASE & operator [] (size_type i) const { return begin()[i]; }

    void clear() { FUNCTION(igraph_vector, clear)(&vec); }
    void resize(size_type newsize) { igCheck(FUNCTION(igraph_vector, resize)(&vec, newsize)); }
    void reserve(size_type newsize) { igCheck(FUNCTION(igraph_vector, reserve)(&vec, newsize)); }

    void push_back(BASE elem) { igCheck(FUNCTION(igraph_vector, push_back)(&vec, elem)); }
    BASE pop_back() { return FUNCTION(igraph_vector, pop_back)(&vec); }

    void swap(igVec<BASE> &other) { igCheck(FUNCTION(igraph_vector, swap)(&vec, &other.vec)); }
};

template<> class igMatrix<BASE> {
    TYPE(igraph_matrix) m;

public:
    typedef BASE value_type;
    typedef igraph_integer_t size_type;
    typedef igraph_integer_t difference_type;

    explicit igMatrix<BASE>(igraph_integer_t row = 0, igraph_integer_t col = 0) {
        FUNCTION(igraph_matrix, init)(&m, row, col);
    }

    igMatrix<BASE>(igMatrix<BASE> &&other) {
        m = other.m;
        other.m.data.stor_begin = nullptr;
        other.m.ncol = 0;
        other.m.nrow = 0;
    }

    igMatrix<BASE>(const igMatrix<BASE> &other) {
        FUNCTION(igraph_matrix, init_copy)(&m, &other.m);
    }

    igMatrix<BASE>(const TYPE(igraph_matrix) *mat) {
        FUNCTION(igraph_matrix, init_copy)(&m, mat);
    }

    igMatrix<BASE> & operator = (const igMatrix<BASE> &other) {
        igCheck(FUNCTION(igraph_matrix, update)(&m, &other.m));
        return *this;
    }

    ~igMatrix<BASE>() {
        FUNCTION(igraph_matrix, destroy)(&m);
    }

    operator TYPE(igraph_matrix) *() { return &m; }
};

#include <igraph_pmt_off.h>
