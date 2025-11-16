#pragma once
#include <string>
#include <iostream>

class InformationReader {
protected:
    std::string modelName;
    std::string connectionType; 

public:
    InformationReader(const std::string& model, const std::string& connection);
    virtual ~InformationReader() = default;
    virtual void displayInfo() const;
};