#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <future>

int returnThreadId() {
    static std::mutex m;
    static int index = 0;

    thread_local int id = [&]{
        std::lock_guard<std::mutex> lock(m);
        return index++;
    }();
        
    return id;
}

void printString(std::string s){
    static std::mutex m;
    std::lock_guard<std::mutex> lock(m);
    std::cout << "\nna wątku " << returnThreadId() << " printuję " << s << std::endl;
}

void asyncFunction(std::launch policy, int n){
    if (n > 0) {
        auto a = std::async(policy, asyncFunction, policy, n - 1);
        a.get();

        printString("stringa w asyncFunction");
    }
}

int main() {
 
    auto a = std::async(std::launch::async, asyncFunction, std::launch::async, 12);
    


    return 0;
}