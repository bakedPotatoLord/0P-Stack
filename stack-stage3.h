/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Josiah Hamm
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1
#include <chrono> // for timing


/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead use the std:: prefix where required in class definitions, as
 * demonstrated in the stack starter code for stage1.
 */




template<typename T>
class stack {
  public:
    T top(){
        return data[len-1];
    }

    // inline definitions, doing nothing at the moment
    void push(const T & s){
      if (len == capacity) {
        capacity *= 2;
        T *new_data = new T[capacity];
        for (size_t i = 0; i < len; i++) {
            new_data[i] = data[i];
        }
        delete [] data;
        data = new_data;
      }
      data[len++] = s;
    };

    void pop(){
        len--;
    }

    size_t size() { return len; }
    bool is_empty() { return len == 0; }

    stack(){
        len = 0;
        capacity = 4;
        data = new T[capacity];
    };

    ~stack(){
        delete [] data;
    };

    //copy constructor
    stack(const stack &other){
        len = other.len;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    };

    //assignment operator
    stack & operator=(const stack &other){
        if (this != &other) {
            delete [] data;
            len = other.len;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < len; i++) {
                data[i] = other.data[i];
            }
        } 
        return *this;
    };
    
    size_t len;
    u_int32_t capacity;
    T *data;
  private:
};

template<typename T>
class badStack : public stack<T> {
public:
    void push(const T & s){
      
    //     this->capacity += 1;
    //     T *new_data = new T[this->capacity];
    //     for (size_t i = 0; i < this->len; i++) {
    //         new_data[i] = this->data[i];
    //     }
    //     delete [] this->data;
    //     this->data = new_data;
    //   this->data[this->len++] = s;

    if (this->len == this->capacity) {
        if (this->capacity == 1) {
            this->capacity = 2;
        } else {
            this->capacity *= 1.5;
        }
        T *new_data = new T[this->capacity];
        for (size_t i = 0; i < this->len; i++) {
            new_data[i] = this->data[i];
        }
        delete [] this->data;
        this->data = new_data;
      }
      this->data[this->len++] = s;
    };
};

inline double time_n_pushes(unsigned n) {
  stack<unsigned> s;
  // get starting clock value
  auto start_time = std::chrono::system_clock::now();
  // do the n pushes
  for (unsigned i = 0; i < n; i++) {
    s.push(i);
  }
  // get ending clock value
  auto stop_time = std::chrono::system_clock::now();
  // compute elapsed time in seconds
  std::chrono::duration<double> elapsed = stop_time - start_time;
  return elapsed.count();
}

inline double time_n_pushes_bad(unsigned n) {
  badStack<unsigned> s;
  // get starting clock value
  auto start_time = std::chrono::system_clock::now();
  // do the n pushes
  for (unsigned i = 0; i < n; i++) {
    s.push(i);
  }
  // get ending clock value
  auto stop_time = std::chrono::system_clock::now();
  // compute elapsed time in seconds
  std::chrono::duration<double> elapsed = stop_time - start_time;
  return elapsed.count();
}

#endif
