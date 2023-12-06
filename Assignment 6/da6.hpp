
// Rylan Clavell
// Caleb Fronek
// 2023-11-9
//
// For CS 311 Fall 2023
// Assignment 6
// da6.hpp
// Header for da6_test.cpp using llnode2.hpp

#ifndef FILE_DA6_HPP_INCLUDED
#define FILE_DA6_HPP_INCLUDED

#include <memory>
#include "llnode2.hpp"
#include <stdexcept>
#include <utility>


//Excersize A, reverse list
//No value type operations
//In place
//linear time
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & forehead){
    std::unique_ptr<LLNode2<ValType>> headTwo = nullptr; //new head
    std::unique_ptr<LLNode2<ValType>> nodeTwo = nullptr; //new node
    
    while (forehead) { //while old dir
        nodeTwo = std::move(forehead->_next); //Go to node
        forehead->_next = std::move(headTwo); //change link dir
        headTwo = std::move(forehead); //Move the _head
        forehead = std::move(nodeTwo); //Next
    }
    forehead = std::move(headTwo); 
}

//Excersize B : Slow Map Class template
template <typename KeyType, typename DataType>
class SlowMap {
    
    public:

        using KVType = std::pair<KeyType, DataType>;

        SlowMap() = default; //Default Constructor

        ~SlowMap() = default; //Defualt Destructor

        size_t size() const noexcept { //const size
            return ::size(_head);
        }

        bool empty() const {    //const empty
            return !_head;
        }
        //Present function to check if key is in dataset
        bool present(const KeyType &key) const { 
            auto current = _head.get();
            while (current) {
                if (current->_data.first == key) {
                    return true; //given key is in our set
                }
            current = current->_next.get(); 
            }
            return false; //Key not in our set
        }
        // Function to get the data associated with the Key 
        // const version
        DataType& get(const KeyType &key){ 
            return const_cast<DataType&>(std::as_const(*this).get(key));
        }
        //Function to get the data associated with the Key
        const DataType& get(const KeyType &key) const { //const get
            auto current = _head.get(); 
            while (current) { 
                if (current->_data.first == key) return current->_data.second; 
                current = current->_next.get();  //Move to next item in list
            }
            throw std::out_of_range("Key out of range"); //throw if out of range
        }
        // Function to get value associated with the key
        void set(const KeyType &key, const DataType &value) {
            auto current = _head.get();
            while (current) {
                if (current->_data.first == key) {
                    current->_data.second = value;
                    return;
                }
                current = current->_next.get();
            }
            push_front(_head, KVType(key, value));
        }
        // Function to erase a key value pair from the dataset
        void erase(const KeyType& key) {
            auto current = _head.get();
            std::unique_ptr<LLNode2<KVType>> *prev = &_head; 
            while (current) { 
                if (current->_data.first == key) {
                    *prev = std::move(current->_next);
                    return;
                }
                prev = &current->_next; 
                current = current->_next.get();  
            }
        }
        // Function to traverse dataset and apply function to each key value pai
        template <typename Func>
        void traverse(Func func) {
           for (auto current = _head.get(); current != nullptr; current = current->_next.get()){
            func(current->_data.first, current->_data.second);
           }
        }
        
    private:
        std::unique_ptr<LLNode2<KVType>> _head; 
        //head of linked list
};

#endif // FILE_DA6_HPP_INCLUDED