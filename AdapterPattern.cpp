#include <iostream>

// Existing Interface that we want to adapt
class OldCoffeeMachine {
public:
    virtual ~OldCoffeeMachine() {}
    virtual void selectA() = 0; // Select option A
    virtual void selectB() = 0; // Select option B
};

// Class implementing the existing interface
class OldCoffee : public OldCoffeeMachine {
private:
    bool optionA;
    bool optionB;

public:
    OldCoffee() : optionA(false), optionB(false) {} // Initialize options to false

    void selectA() override {
        optionA = true;
        optionB = false;
        std::cout << "Selected option A" << std::endl;
    }

    void selectB() override {
        optionA = false;
        optionB = true;
        std::cout << "Selected option B" << std::endl;
    }
};

// New interface that the client expects
class CoffeeMachineInterface {
public:
    virtual ~CoffeeMachineInterface() {}
    virtual void chooseFirstSelection() const = 0; // Choose the first selection
    virtual void chooseSecondSelection() const = 0; // Choose the second selection
};

// Adapter class that adapts OldCoffeeMachine to CoffeeMachineInterface
class CoffeeTouchScreenAdapter : public CoffeeMachineInterface {
private:
    OldCoffee* OldVendingMachine;

public:
    CoffeeTouchScreenAdapter(OldCoffee* obj) : OldVendingMachine(obj) {} // Initialize with OldCoffee object

    void chooseFirstSelection() const override {
        OldVendingMachine->selectA(); // Delegate to OldCoffee's selectA method
    }

    void chooseSecondSelection() const override {
        OldVendingMachine->selectB(); // Delegate to OldCoffee's selectB method
    }
};

int main() {
    OldCoffee OldCoffee; // Create an instance of OldCoffee
    CoffeeTouchScreenAdapter adapter(&OldCoffee); // Create an adapter instance with OldCoffee instance

    adapter.chooseFirstSelection(); // Choose the first selection (option A)
    adapter.chooseSecondSelection(); // Choose the second selection (option B)

    return 0;
}
