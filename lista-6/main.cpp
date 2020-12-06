#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <exception>
#include <numeric>

void iloczynSkal(const std::vector<double> &a, const std::vector<double> &b, std::promise<double> &p) {
       
    try {
        if (a.size() != b.size()) {
            throw std::runtime_error("vector_size_err");
        }

        p.set_value( std::inner_product(a.begin(), a.end(), b.begin(), 0.0) );              
    }
    catch (std::exception &e) {
        p.set_exception(std::current_exception());
    }     

    // return p;   
}

int main() {
 
    std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {1, 2, 3, 4};
    std::vector<double> c = {1, 2, 3, 4};
    std::array<std::thread, 10> threads;
    double sum = 0;

    for (auto &t : threads) {
        std::promise<double> prom;
        std::future<double> fut = prom.get_future(); // = iloczynSkal(a, b, prom);
    
        t = std::thread ([&]{
            iloczynSkal(a, a, prom);
            try {
                //double g = fut.get();
                //std::cout << "result: " << g << "\n";
                sum += fut.get();
            }
            catch(const std::exception& e) {
                std::cout << "exception caught: " << e.what() << '\n';
            }    
        });
        
        t.join();
    }

    std::cout << "sum = " << sum << "\n";
/*
    std::cout << "waiting...\n";

    for (auto &t : threads) {
        t.join();
    }
  */  

    return 0;
}