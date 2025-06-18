#include "chapter03.h"

namespace chapter03 {
    void cpp_chapter03_ex1() {
        std::string strData = "Test String";

        std::cout << "Sample string" << std::endl;
        std::cout << strData << std::endl;

        strData = "New string";
        std::cout << strData << std::endl;

        std::cout << "저는" << 20 << "살" << "입니다" << std::endl;
    }

    void cpp_chapter03_ex2() {
        int* pData = new int; //크기 x
        int* pNewData = new int(10);

        *pData = 5;
        
        std::cout << *pData << std::endl;
        std::cout << *pNewData << std::endl;

        delete pData;
        delete pNewData;
    }

    void cpp_chapter03_ex3() {
        int* pArr = new int[5];

        for (int i = 0; i < 5; i++)
            pArr[i] = (i + 1) * 10;

        for (int i = 0; i < 5; i++)
            std::cout << pArr[i] << std::endl;
        
        delete[] pArr;
    }

    void cpp_chapter03_ex4() {
        int data = 10;

        int& ref = data;
        ref = 20;
        std::cout << data << std::endl;

        int* pData = &data;
        *pData = 30;
        std::cout << data << std::endl;
    }

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void cpp_chapter03_ex5() {
        int x = 10, y = 20;

        swap(x, y);

        std::cout << x << std::endl;
        std::cout << y << std::endl;
    }

    int testFunc(int param) 
    {
        int result = param * 2;
        return result;
    }

    void cpp_chapter03_ex6() {
        int input = 0;

        std::cout << "Input number: ";
        std::cin >> input;

        int&& rData = (input + 5);
        std::cout << rData << std::endl;

        int&& result = testFunc(10);

        result += 10;
        std::cout << result << std::endl;
    }

    void cpp_chapter03_ex7() {
        int list[] = { 10, 20, 30, 40, 50, 60 };

        for (int i = 0; i < 5; i++)
            std::cout << list[i] << ' ';
        std::cout << std::endl;

        for (const auto element : list)
            std::cout << element << ' ';
        std::cout << std::endl;

        for (const auto& element : list)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
}