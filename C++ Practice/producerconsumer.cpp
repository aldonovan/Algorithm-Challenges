#include <mutex>
#include <iostream>
#include <thread>
#include <semaphore.h>

std::mutex bufferLock;
std::condition_variable empty;
std::condition_variable full;
int buffer[20];
int count = 0;

void produce() {
    while (true) {
        std::unique_lock<std::mutex> ul(bufferLock);
        full.wait(ul, [] { return count < 20;});
        int x = rand() % 100;
        buffer[count] = x;
        count++;
        if (count == 1) {
            empty.notify_one();
        }
    }
}

void consume() {
    while (true) {
        std::unique_lock<std::mutex> ul(bufferLock);
        empty.wait(ul, [] { return count > 0;});
        std::cout << buffer[count - 1] << std::endl;
        count--;
        if (count == 19) {
            full.notify_one();
        }
    }
}


int main() {
    std::thread producer(produce);
    std::thread consumer(consume);
    producer.join();
    consumer.join();
    return 0;
}
