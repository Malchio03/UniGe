#include <iostream>
#include "array.h"

void test_arrayContainsArithmeticSeries() {
    int arr1[] = {};
    int arr2[] = {2, 4, 6, 8};
    int arr3[] = {1, 3, 7, 9};
    int arr4[] = {5, 10, 15, 20};
    int arr5[] = {5, 11, 17, 23};
    int arr6[] = {3, 6, 9, 12, 15};
    int arr7[] = {2, 4, 6, 9};
    
    std::cout << "Test arrayContainsArithmeticSeries:" << std::endl;
    std::cout << "Expected: 1, Got: " << arrayContainsArithmeticSeries(arr1, 0, 1) << std::endl;
    std::cout << "Expected: 1, Got: " << arrayContainsArithmeticSeries(arr2, 4, 2) << std::endl;
    std::cout << "Expected: 0, Got: " << arrayContainsArithmeticSeries(arr3, 4, 2) << std::endl;
    std::cout << "Expected: 1, Got: " << arrayContainsArithmeticSeries(arr4, 4, 5) << std::endl;
    std::cout << "Expected: 1, Got: " << arrayContainsArithmeticSeries(arr5, 4, 6) << std::endl;
    std::cout << "Expected: 1, Got: " << arrayContainsArithmeticSeries(arr6, 5, 3) << std::endl;
    std::cout << "Expected: 0, Got: " << arrayContainsArithmeticSeries(arr7, 4, 2) << std::endl;
}


void test_findSecondLargest() {
    int arr1[] = {};
    int arr2[] = {3};
    int arr3[] = {3, 1, 4, 2};
    int arr4[] = {7, 7, 7, 7};
    int arr5[] = {5, 7, 2, 1};
    int arr6[] = {6, 5, 3, 1};
    
    std::cout << "Test findSecondLargest:" << std::endl;
    std::cout << "Expected: -1, Got: " << findSecondLargest(arr1, 0) << std::endl;
    std::cout << "Expected: -1, Got: " << findSecondLargest(arr2, 1) << std::endl;
    std::cout << "Expected: 3, Got: " << findSecondLargest(arr3, 4) << std::endl;
    std::cout << "Expected: -1, Got: " << findSecondLargest(arr4, 4) << std::endl;
    std::cout << "Expected: 5, Got: " << findSecondLargest(arr5, 4) << std::endl;
    std::cout << "Expected: 5, Got: " << findSecondLargest(arr6, 4) << std::endl;
}

void test_findMajorityElement() {
    int arr1[] = {};
    int arr2[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int arr3[] = {3, 3, 4, 2, 4, 4, 2, 4};
    
    std::cout << "Test findMajorityElement:" << std::endl;
    std::cout << "Expected: -1, Got: " << findMajorityElement(arr1, 0) << std::endl;
    std::cout << "Expected: 4, Got: " << findMajorityElement(arr2, 9) << std::endl;
    std::cout << "Expected: -1, Got: " << findMajorityElement(arr3, 8) << std::endl;
}

int main() {
    test_arrayContainsArithmeticSeries();
    test_findSecondLargest();
    test_findMajorityElement();
    return 0;
}
