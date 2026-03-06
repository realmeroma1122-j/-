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
    int get(int index)
    {
        if (size <= index || index < 0) return -1   ;
        else
        {
            return data[index];
        }

    }
    void set(int index, int value)
    {
        if (size <= index || index < 0) std::cout << "Error" << std::endl;
        else data[index] = value;
    }
    void remove(int index)
    {
        if (size <= index || index < 0) std::cout << "Error" << std::endl;
        else
        {
            for (int i = index; i < size - 1; i++)
            {
                data[i] = data[i+1];
            }
            size--;
        }

    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    ArrayList list;
    list.add(40);
    list.add(2);
    list.add(-4);
    list.print();
    std::cout << list.get(0) << std::endl;
    list.set(1,7);
    list.print();
    list.remove(1);
    list.print();
    std::cout << list.getSize() << std::endl;
}
