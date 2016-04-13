#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int origem, destino, vertice, inicio;
        int **matriz;

    public:
    //Construtor
    Grafos(){
    	//void grafo(int nVertice);
    	void adicionarVertice(int nVertice);
    	void adicionarAresta(int origem, int destino);
    };

    Grafos(int origem, int destino, int vertice){
    	this->origem = origem;
    	this->destino = destino;   	
    	this->vertice = vertice;
    }
    /*---------------------------FUNÇÃO LER ARQUIVOS--------------------------*/
    int arquivos() {

   
        ifstream txtFile;
        char elemento;
        int linha = 0;
        txtFile.open("matriz.txt");

        while (txtFile.get(elemento)){
            cout << elemento;
            if(elemento == '\n')
                linha++;
        
        }
        txtFile.close();
        cout << endl << endl;
        cout << "QUANTIDADE: " << linha << endl;
        char matriz[linha][linha];
        
        ifstream myfile;
        myfile.open("matriz.txt");
        while (! myfile.eof()){
            for (int x = 0; x < linha; x++){
                cout << "" << endl;
                for (int y = 0; y < linha; y++){
                    /*if (matriz[i][j] == '[' && matriz[i][j] == ']'){

                    }*/
                    myfile >> matriz[x][y];

                    cout << " X: " << x << " " << matriz[x][y];
                    cout << " Y: " << y << " " << matriz[x][y];
                }
                myfile.ignore();
                cout << "" << endl;
            }
        }
        myfile.close();
        cout << "MATRIZ NA POSICÃO 4 E 4: " << matriz[4][3];
    };
    
};
