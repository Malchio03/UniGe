#include <string>
#include <vector>
#include "hist.h"

void add(Hist & h, int v) {
    bool found = false;
    for (int i = 0; i < h.size(); ++i) {
        if (h[i].value == v) {
            ++h[i].num;
            found = true;
        }
    }

    if (!found) {
        Bin newBin;
        newBin.value = v;
        newBin.num = 1;
        h.push_back(newBin);
    }
}

void sort(Hist &h) {
    int index;
    for (int i = 0; i < h.size() - 1; ++i) {
        index = i;
        for (int j = i + 1; i < h.size(); ++i) {
            if (h[i].value < h[index].value) {
                index = j;
            }
        }
        int temp = h[i].value;
        h[i].value = h[index].value;
        h[index].value = temp;
    }
}