
#define VECTOR_LIST

#include <igraph_pmt.h>

#define ITEM_TYPE BASE_VECTOR

template<> class igVecList<ITEM_TYPE> {
    TYPE list;

public:
    typedef ITEM_TYPE value_type;
    typedef igraph_integer_t size_type;
    typedef igraph_integer_t difference_type;

    explicit igVecList<ITEM_TYPE>(igraph_integer_t n = 0) {
        FUNCTION(init)(&list, n);
    }

    igVecList<ITEM_TYPE>(igVecList<ITEM_TYPE> &&other) {
        list = other.list;
        other.list.stor_begin = nullptr;
    }

    igVecList<ITEM_TYPE>(const igVecList<ITEM_TYPE> &other) {
        for (size_t i{0}; i < other.size(); ++i) {
            FUNCTION(push_back_copy)(&list, &other[i]);
        }
    }

    igVecList<ITEM_TYPE> & operator = (const igVecList<ITEM_TYPE> &other) {
        for (size_t i{0}; i < other.size(); ++i) {
            igCheck(FUNCTION(push_back_copy)(&list, &other[i]));
        }
        return *this;
    }

    ~igVecList<ITEM_TYPE>() {
        FUNCTION(destroy)(&list);
    }

    operator TYPE *() { return &list; }

    ITEM_TYPE *begin() { return list.stor_begin; }
    ITEM_TYPE *end() { return list.end; }

    const ITEM_TYPE *begin() const { return list.stor_begin; }
    const ITEM_TYPE *end() const { return list.end; }

    ITEM_TYPE *data() { return begin(); }

    size_type size() const { return list.end - list.stor_begin; }
    size_type capacity() const { return list.stor_end - list.stor_begin; }

    ITEM_TYPE & operator [] (size_type i) { return begin()[i]; }
    const ITEM_TYPE & operator [] (size_type i) const { return begin()[i]; }

    void clear() { FUNCTION(clear)(&list); }
    void resize(size_type newsize) { igCheck(FUNCTION(resize)(&list, newsize)); }
    void reserve(size_type newsize) { igCheck(FUNCTION(reserve)(&list, newsize)); }

    void push_back(ITEM_TYPE* elem) { igCheck(FUNCTION(push_back)(&list, elem)); }
    ITEM_TYPE pop_back() { return FUNCTION(pop_back)(&list); }

    void swap(igVecList<ITEM_TYPE> &other) { igCheck(FUNCTION(swap)(&list, &other.list)); }
};

#undef VECTOR_LIST

#include <igraph_pmt_off.h>
