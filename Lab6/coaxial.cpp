#include "coaxial.h"
#include <limits>

CoaxialManager::CoaxialManager() {
    for (auto& r : records) {
        r.id = 0;
        r.Z = 0.0;
        r.D = 0.0;
        r.L = 0.0;
    }
    std::cout << "CoaxialManager stvorenyi. Rozmir masyvu = " << MAX_RECORDS << "\n";
}

CoaxialManager::~CoaxialManager() {
    std::cout << "CoaxialManager znyshchuietsya.\n";
}

bool CoaxialManager::isValidZ(double z) const {
    return z > 0.0 && z <= 10000.0;
}

bool CoaxialManager::isValidD(double d) const {
    return d > 0.0 && d <= 1000.0;
}

bool CoaxialManager::isValidL(double l) const {
    return l > 0.0 && l <= 100000.0;
}

void CoaxialManager::inputRecord(std::size_t index) {
    if (index >= MAX_RECORDS) {
        std::cerr << "Indeks za mezhamy (0.." << MAX_RECORDS - 1 << ")\n";
        return;
    }

    Coax_t tmp;
    std::cout << "Vvedennya/redaguvannya zapysu indeks " << index << ":\n";
    std::cout << "Vvedit id (tsile pozytyvne chyslo): ";
    while (!(std::cin >> tmp.id) || tmp.id <= 0) {
        std::cout << "Nepravylnyi id. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Vvedit khvylovyi opir Z (Om, >0): ";
    while (!(std::cin >> tmp.Z) || !isValidZ(tmp.Z)) {
        std::cout << "Nepravylnе znachennya Z. Povtorit (Z > 0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Vvedit diametr D (mm, >0): ";
    while (!(std::cin >> tmp.D) || !isValidD(tmp.D)) {
        std::cout << "Nepravylnе znachennya D. Povtorit (D > 0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Vvedit dovzhynu L (m, >0): ";
    while (!(std::cin >> tmp.L) || !isValidL(tmp.L)) {
        std::cout << "Nepravylnе znachennya L. Povtorit (L > 0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Zberihayemo
    records[index] = tmp;
    std::cout << "Zapys zberezheno u sloti " << index << ".\n";
}

void CoaxialManager::printRecord(std::size_t index) const {
    if (index >= MAX_RECORDS) {
        std::cerr << "Indeks poza mezhamy\n";
        return;
    }
    const Coax_t& r = records[index];
    if (r.id == 0) {
        std::cout << "[" << index << "] Porozhnii slot\n";
    }
    else {
        std::cout << "[" << index << "] id=" << r.id
            << ", Z=" << r.Z << " Om"
            << ", D=" << r.D << " mm"
            << ", L=" << r.L << " m\n";
    }
}

void CoaxialManager::printAll() const {
    std::cout << "=== Vmist masyvu Coaxial ===\n";
    for (std::size_t i = 0; i < MAX_RECORDS; ++i) {
        printRecord(i);
    }
    std::cout << "============================\n";
}

void CoaxialManager::clearRecord(std::size_t index) {
    if (index >= MAX_RECORDS) {
        std::cerr << "Indeks poza mezhamy\n";
        return;
    }
    records[index].id = 0;
    records[index].Z = 0.0;
    records[index].D = 0.0;
    records[index].L = 0.0;
    std::cout << "Slot " << index << " ochyshcheno.\n";
}

bool CoaxialManager::setRecord(std::size_t index, const Coax_t& r) {
    if (index >= MAX_RECORDS) return false;
    if (r.id <= 0) return false;
    if (!isValidZ(r.Z) || !isValidD(r.D) || !isValidL(r.L)) return false;
    records[index] = r;
    return true;
}