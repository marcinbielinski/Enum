#include <iostream>

enum class Method {
    addition = 1,
    subtraction = 2,
    areaOfTriangle = 3,
    division = 4,
};

class Calculate {
public:
    Calculate() = default;

    static double runCalc() {

        greetings();

        auto method = getInput();

        switch (method)
        {
            case Method::addition:
                return add();
            case Method::subtraction:
                return subtract();
            case Method::areaOfTriangle:
                return area();
            case Method::division:
                return division();
        }
    }
    static Method getInput() {
        int input;
        std::cout << "Please input a valid operation number: " << std::endl;

        while(true)
        {
            std::cin >> input;
            if(input <= 4 and input != 0)
            {
                break; // break out of the loop
            }
            else
            {
                std::cout << "Invalid input try again" << std::endl;
            }
        }
        // after break - cast return value to Method
        return static_cast<Method>(input);
    }

private:
    static constexpr double first{10.55};
    static constexpr double second{20.55};

    static double add() {
        return first + second;
    }

    static double subtract() {
        return first - second;
    }

    static double area() {
        return (first * second) / 2;
    }

    static double division() {
        return (first / second);
    }

    static void greetings() {
        std::cout << "Hello! Do you want to calculate something? \n"
                     "These are available methods: \n"
                     "Addition : 1 \n"
                     "Subtraction : 2 \n"
                     "Area of a triangle : 3 \n"
                     "Division : 4 \n";
    }

};

int main() {
    std::cout << Calculate::runCalc();
    return 0;
}