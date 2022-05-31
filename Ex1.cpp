#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Array
{
public:
    Array() : array_length(0), array_data(nullptr) {}

    void push_back(int value)
    {
        int* data = new int[array_length + 1];

        for (int back = 0; back < array_length; ++back)
            data[back] = array_data[back];

        data[array_length] = value;
        delete[] array_data;
        array_data = data;
        ++array_length;
    }

    void pop_back()
    {
        if (array_data)
        {
            array_length--;

            int* data = new int[array_length];

            for (int back = 0; back < array_length; ++back)
                data[back] = array_data[back];

            delete[] array_data;
            array_data = data;
        }
    }

    void front_back()
    {
        if (array_data)
        {
            int* data = new int[array_length];
            for (int back = 0; back < array_length; ++back)
                data[back] = array_data[back + 1];

            delete[] array_data;
            array_data = data;
            array_length--;
        }
    }

    void sort()
    {
        if (array_data)
        {
            int temp = 0;
            for (int i = 0; i < array_length; i++)
                for (int j = array_length - 1; j >= 0; j--)
                {
                    if (array_data[j] < array_data[j - 1])
                    {
                        temp = array_data[j];
                        array_data[j] = array_data[j - 1];
                        array_data[j - 1] = temp;
                    }
                }
        }
    }

    friend ostream& operator<<(ostream& stre, Array& arr)
    {
        for(int i = 0; i < arr.array_length; i++)
            stre << arr.array_data[i];
        return stre;
    }
    ~Array()
    {
        delete[] array_data;
    }
private:
    int array_length;
    int* array_data;
};

int main()
{
    setlocale(LC_ALL, "rus");
    Array a;
    a.push_back(1);  
    a.push_back(0);
    a.push_back(10);
    a.push_back(8);
    a.push_back(7);
    a.sort();
    a.front_back();
    a.pop_back();
    cout << a;
    ex2();
}
