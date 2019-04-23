// Description: Lab10A - Measure the program execution time
// Author: Katherine-Marie Gonzales
// COMSC200 - 5001
// April 22, 2019
// Status: Complete

//myInsertionVsSelectionSortTime.cpp

#include <chrono> 
#include <cstdlib> 
#include <ctime> 
#include <algorithm> 
#include <iostream>


class Timer {
	
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now()) {}
	void reset() { m_beg = clock_t::now(); }
	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void bubbleSort(int* a, int size) {
    for(int i=0; i<size; i++)
        for(int j=0; j<size-1; j++) {
            if(a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
}

void show(int *a) {
    for(int i=0; i<5; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

// insertion sort
void insertionSort(int *a, int size) {
    int temp;
    for(int i = 1; i < size; i++)
    {
        temp = a[i];
        int j;
        for(j = i - 1; j >= 0 && a[i] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    
}


// selection sort

void selectionSort(int *a, int size) {
    int temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = i;j >= 1;j--)
        {
            if (a[j] < a[j-1])
            {
                temp = a[j - 1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    
}
 
int main() {
	const int Size = 10000;
	int array1[Size];
    int array2[Size];
    
    srand (time(NULL));
    int fill;
    for(int i=0; i<Size; i++) {
        array1[i] =array2[i] = rand() % 100003; 
    }
    
    show(array1);
    show(array2);
    

    Timer t1;
	bubbleSort(array1, Size);
	double run1 = t1.elapsed();
    show(array1);
		
    Timer t2;
	std::sort(array2, array2+Size);
    double run2 = t2.elapsed();
    show(array2);
    
    std::cout << "Bubble Sort Time: " << run1 << " seconds\n"
        << "CPP Sort Time: " << run2 << " seconds\n"
        << "Efficiency: " << int( run1/run2 ) << std::endl << std::endl;
 
    Timer t3;
    insertionSort(array1, Size);
    double run3 = t3.elapsed();
    show(array1);
    
    Timer t4;
    selectionSort(array2, Size);
    double run4 = t4.elapsed();
    show(array2);
    
    std::cout << "Insertion Sort Time: " << run3 << " seconds\n"
        << "Selection Sort Time: " << run4 << " seconds\n"
        << "Efficiency: " << int(run3 / run4) << std::endl;
	return 0;
}
