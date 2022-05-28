#include "Sculptor.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
	int i, j, k;
	nx = _nx;
	ny = _ny;
	nz = _nz;
	r = 0; g = 0; b = 0; t = 0;
	
	v = new voxel ** [nx];
	for(i = 0; i<nx; i++){
		v[i] = new voxel * [ny];
	}
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			v[i][j] = new voxel [nz];
		}
	}
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				this -> v[i][j][k].r = this -> r;
				this -> v[i][j][k].g = this -> g;
				this -> v[i][j][k].b = this -> b;
				this -> v[i][j][k].t = this -> t;
				this -> v[i][j][k].isON = false;
			}
		}
	}
}

Sculptor::~Sculptor(){
	int i, j;
	
	for(i = 0; i < nx; i++){
		for(j = 0; j < ny; j++){
			delete [] v[i][j];
		}
	}
	for(i = 0; i < nx; i++){
		delete [] v[i];
	}
	delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
	this -> r = r;
	this -> g = g;
	this -> b = b;
	this -> t = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = true;
		this -> v[x][y][z].r = this -> r;
		this -> v[x][y][z].g = this -> g;
		this -> v[x][y][z].b = this -> b;
		this -> v[x][y][z].t = this -> t;
	}
}

void Sculptor::cutVoxel(int x, int y, int z){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = false;
	}
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
	int i, j, k;
	if((this -> nx >= x0 && this -> nx >= x1) && (this -> ny >= y0 && this -> ny >= y1) && (this -> nz >= z0 && this -> nz >= z1)){
		for(i = x0; i<x1; i++){
			for(j = y0; j<y1; j++){
				for(k = z0; k<z1; k++){
					this -> v[i][j][k].isON = true;
					this -> v[i][j][k].r = this -> r;
					this -> v[i][j][k].g = this -> g;
					this -> v[i][j][k].b = this -> b;
					this -> v[i][j][k].t = this -> t;
				}
			}
		}
	}
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
	int i, j, k;
	if((this -> nx >= x0 && this -> nx >= x1) && (this -> ny >= y0 && this -> ny >= y1) && (this -> nz >= z0 && this -> nz >= z1)){
		for(i = x0; i<x1; i++){
			for(j = y0; j<y1; j++){
				for(k = z0; k<z1; k++){
					this -> v[i][j][k].isON = false;
				}
			}
		}
	}
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
	int i, j, k;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(r,2))){
					this -> v[i][j][k].isON = true;
					this -> v[i][j][k].r = this -> r;
					this -> v[i][j][k].g = this -> g;
					this -> v[i][j][k].b = this -> b;
					this -> v[i][j][k].t = this -> t;
				}
			}
		}
	}
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
	int i, j, k;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(r,2))){
					this -> v[i][j][k].isON = false;
				}
			}
		}
	}
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
	int i, j, k;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(((pow(i - xcenter, 2))/pow(rx,2)) + ((pow(j - ycenter, 2))/pow(ry,2)) + ((pow(k - zcenter, 2))/pow(rz,2)) <= 1){
					this -> v[i][j][k].isON = true;
					this -> v[i][j][k].r = this -> r;
					this -> v[i][j][k].g = this -> g;
					this -> v[i][j][k].b = this -> b;
					this -> v[i][j][k].t = this -> t;
				}
			}
		}
	}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
	int i, j, k;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(((pow(i - xcenter, 2))/pow(rx,2)) + ((pow(j - ycenter, 2))/pow(ry,2)) + ((pow(k - zcenter, 2))/pow(rz,2)) <= 1){
					this -> v[i][j][k].isON = false;
				}
			}
		}
	}
}

void Sculptor::writeOFF(const char* filename){
	int i, j, k, n_voxels, n_vertices;
	n_voxels = 0;
	std::ofstream fout;
	fout.open (filename);
	if(!fout.is_open()){
		std::cout<<"Não foi possivel abrir o arquivo"<<std::endl;
		exit(1);
	}
	
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					n_voxels = n_voxels + 1;
				}
			}
		}
	}
	
	fout << "OFF" << std::endl;
	fout << n_voxels*8 << " " << n_voxels*6 << " " << n_voxels*0 << std::endl;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
					fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
					fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
					fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
				}
			}
		}
	}
	n_voxels = 0;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					n_vertices = n_voxels * 8; 
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 1 << " " << n_vertices + 2 << " " << n_vertices + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 3 << " " << n_vertices + 5 << " " << n_vertices + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 4 << " " << n_vertices + 5 << " " << n_vertices + 7 << " " << n_vertices + 6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 1 << " " << n_vertices + 6 << " " << n_vertices + 7 << " " << n_vertices + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 4 << " " << n_vertices + 6 << " " << n_vertices + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 2 << " " << n_vertices + 7 << " " << n_vertices + 5 << " " << n_vertices + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					n_voxels = n_voxels + 1; 
				}
			}
		}
	}
	fout.close();
}





