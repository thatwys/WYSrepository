//常见的排序算法

//冒泡排序
void BubbleSort(int k[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (k[i] > k[j])
            {
                temp = k[j];
                k[j] = k[i];
                k[i] = temp;
            }
        }
    }
}

//选择排序
void SelectSort(int k[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] < k[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = k[min];
            k[min] = k[i];
            k[i] = temp;
        }
    }
}

//插入排序
void InsertSort(int k[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (k[i] < k[i - 1])
        {
            temp = k[i];
            for (j = i - 1; k[j] > temp; j--)
            {
                k[j + 1] = k[j];
            }
            k[i + 1] = temp;
        }
    }
}

//希尔排序
void ShellSort(int k[], int n)
{
    int i, j, temp;
    int gap = n;

    do
    {
        gap = gap / 8 + 1; //随便写的
        for (i = gap; i < n; i++)
        {
            if (k[i] < k[i - gap])
            {
                temp = k[i];
                for (j = i - gap; k[j] > temp; j -= gap)
                {
                    k[j + gap] = k[j];
                }
                k[i + gap] = temp;
            }
        }
    } while (gap > 1);
}

//堆排序
void swap(int k[], int i, int j)
{
    int temp;
    temp = k[i];
    k[i] = k[j];
    k[j] = temp;
}

void MaxHeapify(int k[], int s, int n)
{
    int i;

    int temp;
    temp = k[s]; //s是双亲

    for (i = 2 * s; i <= n; i *= 2)
    {
        if (i < n && k[i] < k[i + 1])
        {
            i++;
        }
        if (temp >= k[i])
        {
            break;
        }
        k[s] = k[i];
        s = i;
    }
    k[s] = temp;
}
void HeapSort(int k[], int n)
{
    int i;
    for (i = n / 2; i > 0; i--)
    {
        MaxHeapify(k, i, n);
    }
    for (i = n; i > 1; i--)
    {
        swap(k, 1, i);
        MaxHeapify(k, 1, i - 1);
    }
}

//快速排序
//Partition龙鸣版
int Partition(int k[], int low, int high)
{
    int flag;
    flag = k[low];
    while (low < high)
    {
        while (k[high] >= flag && low < high)
        {
            high--;
        }
        swap(k, low, high);
        while (k[low] <= flag && low < high)
        {
            low++;
        }
        swap(k, low, high);
    }
    return low;
}

//Partition升级版
int Partition(int k[], int low, int high)
{
    int flag = k[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (k[j] <= flag)
        {
            i++;
            swap(k, i, j);
        }
    }
    swap(k, i + 1, high);
    return i + 1;
}


void QSort(int k[], int low, int high)
{
    int flag;

    if (low < high)
    {
        flag = Partition(k, low, high);
        QSort(k, low, flag - 1);
        QSort(k, flag + 1, high);
    }
}
void QuickSort(int k[], int n)
{
    QSort(k, 0, n - 1);
}
