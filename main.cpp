#include <iostream>
#include "Sculptor.h"
#include "Sculptor.cpp"
#include "voxel.h"

using namespace std;

int main(){

    Sculptor testeBox(5,5,5);
    testeBox.setColor(0,0,1.1,1);
    testeBox.putBox(0,4,0,4,0,4);
    testeBox.cutBox(1,3,1,3,1,3);
    testeBox.writeOFF("testeBox.off");
    Sculptor Esfera(20,20,20);
        Esfera.setColor(0,0,1.5,1);
        Esfera.putSphere(10,10,10,4);
        Esfera.cutSphere(6, 6, 6, 1);
    Esfera.writeOFF("Esfera.off");
    
    Sculptor Elip(20,20,20);
        Elip.putEllipsoid(5,5,5,4,3,2);
        Elip.cutEllipsoid(2,5,5,2,3,1);
    Esfera.writeOFF("Elip.off");
    return 0;
}

