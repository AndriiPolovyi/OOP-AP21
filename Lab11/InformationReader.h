#pragma once
#include <string>
#include <iostream>

class InformationReader {
protected:
    std::string modelName;
    std::string connectionType;
    double price;

public:
    InformationReader(const std::string& model, const std::string& connection, double cost); 
    virtual ~InformationReader() = default;

    virtual void displayInfo() const;

    friend class DeviceTester;
};