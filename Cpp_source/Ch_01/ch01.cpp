#include <iostream>
#include "Sale_item.h"

void q_1_3(){
    std::cout << "Hello World!" << std::endl;
}

void q_1_4(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
}

void q_1_5(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}

void basic_while(){
    int sum = 0, val = 1;
    while (val <= 10){
        sum += val;
        val++;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}

void q_1_9(){
    int val = 50, sum = 0;
    while (val <= 100){
        sum += val;
        val++;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
}

void q_1_10(){
    int val = 10;
    while (val >= 10){
        std::cout << val << " ";
        val--;
    }
}

void q_1_11(){
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end){
        while (start <= end){
            std::cout << start << " ";
            start++;
        }
    }
    else{
        std::cout << "Start should be smaller than end!" << std::endl;
    }
}

void basic_for(){
    int sum = 0;
    for (int val = 1; val <= 10; ++val){
        sum += val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
}

void q_1_16(){
    int sum = 0;
    for (int value = 0; std::cin >> value; )
        sum += value;
    std::cout << sum << std::endl;
}

void q_1_20(){
    for(Sales_item item; std::cin >> item; std::cout << item << std::endl);
}

void q_1_21(){
    Sales_item item1;
    Sales_item item2;
    std::cin >> item1;
    std::cout << item1;
    std::cin >> item2;
    std::cout << item2;
    std::cout << "Sum of sale items: " << item1 + item2 << std::endl;
}

void q_1_22(){
    Sales_item sum_item;
    std::cin >> sum_item;
    std::cout << sum_item << std::endl;
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl){
        sum_item += item;
    }
    std::cout << "Sum of sale items: " << sum_item << std::endl;
}

void q_1_23(){
    Sales_item total;
    if (std::cin >> total){
        Sales_item item;
        while (std::cin >> item){
            if (total.isbn() == item.isbn()){
                total += item;
            }
            else{
                std::cout << total << std::endl;
                total = item;
            }
        }
        std::cout << total << std::endl;
    }
    else{
        std::cerr << "No data?" << std::endl;  // 写到cerr的数据是不缓冲的。Cerr通常用于输出错误信息与其他不属于正常逻辑的输出内容。
        return;
    }
}

int main(){
    std::cout << /* "*/" /* "/*" */;
    return 0;
}