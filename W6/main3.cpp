#include <iostream>
#include <vector>
#include <algorithm>

struct Animal{
    virtual auto makeSound() const -> void {
        std::cout << "dzwiek" << '\n';
    }
};
struct Cat : Animal{
    virtual auto makeSound() const -> void override {
        std::cout << "meow" << '\n';
    }
};
namespace my {
    template <typename T>
    class Vector {
        ~Vector(){
            //desktuktor
            //działa gdy vector umiera
            delete[] storage;
        }

        int size = 0;
        T* storage = nullptr;
    public:
        auto pushBack(T const& newElement) -> void {
            auto* newStorage = new T[size+1]; //zwraca wskaźnik na początek przydzielonej pamięci.
            newStorage[size] = newElement;
            std::ranges::copy_n(storage, size, newStorage);
            storage = newStorage;
            size++;
        }
        auto print() const -> void {

            for (int i = 0; i < size; ++i) {

                std::cout<<storage[i]<<'\n';
            }
        }


    };


}


int main() {
    using namespace std;

    /*
    using namespace std;
    auto x = 5;
    auto y = 10;

    auto& ref = x;
    ref = 100;

    auto* ptr = &x;
    cout << *ptr << '\n';

    */
    /*
    auto animals = std::vector<Animal>();
    animals.push_back(Animal());
    for (int i = 0; i < 4; ++i) {
        animals.push_back(Cat());
    }
    for (const auto& item: animals) {
        item.makeSound();
    }
     //object sliceing
     */
    




    return 0;
}
