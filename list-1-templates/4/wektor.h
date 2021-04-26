#pragma once

template<typename T, int len = 1>
class Wektor {
    private:
        //adres wektora
        T *array;

        //aktualny rozmiar wektora
        int size;

        //maksymalny rozmiar wektora
        int max_size;

    public:
        Wektor() {
            array = new T[len];

            //inicjalizuję wektor zapełniając go zerami
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

        //overload [] pozwala otrzymać n-ty element wektora
        T operator [](int i) const{
            return array[i];
        }

        //funkcja wypisująca wszystkie elementy wektora
        void print_all() {
            for (int i = 0; i < size; i++) 
            {
                std::cout << array[i] << " ";
            }
        }

        int get_size() const {
            return size;
        }

        //funkcja zamieniająca wartości elementów na zero
        void clear() {
            for (int i = 0; i < size; i++)
            {
                array[i] = 0;
            }
        }

        //funkcja podmieniająca element o indeksie i na zmienną
        void replace(int i, T j) {
            array[i] = j;
        }

        //funkcja usuwająca element z wektora
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
            //pozostawiam niezmieniony max_size na wypadek, gdyby brakowało miejsca na push_back
        }

        void push_back(T value) {
            if (size == max_size) {
                //podwajam ilość miejsc, tak aby poniższy warunek wykonywał się rzadziej 
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