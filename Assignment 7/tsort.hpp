// tsort.hpp
// Rylan Clavell
// Caleb Fronek
// 2023-11-21
//
// For CS 311 Fall 2023
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TSORT_HPP_INCLUDED
#define FILE_TSORT_HPP_INCLUDED

#include <iterator> // For std::iterator_traits
#include <memory>   // For std::unique_ptr

// BinarySearchTree class
template<typename T>
class BinarySearchTree {
public:
    void insert(const T& value) {
        if (!root) {
            root = std::make_unique<Node>(value);
        } else {
            root->insert(value);
        }
    }

    template<typename Iter>
    void inOrderTraversal(Iter& iter) const {
        if (root) {
            root->inOrderTraversal(iter);
        }
    }

private:
    struct Node {
        T value;
        std::unique_ptr<Node> left, right;

        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}

        void insert(const T& val) {
            if (val < value) {
                if (left) {
                    left->insert(val);
                } else {
                    left = std::make_unique<Node>(val);
                }
            } else {
                if (right) {
                    right->insert(val);
                } else {
                    right = std::make_unique<Node>(val);
                }
            }
        }

        template<typename Iter>
        void inOrderTraversal(Iter& iter) const {
            if (left) {
                left->inOrderTraversal(iter);
            }
            *iter++ = value;
            if (right) {
                right->inOrderTraversal(iter);
            }
        }
    };

    std::unique_ptr<Node> root;
};

// treesort function template
template<typename FDIter>
void treesort(FDIter first, FDIter last) {
    using ValueType = typename std::iterator_traits<FDIter>::value_type;
    BinarySearchTree<ValueType> bst;

    for (FDIter iter = first; iter != last; ++iter) {
        bst.insert(*iter);
    }

    bst.inOrderTraversal(first);
}

#endif // #ifndef FILE_TSORT_HPP_INCLUDED
