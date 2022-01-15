class Solution{
public:	
    
    int partition(char a[], int low, int high)
    {
        int pivot= high;
        int i= low-1;
        
        for(int j=low; j<=high; j++)
        {
            if(a[j]<a[pivot])
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        i++;
        swap(a[i], a[pivot]);
        
        return i;
    }
    
    void quicksort( char a[], int low, int high)
    {
        if(low<high)
        {
            int pivot= partition(a,low,high);
            quicksort(a, low, pivot-1);
            quicksort(a, pivot+1, high);
        }
    }

	void matchPairs(char nuts[], char bolts[], int n) {
        	int low=0, high=n-1;
	quicksort(nuts, low, high);
	quicksort(bolts, low, high);
	    
	}

};