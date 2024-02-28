#pragma once
#include <memory>

template <class T, size_t MAX_SIZE = 100, class Alloc = std::allocator<T>>
class Stack {
   private:
    T** _data;
    size_t _size;

    using Alloc_traits = std::allocator_traits<Alloc>;
    Alloc _alloc;

   public:
    class Iterator {
       private:
        friend Stack;
        T** _p;

       public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        Iterator()
            : _p(nullptr) {}

        Iterator(T** p)
            : _p(p) {}

        ~Iterator() noexcept {
            _p = nullptr;
        }

        inline reference operator*() const{
            return **_p;
        }

        inline Iterator& operator++(){
            ++_p;
            return *this;
        }

        inline Iterator operator++(int){
            Iterator tmp = *this;
            ++_p;
            return tmp;
        }

        inline bool operator==(const Iterator& other) const{
            return _p == other._p;
        }

        inline bool operator!=(const Iterator& other) const{
            return _p != other._p;
        }
    };

    class ConstIterator {
       private:
        friend Stack;
        T** _p;

       public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        ConstIterator()
            : _p(nullptr) {}

        ConstIterator(T** p)
            : _p(p) {}

        ~ConstIterator() noexcept {
            _p = nullptr;
        }

        inline value_type operator*() const{
            value_type res = **_p;
            return res;
        }

        inline ConstIterator& operator++(){
            ++_p;
            return *this;
        }

        inline ConstIterator operator++(int){
            ConstIterator tmp = *this;
            ++_p;
            return tmp;
        }

        inline bool operator==(const ConstIterator& other) const{
            return _p == other._p;
        }

        inline bool operator!=(const ConstIterator& other) const{
            return _p != other._p;
        }
    };

    Iterator begin() noexcept{
        return Iterator(_data);
    }

    Iterator end() noexcept{
        return Iterator(_data + _size);
    }

    ConstIterator cbegin() const noexcept{
        return ConstIterator(_data);
    }

    ConstIterator cend() const noexcept{
        return ConstIterator(_data + _size);
    }

    Stack()
        : _size(0), _alloc() { _data = new T*[MAX_SIZE]; }

    Stack(const Stack<T, MAX_SIZE, Alloc>& other) {
        _size = other._size;
        for (size_t i = 0; i != _size; ++i) {
            _data[i] = Alloc_traits::allocate(_alloc, 1);
            *_data[i] = *other._data[i];
        }
    }

    ~Stack() noexcept {
        for (size_t i = 0; i != _size; ++i) {
            Alloc_traits::destroy(_alloc, _data[i]);
            Alloc_traits::deallocate(_alloc, _data[i], 1);
        }

        delete[] _data;
        _size = 0;
    }

    inline size_t size() const{
        return _size;
    }

    inline bool empty() const{
        return _size == 0;
    }

    inline void push(const T& element){
        _data[_size] = Alloc_traits::allocate(_alloc, 1);
        *_data[_size] = element;
        _size++;
    }

    inline T pop(){
        _size--;
        T value = *_data[_size];
        Alloc_traits::destroy(_alloc, _data[_size]);
        Alloc_traits::deallocate(_alloc, _data[_size], 1);
        return value;
    }

    inline Stack& operator=(const Stack<T, MAX_SIZE, Alloc>& other){
        for (size_t i = 0; i != _size; ++i) {
            Alloc_traits::destroy(_alloc, _data[i]);
            Alloc_traits::deallocate(_alloc, _data[i], 1);
        }

        _size = other._size;

        for (size_t i = 0; i != _size; ++i) {
            _data[i] = Alloc_traits::allocate(_alloc, 1);
            *_data[i] = *other._data[i];
        }

        return *this;
    }

    inline T operator[](size_t index) const{
        T value = *_data[index];
        return value;
    }
};

template <class T, size_t MAX_SIZE = 100, class Alloc>
inline std::ostream& operator<<(std::ostream& os, const Stack<T, MAX_SIZE, Alloc>& s){
    os << "Stack elements: ";

    for (size_t i = 0; i != s.size(); ++i) {
        os << s[i] << " ";
    }

    return os;
}
