#pragma once
#ifndef CHAPTER04_H
#define CHAPTER04_H

#include <string>
#include <iostream>

namespace chapter04 {
    void cpp_chapter04_ex1();
    
    void cpp_chapter04_ex2();

    void cpp_chapter04_ex3();
}

void testFunc2(); // 전역 네임스페이스
namespace Test {
    void testFunc2();
}
namespace MyData {
    void testFunc2();
}

#endif