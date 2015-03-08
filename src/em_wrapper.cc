#include "s2.h"
#include "s2cellid.h"
#include "s2cell.h"
#include "s2latlng.h"
#include <iostream>
#include <string>
#include <vector>
#include <emscripten/bind.h>

using namespace emscripten;
using std::string;
using std::cout;
using std::endl;
using std::vector;

struct LngLat {
    double lng;
    double lat;
};

vector<LngLat> translateGeoHash(string hash_string) {
    std::vector<LngLat> polygons;

    S2CellId start = S2CellId::FromString(hash_string);
    S2Cell cell(start);
    for (int i = 0; i < 5; ++i) {
        S2Point point = cell.GetVertex(i % 4);
        S2LatLng s2ll(point);
        LngLat ll;
        ll.lat = s2ll.lat().degrees();
        ll.lng = s2ll.lng().degrees();
        polygons.push_back(ll);
    }

    return polygons;
}

EMSCRIPTEN_BINDINGS(s2_wrappers) {
    value_object<LngLat>("LngLat")
        .field("lng", &LngLat::lng)
        .field("lat", &LngLat::lat)
        ;

    register_vector<LngLat>("VectorLngLat");

    function("translateGeoHash", &translateGeoHash);
}

int main(int argc, char* argv[]) {
    string hash_string = "0f022022";
    if (argc > 1) {
        hash_string = string(argv[1]);
    }

    cout << hash_string << endl;

    auto points = translateGeoHash(hash_string);
    for (auto ll : points) {
        cout << ll.lng << " " << ll.lat << endl;
    }
}

