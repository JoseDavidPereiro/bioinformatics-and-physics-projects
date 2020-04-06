#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

/*##### Punto 1 ####*/
double pi = 3.14159;

/*##### Punto 2 ####*/
void area(double r){
  cout << pi*r*r << ' ' << 2*pi*r << endl;
}

/*##### Punto 5 ####*/
double producto_punto(double *v1, double *v2, int size){
  double resp = 0;
  for(int i = 0; i < size; i++){
    resp += v1[i]*v2[i];
  }
  return resp;
}

double *suma_vector(double *v1, double *v2, int size){
  double *resp = new double[size];
  for(int i = 0; i < size; i++){
    resp[i] = v1[i] + v2[i];  
   }
  return resp;
}

int main(){
  /*##### Punto 3 ####*/
  int N;
  cout << "Introduzca valor de N";
  cin >> N;
  for(int i = 0; i < N; i++){
    srand(i + time(0));
    int r = rand()%11;
    double R = (double)r;
    area(R);
  }
  /*#### Punto 4 ####*/
  int size;
  cout << "Introduzca el size del vector";
  cin >> size;
  double *v1 = new double[size];
  for(int i = 0; i < size; i++){
    v1[i] = 1.0;
  }
  double *v2 = new double[size];
  for(int i = 0; i<size; i++){
    srand(i + time(0));
    int d = rand()%5;
    v2[i] = (double)d;
    }
  cout << "El producto punto es ";
  cout << producto_punto(v1,v2,size) <<endl;
  double *suma = suma_vector(v1,v2,size);
  
  /*#### Punto 5 ####*/
  ofstream archivo;
  archivo.open("vectores.txt");
  for(int i = 0; i<size; i++){
    archivo << v1[i] << ' ' << v2[i] << ' ' << suma[i] << ".\n";
  }
  archivo.close();

  /*#### Punto 6 y 7 ### */
  int size_mat;
  cout << "Introduzca el size de la matriz";
  cin >> size_mat;

  double **mat1 = new double*[size_mat];
  double **mat2 = new double*[size_mat];
  double **matmult = new double*[size_mat];  

  for(int i = 0; i<size_mat; i++){
    mat1[i] = new double[size_mat];
    for(int j = 0; j<size_mat; j++){
      if(i == j){
	mat1[i][j] = 1.0;
      }
      else{
	mat1[i][j] = 0.0;
      }
    }
    mat2[i] = new double[size_mat];
    for(int j = 0; j<size_mat; j++){
      srand(time(0) + i + j);
      mat2[i][j] = rand()%11;
    }
    matmult[i] = new double[size_mat];
  }

  for(int i = 0;i<size_mat; i++){
    for(int j = 0; j<size_mat; j++){
      cout << mat1[i][j] << ' ';
    }
    cout << endl;
  }

  for(int i = 0;i<size_mat; i++){
    for(int j = 0; j<size_mat; j++){
      cout << mat2[i][j] << ' ';
    }
    cout << endl;
  }

  double **m2tr = new double*[size_mat];
  for(int i = 0;i<size_mat; i++){
    m2tr[i] = new double[size_mat];
  }

  for(int i = 0;i<size_mat; i++){
    for(int j = 0; j<size_mat; j++){
      m2tr[i][j] = mat2[j][i];
    }
  }

  for(int i = 0;i<size_mat; i++){
    for(int j = 0; j<size_mat; j++){
      matmult[i][j] = producto_punto(mat1[i],m2tr[j],size_mat);
     }
  }

  for(int i = 0;i<size_mat; i++){
    for(int j = 0; j<size_mat; j++){
      cout << matmult[i][j] << ' ';
    }
    cout << endl;
  }


 

  return 0;
  
}

