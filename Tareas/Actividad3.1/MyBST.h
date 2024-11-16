/* 
Implmentacion de un BST con operaciones avanzadas
En el siguiente codigo veremos las funciones que necesitamos y como es que 
estas funcionaran, ademas de como es que se implementaran los metodos de profundidad,
insertar y remover datos de un arbol.
Se utilio un video de youtube para poder lograr de manera correcta la funcion de remove,tambien
para comprender mejor el tema visto en clase y resolver algunas dudas
Referencia: Programación ATS. (2016, 21 diciembre). 120. Programación en C++ || Árboles || Eliminar un nodo del árbol - parte 2 [Vídeo]. YouTube. https://www.youtube.com/watch?v=u9c-4qlvt24
Referencia 2: Programación ATS. (2016b, diciembre 21). 120. Programación en C++ || Árboles || Eliminar un nodo del árbol - parte 2 [Vídeo]. YouTube. https://www.youtube.com/watch?v=u9c-4qlvt24 
Jesús Eduardo Escobar Meza A01743270
16/10/24
*/
#ifndef MYBST_H
#define MYBST_H
 

struct MyNodeBST{
    int data;
    MyNodeBST *left,
              *right,
              *padre;
        MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
        this->padre=padre;
    }
};
 
class MyBST{
    private:
        int size;
        MyNodeBST* root;
        bool search(int data,MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        //En caso de hacer alguno de los métodos recursivos y necesiten
        //otro método que haga la recursión deben de colocarlo como privado
        //sólo la función de preparación sería pública
        bool remove(MyNodeBST* current, int data);
        int height(MyNodeBST* current);
        void level(MyNodeBST* current, int nivel);
        MyNodeBST* minimo(MyNodeBST* current);
        void remplazo(MyNodeBST* current, MyNodeBST* nuevo); 
        //Tuve que agregar tres nuevas funciones para hacerlas de manera recusiva

    public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool insert(int data);//true si lo inserto o no
        bool remove(int data);//si el valor estaba en el árbol lo borra
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level
                                        //Imprime el recorrido separado por comas sin espacio entre los elementos.
        int height();//regresa la altura del BST.
        void ancestors(int data);//imprime los ancestros del valor pasado separados por comas y sin dejar espacios entre ellos.
                                 //el orden de impresión debe ser de la raíz hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(int data);//regresa el nivel en que se encuentra el valor
                                   //dentro del árbol. Si el valor no está en árbol regresa -1
};
#endif