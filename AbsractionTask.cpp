#include <iostream>
using namespace std;

class Activity {
    public:
        virtual void calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
    private:
        double distance;
        double time;
    public:
        Running(double distance, double time) : distance(distance), time(time) {}
        void calculateCaloriesBurned() override {
            cout << "Calories burned by running: " << distance * time << endl;
        }

};

class Cycling : public Activity {
    private:
        double speed;
        double time;
    public:
        Cycling(double speed, double time) : speed(speed), time(time) {}
        void calculateCaloriesBurned() override {
            cout << "Calories burned by cycling: " << speed * time << endl;
        }
};

int main() {
    Activity* activities[2];
    activities[0] = new Running(2, 30);
    activities[1] = new Cycling(80, 30);

    for(int i = 0; i < 2; i++) {
        activities[i]->calculateCaloriesBurned();
        delete activities[i];
    }
    
    return 0;
}
