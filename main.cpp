#include <iostream>

enum Method {   addition = 1,
                subtraction = 2,
                areaOfTriangle = 3,
                division = 4, };

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

        int input = inputValidity();
        auto userMethod = static_cast<Method>(input);

        switch(userMethod){
            case 1:
                return add();
            case 2:
                return subtract();
            case 3:
                return area();
            case 4:
                return division();
            default:
                std::cout << "Incorrect method chosen" << std::endl;
                getInput();
        }
    }
    static int inputValidity()
    {
        std::cout << "Please enter a number 1-4 to choose method of calculation." << std::endl;

        int x;
        std::cin >> x;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Your entry must be a digit representing an available method." << std::endl;
            std::cin >> x;
        }
        return x;
    }

    static void printResult() {
        std::cout << getInput();
    }

private:
    static constexpr double first {10.55};
    static constexpr double second {20.55};

    static double add()  {
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
