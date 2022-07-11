#ifndef E8C06811_7CDC_41BC_8B11_940FAA62B1BA
#define E8C06811_7CDC_41BC_8B11_940FAA62B1BA

#include <set>

namespace Al {
    template < typename T >
    bool SetHas(const std::set<T> _Set, const T _Val) {
        return _Set.find(_Val) != _Set.end();
    }
}

#endif /* E8C06811_7CDC_41BC_8B11_940FAA62B1BA */
