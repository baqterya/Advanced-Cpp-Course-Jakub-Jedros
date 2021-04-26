#include <iostream>
#include <omp.h>

int main() {

    #pragma omp parallel 
    {
        #pragma omp critical
        {
            std::cout << "Witaj w wątku nr " << omp_get_thread_num() << " spośród " << omp_get_num_threads() << "\n";
        }
    }

    return 0;
}