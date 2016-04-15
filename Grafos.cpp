#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int origem, destino, vertice, inicio, linha, mArestas, nVertice;
        int matrix[0][0], **matriz, **matrizA, **matrizD;

    public:
        //Construtor
        Grafos(){
        	//void grafo(int nVertice);
        	void adicionarVertice(int nVertice);
        	void adicionarAresta(int origem, int destino);
            void matrizAdjacencia(int linha);
        };

        Grafos(int origem, int destino, int nVertice){
        	this->origem = origem;
        	this->destino = destino;   	
        	this->vertice = vertice;
            linha = 0;
            this->mArestas = mArestas;
            this->nVertice = nVertice;
        };

        /*-------------------FUNÇÃO PARA SABER A QUANTIDADE DE LINHAS-------------*/
        int quantidade(){
            ifstream txtFile;
            char elemento;
            txtFile.open("matriz.txt");

            while (txtFile.get(elemento)){
                if(elemento == ']')
                    linha++;  
            };
            txtFile.close();
            return linha;
        };

        /*------------FUNÇÃO ALOCAR O ELEMENTOS DO ARQUIVO EM UMA MATRIZ-------------*/
        int arquivos() {
            quantidade();
            int matrix[linha][linha];
            ifstream myfile;
            myfile.open("matriz.txt");
            int l = 0;
            
            while (!myfile.eof()){
                int c = 0;
                string str;

                getline(myfile, str);

                for(int i = 0; i < str.size(); ++i){
                    if(str[i] == '-'){
                        matrix[l][c] = -(str[i+1] - '0');
                        i++;
                        c++;
                        continue;
                    }
                    else if(str[i] != '[' && str[i] != ']' && str[i] != ' ' && str[i] != '\n'){
                        matrix[l][c] = str[i] - '0';
                        ++c;
                    }
                }
                ++l;
            };
            myfile.close();

            matriz =  (int**)malloc(linha*sizeof(int*));
            for (int x = 0; x < linha; x++){
                matriz[x] =  (int*)malloc(linha*sizeof(int));
                for (int y = 0; y < linha; y++){
                    matriz[x][y] = matrix[x][y];
                    cout << "  " << matriz[x][y];
                }
                cout << endl;
                nVertice++;
            }
            cout << "NÚMERO DE VÉRTICES: " << nVertice << endl;
        };

        /*------------------------FUNÇÃO PARA MOSTRAR AS ARESTAS----------------------*/
        void mostrarArestas(){
            cout << "NÚMERO DE VÉRTICES: " << nVertice << endl;
            for(int x = 0; x < nVertice; x++){
                for(int y = 0; y < nVertice; y++){
                    if(matriz[x][y] == -1){
                        cout << "(" << x+1 << ", " << y+1 << "); ";
                        mArestas++;
                    }                     
                }
            }
            
        };

        /*-------------------FUNÇÃO PARA MOSTRAR MATRIZ DE ADJACÊNCIA-----------------*/
        void matrizAdjacencia(){
            matrizA =  (int**)malloc(nVertice*sizeof(int*));
            for (int x = 0; x < nVertice; x++){
                matrizA[x] =  (int*)malloc(nVertice*sizeof(int));
                for (int y = 0; y < nVertice; y++){
                    matrizA[x][y] = matriz[x][y];
                    if (matrizA[x][y] == -1)
                        matrizA[x][y] = 1;
                    else
                        matrizA[x][y] = 0;
                    cout << " " << matrizA[x][y] << " ";
                }
                cout << endl;
            }
        };

        /*-----------------------FUNÇÃO PARA MOSTRAR MATRIZ DIAGONAL--------------------*/
        void matrizDiagonal(){
            matrizD =  (int**)malloc(nVertice*sizeof(int*));
            for (int x = 0; x < nVertice; x++){
                matrizD[x] =  (int*)malloc(nVertice*sizeof(int));
                for (int y = 0; y < nVertice; y++){
                    matrizD[x][y] = matriz[x][y];
                    if (x != y)
                        matrizD[x][y] = 0;
                    cout << " " << matrizD[x][y] << " ";
                }
                cout << endl;
            }
        };

        /*---------------------FUNÇÃO PARA MOSTRAR MATRIZ LAPLACIANA--------------------*/
        void matrizLaplaciana(){
            for (int x = 0; x < nVertice; x++){
                for (int y = 0; y < nVertice; y++){
                    cout << " " << matriz[x][y] << " ";
                }
                cout << endl;
            }
        };

        /*---------------------FUNÇÃO PARA MOSTRAR MATRIZ DE INCIDÊNCIA------------------*/
        void matrizIncidencia(){
            for (int x = 0; x < nVertice; x++){
                for (int y = 0; y < mArestas/2; y++){
                    
                }
                cout << endl;
            }
        };


        /*-----------------------FUNÇÃO PARA MOSTRAR GRAU DO VÉRTICE----------------------*/
        void grauVertice(int vertice){
            int grau = 0;
            if (vertice > nVertice){
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t O VÉRTICE INFORMADO NÃO EXISTE" << endl;
                cout << "-------------------------------------------------------" << endl;
            }
            else{
                for (int x = 0; x < nVertice; x++){
                    for (int y = 0; y < nVertice; y++){
                        if(x == y && vertice == x+1)
                            grau = matriz[x][y];
                    }
                }
                cout << endl << "-------------------------------------------------------" << endl;
                cout << " VÉRTICE " << vertice << " POSSUI GRAU " << grau << endl;
                cout << "-------------------------------------------------------" << endl;
            }
            
        };

        /*----------------------------FUNÇÃO PARA MOSTRAR VIZINHANÇA------------------------*/
        void vizinhancaVertice(int vertice){
            int comp = 1;
            int vizinho;
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "VIZINHOS: ";
            for(int x = 0; x < nVertice; x++){
                for(int y = 0; y < nVertice; y++){
                    if(matriz[x][y] == -1 && vertice == comp){
                        cout << " " << y+1;
                    }
                }
                comp++;        
            }
        };
    
};
