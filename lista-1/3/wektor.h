#pragma once

template<typename T, int len = 1>
class Wektor {
    private:
        T *array;
        int size;
        int max_size;

    public:
        Wektor() {
            array = new T[len];

            for (int i = 0; i < len; i++)
            {
                array[i] = 0;
            }

            size = len;
            max_size = len;
        }

        ~Wektor() {
            delete[] array;
            array = nullptr;
        }

        typedef T value_type;

        T operator [](int i) {
            return array[i];
        }

        void print_all() {
            for (int i = 0; i < size; i++) 
            {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }

        int get_size() {
            return size;
        }

        void clear() {
            for (int i = 0; i < size; i++)
            {
                array[i] = 0;
            }
        }

        void replace(int i, T j) {
            array[i] = j;
        }

        void remove_slot(int i) {
            T *temp = new T[size - 1];
            
            for (int j = 0; j < size-1; j++)
            {
                if (j >= i)
                    temp[j] = array[j+1];
            }

            delete[] array;
            size -= 1;
            array = temp; 
        }

        void push_back(T value) {
            if (size == max_size) {
                T *temp = new T[max_size * 2];

                for (int i = 0; i < max_size; i++)
                {
                    temp[i] = array[i];
                }

                delete[] array;
                max_size += 1;
                array = temp;                
            }
            
            array[size] = value;
            size++;
        }
};