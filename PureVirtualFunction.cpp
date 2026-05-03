#include <iostream>
using namespace std;

class RemoteControl {
    public:
        virtual void changeChannel(int channel) = 0; // pure virtual function
        virtual void changeVolume(int volume) = 0;
};

class ConcreteRemoteControl : public RemoteControl {
    private:
        int channel;
        int volume;
    public:
        ConcreteRemoteControl(int channel = 1, int volume = 50) : channel(channel), volume(volume) {}
        void changeChannel(int channel) override {
            this -> channel = channel;
            cout << "Channel changed\n";
        }
        void changeVolume(int volume) override {
            this -> volume = volume;
            cout << "Volume changed.\n";
        }
        void displayInfo() {
            cout << "Current Channel: " << channel << "\n" << "Current Volume: " << volume << endl;
        }

};

int main() {
    ConcreteRemoteControl c1;
    c1.displayInfo();
    c1.changeChannel(2);
    c1.changeVolume(70);
    c1.displayInfo();

    return 0;
}
