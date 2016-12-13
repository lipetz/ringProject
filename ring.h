/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ring.h
 * Author: dlipetz
 *
 * Created on December 12, 2016, 8:07 PM
 */

#ifndef RING_H
#define RING_H

#include <iostream>
using namespace std;

template <class T>
class ring {
public:
    class iterator;
public:

    ring(int size) : m_pos(0), m_size(size), m_data(NULL) {
        m_data = new T[size];
    }
    //ring(const ring& orig){ };

    virtual ~ring() {
        delete [] m_data;
    };

    void add(T data) {
        m_data[m_pos++] = data;
        if (m_pos == m_size) m_pos = 0;
    }

    T & get(int i) const {
        return m_data[i];
    }

    int size() const {
        return m_size;
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

private:
    int m_pos;
    int m_size;
    T *m_data;

};

template <class T>
class ring<T>::iterator {
private:
    int m_pos;
    ring &m_ring;
public:

    iterator(int pos, ring & localRing): m_pos(pos), m_ring(localRing) {}
    iterator & operator++(){ //prefix  , postfix would be operator++(int a)
        m_pos++;
        return *this;
    }
    T & operator*(){
        return m_ring.get(m_pos);
    }
    bool operator!=(const iterator &other)const {
        return (m_pos != other.m_pos);
    }
};

#endif /* RING_H */

