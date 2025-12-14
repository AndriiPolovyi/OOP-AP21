#include <iostream>
#include <memory>   
#include <vector>
#include "CoaxialCable.h"

int main() {
    std::cout << "=== LABORATORNA ROBOTA #16: ROZUMNI VKAZIVNYKY ===\n\n";

    std::cout << "--- 1. Robota z std::unique_ptr ---\n";
    {
        std::unique_ptr<CoaxialCable> u_ptr = std::make_unique<CoaxialCable>(50, 7.5, 100);
        u_ptr->displayInfo();
        u_ptr->transmitSignal();

        std::cout << "Sproba peredachi vlasnosti (std::move)...\n";
        std::unique_ptr<CoaxialCable> u_ptr2 = std::move(u_ptr);

        if (!u_ptr) std::cout << "u_ptr teper porozhniy.\n";
        u_ptr2->displayInfo();
    } 

    std::cout << "\n--- 2. Robota z std::shared_ptr ta std::weak_ptr ---\n";
    std::shared_ptr<CoaxialCable> s_ptr1 = std::make_shared<CoaxialCable>(75, 4.8, 50);

    {
        std::shared_ptr<CoaxialCable> s_ptr2 = s_ptr1; 
        std::cout << "Lichylnyk posylanj: " << s_ptr1.use_count() << "\n";
        s_ptr2->displayInfo();

        std::weak_ptr<CoaxialCable> w_ptr = s_ptr1;
        std::cout << "weak_ptr sposterihaye za ob'yektom...\n";

        if (auto locked_ptr = w_ptr.lock()) { 
            std::cout << "Ob'yekt isnuje, dostup cherez lock():\n";
            locked_ptr->transmitSignal();
        }
    }
    std::cout << "Lichylnyk pislja vykhodu z bloku: " << s_ptr1.use_count() << "\n";

    std::cout << "\n--- 3. Konteyner z rozumnymy vkazivnykamy ---\n";
    std::vector<std::shared_ptr<CoaxialCable>> inventory;
    inventory.push_back(s_ptr1);
    inventory.push_back(std::make_shared<CoaxialCable>(50, 10.2, 250));

    for (const auto& item : inventory) {
        item->displayInfo();
    }

    std::cout << "\nZavershennya prohramy. Ochyshchennya vektora...\n";
    inventory.clear();
    s_ptr1.reset();

    std::cout << "Kinetjsj main().\n";
    return 0;
}