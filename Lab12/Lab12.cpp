#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>     
#include "Date.h"

int main() {
    
    Date::setCurrentDate(22, 11, 2025);
    std::cout << "--- Laboratorna robota 12 (Variant 13) ---\n";
    std::cout << "Potochna data vstanovlena: " << Date::currentDate << "\n\n";

    std::vector<Date> dates;
    dates.push_back(Date(10, 1, 2025));  
    dates.push_back(Date(1, 12, 2025));  
    dates.push_back(Date(22, 11, 2020));
    dates.push_back(Date(25, 11, 2025)); 
    dates.push_back(Date(1, 1, 2030));   

    std::cout << "Pochatkovyy perelik dat:\n";
    for (const auto& d : dates) {
        std::cout << d << " (Riznytsya z potochnoyu: " << std::abs(d - Date::currentDate) << " dniv)\n";
    }

    std::sort(dates.begin(), dates.end());

    std::cout << "\n--- Pislya sortuvannya (za blyzkistyu do potochnoyi daty) ---\n";
    for (const auto& d : dates) {
        std::cout << d << " (Riznytsya: " << std::abs(d - Date::currentDate) << " dniv)\n";
    }

    long minDiff = 1000000;
    long maxDiff = 0;

    for (size_t i = 0; i < dates.size(); ++i) {
        for (size_t j = i + 1; j < dates.size(); ++j) {
            long diff = std::abs(dates[i] - dates[j]); 

            if (diff < minDiff) minDiff = diff;
            if (diff > maxDiff) maxDiff = diff;
        }
    }

    std::cout << "\n--- Statystyka ---\n";
    std::cout << "Naymensha riznytsya mizh datamy v masyvi: " << minDiff << " dniv\n";
    std::cout << "Naybilsha riznytsya mizh datamy v masyvi: " << maxDiff << " dniv\n";

    return 0;
}