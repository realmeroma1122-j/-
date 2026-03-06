#include <iostream>
class ArrayList
{
public:
    int* data;
    int size;
    int capacity;
    ArrayList()
    {
        capacity = 3;
        size = 0;
        data = new int[capacity];
    }
    ~ArrayList()
    {
        delete[] data;
    }
    void add(int value)
    {
        if(size == capacity)
        {
            capacity *= 2;
            int* newdata = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
        }

        data[size] = value;
        size++;

    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void clear()
    {
        size = 0;
    }
    int contains(int value)
    {
        int t = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value) t += 1;
        }
        if (t > 0) return 1;
        else return 0;
    }
    void insert(int index, int value)
    {
        if (size <= index || index < 0) std::cout << "Error" << std::endl;
        if(size == capacity)
        {
            capacity *= 2;
            int* newdata = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
        }
        for (int i = size; i > index; i--)
        {
            data[i] = data[i-1];
        }
        data[index] = value;
        size++;
    }
};
int main()
{
    ArrayList list;
    list.add(40);
    list.add(2);
    list.add(-4);
    list.print();
    list.insert(2,50);
    list.print();
    std::cout << list.contains(-4) <<std::endl;
}
