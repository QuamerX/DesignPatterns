#pragma once

#include <vector>

class SortStrategy
{
public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<int>& data) = 0;
};

class BubbleSort : public SortStrategy
{
public:
    void sort(std::vector<int>& data) override
    {
        for (size_t i = 0; i < data.size(); ++i)
            for (size_t j = 0; j + 1 < data.size() - i; ++j)
                if (data[j] > data[j + 1])
                    std::swap(data[j], data[j + 1]);
    }
};

class QuickSort : public SortStrategy
{
    void quickSort(std::vector<int>& a, int l, int r)
    {
        if (l >= r) return;
        int pivot = a[(l + r) / 2];
        int i = l, j = r;
        while (i <= j)
        {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) std::swap(a[i++], a[j--]);
        }
        quickSort(a, l, j);
        quickSort(a, i, r);
    }

public:
    void sort(std::vector<int>& data) override
    {
        if (!data.empty())
            quickSort(data, 0, data.size() - 1);
    }
};

class Sorter
{
    SortStrategy* strategy = nullptr;

public:
    void setStrategy(SortStrategy* s)
    {
        strategy = s;
    }

    void sort(std::vector<int>& data)
    {
		std::cout << "Before sorting: \n";
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
        if (strategy) 
        {
            strategy->sort(data);
        }

		std::cout << "After sorting: \n";
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

