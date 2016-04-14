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
            //cout << elemento;
            if(elemento == '\n')
                linha++;
        
        }
        txtFile.close();
        cout << endl << endl;
        cout << "QUANTIDADE: " << linha << endl;
        
        int matrix[linha][linha];
        //std::vector<std::vector<int> > matrix(2*linha, std::vector<int>(2*linha));

        ifstream myfile;
        myfile.open("matriz.txt");

        //myfile >> matrix[0][0];


        int l = 0;
        
        while (!myfile.eof()){
            /*for (int x = 0; x < linha + 2; x++){
                cout << " " << endl;
                for (int y = 0; y < linha + 2; y++){
                    
                    char c;
                    myfile >> c;

                    if(c != '[' && c != ']')
                        matrix[x-1][y-1] = c;

                   //myfile >> matriz[x][y];                    
                   cout << "  " << matriz[x][y];
                }
                myfile.ignore();
                cout << " " << endl;
            }*/
                int c = 0;
                string str;

                getline(myfile, str);

                for(int i = 0; i < str.size(); ++i)
                {
                    if(str[i] == '-')
                    {
                        matrix[l][c] = -(str[i+1] - '0');
                        i++;
                        c++;
                        continue;
                    }

                    else if(str[i] != '[' && str[i] != ']' && str[i] != ' ' && str[i] != '\n')
                    {
                        matrix[l][c] = str[i] - '0';
                        ++c;
                    }
                }

                ++l;
            }

        for (int x = 0; x < linha; x++)
        {
            for (int y = 0; y < linha; y++)
            {
                cout << matrix[x][y] << " ";
            }

            cout << endl;
        }

        myfile.close();
        cout << "MATRIZ NA POSICÃO 4 E 4: " << matrix[1][0];
    };
    
};
