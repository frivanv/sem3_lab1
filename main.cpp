#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "Sorts.h"
#include "Tests.h"

using namespace std;

void interface() {
    cout << "Choose type of sequence you want to work with:\n1. int\n2. double\n" << endl;
    int type = 0;

    do {
        cin >> type;
        cout << endl;
        if ((type != 1) && (type != 2)) {
            cout << ("You must choose 1 or 2") << endl;
        }
    } while ((type != 1) && (type != 2));

    int oper = 0;

    do {

        cout << "Please, choose the operation:\n"
                "1. Enter sequence and sort it;\n"
                "2. Create random sequence and sort it; (only for integer)\n"
                "3. Find out best sort for your sequence;\n"
                "4. Find out best sort for random sequence;\n"
                "5. Show tests;\n"
                "6. Exit\n" << endl;

        cout << "Your choice:\n";
        cin >> oper;
        cout << "\n" << endl;

        Sequence<int> *mas1 = nullptr;
        Sequence<double> *mas2 = nullptr;
        Sequence<int> *rand_mas = nullptr;

        switch (oper) {
            case 1:
                if (type == 1) {
                    mas1 = new ArraySequence<int>();
                    mas1->Enter();
                    cout << "Your sequence:\n";
                    mas1->Print();
                    cout << "\n" << endl;
                }

                if (type == 2) {
                    mas2 = new ArraySequence<double>();
                    mas2->Enter();
                    cout << "Your sequence:\n";
                    mas2->Print();
                    cout << "\n" << endl;
                }

                cout << "Please, choose type of the sort you want:\n"
                        "1. Bubble sort;\n"
                        "2. Merge sort;\n"
                        "3. Quick sort;\n" << endl;

                int sort_type;
                do {
                    cin >> sort_type;
                    if ((sort_type != 1) && (sort_type != 2) && (sort_type != 3)) {
                        cout << "Please, type '1', '2' or '3'\n" << endl;
                    }
                } while ((sort_type != 1) && (sort_type != 2) && (sort_type != 3));

                if (sort_type == 1) {
                    if (type == 1) bubbleSort(mas1);
                    if (type == 2) bubbleSort(mas2);
                } else if (sort_type == 2) {
                    if (type == 1) mergeSort(mas1, 0, mas1->GetLength() - 1);
                    if (type == 2) mergeSort(mas2, 0, mas2->GetLength() - 1);
                } else {
                    if (type == 1) quickSort(mas1, 0, mas1->GetLength() - 1);
                    if (type == 2) quickSort(mas2, 0, mas2->GetLength() - 1);
                }

                cout << "Result:" << endl;
                if (type == 1) mas1->Print();
                if (type == 2) mas2->Print();
                cout << endl;

                break;

            case 2:
                cout << "Please, enter size of the random sequence you want:\t";
                int rand_size;
                cin >> rand_size;
                cout << "\n" << endl;

                rand_mas = new ArraySequence<int>(rand_size);
                for (int i = 0; i < rand_size; i++) {
                    rand_mas->InsertAt(rand() % 100 + 1, i);
                }

                cout << "Your random sequence:\n";
                rand_mas->Print();
                cout << "\n" << endl;

                cout << "Please, choose type of the sort you want:\n"
                        "1. Bubble sort;\n"
                        "2. Merge sort;\n"
                        "3. Quick sort;\n" << endl;

                do {
                    cin >> sort_type;
                    if ((sort_type != 1) && (sort_type != 2) && (sort_type != 3)) {
                        cout << "Please, type '1', '2' or '3'\n" << endl;
                    }
                } while ((sort_type != 1) && (sort_type != 2) && (sort_type != 3));

                if (sort_type == 1) bubbleSort(rand_mas);
                if (sort_type == 2) mergeSort(rand_mas, 0, rand_mas->GetLength() - 1);
                if (sort_type == 3) quickSort(rand_mas, 0, rand_mas->GetLength() - 1);

                cout << "Result:" << endl;
                rand_mas->Print();
                cout << endl;

                break;

            case 3:
                if (type == 1) {
                    mas1 = new ArraySequence<int>();
                    mas1->Enter();
                    cout << "Your sequence:\n";
                    mas1->Print();
                    cout << "\n" << endl;
                }

                if (type == 2) {
                    mas2 = new ArraySequence<double>();
                    mas2->Enter();
                    cout << "Your sequence:\n";
                    mas2->Print();
                    cout << "\n" << endl;
                }

                cout << "Here is time for each sort for your sequence\n" << endl;
                if (type == 1) {
                    unsigned int start_time = clock();
                    bubbleSort(mas1);
                    unsigned int end_time = clock();
                    unsigned int search_time = end_time - start_time;
                    cout << "Time for Bubble sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    mergeSort(mas1, 0, mas1->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Merge sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    quickSort(mas1, 0, mas1->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Quick sort is " << search_time << " microseconds \n";

                    cout << endl;
                }
                if (type == 2) {
                    unsigned int start_time = clock();
                    bubbleSort(mas2);
                    unsigned int end_time = clock();
                    unsigned int search_time = end_time - start_time;
                    cout << "Time for Bubble sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    mergeSort(mas2, 0, mas2->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Merge sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    quickSort(mas2, 0, mas2->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Quick sort is " << search_time << " microseconds \n";

                    cout << endl;
                }

                break;

            case 4:
                cout << "Please, enter size of the random sequence you want:\t";
                cin >> rand_size;
                cout << "\n" << endl;

                rand_mas = new ArraySequence<int>(rand_size);
                for (int i = 0; i < rand_size; i++) {
                    rand_mas->InsertAt(rand() % 100 + 1, i);
                }

                cout << "Here is time for each sort for random sequence\n" << endl;
                if (type == 1 || type == 2) {
                    unsigned int start_time = clock();
                    bubbleSort(rand_mas);
                    unsigned int end_time = clock();
                    unsigned int search_time = end_time - start_time;
                    cout << "Time for Bubble sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    mergeSort(rand_mas, 0, rand_mas->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Merge sort is " << search_time << " microseconds \n";

                    start_time = clock();
                    quickSort(rand_mas, 0, rand_mas->GetLength() - 1);
                    end_time = clock();
                    search_time = end_time - start_time;
                    cout << "Time for Quick sort is " << search_time << " microseconds \n";

                    cout << endl;
                }

                break;

            case 5:
                Test_Linked_List_Sequence();
                Test_Array_Sequence();
                Test_Bubble_Sort();
                Test_Merge_Sort();
                Test_Quick_Sort();

                break;

            case 6:
                cout << "_-_-_-_Thank you ! Good bye !_-_-_-_\n" << endl;

                break;

            default:
                cout << "ERROR ! PLEASE, TRY AGAIN";

                break;
        }

    } while (oper != 6);
}

int main() {
    interface();
    return 0;
}
