#include <iostream>
using namespace std;

class Sort
{
    private:
        int *arr;
        int size, i, j, temp;

    public:
        void input();
        void display();
        void BubbleSort();
        void InsertionSort();
        void SelectionSort();
        void QuickSort(int low, int high);
        int Partition(int low, int high);
        int getSize() const;
        void MergeSort(int low, int high);
        void merge(int low, int mid, int high);
        void HeapSort();
        void heapify(int n, int i);
};

/////////////////////////////////////////////////

void Sort ::input()
{
    cout<<"Enter size of array : ";
    cin>>size;

    cout<<endl<<"add numbers : \n";
    arr = new int [size];
    for(i=0; i<size; i++){
        cout<<"number["<<i<<"]: ";
        cin>>arr[i];
    }
}

/////////////////////////////////////////////////

void Sort ::BubbleSort()
{
    	for( i=0; i<size-1; i++)
		    for( j=0; j<size-1; j++)
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
}

/////////////////////////////////////////////////

void Sort ::InsertionSort()
{
        for (int i = 1; i < size; i++){
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

/////////////////////////////////////////////////

void Sort ::SelectionSort()
{
    int k;
    for(i=0; i<size; i++){
       temp = arr[i];
       k = i;
        for(j=i+1; j<size; j++){
            if(arr[j] < temp){
                temp = arr[j];
                k = j;
            }
        }
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

/////////////////////////////////////////////////

void Sort ::QuickSort(int low, int high)
{
    if(low < high){
        j = Partition (low, high );
        QuickSort(low, j-1);
        QuickSort(j+1, high);
    }
    
}

/////////////////////////////////////////////////

int Sort ::Partition(int low, int high)
{
    int pivot = arr[low];
    i = low + 1;
    j = high;

    while (i <= j)
    {
        while( i <= j && arr[i] <= pivot )
            i++;

        while( i <= j && arr[j] > pivot )
            j--;
        
        if( i < j )
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;

}

/////////////////////////////////////////////////

int Sort::getSize() const
{
    return size;
}

/////////////////////////////////////////////////

void Sort ::MergeSort(int low, int high)
{

    if(low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(low, mid);
        MergeSort( mid+1, high);
        merge(low, mid, high);
    }
}

/////////////////////////////////////////////////

void Sort ::merge(int low, int mid, int high)
{
    int k, *a;
    i = low;
    j = mid +1;
    k = 0;
    a = new int [high - low +1];

    while( i<= mid && j<=high ){
        if(arr[i] < arr [j])
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++];
    }
    
    while (i <= mid)
            a[k++] = arr[i++];
    while (j <= high)
            a[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
            arr[i] = a[k];

    delete[] a;
    
}

/////////////////////////////////////////////////

void Sort ::display()
{
    for(i=0; i<size; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;

}

/////////////////////////////////////////////////

void Sort ::HeapSort()
{
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);

    for (i = size - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(i, 0);
    }
}

/////////////////////////////////////////////////

void Sort ::heapify(int n, int i)
{
    int high = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[high])
        high = left;

    if (right < n && arr[right] > arr[high])
        high = right;

    if (high != i) {
        temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;

        heapify(n, high);
    }
}

/////////////////////////////////////////////////

int main(){

    int sel;
    Sort sort;
    sort.input();

    cout<<"1.Bubble Sort \n";
    cout<<"2.Insertion Sort \n";
    cout<<"3.Selection Sort \n";
    cout<<"4.Quick Sort \n";
    cout<<"5.Mesrg Sort \n";
    cout<<"6.Heap Sort \n";
    cout<<"Which one? ";
    cin>>sel;

   
    switch (sel)
    {
        case 1:
            sort.BubbleSort();
            break;

        case 2:
            sort.InsertionSort();
            break; 

        case 3:
            sort.SelectionSort();
            break;
        
        case 4:
            sort.QuickSort(0, sort.getSize() -1);
            break;

        case 5:
            sort.MergeSort(0, sort.getSize() -1);
            break;
        case 6:
            sort.HeapSort();
            break;
        
        default:
            cout<<"The entered number is not correct \n";
            break;
        }
        
        sort.display();

    }
    