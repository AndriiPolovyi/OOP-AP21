#pragma once
#include <iostream>
#include <string>

class InformationReader {
protected:
    std::string modelName;
    std::string connectionType;

public:
    InformationReader(const std::string& model, const std::string& connection);

    virtual ~InformationReader();

    virtual void displayInfo() const;

    virtual void performScan() = 0;

    void setConnectionType(const std::string& connection);
};