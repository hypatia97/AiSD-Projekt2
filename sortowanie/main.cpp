#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<time.h>
#include <ctime>
#include <cstdio>


using namespace std;



double obliczSekundy( clock_t czas )
{
    //wyznaczanie czasu w sekundach
    return static_cast < double >( czas ) / CLOCKS_PER_SEC;
}

//wprowadzanie liczb losowych
void Wprowadzanie(const char*nazwa, int n, int M)
{


    ofstream zapis1(nazwa);
    int *Z= new int[n];

    for (int i=0; i<n; i++)
    {


        Z[i]=rand()%20000+1;
        zapis1<<Z[i]<<" ";
    }
    zapis1.close();
    delete [] Z;
}
//wprowadzanie liczb posortowanych rosn¹co
void WprowadzanieSort(const char*nazwa, int n, int M)
{


    ofstream zapis1(nazwa);
    int *Z= new int[n];

    for (int i=0; i<n; i++)
    {


        Z[i]=i;
        zapis1<<Z[i]<<" ";
    }
    zapis1.close();
    delete [] Z;
}


//posortowane malej¹co
void WprowadzanieWaski(const char*nazwa, int n, int M)
{
    int j=0;

    ofstream zapis1(nazwa);
    int *Z= new int[n];

    for (int i=0; i<n; i++)
    {


        Z[i]=20000-j;
        j++;
        zapis1<<Z[i]<<" ";
    }
    zapis1.close();
    delete [] Z;
}


//pdczytywanie licz z pliku txt

void Odczyt_txt(const char* nazwa,int &n,vector<int>&arr)
{

    ifstream zrodlo(nazwa);
    int liczba=0;

    while(zrodlo>>liczba)
        arr.push_back(liczba);

    n=arr.size();



}
//zapisywanie do pliku txt
void Zapisz(const char*nazwa, int arrSize, vector<int>arr)
{

    ofstream plik(nazwa);

    for(int i=0; i<arrSize; i++)
        plik<<arr[i]<<" ";




}
//sortowanie przez wstawianie
void InsertionSort(vector<int> &arr, int arrSize)
{
 //iteracja po wszystkich elementach tablicy
    for(int i=0; i<arrSize; i++)
    {
        //biezacy element tablicy- wartosc odniesienia
        int refValue=arr[i];

        //zmienna do przenoszenia elementow na wlasciwa pozycje
        int j;

        //iteracja po posortowanych elementach w celu umieszenia wartosci odniesiena
        // na wlasciwej pozycji
        for(j=i-1; j>=0; j--)
        {
            //jesli wartosc biezacego elementu tablicy jest wieksza od wartossci
            //odniesienia to przeniosi wartosc biezaca na prawa strone
            // w przeciwnym przypadku przerwanie petli
            if(arr[j]>refValue)
                arr[j+1]=arr[j];
            else
                break;
        }

        //umieszczenie wartosci odniesienia w biezacym indeksie, na wlasciwej pozycji
        arr[j+1]=refValue;


    }
}
//sortowanie kubelkowe
void bucketSort(vector<int> &arr, int n,int M)
{
    // tworzenie n pustych kubelkow
    vector<int> b[n];


    // umieszczanie elementów tablicy w odpowiednich kubelkach
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i]/M; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // sortowanie pojedynczych kubelkow z wykorzystaniem sortowania przez wstawianie
    for (int i = 0; i < n; i++)
        InsertionSort(b[i],b[i].size());


    // polaczenie wszystkich kubelkow w jedna tablice arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    //zakres liczb uwzgledniony w sortowaniu (od 0 do 20000)
    int M=20000;
    srand ( ( unsigned )time ( NULL ) );


    vector<int>arr;
    int n;

    //Testy

    //losowe liczby, przypadek sredni

    cout<<"losowe"<<endl;
    Wprowadzanie("Z10.txt",10,M);
    Odczyt_txt("Z10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("Z10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiZ10.txt",n,arr);

    arr.clear();

    cout<<endl<<endl;

    Wprowadzanie("Z100.txt",100,M);
    Odczyt_txt("Z100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("Z100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiZ100.txt",n,arr);

    arr.clear();

    cout<<endl<<endl;

    Wprowadzanie("Z1000.txt",1000,M);
    Odczyt_txt("Z1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("Z1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiZ1000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    Wprowadzanie("Z10000.txt",10000,M);
    Odczyt_txt("Z10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("Z10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiZ10000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    Wprowadzanie("Z20000.txt",20000,M);
    Odczyt_txt("Z20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("Z20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiZ20000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

//posortowane - najlepszy przypadek bucket sort i insertion sort

    cout<<"posortowane"<<endl;

    WprowadzanieSort("S10.txt",10,M);
    Odczyt_txt("S10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("S10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiS10.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieSort("S100.txt",100,M);
    Odczyt_txt("S100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("S100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiS100.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieSort("S1000.txt",1000,M);
    Odczyt_txt("S1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("S1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiS1000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieSort("S10000.txt",10000,M);
    Odczyt_txt("S10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("S10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiS10000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;


    WprowadzanieSort("S20000.txt",20000,M);
    Odczyt_txt("S20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("S20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiS20000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;



//najgorszy przypadek bucket sort, najogrszy przypadek insertion sort

    cout<<"waski przedial, posortowane malejaco:"<<endl;
    //sztucznie zawyzona liczba elemtnow zeby wszystkie trafily do jednego kubelka
     M=300000001;
    //liczby w waskim przedziale
    WprowadzanieWaski("W10.txt",10,M);
    Odczyt_txt("W10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("W10.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiW10.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieWaski("W100.txt",100,M);
    Odczyt_txt("W100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("W100.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("W100.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieWaski("W1000.txt",1000,M);
    Odczyt_txt("W1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("W1000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiW1000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;
    WprowadzanieWaski("W10000.txt",10000,M);
    Odczyt_txt("W10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("W10000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiW10000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;

    WprowadzanieWaski("W20000.txt",20000,M);
    Odczyt_txt("W20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    InsertionSort(arr,n);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    arr.clear();
    Odczyt_txt("W20000.txt",n,arr);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    bucketSort(arr,n,M);
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    Zapisz("WynikiW20000.txt",n,arr);

    arr.clear();
    cout<<endl<<endl;


    return 0;
}
