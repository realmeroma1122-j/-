#include <iostream>
#include <fstream>

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
        if (size == capacity)
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
        if (index < 0 || index >= size)
        {
            std::cout << "Error\n";
            return -1;
        }
        return data[index];
    }

    void set(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error\n";
            return;
        }
        data[index] = value;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error\n";
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
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

    void save(const char* name)
    {
        std::ofstream file(name, std::ios::binary);

        file.write((char*)&size, sizeof(size));

        for (int i = 0; i < size; i++)
        {
            file.write((char*)&data[i], sizeof(int));
        }
    }

    void load(const char* name)
    {
        std::ifstream file(name, std::ios::binary);

        file.read((char*)&size, sizeof(size));

        delete[] data;
        data = new int[size];
        capacity = size;

        for (int i = 0; i < size; i++)
        {
            file.read((char*)&data[i], sizeof(int));
        }
    }
};

int main()
{
    ArrayList list;

    list.add(40);
    list.add(2);
    list.add(-4);

    list.print();

    list.save("array.bin");

    ArrayList list2;
    list2.load("array.bin");

    list2.print();
}
