#include <iostream>
#include "Grafos.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    int op, origem, destino, vertice, linha; 
    
    Grafos *grafos = new Grafos();
    do{
        cout << endl << "-------------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÕES/VISUALIZAÇÕES" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << " 1 -- VISUALIZAR ARQUIVO " << endl;
        cout << " 2 -- VISUALIZAR MATRIZ DE ADJACÊNCIA " << endl;
        cout << " 3 -- VISUALIZAR MATRIZ DIAGONAL " << endl;
        cout << " 4 -- VISUALIZAR MATRIZ LAPLACIANA " << endl;
        cout << " 5 -- VISUALIZAR MATRIZ DE INCIDÊNCIA " << endl;
        cout << " 6 -- VISUALIZAR O GRAU DE UM VÉRTICE " << endl;
        cout << " 7 -- VISUALIZAR VIZINHANÇA DE UM VÉRTICE " << endl;
        cout << " 8 -- VISUALIZAR TODAS AS POSSIBILIDADE DE ARESTAS " << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "OPÇÃO: ";
        cin >> op;
        cout << "-------------------------------------------------------" << endl;
        

        switch(op){

            case 1:
                grafos->arquivos();
                break;

            case 2:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ DE ADJACÊNCIA" << endl;
                cout << "-------------------------------------------------------" << endl;
                grafos->matrizAdjacencia();
                break;

            case 3:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MAATRIZ DIAGONAL" << endl;
                cout << "-------------------------------------------------------" << endl;
                grafos->matrizDiagonal();
                break;

            case 4:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MAATRIZ LAPLACIANA" << endl;
                cout << "-------------------------------------------------------" << endl;
                grafos->matrizLaplaciana();
                break;

            case 5:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ DE INCIDÊNCIA" << endl;
                cout << "-------------------------------------------------------" << endl;
                grafos->matrizIncidencia();
                break;

            case 6:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t GRAU DE VÉRTICE" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "INFORME O VÉRTICE QUE DESEJA SABER SEU GRAU: " << endl;
                cin >> vertice;
                grafos->grauVertice(vertice);
                break;

            case 7:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t VIZINHANÇA DE VÉRTICE" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "INFORME O VÉRTICE QUE DESEJA SABER SUA VIZINHANÇA: " << endl;
                cin >> vertice;
                grafos->vizinhancaVertice(vertice);
                break;                

            case 8:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t VIZUALIZAÇÃO DAS ARESTAS" << endl;
                cout << "-------------------------------------------------------" << endl;
                grafos->mostrarArestas();   
                break;
            case 0:
                cout << "\t PROGRAMA ENCERRADO COM SUCESSO!\n \t VOLTE EM BREVE!" << endl;
                break;
            default:
                cout << "OPÇÃO INVÁLIDA, DIGITE UMA VÁLIDA POR FAVOR!" << endl;
        };
    }while(op != 0);

    return 0;
}