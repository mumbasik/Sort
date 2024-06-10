﻿#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Паттерн Стратегия позволяет вынести алгоритм поведения объекта за его пределы.
Для решения заданной проблемы может быть представлено несколько алгоритмов.
Инкапсулирование всех алгоритмов внутри класса-владельца грозит нагромождением кода и отсутствием возможности расширения работы класса, а именно добавления дополнительных алгоритмов.
А при данной структуре клиент может выбирать, какой алгоритм поведения объекта ему необходим.
*/

class SortStrategy {
public:
    virtual void Sort(vector<string>& v) = 0;
};

class STLSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        sort(v.begin(), v.end());
    }
};

class ShellSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        int step = v.size() / 2;
        while (step > 0) {
            for (int i = 0; i < (v.size() - step); i++) {
                int j = i;
                while (j >= 0 && v[j] > v[j + step]) {
                    string temp = v[j];
                    v[j] = v[j + step];
                    v[j + step] = temp;
                    j--;
                }
            }
            step = step / 2;
        }
    }
};

class BubbleSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        for (int k = v.size() - 1; k > 0; k--) {
            for (int i = 0; i < k; i++) {
                if (v[i] > v[i + 1]) {
                    string buf = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = buf;
                }
            }
        }
    }
};

class BackBubbleSort : public SortStrategy {
public:
    void Sort(vector<string>& vec) {

        for (int i = 0; i < vec.size() - 1; ++i) {
            for (int j = 0; j < vec.size() - i - 1; ++j) {
                if (vec[j] < vec[j + 1]) {

                    swap(vec[j], vec[j + 1]);
                }
            }
        }
    }
};

class SortedArray {
    vector<string> vector;
    SortStrategy* sortstrategy;

public:
    void SetSortStrategy(SortStrategy* sortstrategy) {
        this->sortstrategy = sortstrategy;
    }

    void Add(string name) {
        vector.push_back(name);
    }

    void Sort() {
        sortstrategy->Sort(vector);
        for (string name : vector) {
            cout << " " + name << endl;
        }
        cout << endl;
    }
};
