#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int origem, destino, vertice, inicio, linha, recebe;
        int matrix[0][0], **matriz;

    public:
        //Construtor
        Grafos(){
        	//void grafo(int nVertice);
        	void adicionarVertice(int nVertice);
        	void adicionarAresta(int origem, int destino);
            void matrizAdjacencia(int linha);
        };

        Grafos(int origem, int destino, int vertice){
        	this->origem = origem;
        	this->destino = destino;   	
        	this->vertice = vertice;
            linha = 0;
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
                    //cout << " " << matrix[x][y] << " ";
                    matriz[x][y] = matrix[x][y];
                    cout << "  " << matriz[x][y];
                }
                cout << endl;
            }
            cout << "POS [29][0]: " <<  matriz[29][0] << endl << endl;
        };


        

        //Matriz Adjacencia
        void matrizAdjacencia(int linha){
            recebe = quantidade()/2;
            for (int x = 0; x < recebe; x++){
                for (int y = 0; y < recebe; y++){
                    if (matriz[x][y] == -1)
                        matriz[x][y] = 1;
                    else
                        matriz[x][y] = 0;
                    cout << " " << matriz[x][y] << " ";
                }
                cout << endl;
            }

        };


        void matrizDiagonal(){
            for (int x = 0; x < linha; x++){
                for (int y = 0; y < linha; y++){
                    if (x != y)
                        matriz[x][y] = 0;
                    cout << " " << matriz[x][y] << " ";
                }
                cout << endl;
            }
        };
    
};
