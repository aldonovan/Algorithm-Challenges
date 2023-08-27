#include <bits/stdc++.h>
using namespace std;

class Car {
    private:
        string owner;
    public:
        int speed;
        string brand;
        int cost;
        Car(int speed, string brand, int cost, string owner) {
            this->speed = speed;
            this->brand = brand;
            this->cost = cost;
            this->owner = owner;
        }
        string getOwner() {
            return owner;
        }
};


int main() {
    Car starterCar(70, "Toyota", 30000, "Tom Johnson");
    starterCar.speed = 100;
    cout << starterCar.speed << endl;
    cout << starterCar.getOwner() << endl;
    return 0;
}