#ifndef VECTOR_H_
#define VECTOR_H_

#include <set>

namespace Al {
    template < typename T >
    bool doesSetContain(const std::set<T> _Set, const T _Val) {
        return _Set.find(_Val) != _Set.end();
    }
}

#endif /* VECTOR_H_ */
