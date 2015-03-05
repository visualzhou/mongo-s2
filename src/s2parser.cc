#include "s2.h"
#include "s2cellid.h"
#include "s2cell.h"
#include "s2latlng.h"
#include <iostream>
#include <string>

using namespace std;
extern "C" {

// void hello(char* name_ptr) {
//     string name = string(name_ptr);
//     cout << "hello " << name << endl;
// }

// struct Point {
//     double lng;
//     double lat;
// };

// void convert_hash(char* hash_str, struct Point points[4]) {
void convert_hash(char* hash_str, double* points) {
    string hash_string = string(hash_str);
    cout << "Coverting " << hash_string << endl;
    S2CellId start = S2CellId::FromString(hash_string);
    S2Cell cell(start);
    for (int i = 0; i < 4; ++i) {
        S2Point point = cell.GetVertex(i % 4);
        S2LatLng ll(point);
        double lat = ll.lat().degrees();
        double lng = ll.lng().degrees();
        cout << lng << " " << lat << endl;
        points[i * 2] = lng;
        points[i * 2 + 1] = lat;
    }
}

}
