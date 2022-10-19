#include <iostream>
#include <thread>
#include "buffered_channel.h"

void Send(BufferedChannel<int> &channel){
    for(int i = 1; i <= 5; i++){
        channel.Send(i);
    }
}

void Recv(BufferedChannel<int> &channel){
    for(int i = 1; i <= 5; i++){
        channel.Recv();
    }
}

int main() {
    BufferedChannel<int> channel(5);
std::vector<std::thread> threads;
    for(int i = 1; i <= 5; i++){
        threads.emplace_back(Send, std::ref(channel));
        threads.emplace_back(Recv, std::ref(channel));
    }
    for(auto &thread: threads){
        thread.join();
    }
    return 0;
}
