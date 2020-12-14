#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <functional>
#include <chrono>
#include <condition_variable>

class myClass {

    public:
        myClass(int numThreads){
            _threadList.reserve(numThreads);
            for (int i = 0; i < numThreads; i++) {
                _threadList.emplace_back( std::bind(&myClass::findTask, this) );
            }
        }

        void add_task(std::function<double()> task) {
            std::lock_guard<std::mutex> lock(_mu_add);
            _taskList.emplace(std::move(task));
            _cond.notify_one();
        }

        double average() {
            std::lock_guard<std::mutex> av_lock(_mu);
            if (!taskCount)
                return 0;
            else
                return sum/taskCount;
        }

        void stop() {

            {
                std::unique_lock<std::mutex> lock(_mu);
                _work = false;
                _cond.notify_all();
            }

            for (auto &t : _threadList) {
                t.join();
            }
        }

    private:
        std::mutex _mu_add, _mu;
        bool _work;
        std::condition_variable _cond;
        double sum = 0, taskCount = 0;
        std::queue<std::function<double()>> _taskList;
        std::vector<std::thread> _threadList;

        void findTask() {
            std::function<double()> task;

            while (1)
            {
                {
                    std::unique_lock<std::mutex> lock(_mu);

                    while (_work && _taskList.empty()) {
                        _cond.wait(lock);
                    }

                    if (_taskList.empty()) {
                        
                        return;
                    }
                    
                    task = std::move(_taskList.front());

                    sum += task();
                    taskCount++;
                    _taskList.pop();
                }
            }            
        }  
};