#include <iostream>
#include<string>

int TestGrid (){

    struct Coordenada{
    int celula;
	int x {0};
    int y{0};
    
    };

    int x=0;
    int y=0;
    int tamano {10};
    int ejex {0};
    int ejey {0};
    //char celula {'#'};
    char espacio {' '};
    std::cout<< "Ingrese las coordenadas de la celula que quiere activar/n X: ";
    std::cin >> x;
    std::cout<< "Y:";
    std::cin >> y;
    
    for (ejex=0; ejex<=tamano; ++ejex){
        if (ejex<tamano){
            std::cout<< "x"<<ejex<<" ";
            } 
        }

    for (ejey=0; ejey<=tamano;++ejey){
            if (ejey<y){
            std::cout<<"y"<<ejey<<"\n";
            }
            else if (ejey==y)
            {
                std::cout<<"y"<<ejey;
                for (ejex=0; ejex<=x; ++ejex){
                    std::cout<< espacio;
                    if (ejex<x)
                        {
                        std::cout<<" ";
                        }
                    else if (ejex==x)
                        {
                        std::cout<<'#'<<"\n";
                        }   
                    }
            }

                
        
        }
    

    return 0;
    }

