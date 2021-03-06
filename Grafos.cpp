#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int vertice, linha, nVertice, mArestas;
        int matrix[0][0], **matriz, **matrizA, **matrizD, **matrizI;
        int *vetorAresta1, *vetorAresta2;

    public:
        //Construtor
        Grafos(){
        };

        Grafos(int nVertice){ 
            this->nVertice = nVertice; 	
            this->mArestas = mArestas;
        	this->vertice = vertice;
            linha = 0;   
            this->matriz = matriz;
            this->matrizA = matrizA;
            this->matrizD = matrizD;
            this->matrizI = matrizI;
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
            cout << endl << "-------------------------------------------------------" << endl;
            cout << "NÚMERO DE VÉRTICES: " << nVertice << endl;
            cout <<"-------------------------------------------------------" << endl;
        };

        /*------------------------FUNÇÃO PARA MOSTRAR AS ARESTAS----------------------*/
        void mostrarArestas(){
            int mArestas = 0;
            for(int x = 0; x < nVertice; x++){
                for(int y = 0; y < nVertice; y++){
                    if(matriz[y][x] == -1){
                        if (x < y){
                            mArestas++;
                            cout << "(" << x+1 << ", " << y+1 << "); "; 
                        }
                    }                       
                }
            }
            cout << endl <<"-------------------------------------------------------" << endl;
            cout << "\t TOTAL DE ARESTAS: " << mArestas << endl;
            cout <<"-------------------------------------------------------" << endl;
        };

        /*-----------------------FUNÇÃO CONTAR QUANTIDADE DE ARESTAS-------------------*/
        int quantidadeArestas(){
            int mArestas = 0;
            for(int x = 0; x < nVertice; x++){
                for(int y = 0; y < nVertice; y++){
                    if(matriz[y][x] == -1){
                        if (x < y)
                            mArestas++;
                    }                       
                }
            }
            return mArestas;
        };

        /*-------------------FUNÇÃO PARA MOSTRAR MATRIZ DE ADJACÊNCIA-----------------*/
        void matrizAdjacencia(){
            matrizA =  (int**)malloc(nVertice*sizeof(int*));
            for (int x = 0; x < nVertice; x++){
                matrizA[x] =  (int*)malloc(nVertice*sizeof(int));
                cout << endl;
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
                cout << endl;
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
                cout << endl;
                for (int y = 0; y < nVertice; y++){
                    cout << " " << matriz[x][y] << " ";
                }
                cout << endl;
            }
        };

        /*---------------------FUNÇÃO PARA MOSTRAR OS VETORES DAS ARESTAS--------------------*/
        void mostrarVetoresArestas(){
            int k = 0;
            vetorAresta1 = (int*) malloc(nVertice*sizeof(int));
            vetorAresta2 = (int*) malloc(nVertice*sizeof(int));
            for(int x = 0; x < nVertice; x++){
                for(int y = 0; y < nVertice; y++){
                    if(matriz[y][x] == -1){
                        if (x < y){
                            vetorAresta1[k] = x+1;
                            vetorAresta2[k] = y+1;
                            k++;
                        }
                    }                      
                }
            }    
        };

        /*---------------------FUNÇÃO PARA MOSTRAR MATRIZ DE INCIDÊNCIA------------------*/
        void matrizIncidencia(){
            mArestas = quantidadeArestas();
            int  w = 0;
            matrizI = (int **) malloc(nVertice*sizeof(int*));
            for(int x = 1; x <= nVertice; x++){
                matrizI[x] = (int *) malloc(mArestas*sizeof(int));
                cout << " " << endl;
                for(int y = 1; y <= mArestas; y++){
                    if(x == vetorAresta1[w] || x == vetorAresta2[w])
                        matrizI[x][y] = 1;
                    else
                        matrizI[x][y] = 0;
                    cout << " " << matrizI[x][y] << " ";
                    w++;
                }
                w = 0;
                cout << " " << endl;
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
            if (vertice > nVertice){
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t O VÉRTICE INFORMADO NÃO EXISTE" << endl;
                cout << "-------------------------------------------------------" << endl;
            }
            else{
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "VIZINHOS: ";
                for(int x = 0; x < nVertice; x++){
                    for(int y = 0; y < nVertice; y++){
                        if(matriz[x][y] == -1 && vertice == comp){
                            cout << "   " << y+1;
                        }
                    }
                    comp++;        
                }
                cout << endl << "-------------------------------------------------------" << endl;
            }
            
        };
    
};
