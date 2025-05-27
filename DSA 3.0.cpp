#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
#define isvalid(min, max, num) ((num) >= (min) && (num) <= (max))
using namespace std;

struct student
{
    int roll_no;
    char name[50];
    float cgpa;
    char department[30];
    char gender[10];
    string contact_no;
    int semester;
    char email[50];

    void setter();
    void getter();

    // Binary search tree pointers
    student* left;
    student* right;

    // Doubly linked list pointers
    student* prev;
    student* next;
};

class bst
{
    student* first = NULL;
    student* last = NULL;
    student* curr = NULL;
    student* root = NULL;

    student* stfirst = NULL;
    student* sttop = NULL;

public:

    // Core system functions
    void addStudent();
    void deleteStudent();
    void updateStudent();

    student* searchStudent(int roll_no);
    void searchBYCgpa(); // Future feature

    void displayAll();
    void sortByCgpa();
    void sreachByCgpa();
    void sortByRollNo();
    void sortInorder(student* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        sortInorder(temp->left);
        temp->getter();
        sortInorder(temp->right);
    }

    // Stack-related functions for undo feature
    void push(student* data);
    student* pop();
    void undo();

    // File handling functions
    void save_to_file();
    void readfile();
    void clearfile();
};


int main()
{
    bst studentList;
    int choice;

    do
    {
        system("cls");
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Sort Students\n";
        cout << "6. Display All Students\n";
        cout << "7. Undo Last Operation\n";
        cout<<  "8. clear file \n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentList.addStudent();
            break;
        case 2:
            studentList.deleteStudent();
            break;
        case 3:
            studentList.updateStudent();
            break;

        case 4: // SEARCH SUBMENU
        {
            int sch;
            do {

                cout << "\n--- Search Menu ---\n";
                cout << "1. Search by Roll Number\n";
                cout << "2. Search by CGPA\n";
                cout << "3. Return to Main Menu\n";
                cout << "Enter choice: ";
                cin >> sch;
                switch (sch)
                {
                case 1:
                    int rno;
                    cout<<"enter roll no to search \n";
                    cin>>rno;
                    studentList.searchStudent(rno);
                    getch();
                    break;
                case 2:
                    studentList.sreachByCgpa();  // Keep as-is unless you rename it
                    getch();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice!\n";
                    getch();
                }
            } while (sch != 3);
            break;
        }

        case 5: // SORT SUBMENU
        {
            int srt;
            do {
                system("cls");
                cout << "\n--- Sort Menu ---\n";
                cout << "1. Sort by Roll Number (Inorder BST)\n";
                cout << "2. Sort by CGPA\n";
                cout << "3. Return to Main Menu\n";
                cout << "Enter choice: ";
                cin >> srt;
                switch (srt)
                {
                case 1:
                    cout << "\n--- Sorted by Roll Number ---\n";
                    studentList.sortByRollNo();
                    getch();
                    break;
                case 2:
                    studentList.sortByCgpa();
                    getch();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice!\n";
                    getch();
                }
            } while (srt != 3);
            break;
        }

        case 6:
            studentList.displayAll();
            getch();
            break;

        case 7:
            studentList.undo();
            getch();
            break;
        case 8:
            studentList.clearfile();
            getch();
            break;

        case 9:
            cout << "Exiting the system...\n";
            exit(-1);

        default:
            cout << "Invalid choice! Try again.\n";
            getch();
        }

    } while (true);

    return 0;
}


// STUDENT SETTER FUNCTION
void student::setter()
{
    for (int i = 5; i > 0; i--)
    {
        cout << "Enter Roll Number: ";
        cin >> roll_no;
        cin.ignore();

        if (isvalid(0, 9999, roll_no))
        {
            break;
        }
        else
        {
            cout << "Incorrect roll number. You have " << i - 1 << " attempts remaining! ";
        }
    }

    cout << "Enter Name: ";
    cin.getline(name, 50);

    for (int i = 5; i > 0; i--)
    {
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();

        if (isvalid(0.0, 4.0, cgpa))
        {
            break;
        }
        else
        {
            cout << "Incorrect CGPA. You have " << i - 1 << " attempts remaining! ";
        }
    }

    cout << "Enter Department: ";
    cin.getline(department, 30);

    for (int i = 5; i > 0; i--)
    {
        cout << "Enter Gender (male/female): ";
        cin.getline(gender, 10);

        if (strcmp(gender, "male") == 0 || strcmp(gender, "MALE") == 0 ||
            strcmp(gender, "female") == 0 || strcmp(gender, "FEMALE") == 0)
        {
            break;
        }
        else
        {
            cout << "Incorrect gender. You have " << i - 1 << " attempts remaining! ";
        }
    }

    cout << "Enter Contact Number: ";
    getline(cin, contact_no);

    for (int i = 5; i > 0; i--)
    {
        cout << "Enter Semester: ";
        cin >> semester;

        if (isvalid(1, 8, semester))
        {
            break;
        }
        else
        {
            cout << "Incorrect semester. You have " << i - 1 << " attempts remaining! ";
        }
    }

    cin.ignore();
    cout << "Enter Email: ";
    cin.getline(email, 50);
}


// STUDENT GETTER FUNCTION
void student::getter()
{
    cout << "\n--- Student Details ---\n";
    cout << "Roll Number: " << roll_no << endl;
    cout << "Name: " << name << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Department: " << department << endl;
    cout << "Gender: " << gender << endl;
    cout << "Contact No: " << contact_no << endl;
    cout << "Semester: " << semester << endl;
    cout << "Email: " << email << endl;
}


// ADD STUDENT FUNCTION
void bst::addStudent()
{
    student* newStudent = new student();
    newStudent->setter();
    newStudent->left = NULL;
    newStudent->right = NULL;

    // BST insert
    if (root == NULL)
    {
        root = newStudent;
    }
    else
    {
        student* temp = root;
        student* parent = NULL;

        while (temp != NULL)
        {
            parent = temp;

            if (newStudent->roll_no < temp->roll_no)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (newStudent->roll_no < parent->roll_no)
        {
            parent->left = newStudent;
        }
        else
        {
            parent->right = newStudent;
        }
    }

    // DLL insert
    if (first == NULL)
    {
        first = newStudent;
        last = newStudent;
        newStudent->prev = NULL;
        newStudent->next = NULL;
    }
    else
    {
        last->next = newStudent;
        newStudent->prev = last;
        newStudent->next = NULL;
        last = newStudent;
    }

    push(newStudent);
    save_to_file();
}


// SEARCH STUDENT FUNCTION
//with cgpa
void bst::sreachByCgpa()
{
    if (first == NULL)
    {
        cout << "No student records available.\n";
        return;
    }

    float targetCgpa;
    cout << "Enter CGPA to search: ";
    cin >> targetCgpa;

    bool found = false;
    student* temp = first;

    while (temp != NULL)
    {
        if (temp->cgpa == targetCgpa)
        {
            temp->getter();
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "No student found with CGPA " << targetCgpa << ".\n";
    }
}




//with tree and roll no
student* bst::searchStudent(int rno)
{
    student* temp = root;

    while (temp != NULL)
    {
        if (temp->roll_no == rno)
        {
            temp->getter();
            return temp;
        }
        else if (rno < temp->roll_no)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    cout << "Student not found.\n";
    return NULL;
}


// DELETE STUDENT FUNCTION
void bst::deleteStudent()
{
    int r;
    cout << "Enter roll number to delete: ";
    cin >> r;

    student* pre_temp = NULL;
    student* temp = root;

    while (temp != NULL && temp->roll_no != r)
    {
        pre_temp = temp;

        if (r < temp->roll_no)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    push(temp);

    // DLL removal
    if (temp == first && temp == last)
    {
        first = NULL;
        last = NULL;
    }
    else if (temp == first)
    {
        first = first->next;
        if (first != NULL)
        {
            first->prev = NULL;
        }
    }
    else if (temp == last)
    {
        last = last->prev;
        if (last != NULL)
        {
            last->next = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    // BST delete logic (0, 1, or 2 children)
    if (temp->left == NULL && temp->right == NULL)
    {
        if (pre_temp == NULL)
        {
            root = NULL;
        }
        else
        {
            if (pre_temp->left == temp)
            {
                pre_temp->left = NULL;
            }
            else
            {
                pre_temp->right = NULL;
            }
        }
    }
    else if (temp->left == NULL || temp->right == NULL)
    {
        student* child;

        if (temp->left != NULL)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }

        if (pre_temp == NULL)
        {
            root = child;
        }
        else if (pre_temp->left == temp)
        {
            pre_temp->left = child;
        }
        else
        {
            pre_temp->right = child;
        }
    }
    else
    {
        student* successor = temp->right;
        student* pre_successor = temp;

        while (successor->left != NULL)
        {
            pre_successor = successor;
            successor = successor->left;
        }

        temp->roll_no = successor->roll_no;
        strcpy(temp->name, successor->name);
        temp->cgpa = successor->cgpa;
        strcpy(temp->department, successor->department);
        strcpy(temp->gender, successor->gender);
        temp->contact_no = successor->contact_no;
        temp->semester = successor->semester;
        strcpy(temp->email, successor->email);

        if (pre_successor->left == successor)
        {
            pre_successor->left = successor->right;
        }
        else
        {
            pre_successor->right = successor->right;
        }
    }

    cout << "Student deleted successfully.\n";
    save_to_file();
}


// UPDATE FUNCTION
void bst::updateStudent()
{
    int r;
    cout << "Enter the roll number to update: ";
    cin >> r;

    student* update = searchStudent(r);

    if (update == NULL)
    {
        cout << "Student not found, update failed.\n";
        return;
    }

    cout << "Enter new details:\n";
    update->setter();

    push(update);
    save_to_file();

    cout << "Student information updated successfully.\n";
}


// DISPLAY ALL FUNCTION
void bst::displayAll()
{
    readfile();
}


// SORT FUNCTION

//sort by cgpa
void bst::sortByCgpa()
{
    if (first == NULL || first->next == NULL)
    {
        cout << "Not enough students to sort.\n";
        return;
    }

    student* current;
    student* nextStudent;

    // Outer loop to control passes
    for (current = first; current != NULL; current = current->next)
    {
        // Inner loop to compare and swap
        nextStudent = current->next;
        while (nextStudent != NULL)
        {
            if (current->cgpa > nextStudent->cgpa)
            {
                // Swap all student data
                swap(current->roll_no, nextStudent->roll_no);
                swap(current->name, nextStudent->name);
                swap(current->cgpa, nextStudent->cgpa);
                swap(current->department, nextStudent->department);
                swap(current->gender, nextStudent->gender);
                swap(current->contact_no, nextStudent->contact_no);
                swap(current->semester, nextStudent->semester);
                swap(current->email, nextStudent->email);
            }
            nextStudent = nextStudent->next;
        }
    }

    cout << "\nStudents sorted by CGPA (Ascending Order):\n";
    current = first;
    while (current != NULL)
    {
        current->getter();
        current = current->next;
    }
}
//sort by roll no
void bst::sortByRollNo()
{
    if (root == NULL)
    {
        cout << "No student records to display.\n";
    }
    else
    {
        cout << "\n--- Students Sorted By Roll Number ---\n";
        sortInorder(root);
    }
}


// UNDO STACK FUNCTIONS
void bst::push(student* data)
{
    curr = new student(*data);

    if (stfirst == NULL)
    {
        stfirst = curr;
        sttop = curr;
        curr->prev = NULL;
        curr->next = NULL;
    }
    else
    {
        sttop->next = curr;
        curr->prev = sttop;
        curr->next = NULL;
        sttop = curr;
    }
}

student* bst::pop()
{
    if (sttop == NULL)
    {
        cout << "Nothing to undo.\n";
        return NULL;
    }

    student* temp = sttop;

    if (sttop == stfirst)
    {
        stfirst = NULL;
        sttop = NULL;
    }
    else
    {
        sttop = sttop->prev;
        sttop->next = NULL;
    }

    return temp;
}


void bst::undo()
{
    student* undovalue = pop();

    if (undovalue == NULL)
    {
        return;
    }

    // Reinsert into BST
    student* temp = root;
    student* parent = NULL;

    while (temp != NULL)
    {
        parent = temp;

        if (undovalue->roll_no < temp->roll_no)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (parent == NULL)
    {
        root = undovalue;
    }
    else if (undovalue->roll_no < parent->roll_no)
    {
        parent->left = undovalue;
    }
    else
    {
        parent->right = undovalue;
    }

    // DLL restore
    if (first == NULL)
    {
        first = undovalue;
        last = undovalue;
        undovalue->prev = NULL;
        undovalue->next = NULL;
    }
    else
    {
        last->next = undovalue;
        undovalue->prev = last;
        undovalue->next = NULL;
        last = undovalue;
    }

    undovalue->getter();
    cout << "Undo successful.\n";
    save_to_file();
}


// FILE HANDLING
void bst::save_to_file()
{
    ofstream outfile("infile.txt", ios::out);

    if (!outfile)
    {
        cout << "Error opening file.\n";
        return;
    }

    student* temp = first;

    while (temp != NULL)
    {
        outfile << "Student Name: " << temp->name << endl;
        outfile << "Roll No: " << temp->roll_no << endl;
        outfile << "CGPA: " << temp->cgpa << endl;
        outfile << "Department: " << temp->department << endl;
        outfile << "Gender: " << temp->gender << endl;
        outfile << "Contact No: " << temp->contact_no << endl;
        outfile << "Semester: " << temp->semester << endl;
        outfile << "Email: " << temp->email << endl;
        outfile << "--------\n";

        temp = temp->next;
    }

    outfile.close();
    cout << "Profile saved to file.\n";
}


void bst::readfile()
{
    ifstream infile("infile.txt", ios::in);

    if (!infile)
    {
        cout << "Error opening file.\n";
        return;
    }

    string line;

    cout << "\n***** User Profiles *****\n";

    while (getline(infile, line))
    {
        cout << line << endl;
    }

    infile.close();
}

void bst::clearfile()
{
     ofstream fout("infile.txt", ios::trunc);
    if (fout.is_open())
    {
        cout << "Student data file cleared successfully!\n";
        fout.close();
    }
    else
    {
        cout << "Error: Unable to clear the file.\n";
    }
}
