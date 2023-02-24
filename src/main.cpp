#include "asynchronously/async.h"

#include <iostream>
#include <string>
#include <thread>

int main(int argc, char* argv[]) {
    std::size_t bulk = 5;
    auto h1 = async::connect(bulk);
    auto h2 = async::connect(bulk);


    async::receive(h1, "1", 1);
    async::receive(h2, "1", 1);
    async::receive(h1, "2", 1);
    async::receive(h1, "3", 1);
    async::receive(h1, "4", 1);
    async::receive(h1, "5", 1);
    async::receive(h1, "6", 1);
    async::receive(h1, "{", 1);
    async::receive(h1, "a", 1);
    async::receive(h1, "b", 1);
    async::receive(h1, "c", 1);
    async::receive(h1, "d", 1);
    async::receive(h1, "}", 1);
    async::receive(h1, "89", 2);

    async::disconnect(h1);
    async::disconnect(h2);
    return 0;
}
