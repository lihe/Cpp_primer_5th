//
// Created by Leslie on 2021/1/24.
//

#ifndef CPP_PRIMER_5TH_DATE_H
#define CPP_PRIMER_5TH_DATE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date{
public:
    friend ostream& operator << (ostream&, const date&);

    date() = default;
    explicit date(const string &ds);

    unsigned y() const {return year;}
    unsigned m() const {return month;}
    unsigned d() const {return day;}

private:
    unsigned year, month, day;
};

// �·�ȫ��
const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                             "September", "October", "November", "December"};

// �·ݼ�д
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
                             "Sept", "Oct", "Nov", "Dec"};

// ÿ������
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(const string &ds, int &end_of_month){
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < month_abbr[i].size(); j++) {
            if (ds[j] != month_abbr[i][j]) {     // ���Ǵ��¼�д
                break;
            }
        }

        if (j == month_abbr[i].size()) {      // ���дƥ��
            break;
        }
    }

    if (i == 12){        // �������·ݼ�д����ƥ��
        throw invalid_argument("���Ϸ����·�����");
    }

    if (ds[j] == ' '){        // �������·ݼ�д������ȫ��
        end_of_month = j + 1;
        return i + 1;
    }

    for (; j < month_name[i].size(); j++){
        if (ds[j] != month_name[i][j])
            break;
    }

    if (j == month_name[i].size() && ds[j] == ' '){       // ���·�ȫ��
        end_of_month = j + 1;
        return i + 1;
    }
    throw invalid_argument("���Ϸ����·�����");
}

inline int get_day(const string &ds, unsigned month, int &p){      // ��p��ʼת��Ϊ����ֵ
    size_t q;
    int day = stoi(ds.substr(p), &q);
    if (day < 1 || day > days[month])
        throw invalid_argument("���ǺϷ�������ֵ��");
    p += q;      // ת�Ƶ�����ֵ֮��
    return day;
}

inline int get_year(const string &ds, int &p){     // ��p��ʼת��Ϊ��
    size_t q;
    int year = stoi(ds.substr(p), &q);
    if (p + q < ds.size())
        throw invalid_argument("�Ƿ���β���ݣ�");
    return year;
}

date::date(const string &ds){
    int p;
    size_t q;

    if ((p = ds.find_first_of("0123456789")) == string::npos){
        throw invalid_argument("û�����֣����ǺϷ����ڣ�");
    }

    if (p > 0){       // �·�Ϊ���Ƹ�ʽ
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ' ' && ds[p] != ','){
            throw invalid_argument("�Ƿ��������");
        }
        p++;
        year = get_year(ds, p);
    }
    else{        // �·�Ϊ���ָ�ʽ
        month = stoi(ds, &q);
        p = q;
        if (month > 12 || month < 1){
            throw invalid_argument("���ǺϷ����·ݣ�");
        }
        if (ds[p++] != '/'){
            throw invalid_argument("�Ƿ������");
        }
        day = get_day(ds, month, p);
        if (ds[p++] != '/'){
            throw invalid_argument("�Ƿ������");
        }
        year = get_year(ds, p);
    }
}

ostream & operator << (ostream& out, const date &d){
    out << d.y() << "��" << d.m() << "��" << d.d() << "��" << endl;
    return out;
}
#endif //CPP_PRIMER_5TH_DATE_H
