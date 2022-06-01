#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
#include <stdio.h>
#include <stdlib.h>

/** 
  @file Sculptor.h
  @authors Nilsiane Almeida & Thiago Lopes
  @since 05/2022
  @brief Class Sculptor - Funções
 */

class Sculptor {
protected:
  voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,t; // Current drawing color
public:

/**
   @brief Método construtor da classe.
   @param nx, ny, nz
 */
  Sculptor(int _nx, int _ny, int _nz);
/**
   @brief Destrutor da classe.
 */
  ~Sculptor();

  /**
   @brief Essa função serve para definir ou alterar a cor e transparencia do voxel no seu projeto.
   @param r, g, b, alpha. Onde r, g e b recebem o valor de vermelho, verde e azul no sistema rgb. 
   Esses valores variam de 0.01 a 0.99. Já o parametro alpha define a transparencia do bloco, com valores variando de 0 a 1.
 */
  void setColor(float r, float g, float b, float alpha);

 /**
   @brief Ativa o voxel na posição (x,y,z) (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho
   @param x, y, z
 */
  void putVoxel(int x, int y, int z);
 /**
   @brief Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
   @param x, y, z
 */
  void cutVoxel(int x, int y, int z);
  /**
  @brief  Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
  De forma prática, adiciona um quadrado a sua escultura.
  @param x0, x1, y0, y1, z0, z1
 */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
 /**
  @brief  Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
  De forma prática, exclui um quadrado da sua escultura.
  @param x0, x1, y0, y1, z0, z1
 */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
 /**
  @brief  Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho.
  De forma prática, adiciona uma esfera a sua escultura.
  @param xcenter, ycenter, zcenter, radius
 */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
 /**
  @brief  desativa todos os voxels que satisfazem à equação da esfera.
  De forma prática, retira uma esfera da sua escultura.
  @param xcenter, ycenter, zcenter, radius
 */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
 /**
  @brief  Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
  De forma prática, adiciona uma elipse a sua escultura.
  @param xcenter, ycenter, zcenter, rx, ry, rz
 */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
 /**
  @brief  Desativa todos os voxels que satisfazem à equação do elipsóide.
  De forma prática, retira uma elipse sa sua escultura.
  @param xcenter, ycenter, zcenter, rx, ry, rz
 */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
    @brief Cria e escreve um arquivo no formato .OFF, que pode ser lifo por um software de visualização para geração da imagem 3D
    @param fimename. Nome do arquivo.
 */
  void writeOFF(const char* filename);
};

#endif
