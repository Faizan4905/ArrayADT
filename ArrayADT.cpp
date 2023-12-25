#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout<<"The elements are: "<<endl;
    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }

}

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
    {
        for(int i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }

}

int Delete(struct Array *arr,int index)
{
    int x=0;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length;i++)
        {
            arr->A[i]=arr->A[i++];
        }
        arr->length--;
        return x;

    }
    return 0;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    
}

int LinearSearch(struct Array *arr,int key)
{
    int i=0;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            swap(&arr->A[i],&arr->A[key]);
            return i;
        } 
       
    }
    return -1;
}

int BinarySearch(struct Array *arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr->length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr->A[mid]) return mid;
        else if(key<arr->A[mid]) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    }
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }

    }

    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min) 
        {
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum=sum+arr.A[i];
    }
    return sum;
}

float Average(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0 ;i>=0;i--,j++)
    {
        B[j]=arr->A[i];
    }

    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=B[i];
    }
    
}

void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size) return ;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
}

int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }

}

struct Array * Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else
        {
            arr3->A[k++]=arr2->A[j++];

        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i++];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j++];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}

struct Array * Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *) malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            arr1->A[k++]=arr2->A[j++];
        }
        else 
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
        for(;i<arr1->length;i++)
        
            arr3->A[k++]=arr1->A[i++];
        
        for(;j<arr2->length;j++)
        
            arr3->A[k++]=arr2->A[j++];
        return arr3;
        
}

struct Array *Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        }

        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

struct Array * Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]) 
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr2->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}


int main()
{
    int x,index;
    int ch;
     struct Array arr1, arr2, *arr3;
   printf("Enter the size of Array 1: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    printf("Enter the length of Array 1: ");
    scanf("%d", &arr1.length);
    printf("Enter elements of Array 1: ");
    for (int i = 0; i < arr1.length; i++)
        scanf("%d", &arr1.A[i]);

    printf("Enter the size of Array 2: ");
    scanf("%d", &arr2.size);
    arr2.A = (int *)malloc(arr2.size * sizeof(int));
    printf("Enter the length of Array 2: ");
    scanf("%d", &arr2.length);
    printf("Enter elements of Array 2: ");
    for (int i = 0; i < arr2.length; i++)
        scanf("%d", &arr2.A[i]);
    do
    {  
        cout<<"\n\nMENU"<<endl<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.LINEAR Search"<<endl;
        cout<<"4.BINARY Search"<<endl;
        cout<<"5.Sum"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Max"<<endl;
        cout<<"8.Min"<<endl;
        cout<<"9.Reverse an Array "<<endl;
        cout<<"10. Is Array is Sorted?"<<endl;
        cout<<"11.Average of Array"<<endl;
        cout<<"12.Insert in Sorted"<<endl;
        cout<<"13.Merge Two Sorted Arrays"<<endl;
        cout<<"14.UNION of two sets"<<endl;
        cout<<"15.INTERSECTION of two sets"<<endl;
        cout<<"16.DIFFERENCE of two sets "<<endl;
        cout<<"17.Exit"<<endl;
        cout<<endl;
        cout<<"Enter your CHOICE : ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter an element: ";
            cin>>x;
            cout<<endl;
            cout<<"Enter an Index: ";
            cin>>index;
            Insert(&arr1,index,x);
            break;

        case 2:
            cout<<"Enter Index: ";
            cin>>index;
            Delete(&arr1,index);
            break;
        
        case 3:
            cout<<"Enter a key for Linear Search: ";
            cin>>index;
            LinearSearch(&arr1,index);
            break;
        
        case 4:
            cout<<"Enter a ke for Binary Search: ";
            cin>>index;
            BinarySearch(&arr1,index);
            break;
        
        case 5:
            cout<<"Sum is  : "<<Sum(arr1);
            break;

        case 6:
            Display(arr1);
            break;

        case 7:
            cout<<" The maximum Elements in an Array is "<<Max(arr1)<<endl;
            break;
        
        case 8:
            cout<<"The minimum elements in an Array is "<<Min(arr1)<<endl;
            break;

        case 9:
            Reverse(&arr1);
            Display(arr1);
            break;
        case 10:
            if(isSorted(arr1)) cout<<" Array is Sorted "<<endl;
            else  cout<<"Array is Not Sorted "<<endl;
            break;
        
        case 11:
            cout<<"Average of an Array is "<<Average(arr1)<<endl;
            break;
        
        case 12:
            cout<<"Enter an element you wanna insert: ";
            cin>>x;
            InsertSort(&arr1,x);
            Display(arr1);
            break;
        
        case 13:
            arr3 = Merge(&arr1, &arr2);
            printf("Merged  Arrays: ");
            for (int i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            printf("\n");
            break;
        
        case 14:
            arr3 = Union(&arr1, &arr2);
            printf("UNION is : ");
            for (int i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            printf("\n");
            break;

        case 15:
            arr3 = Intersection(&arr1, &arr2);
            printf("Intersection is : ");
            for (int i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            printf("\n");
            break;

        case 16:
            arr3 = Difference(&arr1, &arr2);
            printf("Difference of Set is : ");
            for (int i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            printf("\n");
            break;

        }

    } while (ch<17);

  

    
}

