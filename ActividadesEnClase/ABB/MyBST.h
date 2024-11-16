#ifndef MYBST_H
#define MYBST_H

struct MyNodeBST {
    int data;
    MyNodeBST *left,
              *right,
              *padre;

    MyNodeBST(int data){
        this->data = data;
        this->left = this->right = nullptr;
        this->padre = padre;
    }

    MyNodeBST(int data):MyNodeBST(data, nullptr, nullptr, nullptr){}
};

class MyBST {
    //Las cosas que pongamos en el privado se deberna hacer publicos al momento de hacer la entrega
    private:
        int size;
        MyNodeBST *root; //raiz del arbol(padre de todos)
        bool remove(MyNodeBST* current, int data);
        MyNodeBST* minimo(MyNodeBST* current);
        void remplazo(MyNodeBST* current, MyNodeBST* nuevo);
        void merge(int* array, int ini, int fin);
        void mezcla(int* array, int ini, int mid, int fin);
        void swap(int* array, int i, int j); 
        void getNodeAt(int pos);

        //Funciones que estaban en la tarea pero no en la aplicacion original del archivo
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        bool searchRec(int data, MyNodeBST *current);
        int height(MyNodeBST* current);
        void level(MyNodeBST* current, int nivel);
        int length();
    public:
        MyBTS();
        ~MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool searchRec(int data);
        bool insert(int data);
        bool remove(int data);
        void mergeSort();
        
        //Funciones que no esteban en la el programa original
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);
        int height();//regresa la altura del BST.
        void ancestors(int data);
        int whatLevelAmI(int data);

        //Funciones auxiliares
        void treeToArray(MyNodeBST* node, int* array, int &index); 
        MyNodeBST* arrayToTree(int* array, int start, int end);
};

#endif