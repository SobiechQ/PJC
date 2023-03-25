
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

int main() {
    using namespace std;
    /*
    using namespace std;
    auto vec = std::vector<int>{1,2,3,4,5,6,7,8};
    vec.erase(vec.begin(), vec.begin()+2);
    //ersae usuwa w zakresie <a,b) -> czyli bez B.
    for (int i: vec) {
        cout << i << '\n';
    } //usuwa od 0 do 3 bez 3



    //vec end wskazuje na element o 1 POZA vec, dlatego to usunie calosc
    vec.erase(vec.begin(), vec.end());
    //end = begin + size;
    */
    /*
    auto vec = std::vector<int>{1,0,2,4,6,-4,44,2,2,2,2};
//    auto set = std::set<int>{};
//    for (const auto &item: vec) {
//        set.insert(item);
//    }
    auto set2 = std::set<int>(vec.begin(), vec.end()); //lepsza opcja przypisywania vectora do seta

    for (const auto &item: set2) {
        cout << item << '\n';
    }
    */
    /*
    auto vec = std::vector<int>{1,0,-4,-4,-4,5,3,1,0,1,1,1,1,1};
    std::ranges::sort(vec);
    for (const auto &item: vec) {
        cout << item << ", ";
    }
    cout << "" << '\n';
    cout << "=========================" << '\n';
    std::ranges::unique(vec.begin(), vec.end());
    for (const auto &item: vec) {
        cout << item << ", ";
    }
     */
    /*
    //mapa
    auto text = std::string("ale ma kota");
    auto occurences = std::map<char, int>(); //mapa ma unikalne klucze i jest posortowana po kluczach.
//    occurences['a']; //soro nie ma elementu o indeksie a to tworzy element o indeksie 'a';
    for(auto a:text) {
        occurences[a] += 1;
    }
//    for(auto pair : occurences){
//        cout << pair.first <<", "<<pair.second << '\n';
//    }
    //lepsza opcja tego co wyżej:
    for(auto [key, value]:occurences){ //można nadać nazwę dla klucza i wartości.
        cout << key <<", "<<value << '\n';
    }



//    auto it = std::ranges::find(occurences, 5); //find if do szukania po mapie

//    if(it != vec.end()){
//        //tylko jak it nie skazuje na koniec
//    }
//    //lepsza opcja
//    if(abc = std::ranges::find(occurences, 1); abd==3){ //tak jak w for(;;) w if moge w pierwszym segmencie
//        //dac dowolna rzecz, dobra praktyka jest danie zmiennej ktora na pewno bie bedzie uzywana poza petla
//
//    }
     */



    return 0;
}