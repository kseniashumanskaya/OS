#ifndef BUFFERED_CHANNEL_BUFFERED_CHANNEL_H
#define BUFFERED_CHANNEL_BUFFERED_CHANNEL_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class BufferedChannel{
private:
    int buffer_size_;
    std::queue<T> queue_;
    std::mutex g_lock_;
    std::condition_variable cv_;
    bool is_closed_;
public:
    BufferedChannel(int size);
    void Send(T value);
    std::pair<T, bool> Recv();
    void Close();
};

template<typename T>
BufferedChannel<T>::BufferedChannel(int size) {
    buffer_size_ = size;
    is_closed_ = false;
}

template<typename T>
void BufferedChannel<T>::Send(T value) {
    std::unique_lock<std::mutex> unique_lock (g_lock_);
    if(is_closed_){
        throw std::runtime_error("channel is closed");
    }
    cv_.wait(unique_lock, [&] () {
        return !(buffer_size_ == queue_.size());});
    queue_.push(value);
    cv_.notify_one();
    unique_lock.unlock();
}

template<typename T>
std::pair<T, bool> BufferedChannel<T>::Recv() {
    std:: unique_lock<std::mutex> unique_lock (g_lock_);
    if(is_closed_ && queue_.size() == 0){
        return std::make_pair(T(), false);
    }
    cv_.wait(unique_lock, [&]() {
        return queue_.size() != 0;
    });
    T value = queue_.front();
    queue_.pop();
    cv_.notify_one();
    unique_lock.unlock();
    return std::make_pair(value, true);
}

template<typename T>
void BufferedChannel<T>::Close() {
    std:: unique_lock<std::mutex> unique_lock (g_lock_);
    is_closed_ = true;
    cv_.notify_one();
}

#endif //BUFFERED_CHANNEL_BUFFERED_CHANNEL_H
