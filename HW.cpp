#include <iostream>
using namespace std;

template <typename T>
class Array {
    T* elements;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialCapacity = 10, int grow = 1) : size(0), capacity(initialCapacity), grow(grow) {
        elements = new T[capacity];
    }

    ~Array() {
        delete[] elements;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize) {
        if (newSize > capacity) {
            cout << "error";
        }
        size = newSize;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void RemoveAll() {
        delete[] elements;
        capacity = 0;
        size = 0;
        elements = new T[capacity];
    }

    void Add(const T& element) {
        if (size >= capacity) {
            cout << "error!";
        }
        elements[size++] = element;
    }

    void Append(const Array<T>& other) {
        int newSize = size + other.size;
        if (newSize > capacity) {
            cout << "error";
        }
        for (int i = 0; i < other.size; ++i) {
            elements[size++] = other.elements[i];
        }
    }

    Array<T>& operator=(const Array<T>& other)
    {
        if (this != &other) {
            delete[] elements;
            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            for (int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    T* GetData() const {
        return elements;
    }

    T& GetAt(int index) {
        return elements[index];
    }

    void SetAt(int index, const T& value) {
        if (index >= 0 && index < size) {
            elements[index] = value;
        }
    }

    void InsertAt(int index, const T& value) {
        if (index >= 0 && index <= size) {
            if (size >= capacity) {
                cout << "error";
            }
            for (int i = size; i > index; --i) {
                elements[i] = elements[i - 1];
            }
            elements[index] = value;
            size++;
        }
    }

    void RemoveAt(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            size--;
        }
    }

    T& operator[](int index) {
        return elements[index];
    }

    const T& operator[](int index) const {
        return elements[index];
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Array<int> arr(5, 5);
    arr.Add(65);
    arr.Add(12);
    arr.Add(6);
    cout << "Size: " << arr.GetSize() << endl;
    cout << "GetUpperBound: " << arr.GetUpperBound() << endl;
    cout << "IsEmpty: " << arr.IsEmpty() << endl;

    cout << "Elements: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAll();

    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    arr.SetSize(10);
    cout << "newGetSize : " << arr.GetSize() << endl;

    arr.SetAt(0, 100);

    cout << "элемент под индексом: " << arr.GetAt(0) << endl;

    arr.InsertAt(1, 200);
    cout << "Size #3: " << arr.GetSize() << endl;
    cout << "элемент за индексом 1: " << arr.GetAt(1) << endl;

    arr.RemoveAt(2);
    cout << "Size после RemoveAt(2): " << arr.GetSize() << endl;

    return 0;
}