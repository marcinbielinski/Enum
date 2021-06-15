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

    static void greetings() {
        std::cout << "Hello! Do you want to calculate something? \n"
                     "These are available methods: \n"
                     "Addition : 1 \n"
                     "Subtraction : 2 \n"
                     "Area of a triangle : 3 \n"
                     "Division : 4 \n";
    }

    static double getInput() {
        std::cout << "Please enter a number 1-4 to choose available method of calculation." << std::endl;
        int input;

        while(true) {
                while (!(std::cin >> input)) {
                    std::cout << "Must be a number!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                }
            if (input <= 4 && input != 0) {
                auto userMethod = static_cast<Method>(input);
                switch (userMethod) {
                    case Method::addition:
                        return add();
                    case Method::subtraction:
                        return subtract();
                    case Method::areaOfTriangle:
                        return area();
                    case Method::division:
                        return division();
                }
            } else {
                getInput();
            }
            break;
        }
    }

    static void printResult() {
        std::cout << getInput();
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
};

int main() {
    Calculate::greetings();
    Calculate::printResult();
    return 0;
}