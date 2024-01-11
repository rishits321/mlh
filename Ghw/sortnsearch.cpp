//Rishikesh Suryavanshi
//Various Sorting and searching functions


//A student database. Database contains different fields of every student like Roll No, Name and GPA.

#include <iostream>
#include <string.h>
using namespace std;

typedef struct student
{
    int roll_num;
    char name [100];
    float marks;
}stud;

void create(stud s[100],int n);
void display(stud s[100],int n);
void bubble_sort(stud s[100],int n);
void insertionSort(stud s[100],int n);
void quick_sort(stud s[100],int,int);
int partition(stud s[100],int,int);
void search(stud s[100],int n,double key);
int bsearch(stud s[100], char x[20],int low,int high);


int main()
{
    stud s[100];
    int ch,n,key,result;
    char x[100];
    do
    {
        cout<<"\n1] Create Student Database(Max 100)";
        cout<<"\n2] Display Student Records";
        cout<<"\n3] Bubble Sort (To sort Roll No wise)";
        cout<<"\n4] Insertion Sort (To sort according to the Name)";
        cout<<"\n5] Quick Sort (To sort according to the marks)";
        cout<<"\n6] Linear search";
        cout<<"\n7] Binary search";
        cout<<"\n8] Exit ";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n Enter The Number Of Records:";
            cin>>n;
            create(s,n);
            break;

        case 2:
            display(s,n);
            break;
        case 3:
            bubble_sort(s,n);
            cout<<"\n Bubble sort Successful, print 2 to display.\n";
            break;
        case 4:
            insertionSort(s,n);
            cout<<"\n Inserion sort Successful, print 2 to display.\n";
            break;
        case 5:
            quick_sort(s,0,n-1);
            cout<<"\n Quick sort Successful, print 2 to display.\n";
            break;
        case 6:
            cout<<"\n Enter the marks which you want to search: ";
            cin>>key;
            search(s,n,key);
            break;
        case 7:
            cout<<"\n Enter the name of student which you want to search(case sensitive): ";
            cin>>x;
            insertionSort(s,n);
            result=bsearch(s,x,0,(n-1));
            if(result==-1)
            {
                cout<<" \n Student name you want to search is not present ! \n";
            }
            else
            {
                cout<<" \n The student is present :\t" << s[result].name<<" with marks: " << s[result].marks <<" and Roll Number: " << s[result].roll_num<< ".";
            }
            break;
        case 8:return 0;

        default:cout<<"\n Invalid choice !!"<<endl;
        }
    }while(ch!=8);
}

void create(stud s[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter student "<< (i + 1) <<" Roll Number: ";
        cin>>s[i].roll_num;
        cout<<" Enter student "<< (i + 1) <<" Name: ";
        cin>>s[i].name;
        cout<<" Enter student "<< (i + 1) <<" Marks: ";
        cin>>s[i].marks;
    }
    cout<<"\nCreated Successfully.";
}

void display(stud s[100],int n)
{
    int i;
    cout<<"\n"<< "\t\t"<< "Roll No"<< "\t\t"<<" Name" <<"\t\t"<< "Marks";
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        cout<<"\t\t "<< s[i].roll_num<<"\t\t "<<s[i].name<<"\t\t "<<s[i].marks;
    }
}

//bubble sort to sort in ascending order
void bubble_sort(stud s[100],int n)
{
    int i,j;
    stud temp;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(s[j].roll_num>s[j+1].roll_num)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }

    }
}

// insertion sort in ascending order
void insertionSort(stud s[100], int n)
{
    int i, j;
    stud key;
    for (i = 1; i < n; i++)
    {
        key= s[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && strcmp(s[j].name, key.name) >0)
        {
            s[j + 1]= s[j];
            j = j - 1;
        }
        s[j + 1]= key;
    }
}

//Quick sort
void quick_sort(stud s[100], int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(s,l,u);
        quick_sort(s,l,j-1);
        quick_sort(s,j+1,u);
    }
}

int partition(stud s[100], int l,int u)
{
    int i,j;

    stud temp, v;

    v=s[l];
    i=l;

    j=u+1;
    do
    {
        do
        {
            i++;
        }while(s[i].marks<v.marks&&i<=u);

        do
        {
            j--;
        }while(v.marks<s[j].marks);
        if(i<j)
        {
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }while(i<j);
    s[l]=s[j];
    s[j]=v;
    return(j);
}

// linear search for marks
void search(stud s[100],int n,double key)
{
    int i;
    cout<<"\n"<< "\t\t"<< "Roll No"<< "\t\t"<<" Name" <<"\t\t"<< "Marks";
    for(i=0;i<n;i++)
    {
        if(key==s[i].marks)
        {
            cout<<"\n\t\t "<< s[i].roll_num<<"\t\t "<<s[i].name<<"\t\t"<<s[i].marks;
        }
    }
}

//binary search for name
int bsearch(stud s[100], char x[100],int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(x,s[mid].name)==0)
        {
            return mid;
        }
        else if(strcmp(x,s[mid].name)<0)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}