#pragma once

#include <iostream>

class DataProcessor
{
public:
    void process()
    {
        readData();
        processData();
        saveData();
    }

protected:
    virtual void readData() = 0;
    virtual void processData() = 0;

    // Optional override
    virtual void saveData()
    {
        std::cout << "Saving to file\n";
    }
};

class CSVProcessor : public DataProcessor
{
protected:
    void readData() override
    {
        std::cout << "Reading CSV data\n";
    }

    void processData() override
    {
        std::cout << "Processing CSV data\n";
    }
};

class JSONProcessor : public DataProcessor
{
protected:
    void readData() override
    {
        std::cout << "Reading JSON data\n";
    }

    void processData() override
    {
        std::cout << "Processing JSON data\n";
    }
};

