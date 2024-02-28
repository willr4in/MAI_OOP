#pragma once
#include <memory>
#include <deque>

template <class T, size_t SIZE = 1000>
class Allocator {
   public:
    std::deque<T> data;
    size_t free_slots;

    using value_type = T;
    using pointer = T*;
    using const_ointer = const T*;
    using size_type = size_t;

    Allocator() {
        data.resize(SIZE);
        free_slots = SIZE;
    }

    ~Allocator() = default;

    pointer allocate(size_t n){
        if (n > free_slots) {
            throw std::bad_alloc();
        }

        free_slots -= n;

        return &data[free_slots];
    }

    void deallocate(pointer p, size_t n){
        free_slots += n;
    }

    template <class U, class... Args>
    void construct(U* p, Args&&... args){
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p){
        p->~T();
    }

    template <class U>
    struct rebind {
        using other = Allocator<U>;
    };
};

template <class T, class U>
constexpr bool operator==(const Allocator<T>& lhs, const Allocator<U>& rhs){
    return true;
}

template <class T, class U>
constexpr bool operator!=(const Allocator<T>& lhs, const Allocator<U>& rhs){
    return false;
}

