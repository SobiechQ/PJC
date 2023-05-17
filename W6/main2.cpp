//
// Created by s27233 on 2023-04-05.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <fmt/printf.h>
#include <cmath>

struct Point {
    //JEDYNA różnica między struct i class to że w struct wszystko
    //domyslnie jest publiczne.
    int x;
    int y;



};
auto closestFrom(std::vector<Point> const& points, Point const destination) ->  Point {
    auto const distanceToDest = [destination] (Point const candidate){
        return std::hypot(candidate.x -destination.x, candidate.y - destination.y);
    };


    return std::ranges::min(points, {}, distanceToDest);
}



int main() {
    using namespace std;
    auto p1 = Point();
    auto p2 = Point(1,2);
    auto p3 = Point{3,4};
    auto p4 = Point{5,6};
    auto points = std::vector<Point>{
       p3, {}, {7,1}, p1, p2, p4
    };
/*


    std::ranges::sort(points, [](Point const left, Point const right){
        auto const leftDist = std::hypot(left.x, left.y);
        auto const rightDist = std::hypot(right.x, right.y);
        return leftDist < rightDist;
    });


    for(auto [x,y]: points)
        cout << x << " " << y <<'\n';

*/
    ranges::sort(points, {}, [](Point const p){
        return std::hypot(p.x, p.y);
    });
    auto closest = closestFrom(points, {4,4});




    return 0;
}