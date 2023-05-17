#include <iostream>
#include <vector>
#include <algorithm>
int change(int input) {

}


int main() {
    using namespace std;
    auto const vec = std::vector<int>();
    //taki vector nie bedzie mógł mieć żadnuch zmian w sobie, jako const.


    //jak działa kopiowanie obiektów?

    auto const compareBySize = [](std::string left, std::string right){
        return left.size() < right.size();
    };

    //projecttion
    auto const projectBySize = [](std::string const& s){

        //nie można mnożyć przez -1 ponieważ jest to unsigned type.
        return s.size();
    };



    auto strings = std::vector<std::string>{
        "a", "d", "h", "aa", "a", "ab", "abb", "aaa"
    };
    //std::ranges::sort(strings, compareBySize, projectBySize);

    //default operator
    std::ranges::sort(strings, {}, projectBySize);
    //mozna go uzyc, bo zdefiniowano project bby size, ktory zwraca inty, które powównujemy algorymem naturalnym.



    for(auto i:strings)
        cout << i << '\n';
    return 0;
}
