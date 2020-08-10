//
//  Vector.hpp
//  Data Structure
//
//  Created by Soubhi Hadri on 8/9/20.
//  Copyright © 2020 hadri. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <utility>

template <typename T>
class Vector {
                
    
public:
    Vector(): m_Capacity(0), m_Size(0){ ReAllocate(2);}
    
    void PushBack(const T& newEle){
        if(m_Size >= m_Capacity){
            ReAllocate(m_Capacity + m_Capacity/2);
        }
        m_Data[m_Size++] = newEle;
    }
    
    void PushBack(T&& newEle){
        if(m_Size >= m_Capacity){
            ReAllocate(m_Capacity + m_Capacity/2);
        }
        m_Data[m_Size++] = std::move(newEle);
    }
    
    size_t Size() const {
        return m_Size;
    }
    
    const T& operator[](size_t index) const{
        if(index>=m_Size){
            
        }
        return m_Data[index];
    }
    
private:
    void ReAllocate(const size_t newCapacity){
//        T* newData = (T*)::operator new( newCapacity * sizeof(T));
        T* newData = new T[newCapacity];
        
        if (newCapacity < m_Size)
            m_Size = newCapacity;
        
        for (size_t index = 0; index < m_Capacity; index++) {
            newData[index] = std::move(m_Data[index]); // Move if able to or just copy
        }
        
//        ::operator delete(m_Data, newCapacity * sizeof(T));
        delete[] m_Data;
        m_Data = newData;
        m_Capacity = newCapacity;
        
    }
    
private:
    T* m_Data = nullptr;
    size_t m_Capacity;
    size_t m_Size;
    
    
};

#endif /* Vector_hpp */
