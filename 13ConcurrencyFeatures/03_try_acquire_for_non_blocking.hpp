#pragma once
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <syncstream>

std::counting_semaphore<2> semaphore(2);

auto sync_out(std::ostream& ostream = std::cout)
{
    return std::osyncstream{ ostream };
}

void non_blocking_worker(int id) {
    if (semaphore.try_acquire()) {
        sync_out() << "Thread " << id << " acquired semaphore.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sync_out() << "Thread " << id << " releasing semaphore.\n";
        semaphore.release();
    }
    else {
        sync_out() << "Thread " << id << " could not acquire semaphore.\n";
    }
}

void for_main() {
    std::thread threads[5];
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(non_blocking_worker, i);
    }
    for (auto& t : threads) {
        t.join();
    }
}
