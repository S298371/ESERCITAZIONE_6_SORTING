#include <chrono>
#include <iostream>
#include <unistd.h>
#include <numeric>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;


vector<int> createVector_ordinato(int dimv) {
    vector<int> v(dimv);
    int n = 0;
    generate(v.begin(), v.end(), [&n] () { return n++; });

    return v;
}



// Perturbazioni

vector<int> createVector_perturbazioni(int dimv) {
    vector<int> v(dimv);
    int n = 0;
    generate(v.begin(), v.end(), [&n] () { return n++; });

    for(unsigned int i =0; i <800; i++)
        v[i] = rand() %100;


    return v;
}

// randomico
vector<int> createRandomVector(int dimv) {

    vector<int> v(dimv);
    for (int i = 0; i < dimv; ++i) {

        v[i] = rand() % 100 + 1;
    }
    return v;
}


double TimeMergeSort(vector<int>& v) {
    // inizio
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    sleep(1);
    SortLibrary::MergeSort(v);

    // fine
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();


    return chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
}

double TimeBubbleSort(vector<int>& v) {
    // inizio
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    sleep(1);
    SortLibrary::BubbleSort(v);

    // fine
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();


    return chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
}







int main(int argc, char ** argv)
{

    int dimv = atoi(argv[1]);


    //vettore oridnato:
    vector<int> vo = createVector_ordinato(dimv);
    cout<<"timeMergeSort vettore orindato dimensione: "<<dimv<<" " ;
    double timeElapsedMo = TimeMergeSort(vo);
    cout<< timeElapsedMo<<endl;
    cout<<"timeBubbleSort vettore orindato dimensioni: "<<dimv<<" " ;
    double timeElapsedBo = TimeBubbleSort(vo);
    cout<< timeElapsedBo<<endl;



    //vettore con perturbazioni

    //prima di eseguire il test controllare che il numero di perturbazioni sia minore o uguale della dimensione  del vettore.
    //variando il numero di perturbazioni i contronti tra i due tipi di algormitomo sono differenti.
    vector<int> vp = createVector_perturbazioni(dimv);
    cout<<"timeMergeSort vettore con perturbazioni dimensione: "<<dimv<<" ";
    double timeElapsedMp = TimeMergeSort(vp);
    cout<< timeElapsedMp<<endl;
    cout<<"timeBubbleSort vettore con perturbazioni dimensioni "<<dimv<<" " ;
    double timeElapsedBp = TimeBubbleSort(vp);
    cout<< timeElapsedBp<<endl;



    //vettore randomico
    vector<int> vr = createRandomVector(dimv);
    cout<<"timeMergeSort vettore randomico dimensione: "<<dimv<<" ";
    double timeElapsedMr = TimeMergeSort(vr);
    cout<< timeElapsedMr<<endl;
    cout<<"timeBubbleSort vettore randomico dimensioni "<<dimv<<" " ;
    double timeElapsedBr = TimeBubbleSort(vr);
    cout<< timeElapsedBr<<endl;

 //modificando la dimensione del vettore, si può notare come per i vettori di piccole dimensioni non cambi molto l'akgoritmo utulizzato
 //mentre sui vettori di gradni dimensioni, il tipo di vettore e il tipo di algoritmso utilizzato ha un impatto maggiore sul tempo.


    return 0;
}
