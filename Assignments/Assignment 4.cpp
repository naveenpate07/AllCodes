#include <bits/stdc++.h>
using namespace std;

struct PatientNode{
    string name;
    int id;
    PatientNode* left;
    PatientNode* right;
    bool lthread;
    bool rthread;
    PatientNode(string names, int iid) : name(names), id(iid), left(NULL), right(NULL), lthread(true), rthread(true) {}
};

struct Department {
    int DepartmentId;
    string departmentName;
    Department* left;
    Department* right;
    Department* parent;
    PatientNode* PatientRoot;  
    Department(string name, int id) : departmentName(name), DepartmentId(id), left(NULL), right(NULL), parent(NULL), PatientRoot(NULL) {}
};

class Management {
private:
    Department* department;

public:
    Management() : department(NULL) {}
    Department* addDept(Department* root, string name, int id) {
        if (root == NULL) {
            return new Department(name, id);
        }
        if (id < root->DepartmentId) {
            root->left = addDept(root->left, name, id);
            root->left->parent = root;
        } else {
            root->right = addDept(root->right, name, id);
            root->right->parent = root;
        }
        return root;
    }

    Department* findDept(Department* root, int id) {
        if (root == NULL) return NULL;
        if (id < root->DepartmentId) {
            return findDept(root->left, id);
        } else if (id > root->DepartmentId) {
            return findDept(root->right, id);
        } else {
            return root;
        }
    }

    PatientNode* addPatientToDept(PatientNode* root, string name, int id) {
        if (root == NULL) {
            return new PatientNode(name, id);
        }

        PatientNode* parent = NULL;
        PatientNode* current = root;

        while (current != NULL) {
            parent = current;
            if (id < current->id) {
                if (current->lthread == false) {
                    current = current->left;
                } else {
                    break;
                }
            } else {
                if (current->rthread == false) {
                    current = current->right;
                } else {
                    break;
                }
            }
        }

        PatientNode* newNode = new PatientNode(name, id);
        if (id < parent->id) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->left = newNode;
            parent->lthread = false;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->right = newNode;
            parent->rthread = false;
        }
        return root;
    }

    PatientNode* delPatFromDep(PatientNode* root, int id) {
        if (root == NULL) return NULL;

        if (id < root->id) {
            if (root->lthread == false) {
                root->left = delPatFromDep(root->left, id);
            }
        } else if (id > root->id) {
            if (root->rthread == false) {
                root->right = delPatFromDep(root->right, id);
            }
        } else {
            if (root->lthread && root->rthread) {
                delete root;
                return NULL;
            } else if (root->lthread) {
                PatientNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->rthread) {
                PatientNode* temp = root->left;
                delete root;
                return temp;
            } else {
                PatientNode* successor = root->right;
                while (successor->lthread == false) {
                    successor = successor->left;
                }
                root->id = successor->id;
                root->name = successor->name;
                root->right = delPatFromDep(root->right, successor->id);
            }
        }
        return root;
    }

    void displayDepartments(Department* root) {
        if (root == NULL) return;
        displayDepartments(root->left);
        cout << "Department ID: " << root->DepartmentId << ", Name: " << root->departmentName << endl;
        displayDepartments(root->right);
    }

 
    void displayDepPat(PatientNode* root) {
        if (root == NULL) return;

        PatientNode* current = root;
        while (current->lthread == false) {
            current = current->left;
        }

        while (current != NULL) {
            cout << "  Patient id: " << current->id << " Name: " << current->name << endl;

            if (current->rthread) {
                current = current->right;
            } else {
                current = current->right;
                while (current != NULL && current->lthread == false) {
                    current = current->left;
                }
            }
        }
    }

   
    void addDepartment(string name, int id) {
        department = addDept(department, name, id);
    }



    void addDeptPatient(int id, string name, int pid) {
        Department* deptRoot = findDept(department, id);
        if (deptRoot == NULL) {
            cout << "Department Not Found!" << endl;
            return;
        }
        deptRoot->PatientRoot = addPatientToDept(deptRoot->PatientRoot, name, pid);
    }

    void delPatFromDep(int did, int pid) {
        Department* deptRoot = findDept(department, did);
        if (deptRoot == NULL) {
            cout << "Department Not Found!" << endl;
            return;
        }
        deptRoot->PatientRoot = delPatFromDep(deptRoot->PatientRoot, pid);
    }

    void displayDepartments() {
        displayDepartments(department);
    }

    void displayDepPat(int id) {
        Department* deptRoot = findDept(department, id);
        if (deptRoot == NULL) {
            cout << "Department Not Found!" << endl;
            return;
        }
        displayDepPat(deptRoot->PatientRoot);
    }
};

int main() {
    Management manage;

    while (true) {
        cout << "1. Add Departments \n2. Add Sub-Departments \n3. Add Patients \n4. Delete Patients \n5. Display Departments \n6. Display Patients in Departments \n0. Exit" << endl;
        int data;
        cin >> data;
        cin.ignore();  // To consume the newline character after input
        if (data == 1) {
            string name;
            int id;
            cout << "Enter the name of Department: ";
            getline(cin, name);
            cout << "Enter the Department ID for " << name << ": ";
            cin >> id;
            manage.addDepartment(name, id);
        } else if (data == 2) {
            int parentId;
            string name;
            int id;
            cout << "Enter the parent department ID: ";
            cin >> parentId;
            cin.ignore();  // Consume the newline
            cout << "Enter the name of the sub-department: ";
            getline(cin, name);
            cout << "Enter the sub-department ID for " << name << ": ";
            cin >> id;
            // manage.addSubDepartment(parentId, name, id);
        } else if (data == 3) {
            int did, pid;
            string name;
            cout << "Enter the department ID: ";
            cin >> did;
            cin.ignore();  // Consume the newline
            cout << "Enter the name of the patient: ";
            getline(cin, name);
            cout << "Enter the Patient ID: ";
            cin >> pid;
            manage.addDeptPatient(did, name, pid);
        } else if (data == 4) {
            int did, pid;
            cout << "Enter the department ID: ";
            cin >> did;
            cout << "Enter the Patient ID: ";
            cin >> pid;
            manage.delPatFromDep(did, pid);
        } else if (data == 5) {
            manage.displayDepartments();
        } else if (data == 6) {
            int id;
            cout << "Enter the department ID: ";
            cin >> id;
            manage.displayDepPat(id);
        } else if (data == 0) {
            break;
        }
    }
    return 0;
}