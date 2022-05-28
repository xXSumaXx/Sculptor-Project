#include <iostream>
#include "Sculptor.h"
#include "Sculptor.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void movC(Sculptor *M, int x, int y, int z){
	// para mudar a cor do voxel
	(*M).setColor(0.99,0.01,0.01,1); // Cor da pele
	// Fucinho
  	(*M).putBox(0+x,11+x,-1+y,9+y,0+z,5+z);
  	(*M).cutBox(2+x,3+x,5+y,9+y,3+z,4+z);
  	(*M).cutBox(8+x,9+x,5+y,9+y,3+z,4+z);
  	// Cabeça
  	(*M).putBox(0+x,11+x,-1+y,5+y,5+z,9+z);
  	// Sobrancelhas
  	(*M).putBox(0+x,5+x,3+y,5+y,9+z,10+z);
  	(*M).putBox(6+x,11+x,3+y,5+y,9+z,10+z);
  	// Cor do fundo dos olhos
  	(*M).setColor(0.99,0.99,0.99,1); // Branco
  	// Fundo dos olhos
  	(*M).putBox(1+x,5+x,4+y,5+y,5+z,8+z);
  	(*M).putBox(6+x,10+x,4+y,5+y,5+z,8+z);
  	// Cor da Iris
  	(*M).setColor(0.0,0.0,0.0,1); // Preto
  	// Iris
  	(*M).putBox(2+x,5+x,4+y,5+y,5+z,7+z);
  	(*M).putBox(6+x,9+x,4+y,5+y,5+z,7+z);
  	// Cor da Boca
  	(*M).setColor(0.99,0.65,0.3,1); // Cor da pele
  	// Boca
  	(*M).putBox(0+x,11+x,4+y,9+y,0+z,2+z);
}

void movB(Sculptor *M, int x, int y, int z){
	(*M).setColor(0.99,0.01,0.01,1); // Cor da pele
	// Pescoço
  	(*M).putBox(0+x,11+x,8+y,12+y,0+z,14+z);
  	(*M).putBox(0+x,11+x,3+y,8+y,0+z,14+z);
  	(*M).putBox(0+x,11+x,0+y,3+y,0+z,12+z);
  	// Mãos
  	(*M).putBox(0+x,11+x,12+y,14+y,8+z,10+z);
  	(*M).cutBox(2+x,9+x,12+y,14+y,8+z,10+z);
  	(*M).putBox(0+x,11+x,14+y,15+y,6+z,9+z);
  	(*M).cutBox(2+x,9+x,14+y,15+y,6+z,9+z);
  	(*M).setColor(0.99,0.65,0.3,1); // Cor da Boca
  	(*M).putBox(0+x,11+x,14+y,15+y,6+z,7+z);
  	(*M).cutBox(2+x,9+x,14+y,15+y,6+z,7+z);
  	// Barriga
  	(*M).putBox(2+x,9+x,12+y,13+y,0+z,14+z);
  	(*M).putBox(1+x,10+x,12+y,16+y,13+z,14+z);
}
void movP(Sculptor *M, int x, int y, int z){
	(*M).setColor(0.99,0.01,0.01,1); // Cor da pele
	// Patas
  	(*M).putBox(0+x,15+x,8+y,16+y,6+z,13+z);
  	(*M).cutBox(3+x,12+x,8+y,16+y,6+z,7+z);
  	(*M).putBox(0+x,15+x,7+y,14+y,3+z,6+z);
  	(*M).cutBox(3+x,12+x,7+y,14+y,3+z,6+z);
  	(*M).putBox(0+x,15+x,8+y,17+y,0+z,3+z);
  	(*M).cutBox(3+x,12+x,8+y,17+y,0+z,3+z);
  	(*M).setColor(0.99,0.65,0.3,1); // Cor da Boca
  	(*M).putBox(0+x,15+x,16+y,17+y,0+z,3+z);
  	(*M).cutBox(3+x,12+x,16+y,17+y,0+z,3+z);
  	(*M).cutBox(1+x,2+x,16+y,17+y,0+z,3+z);
  	(*M).cutBox(13+x,14+x,16+y,17+y,0+z,3+z);
  	(*M).putBox(4+x,11+x,7+y,19+y,7+z,8+z);
}
void movCal(Sculptor *M, int x, int y, int z){
	// Calda
  	(*M).setColor(0.99,0.65,0.3,1); // Cor da Boca
  	(*M).putBox(5+x,10+x,3+y,8+y,7+z,10+z);
  	(*M).cutBox(5+x,10+x,3+y,5+y,7+z,8+z);
  	(*M).setColor(0.99,0.01,0.01,1); // Cor da pele
  	(*M).putBox(5+x,10+x,4+y,8+y,9+z,11+z);
  	(*M).putBox(5+x,10+x,3+y,4+y,10+z,12+z);
  	(*M).putBox(5+x,10+x,2+y,3+y,11+z,13+z);
  	(*M).putBox(5+x,10+x,1+y,2+y,11+z,16+z);
  	(*M).putBox(5+x,10+x,2+y,4+y,15+z,16+z);
  	(*M).setColor(0.99,0.65,0.3,1); // Cor da Boca
  	(*M).putBox(5+x,10+x,0+y,1+y,11+z,16+z);
  	(*M).putBox(5+x,10+x,1+y,3+y,10+z,11+z);
  	(*M).putBox(5+x,10+x,1+y,4+y,16+z,17+z);
}

int main(void) {
  	// cria um escultor cuja matriz tem 10x10x10 voxels
  	Sculptor Dino(100,100,100);
  	movC(&Dino, 2, 16, 21);
    movB(&Dino, 2, 8, 7);
    movP(&Dino, 0, 1, 0);
    movCal(&Dino, 0, 0, 0);
  
  Dino.writeOFF("Dino2.off");
}
