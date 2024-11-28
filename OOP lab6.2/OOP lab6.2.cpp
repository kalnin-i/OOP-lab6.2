#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <Windows.h>

using namespace std;

template <typename T>
class Set
{
private:
    set<T> elements;

public:
    void add(const T& element)
    {
        elements.insert(element);
    }

    Set<T> unionWith(const Set<T>& other) const
    {
        Set<T> result;
        set_union(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set<T> intersectWith(const Set<T>& other) const
    {
        Set<T> result;
        set_intersection(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set<T> differenceWith(const Set<T>& other) const
    {
        Set<T> result;
        set_difference(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    bool operator==(const Set<T>& other) const
    {
        return elements == other.elements;
    }

    friend ostream& operator<<(ostream& os, const Set<T>& s)
    {
        os << "{ ";
        for (const auto& element : s.elements)
        {
            os << element << " ";
        }
        os << "}";
        return os;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choise;
    cout << "Для введення масиву трьох дійсних чисел натисніть 1, а для цілих - 2\n";
    cin >> choise;
    switch (choise)
    {
    case 1:
    {
        float a1, a2, a3, b1, b2, b3;

        cout << "Введіть першу множину: ";
        cin >> a1 >> a2 >> a3;
        cout << "Введіть другу множину: ";
        cin >> b1 >> b2 >> b3;

        Set<float> set1, set2;
        set1.add(a1);
        set1.add(a2);
        set1.add(a3);

        set2.add(b1);
        set2.add(b2);
        set2.add(b3);

        Set<float> unionSet = set1.unionWith(set2);
        Set<float> intersectSet = set1.intersectWith(set2);
        Set<float> differenceSet = set1.differenceWith(set2);

        cout << "Множина 1: " << set1 << endl;
        cout << "Множина 2: " << set2 << endl;
        cout << "Об'єднання: " << unionSet << endl;
        cout << "Перетин: " << intersectSet << endl;
        cout << "Різниця: " << differenceSet << endl;

        break;
    }
    case 2:
    {
        int a1, a2, a3, b1, b2, b3;

        cout << "Введіть першу множину: ";
        cin >> a1 >> a2 >> a3;
        cout << "Введіть другу множину: ";
        cin >> b1 >> b2 >> b3;

        Set<int> set1, set2;
        set1.add(a1);
        set1.add(a2);
        set1.add(a3);

        set2.add(b1);
        set2.add(b2);
        set2.add(b3);

        Set<int> unionSet = set1.unionWith(set2);
        Set<int> intersectSet = set1.intersectWith(set2);
        Set<int> differenceSet = set1.differenceWith(set2);

        cout << "Множина 1: " << set1 << endl;
        cout << "Множина 2: " << set2 << endl;
        cout << "Об'єднання: " << unionSet << endl;
        cout << "Перетин: " << intersectSet << endl;
        cout << "Різниця: " << differenceSet << endl;

        break;
    }

    default:
        cout << "Неправильний вибір!" << endl;
        return 1;
    }
    return 0;
}