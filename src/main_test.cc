#include "s2.h"
#include "s2cellid.h"
#include "s2cell.h"
#include "s2latlng.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string hash_string = "0f022022";
    if (argc > 0) {
        hash_string = string(argv[1]);
    }
    S2CellId start = S2CellId::FromString(hash_string);
    S2Cell cell(start);
    for (int i = 0; i < 5; ++i) {
        S2Point point = cell.GetVertex(i % 4);
        S2LatLng ll(point);
        double lat = ll.lat().degrees();
        double lng = ll.lng().degrees();
        cout << lng << " " << lat << endl;
    }
}
