#pragma once
#include <string>
#include <iostream>
#include <fstream>

class InformationReader {
protected:
    std::string modelName;
    std::string connectionType; 

public:
    InformationReader(const std::string& model = "", const std::string& conn = "");
    virtual ~InformationReader() = default;

    virtual void display() const;

    virtual void saveToFile(std::ofstream& out) const = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;

    virtual int getTypeID() const = 0;
};