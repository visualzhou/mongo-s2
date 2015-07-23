#include "s2.h"
#include "s2cellid.h"
#include "s2cell.h"
#include "s2latlng.h"
#include "s2cellunion.h"
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

vector<LngLat> cellToPolgyon(S2CellId id) {
    std::vector<LngLat> polygons;

    S2Cell cell(id);
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

vector<LngLat> getPolygonFromCellId(string hash_string) {
    S2CellId start = S2CellId::FromString(hash_string);
    return cellToPolgyon(start);
}

string getCellIdFromMinMax(string minStr, string maxStr) {
    // Find the common parent of min and max.
    S2CellId minCellId = S2CellId(static_cast<uint64>(std::stoll(minStr)));
    S2CellId maxCellId = S2CellId(static_cast<uint64>(std::stoll(maxStr)));
    S2CellId parentId = minCellId;
    // Assume min and max share the same parent, otherwise fail loudly.
    while (!parentId.contains(maxCellId)) {
        parentId = parentId.parent();
    }
    return parentId.toString();
}

vector<string> getCellUnion(vector<string> cellStrings) {
    vector<S2CellId> cells;
    for (auto c : cellStrings) {
        cells.push_back(S2CellId::FromString(c));
    }

    S2CellUnion cellUnion;
    cellUnion.Init(cells);
    vector<string> resultCells;
    for (auto c : cellUnion.cell_ids()) {
        resultCells.push_back(c.toString());
    }
    return resultCells;
}

EMSCRIPTEN_BINDINGS(s2_wrappers) {
    value_object<LngLat>("LngLat")
        .field("lng", &LngLat::lng)
        .field("lat", &LngLat::lat)
        ;

    register_vector<LngLat>("VectorLngLat");
    register_vector<string>("VectorString");

    function("getPolygonFromCellId", &getPolygonFromCellId);
    function("getCellIdFromMinMax", &getCellIdFromMinMax);
    function("getCellUnion", &getCellUnion);
}

int main(int argc, char* argv[]) {
    string hash_string = "0f022022";
    if (argc > 1) {
        hash_string = string(argv[1]);
    }

    cout << hash_string << endl;
    auto points = getPolygonFromCellId(hash_string);
    for (auto ll : points) {
        cout << ll.lng << " " << ll.lat << endl;
    }

    // Test numerical type index format
    cout << endl;
    string min = "3563805708640059393", max = "3563805710787543039";
    for (auto ll : getPolygonFromCellId(getCellIdFromMinMax(min, max))) {
        cout << ll.lng << " " << ll.lat << endl;
    }
}

