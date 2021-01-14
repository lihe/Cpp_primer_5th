#include <iostream>
#include "Sales_data.h"

void q_2_3(){
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}


// 重写 1.5.1 1.5.2 1.6

int q_1_5_1()
{
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

    return 0;
}

int q_1_5_2(){
    Sales_data data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0){
            std::cout << totalRevenue / totalCnt << std::endl;
        }
        else{
            std::cout << "(no sales)" << std::endl;
        }
        return 0;
    }
    else{
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}

int q_1_6(){
    Sales_data total;
    double totalPrice = 0;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice){
        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice){
            trans.revenue = trans.units_sold * transPrice;

            if (total.bookNo == trans.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else{
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0){
                    std::cout << total.revenue / total.units_sold << std::endl;
                    std::cout << "(no sales)" << std::endl;
                }
                else {
                    total.bookNo = trans.bookNo;
                    total.units_sold = trans.units_sold;
                    total.revenue = trans.revenue;
                }
            }
            std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
            if (total.units_sold != 0)
                std::cout << total.revenue / total.units_sold << std::endl;
            else
                std::cout << "(no sales)" << std::endl;

            return 0;
        }
    }
    else{
        std::cerr << "No data?" << std::endl;
        return -1;
    }
}

int main(){
//    q_2_3();
//    q_1_5_1();
//    q_1_5_2();
    q_1_6();
    return 0;
}