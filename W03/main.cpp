
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
void boxPrint(std::vector<std::string>names){
    using namespace std;
    string max = "";
    for (string name:names) {
        if(name.length()>max.length())
            max=name;
    }
}

auto main() -> int {
    using namespace std;
    vector<string> words;
    string tmp;
    cin >> tmp;
    while (tmp!="q"){
        words.push_back(tmp);
        cin>>tmp;
    }
    for (int i = 0; i < 10; ++i) {
        cout << " " << '\n';
    }
    for (string w:words) {
        cout << w << '\n';
    }



    return 0;
}